/*CSCI 241       Assignment 2   Spring 2021
Programmer: Christopher Huguelet
Section: 2
Date Due: 1/28/2021
Purpose: this program is created in order to replicate the concept of the 8 queens problem.

We namely use the board object to interfact with the boolean values, checking using a ton of boolean if statements.
Nothing exactly odd about this one, it was fairly run of the mill once I understood the concept of the created objects.
*/

#include <iostream>

using std::cout;
using std::endl;

class queen_solver //defined for the board object here
{
	bool board[8][8] = {{false}};
	
public:
    queen_solver() = default;
    bool place_queens(int);
    bool is_safe (int,int) const;
    void print_solution() const;
};

int main()
{
	queen_solver q;
	q.place_queens(0);
	q.print_solution();
	return 0;
}

bool queen_solver::place_queens(int row) //places queen down on the row
{
	if(row >= 8)
	{
		return true;
	}
    for(int c = 0; c <= 7; c++)
    {
		board[row][c] = true; 
		if (is_safe(row,c))
		{ 
			if (place_queens(row+1))
			{
				return true; //the final loop, should only run when everything works.
			}
			else
				{
				board[row][c] = false;
				} 
		}	
		else
				{
				board[row][c] = false;
				}
	}
	board[row][7] = false;
	return false;
}

bool queen_solver::is_safe(int row, int col) const
{
	//checks vertical for queens (boolean value = true), checking upwards.
	for (int r = row-1; r >= 0; r--)
    {
	    if (board[r][col]) 
	        return false;
    }
    
    //checks left upper diagonal for queens (boolean value = true), checking upwards.
	for (int r = row - 1, c = col - 1; r >= 0 && c >= 0; r--, c--)
    {
	    if (board[r][c])
	        return false;
    }
    
    //checks right upper diagonal for queens (boolean value = true), checking upwards.
	for (int r = row - 1, c = col + 1; r >= 0 && c <= 7; r--, c++)
    {
	    if (board[r][c])
	        return false;
    }
    
    return true;
}

void queen_solver::print_solution() const //outputs and prints out the array for the problem
{
	for(int row = 0; row < 8; row++)
	{
		for(int col = 0; col < 8; col++)
		{
		if(board[row][col]) cout << "1 ";
			else cout << "0 ";
		}
	cout << endl;
	}
}
