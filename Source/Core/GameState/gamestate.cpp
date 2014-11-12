#include "gamestate.h"
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

	file_location = file_path + "game" + buf + ".txt";
	std::cout << file_location << std::endl;
}

void GameState::gameOver() {
	saveGame();
	resetGame();
}

void GameState::saveGame() {
	// save at the file location and reset the game
	std::ofstream save_file;
	save_file.open(file_location);

	//first write player
	for (int i = 0; i < number_players; i++) {
		save_file << i << ", " <<
			number_stocks_max - player_stocks[i] << ", " <<
			player_character[i] << std::endl;
	}
	save_file.close();
}