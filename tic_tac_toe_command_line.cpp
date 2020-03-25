#include <iostream>
#include "engine_API.h"

void print_board(EngineAPI& engine)
{
    char board[9];
    for (int n=0; n<=8; n++)
        board[n] = engine.get_value(n);
    std::cout << " --- --- ---" << std::endl
    << "| " << board[0] << " | " << board[1] << " | " << board[2]
    << " |" << std::endl << " --- --- ---" << std::endl
    << "| " << board[3] << " | " << board[4] << " | " << board[5]
    << " |" << std::endl << " --- --- ---" << std::endl
    << "| " << board[6] << " | " << board[7] << " | " << board[8]
    << " |" << std::endl << " --- --- ---" << std::endl;
}

int main()
{
    EngineAPI engine;
    char answer[20];
    bool exit_program = false;
    int move;

    std::cout << std::endl;
    std::cout << "The squares are numbered as follows:" << std::endl;
    std::cout << std::endl;
    std::cout << " --- --- ---" << std::endl;
    std::cout << "| 0 | 1 | 2 |" << std::endl;
    std::cout << " --- --- ---" << std::endl;
    std::cout << "| 3 | 4 | 5 |" << std::endl;
    std::cout << " --- --- ---" << std::endl;
    std::cout << "| 6 | 7 | 8 |" << std::endl;
    std::cout << " --- --- ---" << std::endl;
    std::cout << std::endl;
    std::cout << "To play the game, enter the number for the square of choice." << std::endl;
    std::cout << std::endl;
    std::cout << "Print q to quit." << std::endl;
    std::cout << std::endl;

    std::cout << "Difficulty level (1-3): ";
    std::cin >> answer;
    switch (answer[0])
    {
        case '1': engine.set_difficulty_level(1); break;
        case '2': engine.set_difficulty_level(2); break;
        case '3': engine.set_difficulty_level(3); break;
        case 'q': exit_program = true; break;
    }

    if (not exit_program)
    {
        std::cout << std::endl;
        print_board(engine);
        std::cout << std::endl;
    }

    while (not engine.board_full() and not exit_program)
    {
        std::cout << "Input: ";
        std::cin >> move;
        engine.make_move(move);
        print_board(engine);
        if (engine.three_in_a_row(move))
        {
            std::cout << "You win!" << std::endl;
            break;
        }
        move = engine.engine_move();
        engine.make_move(move);
        print_board(engine);
        if (engine.three_in_a_row(move))
        {
            std::cout << "Computer win." << std::endl;
            break;
        }
    }

    return 0;
}
