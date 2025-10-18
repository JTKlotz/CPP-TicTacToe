
#include "TicTacToe.h"

#include <iostream>


void TicTacToe::Display() const
{
	std::cout << m_board[0]<<"|" << m_board[1] << "|" << m_board[2] << "\n" << "-----\n"
		<< m_board[3] << "|" << m_board[4] << "|" << m_board[5] << "\n" << "-----\n"
		<< m_board[6] << "|" << m_board[7] << "|" << m_board[8] << "\n";
}

bool TicTacToe::IsGameOver() const
{
	//Work on this
	if(isWinner() || GameCount = 9)
	return false;
}

void TicTacToe::TakeTurn()
{
	int Player = GetPlayer();
	int choice = 0;
	bool isValid = false;

	//determine who's turn it is
	Player == 0 ? Player = 1 : Player = 0;
	
	//get the user's choice
	while (!(isValid))
	{
		std::cout << "Player " << (Player + 1) << ", pick a number between 1-9\n";
		std::cin >> choice;

		isValid = ValidateChoice(choice);
		if (!(isValid))
		{
			std::cout << "Please enter a valid spot\n";
		}
	}

	if (Player == 0)
	{
		SetArray('X', choice);
	}
	else
	{
		SetArray('O', choice);

	}

	SetPlayer(Player);

}

bool isWinner()
{
	
	

	return false;
}
