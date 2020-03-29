#ifndef ENGINE_API_H
#define ENGINE_API_H

#include "engine.h"
#include "game_state.h"

/* Positions are represented as in the diagram below.

  --- --- ---
 | 0 | 1 | 2 |
  --- --- ---
 | 3 | 4 | 5 |
  --- --- ---
 | 6 | 7 | 8 |
  --- --- ---
*/

class EngineAPI
{
public:
    EngineAPI();

    void set_difficulty_level(int difficulty_level);
    // difficulty_level can be 1, 2 or 3.

    void new_game();

    bool legal_move(int position);

    int engine_move();
    // Return an integer från 0 to 8 that represents a move computed by the engine.

    void make_move(int position);

    bool board_full();

    char get_value(int position);
    /* Return 'X', 'O' or ' ' depending on the state of the corresponding position.
       'X' represents the player making the first move, 'O' the player making
       second move and ' ' that the position is empty.*/

    bool three_in_a_row(int position);
    /* True iff the given position is a part of a three in a row. This can be used
       both for finding if it's game over and for highligting three in a rows after
       a game is finished.*/

private:
    GameState game_state;
    int difficulty_level_;
};

#endif
