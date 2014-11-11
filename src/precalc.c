#include "bitmanip.h"
#include "board.h"
#include "precalc.h"
#include "util.h"
#include "stdio.h"
#include "stdlib.h"

static int move_to_delta[4][2] = {
    {0, -1},
    {1, 0},
    {0, 1},
    {-1, 0},
};//direction and step for moving

/* a bitmap used to quickly find all the cells a number can move to */
// SIZE: #define SIZE (COLSIZE * COLSIZE)
// COLSIZE=4
// column 4 for the four directions to move
int precalc_directions[SIZE][4];

/* used to find the index of the most distant cell a number can move to */
int precalc_directions_last[SIZE][4];

/* used to find the index of the nearest cell a number can move to */
int precalc_directions_first[SIZE][4];

void precalc_init() 
{
    for (int i = 0; i < SIZE; ++i) 
    {
        for (int move = 0; move < 4; ++move) 
        {
            //move is the for the direction to move
            int dx = move_to_delta[move][0];
            int dy = move_to_delta[move][1];

            int x = i % COLSIZE;//find the colum number
            int y = i / COLSIZE;//find the row number

            precalc_directions[i][move] = 0;
            precalc_directions_last[i][move] = -1;
            precalc_directions_first[i][move] = -1;

            for (x += dx, y += dy; x >= 0 && x < COLSIZE && y >= 0 && y < COLSIZE; x += dx, y += dy) 
            {
                //use a 16 bits to record the location to move in the 4X4 squres
                precalc_directions[i][move] |= (1 << (y * COLSIZE + x));

                //Output the bitmap
                /*
                char *s1=(char*)malloc(20*sizeof(char));
                for(int i=1;i<5;i++){
                    for(int j=1;j<5;j++)
                    {
                        int tmp=precalc_directions[i][move];
                        int num=16;
                        while(num>0)
                        {
                            *(s1+num-1)=tmp%2+'0';
                            tmp=tmp/2;
                            num--;
                        }
                    *(s1+16)='\0';
                    printf("%d\n",precalc_directions[i][move]);
                    printf("%s\n",s1);
                    }
                }
                */
                //end of the Output of bitmap

                precalc_directions_last[i][move] = y * COLSIZE + x;
                if (precalc_directions_first[i][move] == -1)
                //each direction can have one smallest move number
                {
                    precalc_directions_first[i][move] = y * COLSIZE + x;
                }
            }//end of the one direction loop
        }//end of the fout directions loops
    }//end of every cells loops
}
