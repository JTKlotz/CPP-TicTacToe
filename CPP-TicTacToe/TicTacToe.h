#pragma once

#include "Game.h"

class TicTacToe : public Game
{
public:
	TicTacToe() {};
	~TicTacToe() {};

	// Methods to be implemented by derived class
	bool IsGameOver() const;
	void TakeTurn();
	void Display() const;
};