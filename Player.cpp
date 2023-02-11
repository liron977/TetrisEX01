#include "Player.h"
#pragma warning(disable : 4996)

int Player::getDirection(char key) {
	for (int i = 0; i < ARROW_KEYS_SIZE; i++)
	{
		if (key == arrowKeys[i])
			return i;
	}
	return -1;//The key is not the key of the current player.
}
void Player::setArrowKeys(const char* keys) {

	for (int i = 0; i < ARROW_KEYS_SIZE; i++)
	{
		arrowKeys[i] = keys[i];
	}
}
void Player::printWinner() {
	system("cls");
	gotoxy(22, 10);
	cout << "The winner is " << playerName << " With " << playerScore << " points " << "!!";
	gotoxy(0, 0);
	cout << "(ESC)-Back to menu";
}
void Player::printPlayerScore()
{
	if (playerCode == PLAYER_1_KOD) {
		gotoxy(5, 22);
	}
	else {
		gotoxy(18, 22);
	}
	cout << playerScore;
}
void Player::printPlayerName() {
	if (playerCode == PLAYER_1_KOD) {
		gotoxy(3, 21);
	}
	else {
		gotoxy(16, 21);
	}
	cout << playerName;
}

void Player::setPlayerName()
{
	if (playerCode == PLAYER_1_KOD) {
		strcpy(playerName, "PLAYER A");
	}
	else {
		strcpy(playerName, "PLAYER B");
	}
}
void Player::setPlayerCode(int _code)
{
	playerCode = _code;
}
void Player::setPlayerScore(int _score)
{
	playerScore = _score;
}
int Player::getPlayerScore()
{
	return playerScore;
}
void Player::printTie()
{
	system("cls");
	gotoxy(15, 10);
	cout << "Unfortunately, we don't have winner... only losers :(";
	gotoxy(0, 0);
	cout << "(ESC)-Back to menu";
}