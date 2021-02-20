#include "classes.hpp"
#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

void Player::determine_betting_amount_player()
{

    int current_bet;

    cout << "You currently have " << current_money << " available to play with.\n";
    cout << "How much would you like to bet this round? ";
    cin >> current_bet;
    cout << "\n";

    while (current_bet > current_money)
    {

        cout << "I'm sorry, you don't have that much money.\n";
        cin.clear();
        cin.ignore();
        cout << "Please enter the amount you would like to bet: ";
        cin >> current_bet;
        cout << "\n";
    }

    if (current_bet <= current_money)
    {

        char answer;

        cout << "So you want to bet " << current_bet << " this round? (y/n) ";
        cin >> answer;
        cout << "\n";

        while (answer != 'y' && answer != 'Y' && answer != 'n' && answer != 'N')
        {
            cin.clear();
            cin.ignore();
            cout << "Please enter the amount you would like to bet: ";
            cin >> current_bet;
            cout << "So you want to bet " << current_bet << " this round? (y/n) ";
            cin >> answer;
            cout << "\n";
        }

        while (answer == 'n' || answer == 'N')
        {
            cout << "Please enter the amount you would like to bet: ";
            cin >> current_bet;
            cout << "So you want to bet " << current_bet << " this round? (y/n) ";
            cin >> answer;
            cout << "\n";
        }

        if (answer == 'y' || answer == 'Y')
        {
            cout << "Great!\n";
            cout << "The round will now start!\n";
            current_money = current_money - current_bet;
            Sleep(1000 * 3);
            return;
        }
    }
}