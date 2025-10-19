
#include "TicTacToe.h"

#include <iostream>
#include <string>



void TicTacToe::Display() const
{
	std::cout << m_board[0]<<"|" << m_board[1] << "|" << m_board[2] << "\n" << "-----\n"
		<< m_board[3] << "|" << m_board[4] << "|" << m_board[5] << "\n" << "-----\n"
		<< m_board[6] << "|" << m_board[7] << "|" << m_board[8] << "\n";
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

bool TicTacToe::CheckWinner(int player)
{
	char winner;
	player == 0 ? winner = 'X' : winner = 'O';

	//check row 1
	if (m_board[0] == m_board[1] && m_board[1] == m_board[2]&& m_board[0]==winner)
	{
		std::cout << "Player " << (player + 1) << " wins";
		return true;
	}
	//check row 2
	else if (m_board[3] == m_board[4] && m_board[4] == m_board[5] && m_board[3] == winner)
	{
		std::cout << "Player " << (player + 1) << " wins";
		return true;
	}
	//check row 3
	else if (m_board[6] == m_board[7] && m_board[7] == m_board[8] && m_board[6] == winner)
	{
		std::cout << "Player " << (player + 1) << " wins";
		return true;
	}
	//check column 1
	else if (m_board[0] == m_board[3] && m_board[3] == m_board[6] && m_board[0] == winner)
	{
		std::cout << "Player " << (player + 1) << " wins";
		return true;
	}
	//check column 2
	else if (m_board[1] == m_board[4] && m_board[4] == m_board[7] && m_board[1] == winner)
	{
		std::cout << "Player " << (player + 1) << " wins";
		return true;
	}
	//check column 3
	else if (m_board[2] == m_board[5] && m_board[5] == m_board[8] && m_board[2] == winner)
	{
		std::cout << "Player " << (player + 1) << " wins";
		return true;
	}
	//check diagonal 1
	else if (m_board[0] == m_board[4] && m_board[4] == m_board[8] && m_board[0] == winner)
	{
		std::cout << "Player " << (player + 1) << " wins";
		return true;
	}
	//check diagonal 2
	else if (m_board[2] == m_board[4] && m_board[4] == m_board[6] && m_board[0] == winner)
	{
		std::cout << "Player " << (player + 1) << " wins";
		return true;
	}
	// no winner
	return false;
}


bool TicTacToe::IsGameOver() const
{
	int player = GetPlayer();
	bool gameOver = CheckWinner(player);
	//Work on this
	if (gameOver || GameCount = 9)
	{
		return true;
	}
	return false;
}