#pragma once

#include "Game.h"

class TicTacToe : public Game
{
private:
	char m_board[9] = { '1','2','3','4','5','6','7','8','9'};
	int m_player = 2;
	int m_gameCount = 0;
public:
	TicTacToe() {};
	~TicTacToe() {};

	// mutator methods 
	void SetArray(const char playerMarker, const int choice)
	{
		m_board[(choice - 1)] = playerMarker;
	}
	void SetPlayer(const int player)
	{
		m_player = player;
	}

	void SetGameCount(const int i)
	{
		m_gameCount = i;
	}
	//Accessor methods
	int GetPlayer()const 
	{
		return m_player;
	}
	
	int GetGameCount()const 
	{
		return m_gameCount;
	}


	//other methods
	bool IsGameOver() const;
	void TakeTurn();
	void Display() const;
	bool ValidateChoice(int i) const;
	bool CheckWinner() const;
};