#include <iostream>
#include "classes.hpp"
#include <windows.h>
#include <cstdlib>
#include <time.h>
#include "stdfunctions.hpp"
#include <algorithm>

using namespace std;

void Gameframe::game_intro(int new_number_of_players)
{
    char answer;

    cout << "Welcome to Blackjack (terminal edition)!\n";
    cout << "With how many players do you wanna play (max 3)? ";
    cin >> new_number_of_players;
    number_of_players = new_number_of_players;
    cout << "\n";

    while (new_number_of_players > 3 || new_number_of_players < 1)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Please enter a valid number of players!\n";
        cin >> new_number_of_players;
    }

    cout << "So " << new_number_of_players << " then? (y/n)";
    cin >> answer;

    if (answer == 'y' || answer == 'Y')
    {
        number_of_players = new_number_of_players;
        return;
    }

    while (answer != 'y' || answer != 'Y')
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "With how many players do you wanna play? (max 3) ";
        cin >> new_number_of_players;
        number_of_players = new_number_of_players;
        cout << "So " << new_number_of_players << " then? (y/n)";
        cin >> answer;

        if (answer == 'y' || answer == 'Y')
        {
            return;
        }
    }
    return;
}

int Gameframe::get_number_of_players()
{

    return number_of_players;
}

void Gameframe::game_print_info()
{

    char answer;

    cout << "Would you like to know how Blackjack is played? (y/n) ";
    cin >> answer;
    cout << "\n";

    while (answer != 'y' && answer != 'Y' && answer != 'n' && answer != 'N')
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "I'm sorry, that is not a valid input. Please answer with 'y' or 'n'.\n";
        cout << "Would you like to know how Blackjack is played? (y/n) ";
        cin >> answer;
        cout << "\n";
    }

    if (answer == 'y' || answer == 'Y')
    {
        cout << "The rules go like this:\n";
        Sleep(1000 * 1);
        cout << "The goal of the game is to draw cards equal to a value of 21 (Ace is 11 or 1 and pictures are 10).\n";
        Sleep(1000 * 3);
        cout << "If the value of your cards exceeds 21, you are bust and you will lose the money you bet that turn.\n";
        Sleep(1000 * 3);
        cout << "You win if you have have a higher value than the dealer.\n";
        Sleep(1000 * 3);
        cout << "The dealer must always take an extra card if he has less than 17.\n";
        Sleep(1000 * 3);
        cout << "If you have a value of 9, 10 or 11 on the board you can double your bet at the cost of only drawing one card.\n";
        Sleep(1000 * 3);
        cout << "If you have two cards of the same value, you can split.\n";
        Sleep(1000 * 3);
        cout << "This means you double your bet but you split your cards making 2 hands to play.\n";
        Sleep(1000 * 3);
        cout << "Have fun and good luck!\n";
        Sleep(1000 * 3);

        cout << "One moment please.";
        for (int i = 0; i < 10; i++)
        {
            Sleep(1000 * 0.5);
            cout << ".";
        }
        cout << "\n";

        return;
    }

    else if (answer == 'n' || answer == 'N')
    {

        cout << "Sure thing! The game will be started for you.\n";
        cout << "One moment please.";

        for (int i = 0; i < 10; i++)
        {
            Sleep(1000 * 0.5);
            cout << ".";
        }
        cout << "\n";
        return;
    }
}

int Gameframe::get_card_drawn()
{

    int new_suit;
    int new_number;

    srand(time(NULL));

    new_suit = rand() % 4 + 1;
    card_suit = new_suit;

    new_number = rand() % 13 + 1;
    card_number = new_number;

    card_position = concat(new_suit, new_number);

    while (count(all_already_drawn_cards.begin(), all_already_drawn_cards.end(), card_position))
    {

        new_suit = rand() % 4 + 1;
        card_suit = new_suit;

        new_number = rand() % 13 + 1;
        card_number = new_number;

        card_position = concat(new_suit, new_number);
    }

    return card_position;
}

string Gameframe::get_card_name()
{

    string this_card_suit;
    string this_card_number;
    string this_card;

    switch (card_suit)
    {
    case 1:
        this_card_suit = "of Spades.";
        break;
    case 2:
        this_card_suit = "of Hearts.";
        break;
    case 3:
        this_card_suit = "of Diamonds.";
        break;
    case 4:
        this_card_suit = "of Clubs.";
        break;
    }

    switch (card_number)
    {
    case 1:
        this_card_number = "Ace ";
        break;
    case 2:
        this_card_number = "Two ";
        break;
    case 3:
        this_card_number = "Three ";
        break;
    case 4:
        this_card_number = "Four ";
        break;
    case 5:
        this_card_number = "Five ";
        break;
    case 6:
        this_card_number = "Six ";
        break;
    case 7:
        this_card_number = "Seven ";
        break;
    case 8:
        this_card_number = "Eight ";
        break;
    case 9:
        this_card_number = "Nine ";
        break;
    case 10:
        this_card_number = "Ten ";
        break;
    case 11:
        this_card_number = "Jack ";
        break;
    case 12:
        this_card_number = "Queen ";
        break;
    case 13:
        this_card_number = "King ";
        break;
    }

    this_card = this_card_number + this_card_suit;
    return this_card;
}

int Gameframe::get_card_value()
{
    int new_number;

    switch (card_number)
    {
    case 1:
        new_number = 11;
        break;
    case 2:
        new_number = 2;
        break;
    case 3:
        new_number = 3;
        break;
    case 4:
        new_number = 4;
        break;
    case 5:
        new_number = 5;
        break;
    case 6:
        new_number = 6;
        break;
    case 7:
        new_number = 7;
        break;
    case 8:
        new_number = 8;
        break;
    case 9:
        new_number = 9;
        break;
    case 10:
        new_number = 10;
        break;
    case 11:
        new_number = 10;
        break;
    case 12:
        new_number = 10;
        break;
    case 13:
        new_number = 10;
        break;
    }
    return new_number;
}

void Gameframe::print_card_value_player()
{
    cout << "You have " << get_card_value() << " on the board right now.\n";
    Sleep(1000 * 2);
}

void Gameframe::print_card_value_dealer()
{
    cout << "Dealer has " << get_card_value() << " on the board right now.\n";
    Sleep(1000 * 2);
}

vector<int> Gameframe::get_specific_card_in_deck()
{

    specific_card_in_deck.push_back(card_suit);
    specific_card_in_deck.push_back(card_number);

    return specific_card_in_deck;
}

void Gameframe::print_specific_card_in_deck()
{

    for (int i = 0; i < specific_card_in_deck.size(); i++)
    {
        cout << specific_card_in_deck[i];
    }
}

void Gameframe::get_all_cards_drawn()
{

    int x;
    int y;

    x = card_suit;
    y = card_number;

    all_already_drawn_cards.push_back(concat(card_suit, card_number));

    specific_card_in_deck.pop_back();
    specific_card_in_deck.pop_back();
}

void Gameframe::print_all_cards_drawn()
{
    for (int i = 0; i < all_already_drawn_cards.size(); i++)
    {
        cout << all_already_drawn_cards[i] << " ";
    }
}

int Gameframe::get_first_dealer_card()
{

    return get_card_value();
}

int Gameframe::get_first_player_card()
{

    return get_card_value();
}

void Gameframe::get_dealer_value()
{

    dealer_total_value = get_first_dealer_card() + get_card_value();

    cout << "Dealer now has " << dealer_total_value << " on the board.\n";
}

void Gameframe::get_player_value()
{
    player_total_value = get_first_player_card() + get_card_value();

    cout << "Player now has " << player_total_value << " on the board.\n";
}