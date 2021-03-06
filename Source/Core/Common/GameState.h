#include <string>

class GameState {
public:
 GameState(int, int, std::string);
	void setNumberPlayers(int);
	void setNumberStocks(int);
	void setCharacter(int, std::string);
	void setCharacterByInt(int, int);
	void playerDied(int);
	void resetGame();
	void setFilePath(std::string);
	void reportReadyForHosting();
	std::string logGameState();

private:
	int number_players;
	int * player_stocks;
	std::string * player_character;
	int number_stocks_max;
	std::string file_path;
	std::string file_location;

	void gameOver();
	void saveGame();
};

GameState* g_game_state = new GameState(2, 4, "");