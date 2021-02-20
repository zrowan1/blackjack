#include <vector>
#include <string>

class Gameframe
{
private:
    int number_of_players;
    int cards_in_deck = 52;
    int card_suit;
    int card_number;
    int card_position;
    int dealer_first_card;
    int player_first_card;
    int dealer_total_value;
    int player_total_value;

    std::vector<int> specific_card_in_deck;
    std::vector<int> all_already_drawn_cards;

public:
    void game_intro(int new_number_of_players = 0);
    int get_number_of_players();
    void game_print_info();
    void game_turn();

    int get_card_drawn();
    std::string get_card_name();
    int get_card_value();
    void print_card_value_player();
    void print_card_value_dealer();
    std::vector<int> get_specific_card_in_deck();
    void print_specific_card_in_deck();
    void get_all_cards_drawn();
    void print_all_cards_drawn();

    int get_first_dealer_card();
    int get_first_player_card();

    void get_dealer_value();
    void get_player_value();

};

class Dealer
{

private:

int dealer_first_card;


public:

void get_first_card();

};

class Player
{
private:
    int current_money = 100;
    int betting_amount;

public:
    void determine_betting_amount_player();
};
