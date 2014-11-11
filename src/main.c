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

int main(int argc, char **argv) 
{
    int seed = time(NULL);
    //seed = 1394569404;
    //printf("Random seed: %d\n", seed);
    srand(seed);

    //printf("%d %d %d\n", LSB(0x11), MSB(0x11), PopCnt(0xFFFF));

    precalc_init();
    //to understand the function precalc_init(),add some print out
    //start print
//    char *s1=(char*)malloc(20*sizeof(char));
//    for(int i=1;i<5;i++){
//        for(int j=1;j<5;j++)
//        {
//            int tmp=precalc_directions[i][j];
//            int num=16;
//            while(num>0)
//            {
//                *(s1+num-1)=tmp%2+'0';
//                tmp=tmp/2;
//                num--;
//            }
//            *(s1+16)='\0';
//            printf("%d\n",precalc_directions[i][j]);
//            printf("%s\n",s1);
//        }
//    }
//   printf("\n");
    //end print

    if (argc == 2) 
    {
        if (0 == strcmp(argv[1], "--human")) 
        {
            board_t board = board_init();

            while (1) 
            {
                board_print(board);

                printf("[hjkl] ");
                char key = getchar();
                getchar(); // eat newline

                if (key == 'k') 
                {
                    board_move(&board, MOVE_UP);
                }
                else if (key == 'l') 
                {
                    board_move(&board, MOVE_RIGHT);
                }
                else if (key == 'j') 
                {
                    board_move(&board, MOVE_DOWN);
                }
                else if (key == 'h') 
                {
                    board_move(&board, MOVE_LEFT);
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
