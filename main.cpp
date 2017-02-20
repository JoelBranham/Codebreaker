#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include "header.h"

using namespace std;
 
const char CODE_SPAN = 6;		// range of digits allowed in the code (only digits 1 - 6 allowed)
const int CODE_LENGTH = 4;		// length of code

int main() {

	srand(time(NULL));

	string player_guess, secret_code, secret_copy, player, player_copy;

	char repeat_game;

	int num_guesses;

	bool game_over = false, guessed_code = false;

	cout << "WELCOME TO CODEBREAKER!\n\n";
	cout << "Oh no! The computer has generated a secret code. Can you guess it?\n";

	while ( !game_over ) {


		cout << '\n' << setw(40) << "YOUR GUESSES:" << setw(15) << "CORRECT:" << setw(15) << "MISPLACED:" << '\n';
		cout << string(70, '=') << '\n';
	
		secret_code = generate_code();    
		secret_copy = secret_code;
		num_guesses = 0;
		
		while (!guessed_code) {
	
			secret_code = secret_copy; 
			player = get_player_code();
			player_copy = player;
			int correct = 0;
			int misplaced = 0;
			num_guesses++;
			
			if (player == secret_code){
			cout << "Congratulations, you guessed the code!\nIt only took you " << num_guesses << " guess(es)\n\n";
			break;
			} 
			
			for (int x = 0; x < CODE_LENGTH; x++){ 			// checking for correct 
				if (player[x] == secret_code[x]){
				correct++;
				player[x] = 'c';
				secret_code[x] = 'd';
				}
			}
			
			for (int x = 0; x < CODE_LENGTH; x++){    		// checking for misplaced
				for(int i = 0; i < CODE_LENGTH; i++){
					if (player[x] == secret_code[i]){
					misplaced++;
					player[x] = 'z';
					secret_code[i] = 'm';	
					}
				}
			}	
	
			cout << '\n' << setw(40) << player_copy << setw(15) << correct << setw(15) << misplaced << '\n';
			cout << string(70, '=') << '\n';
			
		}

		cout << "Would you like to play again (Y/N)? ";
		
		cin >> repeat_game;
		repeat_game = toupper(repeat_game);


		if ( repeat_game == 'N' ) {
			game_over = true;
		}

		else {
			guessed_code = false;
		}

	} 

	cout << "Thanks for playing!\n";

	return 0;

} // end main

string get_player_code() {

	string player_code = "0000";
	string player_input;
	bool valid_code = false;

	while ( !valid_code ) {
		
		player_code = "0000";
		cout << "Enter Code: ";
		cin >> player_input;

		if (player_input.size() < CODE_LENGTH) {
			cout << "ERROR: Code Too Short!\n\n";
		}
		
		else if (player_input.size() > CODE_LENGTH){
			cout << "ERROR: Code Too Long!\n\n";
		}

		for (int x = 0; x < player_input.size(); x++){
			if (player_input[x] > (CODE_SPAN + '0') ){
				player_code = "1";
			}
		}
			
		if (player_code == "1"){
			cout << "ERROR: Code contains digits out of range specified or are not integers!\n\n";
		}
		
		if (player_input.size() == CODE_LENGTH && player_code != "1"){
			valid_code = true;
		}
		
	} // end while
	
	player_code = player_input;
	
	return player_code;	

} // end get_player_code()


string generate_code() {    			// generate code

	string code = "";

	for (int x = 0; x < CODE_LENGTH; x++){
		code.push_back( randint(1, CODE_SPAN + 1) + '0' );
	}
	
	return code;
	
} // end generate_code()

int randint(int max) {				// random number generator

	return ( rand() % max );

} 

int randint(int min, int max) {			// random number generator

	return ( randint( max - min ) + min );

} 
