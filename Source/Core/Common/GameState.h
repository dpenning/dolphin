#include <string>

class GameState {
public:
 GameState(int, int, std::string);
	void setNumberPlayers(int);
	void setNumberStocks(int);
	void setCharacter(int, std::string);
	void playerDied(int);
	void resetGame();
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