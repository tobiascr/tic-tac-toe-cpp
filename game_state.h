#ifndef GAMESTATE_H
#define GAMESTATE_H

class GameState
{
public:
    GameState();

    void reset();

    bool position_empty(int position) const;

    char get_value(int position) const;
    // Return 'X', 'O' or ' ' depending on the state of the corresponding position.
    // 'X' represents the player making the first move, 'O' the second move and ' ' that
    // the position is empty.

    void make_move(int position);

    void undo_move(int position);

    bool three_in_a_row(int position) const;
    // Return true if there is a three in a rown through the given
    // position and false if not. It is assumed that the given
    // position is not empty.

    bool board_full() const;

    int get_number_of_empty_positions() const;

private:
    char board[9];
    int number_of_empty_positions;
};

#endif
