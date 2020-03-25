#include <iostream>
#include "engine_API.h"

void first_move_test(EngineAPI& engine)
// Test how often each first move occurs.
{
    int number[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int trials = 10000;
    engine.new_game();
    for (int n=1; n<=trials; n++)
    {
        number[engine.engine_move()]++;
    }
    std::cout << "0: " << number[0] << " times" << std::endl;
    std::cout << "1: " << number[1] << " times" << std::endl;
    std::cout << "2: " << number[2] << " times" << std::endl;
    std::cout << "3: " << number[3] << " times" << std::endl;
    std::cout << "4: " << number[4] << " times" << std::endl;
    std::cout << "5: " << number[5] << " times" << std::endl;
    std::cout << "6: " << number[6] << " times" << std::endl;
    std::cout << "7: " << number[7] << " times" << std::endl;
    std::cout << "8: " << number[8] << " times" << std::endl;
}

int single_game(EngineAPI& engine1, EngineAPI& engine2, bool engine1_begin)
// Let engine1 and engine2 play a game against each other.
// Return 1 if engine1 wins, 0 if draw and 2 if engine2 wins.
{
    bool engine1_to_play = engine1_begin;
    int move;

    engine1.new_game();
    engine2.new_game();

    while (true)
    {
        if (engine1_to_play)
        {
            move = engine1.engine_move();
            engine1.make_move(move);
            engine2.make_move(move);
            if (engine1.three_in_a_row(move))
                return 1;
            if (engine1.board_full())
                return 0;
        }
        else
        {
            move = engine2.engine_move();
            engine1.make_move(move);
            engine2.make_move(move);
            if (engine1.three_in_a_row(move))
                return 2;
            if (engine1.board_full())
                return 0;
        }
        engine1_to_play = not engine1_to_play;
    }
}

int main()
{
    EngineAPI engine1;
    engine1.set_difficulty_level(2);
    EngineAPI engine2;
    engine2.set_difficulty_level(3);

    int number_of_games = 100;
    int engine1_wins = 0;
    int engine2_wins = 0;
    int draws = 0;
    bool engine1_begin = true;
    int result;

    for (int n=1; n<=number_of_games; n++)
    {
        result = single_game(engine1, engine2, engine1_begin);
        if (result == 1)
            engine1_wins++;
        if (result == 2)
            engine2_wins++;
        if (result == 0)
            draws++;
        engine1_begin = not engine1_begin;
    }

    std::cout << "Number of games: " << number_of_games << std::endl;
    std::cout << "Engine 1 wins: " << engine1_wins << std::endl;
    std::cout << "Engine 2 wins: " << engine2_wins << std::endl;
    std::cout << "Draws: " << draws << std::endl;

    first_move_test(engine2);
}


