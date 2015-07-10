c2048
=====

c2048 is a 2048 game engine with AI, made in C.

c2048 uses bitmaps extensively, and should have a very fast board implementation. The AI is a simple depth-first search using `score + number_or_free_cells` as a heuristic.

If you want to change the parameters for the search algorithm, change `AI_DEPTH` and `AI_NUM_TRIES` in `ai.h`.

Shell arguments:
----------------

    --human  Play on the console, using hjkl to move around
    --test   Runs some testcases
    --ai     Runs infinitly many games in a row, while tracking stats (avg, max, nps, etc.)

Improvement:
------------

    First:
    Base on https://github.com/helgefmi/c2048, I fix its movement[1] regulation and score regulation[2].
    [1].After the collision conduction, all the cells should be moved along the direction. Add this rule into
        the void board_move() in board.c file.
    [2].The scoring regulation should not include the cell value, just score it when collision happens and  
        the two cells can merge.
    Second:
    Optimize the interface so that it can step over the wrong key stroking and warn you about this[3].
    [3].The fix is in the main.c file and add some condition judge to ensure better interface.
