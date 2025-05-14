#include <iostream>

//creating our board
char board[3][3] = {{' ', ' ', ' '},
					{' ', ' ', ' '},
					{' ', ' ', ' '}};

//struct to identify player 1 & 2
struct Player
{
	std::string name;
	bool isWinner = false;
} Player1, Player2;

//print our board in console
void boardMap();

//save the "names" of Player 1 & 2
void logPlayers();

//if the 'move' has been accepted, the move will be displayed on the board
void makeMove();

//request an 'acceptable' move
void askForMove(int&, int&, int&);

//verify if the row is within the range of 1-3
bool isRowAccepted();

//verify if the column is within the range of 1-3
bool isColumnAccepted();

//verify if the space selected is taken
bool isSpaceTaken();

//verify if there is a winner
bool isThereAWinner();

//verify if there is a draw
bool isThereADraw();

//display the winner
void winnerMessage();

//display 
void drawMessage();

//decide which player should make a move
int playerTurn{ 1 };
int row{};		//represent the rows
int column{};	//represent the columns
int xMoves{};	//counter of 'X' moves
int oMoves{};	//counter of 'O' moves

int main() {

	logPlayers();

	while (!isThereAWinner()) {
		if (isThereADraw()) {
			break;
		}
		else {
			makeMove();
			boardMap();
		}
	}

	if (isThereAWinner()) {
		winnerMessage();
	}
	else if (isThereADraw()) {
		drawMessage();
	}

	return 0;
}

//updates the board and displays it
void boardMap() {
	std::cout << "\n------------\n";

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << " " << board[i][j] << " |";
		}
		std::cout << "\n------------\n";
	}

	std::cout << std::endl;
}

//saves the names of Player 1 & 2
void logPlayers() {
	std::cout << "Input the name of the Player 1: ";
	std::cin >> Player1.name;

	std::cout << std::endl;

	std::cout << "Input the name of the Player 2: ";
	std::cin >> Player2.name;

	std::cout << std::endl;
}

//if the move is accepted, the move will be displayed on the board
void makeMove() {
	switch (playerTurn)
	{
	case 1:
		do
		{
			askForMove(playerTurn, row, column);
		} while (isSpaceTaken());

		board[row - 1][column - 1] = 'X';
		xMoves++;
		playerTurn++;
		break;

	case 2:
		do
		{
			askForMove(playerTurn, row, column);
		} while (isSpaceTaken());

		board[row - 1][column - 1] = 'O';
		oMoves++;
		playerTurn--;
		break;
	}
}

//request an acceptable move
void askForMove(int& playerTurn, int& row, int& column) {
	do
	{
		std::cout << "Player " << playerTurn << " select a row from (1-3) and a column from (1-3): ";
		std::cin >> row >> column;
	} while (!(isRowAccepted() && isColumnAccepted()));
}

//verify if the row is within the range of 1-3
bool isRowAccepted() {
	if (row >= 1 && row <= 3) {
		return true;
	}
	else if (row <= 1 || row >= 3) {
		return false;
	}
}

//verify if the column is within the range of 1-3
bool isColumnAccepted() {
	if (column >= 1 && column <= 3) {
		return true;
	}
	else if (column <= 1 || column >= 3) {
		return false;
	}
}

//verify if the space selected is taken
bool isSpaceTaken() {
	if (board[row - 1][column - 1] == 'X')
		return true;
	else if (board[row - 1][column - 1] == 'O')
		return true;
	else
		return false;
}

//verify if there is a winner
bool isThereAWinner()
{
	//check possible horizontal win
	if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X') {
		Player1.isWinner = true;
		return true;
	}
	else if (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O') {
		Player2.isWinner = true;
		return true;
	}

	if (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X') {
		Player1.isWinner = true;
		return true;
	}
	else if (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O') {
		Player2.isWinner = true;
		return true;
	}

	if (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X') {
		Player1.isWinner = true;
		return true;
	}
	else if (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O') {
		Player2.isWinner = true;
		return true;
	}


	//check possible diagonal win
	if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') {
		Player1.isWinner = true;
		return true;
	}
	else if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') {
		Player2.isWinner = true;
		return true;
	}

	if (board[2][0] == 'X' && board[1][1] == 'X' && board[0][2] == 'X') {
		Player1.isWinner = true;
		return true;
	}
	else if (board[2][0] == 'O' && board[1][1] == 'O' && board[0][2] == 'O') {
		Player2.isWinner = true;
		return true;
	}


	//check possible vertical win
	if (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X') {
		Player1.isWinner = true;
		return true;
	}
	else if (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O') {
		Player2.isWinner = true;
		return true;
	}

	if (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X') {
		Player1.isWinner = true;
		return true;
	}
	else if (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O') {
		Player2.isWinner = true;
		return true;
	}

	if (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X') {
		Player1.isWinner = true;
		return true;
	}
	else if (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O') {
		Player2.isWinner = true;
		return true;
	}


	return false;
}

//verify if there is a draw
bool isThereADraw()
{
	if (xMoves + oMoves == 9)
		return true;
	else
		return false;
}

//display the winner
void winnerMessage()
{
	if (Player1.isWinner)
		std::cout << "The winner is the Player 1, AKA: " << Player1.name << std::endl;
	else if (Player2.isWinner)
		std::cout << "The winner is the Player 2, AKA: " << Player2.name << std::endl;
}

//display the draw message
void drawMessage()
{
	std::cout << "\nThe game ended up in a Draw! Well played." << std::endl;
}
