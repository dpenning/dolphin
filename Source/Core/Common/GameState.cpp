#include "GameState.h"
#include <string>
#include <iostream>
#include <fstream>
#include "stdio.h"
#include "time.h"

GameState::GameState(int np, int ns, std::string fp) {
	number_players = np;
	number_stocks_max = ns;
	player_stocks = new int[number_players];
	player_character = new std::string[number_players];
	file_path = fp;
	// initially start a game
	resetGame();
}

void GameState::setNumberPlayers(int players) {
	if (players > 1 && players <= 4) {
		number_players = players;
	}
	resetGame();
}

void GameState::setNumberStocks(int stocks) {
	if (stocks > 0) {
		number_stocks_max = stocks;
	}
	resetGame();
}

void GameState::setCharacter(int index, std::string character) {
	if (index < number_players) {
		player_character[index] = character;
	}
}

void GameState::setCharacterByInt(int index, int character_val) {
	std::string name = "No Character Parsed";
	switch(character_val) {
		// row 1
		case 23: name = "Wario"; break;
		case 0: name = "Mario"; break;
		case 9: name = "Luigi"; break;
		case 13: name = "Peach"; break;
		case 12: name = "Bowser"; break;
		case 5: name = "Yoshi"; break;
		case 1: name = "Donkey Kong"; break;
		case 28: name = "Diddy Kong"; break;
		case 10: name = "Captain Falcon"; break;

		//row 2
		case 41: name = "Wolf"; break;
		case 7: name = "Fox"; break;
		case 21: name = "Falco"; break;
		case 16: name = "Ice Climbers"; break;
		case 14: name = "Zelda"; break;
		case 15: name = "Sheik"; break;
		case 2: name = "Link"; break;
		case 40: name = "Toon Link"; break;
		case 22: name = "Ganondorf"; break;

		//row 3
		case 51: name = "Mewtwo"; break;
		case 36: name = "Lucario"; break;
		case 8: name = "Pikachu"; break;
		case 39: name = "Jigglypuff"; break;
		case 32: name = "Squirtle"; break;
		case 34: name = "Ivysaur"; break;
		case 30: name = "Charizard"; break;
		case 3: name = "Samus"; break;
		case 4: name = "Zero Suit Samus"; break;

		//row 4
		case 27: name = "Lucas"; break;
		case 11: name = "Ness"; break;
		case 25: name = "Pit"; break;
		case 6: name = "Kirby"; break;
		case 24: name = "Meta Knight"; break;
		case 35: name = "Dedede"; break;
		case 37: name = "Ike"; break;
		case 19: name = "Marth"; break;
		case 50: name = "Roy"; break;

		//row 5
		case 26: name = "Olimar"; break;
		case 38: name = "Rob"; break;
		case 20: name = "Mr. Game & Watch"; break;
		case 42: name = "Snake"; break;
		case 43: name = "Sonic"; break;
	}
	setCharacter(index, name);
}

std::string GameState::logGameState() {
	std::string output_str = "";
	for(int i = 0; i < number_players; i++) {
		output_str += "Player[" + std::to_string(i) + "]: ";
		output_str += "Character: " + player_character[i] + " ";
		output_str += "Stocks: " + std::to_string(player_stocks[i]) + " ";
	}
	return output_str;
}

void GameState::playerDied(int index) {
	if (index < number_players) {
		player_stocks[index]--;
		if (player_stocks[index] == 0) {
			gameOver();
		}
	}
}

void GameState::resetGame() {

	for(int i = 0; i < number_stocks_max; i++) {
		player_stocks[i] = number_stocks_max;
	}

	time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d-%X", &tstruct);

	file_location = file_path + "/game" + buf + ".txt";
}

void GameState::gameOver() {
	saveGame();
	resetGame();
}

void GameState::saveGame() {
	// save at the file location and reset the game
	std::ofstream save_file;
	save_file.open(file_path + file_location);

	//first write player
	for (int i = 0; i < number_players; i++) {
		save_file << i << "," <<
			player_stocks[i] << "," <<
			player_character[i] << std::endl;
	}
	save_file.close();
}

void GameState::setFilePath(std::string fp) {
	std::cout << "New File Path " << fp << std::endl;
	file_path = fp;
}

void GameState::reportReadyForHosting() {
	// save at the file location and reset the game
	std::ofstream save_file;
	std::cout << "* Reporting Host Ready to " << file_path + "/ready_for_hosting.txt" << std::endl;
	save_file.open(file_path + "/ready_for_hosting.txt");

	//first write player
	save_file << "Ready To Host" << std::endl;
	save_file.close();
}