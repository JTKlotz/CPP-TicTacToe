
#include "TicTacToe.h"

#include <iostream>
#include <string>



void TicTacToe::Display() const
{
	//display board
	std::cout << m_board[0]<<"|" << m_board[1] << "|" << m_board[2] << "\n" << "-----\n"
		<< m_board[3] << "|" << m_board[4] << "|" << m_board[5] << "\n" << "-----\n"
		<< m_board[6] << "|" << m_board[7] << "|" << m_board[8] << "\n";
}
bool TicTacToe::ValidateChoice(int i) const
{
	//validate that choice is in the correct range
	if ((i < 1) || (i > 9))
	{
		return false;
	}
	else
	{
		//validate that the choice is not already taken
		if (m_board[(i - 1)] == 'X' || m_board[(i - 1)] == 'O')
		{
			std::cout << "Spot already taken, pick again.\n";
			return false;
		}
		else
		{
			return true;
		}
	}
}


void TicTacToe::TakeTurn()
{
	//determine player's turn
	int player = GetPlayer();
	
	// variables
	int choice;
	bool isValid = false;

	//change turns 
	player == 1 ? player = 2 : player = 1;
	
	//get the user's choice
	while (!(isValid))
	{
		//ask for users input
		std::cout << "Player " << (player) << ", pick a number between 1-9: ";
		std::cin >> choice;

		//validate the entered data
		isValid = ValidateChoice(choice);
	}

	//enter a "X" or "O" depending on which player's turn it is
	if (player == 1)
	{
		SetArray('X', choice);
	}
	else
	{
		SetArray('O', choice);

	}

	
	//set the player field to the current player
	SetPlayer(player);
	//increment gamecountfield to track the amount of games
	SetGameCount(m_gameCount + 1);
	//clear the console so that the boards to continously stack
	system("cls");
}

bool TicTacToe::CheckWinner()const
{
	//variable used to assess possible win, will hold players sign (X or O)
	char winner;
	//assign X to winner if player 1's turn and O to winner if player 2's turn
	m_player == 1 ? winner = 'X' : winner = 'O';

	//check row 1 for win
	if (m_board[0] == m_board[1] && m_board[1] == m_board[2]&& m_board[0]==winner)
	{
		std::cout << "Player " << (m_player) << " wins\n";
		return true;
	}
	//check row 2 for win
	else if (m_board[3] == m_board[4] && m_board[4] == m_board[5] && m_board[3] == winner)
	{
		std::cout << "Player " << (m_player) << " wins\n";
		return true;
	}
	//check row 3 for win
	else if (m_board[6] == m_board[7] && m_board[7] == m_board[8] && m_board[6] == winner)
	{
		std::cout << "Player " << (m_player) << " wins\n";
		return true;
	}
	//check column 1 for win
	else if (m_board[0] == m_board[3] && m_board[3] == m_board[6] && m_board[0] == winner)
	{
		std::cout << "Player " << (m_player) << " wins\n";
		return true;
	}
	//check column 2 for win
	else if (m_board[1] == m_board[4] && m_board[4] == m_board[7] && m_board[1] == winner)
	{
		std::cout << "Player " << (m_player) << " wins\n";
		return true;
	}
	//check column 3 for win
	else if (m_board[2] == m_board[5] && m_board[5] == m_board[8] && m_board[2] == winner)
	{
		std::cout << "Player " << (m_player) << " wins\n";
		return true;
	}
	//check diagonal 1 for win
	else if (m_board[0] == m_board[4] && m_board[4] == m_board[8] && m_board[0] == winner)
	{
		std::cout << "Player " << (m_player) << " wins\n";
		return true;
	}
	//check diagonal 2 for win
	else if (m_board[2] == m_board[4] && m_board[4] == m_board[6] && m_board[0] == winner)
	{
		std::cout << "Player " << (m_player) << " wins\n";
		return true;
	}
	// no winner
	return false;
}


bool TicTacToe::IsGameOver() const
{

	//assing status of the game to isWinner (true = game was won and false = game is not over yet)
	//check if there is a winning combination
	bool isWinner = CheckWinner();
	//if there is a winner or a tie
	if (isWinner || m_gameCount == 9)
	{
		if (!isWinner && m_gameCount == 9)
		{
			//if there is a tie, display message then return true
			std::cout << "Game ends in a tie!\n";
		}
		//if there is a winner, return true
		return true;
	}
	//if no winner or not yet at game 9, return false
	return false;
}