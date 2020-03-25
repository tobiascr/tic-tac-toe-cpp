#include "game_state.h"

GameState::GameState()
{
    int n;
    for (n=0; n<=8; n++)
        board[n] = ' ';
    number_of_empty_positions = 9;
}

void GameState::reset()
{
    int n;
    for (n=0; n<=8; n++)
        board[n] = ' ';
    number_of_empty_positions = 9;
}

bool GameState::X_in_turn() const
{
    return (number_of_empty_positions % 2) == 1;
}

bool GameState::position_empty(int position) const
{
    return board[position] == ' ';
}

char GameState::get_value(int position) const
{
    return board[position];
}

void GameState::make_move(int position)
{
    if (X_in_turn())
        board[position] = 'X';
    else
        board[position] = 'O';
    number_of_empty_positions--;
}  

void GameState::undo_move(int position)
{
    board[position] = ' ';
    number_of_empty_positions++;
}

bool GameState::three_in_a_row(int position) const
{
    switch (position)
    {
        case 0:
            if (board[0] == board[1] and  board[0] == board[2])
                return true;
            if (board[0] == board[3] and  board[0] == board[6])
                return true;
            if (board[0] == board[4] and  board[0] == board[8])
                return true;
            return false;
        case 1:
            if (board[1] == board[0] and  board[1] == board[2])
                return true;
            if (board[1] == board[4] and  board[1] == board[7])
                return true;
            return false;
        case 2:
            if (board[2] == board[0] and  board[2] == board[1])
                return true;
            if (board[2] == board[4] and  board[2] == board[6])
                return true;
            if (board[2] == board[5] and  board[2] == board[8])
                return true;
            return false;
        case 3:
            if (board[3] == board[0] and  board[3] == board[6])
                return true;
            if (board[3] == board[4] and  board[3] == board[5])
                return true;
            return false;
        case 4:
            if (board[4] == board[0] and  board[4] == board[8])
                return true;
            if (board[4] == board[1] and  board[4] == board[7])
                return true;
            if (board[4] == board[3] and  board[4] == board[5])
                return true;
            if (board[4] == board[2] and  board[4] == board[6])
                return true;
            return false;
        case 5:
            if (board[5] == board[2] and  board[5] == board[8])
                return true;
            if (board[5] == board[3] and  board[5] == board[4])
                return true;
            return false;
        case 6:
            if (board[6] == board[0] and  board[6] == board[3])
                return true;
            if (board[6] == board[4] and  board[6] == board[2])
                return true;
            if (board[6] == board[7] and  board[6] == board[8])
                return true;
            return false;
        case 7:
            if (board[7] == board[6] and  board[7] == board[8])
                return true;
            if (board[7] == board[4] and  board[7] == board[1])
                return true;
            return false;
        case 8:
            if (board[8] == board[6] and  board[8] == board[7])
                return true;
            if (board[8] == board[0] and  board[8] == board[4])
                return true;
            if (board[8] == board[5] and  board[8] == board[2])
                return true;
            return false;
        }
        return false;
    }

    bool GameState::board_full() const
    {
        return number_of_empty_positions == 0;
    }

    int GameState::get_number_of_empty_positions() const
    {
        return number_of_empty_positions;
    }
