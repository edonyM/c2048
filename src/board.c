#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "bitmanip.h"
#include "board.h"
#include "ai.h"
#include "test.h"
#include "precalc.h"

static void fill_random_cell(board_t*);
static int get_score(int);

static int score_map[] = 
{
        2, //     2
        5, //     4
       10, //     8
       25, //    16
       50, //    32
      125, //    64
      250, //   128
      500, //   256
     1000, //   512
     2000, //  1024
     4000, //  2048
     8000, //  4096
    16000, //  8192
    32500, // 16384
};

static int get_score(int number) 
{
    if (number > 16384) 
    {
        return number * 2;
    }

    /* since `number` is always a power of two, we can use LSB() to get its index into `score_map`. */
    unsigned int score_i = LSB(number);
    return score_map[score_i - 1];
}

static void fill_random_cell(board_t *board) 
{
    /* we don't want randomness while doing testcases. */
    if (test_status == DOING_TESTS) 
    {
        return;
    }

    /* bitmap of all the unoccupied squares */
    int bitmap_flipped = ~board->occupied_cells & ((1 << SIZE) - 1);
    if (bitmap_flipped) 
    {
        //numbers of unoccupied cells
        int num_unoccupied = PopCnt(bitmap_flipped);

        /* remove a bit from the bottom of `bitmap_flipped`, `rand() % num_unoccupied` times. */
        //this is to get the cell that is not occupied to used in the following
        for (int r = rand() % num_unoccupied; r; --r) 
        {
            bitmap_flipped &= bitmap_flipped - 1;
        }

        /* Get the index of the lowermost bit, which should now be a random index of the unoccupied squares. */
        //auto occupy the cell which 2 or 4 and the probability of 2 is larger than 4's
        int rand_i = LSB(bitmap_flipped);
        int rand_val = (rand() % 9) ? 2 : 4;

        board->cells[rand_i] = rand_val;
        board->occupied_cells |= (1 << rand_i);
        board->score += rand_val;
    }
}

board_t board_init() 
{
    board_t board;
    //func memset(char*a,char b,int n) included in the <string.h>or<memory.h>
    //which means set the n memebers of the a as character b
    memset(&board, 0, sizeof(board_t));
    for (int i = 0; i < 2; ++i)
        fill_random_cell(&board);
    return board;
}

void board_setup_bitfields(board_t *board) 
{
    board->occupied_cells = 0;
    for (int i = 0; i < SIZE; ++i) 
    {
        if (board->cells[i]) 
        {
            board->occupied_cells |= (1 << i);
        }
    }
}

void board_move(board_t *board, int move) 
{
    int reversed = move == MOVE_UP || move == MOVE_LEFT;

    /* `bitmap` represents all the numbers that we haven't moved yet */
    for (int bitmap = board->occupied_cells; bitmap;) 
    {
        //if the key strock is UP or LEFT than get the lowest bit that is not occupied
        //else get the highest bit
        //this is the cell to move
        int i = reversed ? MSB(bitmap) : LSB(bitmap);
        int val = board->cells[i];

        bitmap ^= (1 << i);

        /* did this number collide with another number? */
        int collision_bitmap = precalc_directions[i][move] & board->occupied_cells;

        if (!collision_bitmap) 
        {
            /* if not, put the number on the most distant square (if it's not there already) */
            //this is the location being moved to
            int last_i = precalc_directions_last[i][move];
            if (last_i >= 0) 
            {
                puts("no collision\n");
                //set the cell bit into 0 and the to move bit into 1
                board->occupied_cells ^= (1 << i) | (1 << last_i);
                board->cells[i] = 0;
                board->cells[last_i] = val;

                //check if there are other cells to move along the direction(4 directions)
                /*if(move == MOVE_UP)
                {
                    puts("MOVE_UP all the other cells\n");
                    int last_cell_i = last_i;
                    int move_to_row = last_cell_i / 4;
                    int move_to_colum = last_cell_i % 4;
                    int move_row = i / 4;
                    int move_colum = i % 4;
                    for(int counter=move_row + 1; counter < 4; counter++)
                    {
                        //the location of moving to 
                        move_to_row++;
                        last_cell_i = (move_to_row * 4) + move_to_colum;
                        //value of to moved cell
                        int val = board->cells[counter * 4 + move_colum];

                        //check if there is a cell, true then move the cell to the location
                        if(board->occupied_cells & (1 << (counter * 4 + move_colum)))
                        {
                            //update the bitmap
                            bitmap ^= (1 << last_cell_i);
                            //update the occupied_cells
                            board->occupied_cells ^= (1 << (counter * 4 + move_colum)) | (1 << last_cell_i);
                            //update the value of the both cells
                            board->cells[counter * 4 + move_colum] = 0;
                            board->cells[last_cell_i] = val;
                        }
                    }//end of for
                }//end of MOVE_UP
                */

                //direction of MOVE_DOWN
                if(move == MOVE_DOWN)
                {
                    puts("MOVE_DOWN all the other cells\n");
                    int last_cell_i = last_i;
                    int move_to_row = last_cell_i / 4;
                    int move_to_colum = last_cell_i % 4;
                    int move_row = i / 4;
                    int move_colum = i % 4;
                    for(int counter=move_row - 1; counter>=0; counter--)
                    {
                        //the location of moving to 
                        move_to_row--;
                        last_cell_i = (move_to_row * 4) + move_to_colum;
                        //value of being moved cell
                        int val = board->cells[counter * 4 + move_colum];

                        //check if there are any cells, true then move the cell to the location
                        if(board->occupied_cells & (1 << (counter * 4 + move_colum)))
                        {
                            //update the bitmap
                            bitmap ^=  (1 << last_cell_i);
                            //update the occupied_cells
                            board->occupied_cells ^= (1 << (counter * 4 + move_colum)) | (1 << last_cell_i);
                            //update the value of the both cells
                            board->cells[counter * 4 + move_colum] = 0;
                            board->cells[last_cell_i] = val;
                        }
                    }
                }//end of MOVE_DOWN

                //direction of MOVE_RIGHT
                if(move == MOVE_RIGHT)
                 {
                    puts("MOVE_RIGHT all the other cells\n");
                    int last_cell_i = last_i;
                    int move_to_row = last_cell_i / 4;
                    int move_to_colum = last_cell_i % 4;
                    int move_row = i / 4;
                    int move_colum = i % 4;
                    for(int counter=move_colum - 1; counter>=0; counter--)
                    {
                        //the location of moving to 
                        move_to_colum--;
                        last_cell_i = (move_to_row * 4) + move_to_colum;
                        //value of being moved cell
                        int val = board->cells[move_row * 4 + counter];

                        //check if there are any cells, true then move the cell to the location
                        if(board->occupied_cells & (1 << (move_row * 4 + counter)))
                        {
                            //update the bitmap
                            bitmap ^=  (1 << last_cell_i);
                            //update the occupied_cells
                            board->occupied_cells ^= (1 << (move_row * 4 + counter)) | (1 << last_cell_i);
                            //update the value of the both cells
                            board->cells[move_row * 4 + counter] = 0;
                            board->cells[last_cell_i] = val;
                        }//end of if
                    }//end of for
                }//end of if(MOVE_RIGHT)
            }//end of if(last_i>=0)
        }//end of if(!collision_bitmap)
        else //collide happens
        {
            /* we have a collision; find out the index and value */
            int other_i = reversed ? MSB(collision_bitmap) : LSB(collision_bitmap);
            int other_val = board->cells[other_i];

            if (other_val == val) 
            {
                puts("collision and can merge\n");
                /* score! */
                //clear the moved bit
                board->occupied_cells ^= 1 << i;

                /*--Step 1 handle the collision and plus them--*/
                board->cells[i] = 0;
                board->cells[other_i] = val * 2;
                board->score += get_score(val);
                /* remove the number from `bitmap` as it's been merged, and so it shouldn't move */
                //just change the collide bit
                bitmap &= ~(1 << other_i);
                
                /*--Step 2 move along the direction again--*/
                //after handle the collision, the collision cell should move into the first
                //unoccupied cell along the move direction
                if(move == MOVE_UP)
                {
                    //move all cells after the collision cell
                    int move_row = other_i / 4;
                    int move_colum = other_i % 4;
                    printf("%d, %d\n",val,other_i);
                    //move the cell along the direction
                    for(int counter = move_row - 1; counter >= 0; counter--)
                    {
                        if((board->occupied_cells & (1 << (counter * 4 + move_colum))) == 0)
                        {
                            puts("update the cell");
                            //update the occupied_cells of move to and move from
                            board->occupied_cells ^= 1 << ((counter + 1) * 4 + move_colum);
                            board->occupied_cells ^= 1 << (counter * 4 + move_colum);
                            //update the cells of move to and move from
                            board->cells[counter * 4 + move_colum] = 2 * val;
                            board->cells[(counter + 1) * 4 + move_colum] = 0;
                            //update the bitmap of move to and move from
                            bitmap &= ~(1 << ((counter + 1) * 4 + move_colum));
                            bitmap ^= (1 << (counter * 4 + move_colum));
                        }
                        else 
                        {
                            printf("break");
                            break;
                        }
                    }
                }
            }
            else 
            {
                puts("collision and can not merge\n");
                /* two different numbers; move to its neighbor square if we're not there already */
                // `(move + 2) % 4` flips the direction.
                int first_i = precalc_directions_first[other_i][(move + 2) % 4]; 
                if (first_i >= 0 && first_i != i) 
                {
                    board->occupied_cells ^= (1 << i) | (1 << first_i);
                    board->cells[i] = 0;
                    board->cells[first_i] = val;
                }
            }
        }//end of collsion handles
    }//end of for bitmap loops

    fill_random_cell(board);
}

void board_print(board_t board) 
{
    for (int y = 0; y < COLSIZE; ++y) 
    {
        for (int x = 0; x < COLSIZE; ++x) 
        {
            printf("%4d ", board.cells[y * COLSIZE + x]);
        }
        printf("\n");
    }
    printf("Score: %d\n", board.score);
    printf("\n");
}
void board_print_occupied(board_t board)
{
    int tmp = board.occupied_cells;
    for(int i = 1;i<17;i++)
    {
        printf("%4d ",tmp % 2);
        if(i % 4 == 0)printf("\n");
        tmp = tmp / 2;
    }
    puts("======================");
}














