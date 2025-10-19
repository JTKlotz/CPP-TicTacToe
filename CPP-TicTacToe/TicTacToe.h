#pragma once

#include "Game.h"

class TicTacToe : public Game
{
private:
	char m_board[9] = { '1','2','3','4','5','6','7','8','9'};
	int Player = 1;
	int GameCount = 1;
public:
	TicTacToe() {};
	~TicTacToe() {};

	// Methods to be implemented by derived class
	void SetArray(const char v, const int choice)
	{
		m_board[(choice - 1)] = v;
	}
	void SetPlayer(const int i)
	{
		Player = i;
	}
	int GetPlayer()const {
		return Player;
	}
	void SetGameCount(const int i)
	{
		GameCount = i;
	}
	int GetGameCount()const {
		return GameCount;
	}

	bool IsGameOver() const;
	void TakeTurn();
	void Display() const;
	bool ValidateChoice(const int i)
	{
		//validate that choice is in the correct range
		if((i < 1) && (i > 9))
		{
			return false;
		}
		//validate that the choice is not already taken
		if (!(m_board[(i-1)] == 'X') && !(m_board[(i-1)] == 'O'))
		{
			
			return true;
		}

		return false;
	}
	bool CheckWinner(int Player);
};