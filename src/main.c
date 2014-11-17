#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "board.h"
#include "ai.h"
#include "test.h"
#include "interface.h"
#include "precalc.h"
#include "bitmanip.h"
//#include <conio.h>//not a standard head file in C

int main(int argc, char **argv) 
{
    int seed = time(NULL);
    //seed = 1394569404;
    //printf("Random seed: %d\n", seed);
    srand(seed);

    //printf("%d %d %d\n", LSB(0x11), MSB(0x11), PopCnt(0xFFFF));

    precalc_init();

    if (argc == 2) 
    {
        if (0 == strcmp(argv[1], "--human")) 
        {
            board_t board = board_init();

            while (1) 
            {
                board_print(board);

                printf("[hjkl] ");
                //char key = getchar();
                //getchar(); // eat newline
                char key;
                int flag = 0;
                scanf("%c",&key);
                while(getchar() != '\n')
                {//eat the wrong key strock until the new line
                    flag++;
                    continue;
                }
                //printf("%d",flag);

                if (key == 'k' && flag == 0) 
                {
                    board_move(&board, MOVE_UP);
                    //board_print_occupied(board);
                }
                else if (key == 'l' && flag == 0) 
                {
                    board_move(&board, MOVE_RIGHT);
                    //board_print_occupied(board);
                }
                else if (key == 'j' && flag == 0) 
                {
                    board_move(&board, MOVE_DOWN);
                    //board_print_occupied(board);
                }
                else if (key == 'h' && flag == 0) 
                {
                    board_move(&board, MOVE_LEFT);
                    //board_print_occupied(board);
                }
                else
                {
                    puts("+++++++++++++++++++++");
                    puts("+ Wrong Key Strock! +");
                    puts("+     Try Again      ");
                    puts("+++++++++++++++++++++");
                    continue;
                }
            }
        }
        else if (0 == strcmp(argv[1], "--test")) 
        {
            test_status = DOING_TESTS; // disable board_fill_random_cell
            test_run_testcases();
            test_status = NOT_DOING_TESTS;
        }
        else if (0 == strcmp(argv[1], "--ai")) 
        {
            ai_loop();
        }
        else 
        {
            interface_main(argv[1]);
        }
    }
    else 
    {
        printf("c2048, compiled with AI_DEPTH=%d AI_NUM_TRIES=%d\n\n", AI_DEPTH, AI_NUM_TRIES);
        puts("--human  Play on the console, using hjkl to move around");
        puts("--test   Runs some testcases");
        puts("--ai     Runs infinitly many games in a row, while tracking stats (avg, max, nps, etc.)");
        return 1;
    }

    return 0;
}
