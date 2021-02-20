#include <iostream>
#include <cstdlib>
#include <windows.h>
#include "classes.hpp"

using namespace std;

int main()
{

    Gameframe game1;

    game1.game_intro();

    game1.get_number_of_players();

    Player player1;

    if (game1.get_number_of_players() == 1)
    {
        game1.game_print_info();

        player1.determine_betting_amount_player();
        //////////////////////////////////////////////////////

        game1.get_card_drawn();

        cout << game1.get_card_name() << "\n";

        game1.get_card_value();

        game1.print_card_value_player();

        cout << "\n";

        game1.get_specific_card_in_deck();

        game1.get_all_cards_drawn();

        game1.get_first_player_card();
        /////////////////////////////////

        game1.get_card_drawn();

        cout << game1.get_card_name() << "\n";

        game1.get_card_value();

        game1.print_card_value_dealer();

        cout << "\n";

        game1.get_specific_card_in_deck();

        game1.get_all_cards_drawn();

        game1.get_first_dealer_card();
        ///////////////////////////////////

        game1.get_card_drawn();

        cout << game1.get_card_name() << "\n";

        game1.get_card_value();

        cout << "\n";

        game1.get_specific_card_in_deck();

        game1.get_all_cards_drawn();

        game1.get_player_value();
        ///////////////////////////////////

        game1.get_card_drawn();

        cout << game1.get_card_name() << "\n";

        game1.get_card_value();

        cout << "\n";

        game1.get_specific_card_in_deck();

        game1.get_all_cards_drawn();

        game1.get_dealer_value();
    }

    else if (game1.get_number_of_players() == 2)
    {
        Player player2;
        game1.game_print_info();
    }

    else if (game1.get_number_of_players() == 3)
    {
        Player player3;
        game1.game_print_info();
    }
}
