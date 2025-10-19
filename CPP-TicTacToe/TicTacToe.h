#pragma once

#include "Game.h"

class TicTacToe : public Game
{
private:
	char m_board[9] = { '1','2','3','4','5','6','7','8','9'};
	int Player = 1;
	int GameCount = 0;
public:
	TicTacToe() {};
	~TicTacToe() {};

	// mutator methods 
	void SetArray(const char v, const int choice)
	{
		m_board[(choice - 1)] = v;
	}
	void SetPlayer(const int i)
	{
		Player = i;
	}

	void SetGameCount(const int i)
	{
		GameCount = i;
	}
	//Accessor methods
	int GetPlayer()const {
		return Player;
	}
	
	int GetGameCount()const {
		return GameCount;
	}


	//other methods
	bool IsGameOver() const;
	void TakeTurn();
	void Display() const;
	bool ValidateChoice(int i)const;
	bool CheckWinner(int Player)const;
};