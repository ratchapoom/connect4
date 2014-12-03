#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
void init(int grid[6][7]){
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			grid[i][j] = 0;
		}
	}
}

void display(int grid[6][7])
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (grid[i][j] == 0)
			{
				cout << " ";
			}
			else if (grid[i][j] == 1)
			{
				cout << "X";
			}
			else
			{
				cout << "O";
			}
			if (j < 6)
			{
				cout << " | ";
			}
		}
		cout << endl;
		if (i < 6)
		{
			cout << "--+---+---+---+---+---+--" << endl;
		}
	}
}
void update(int grid[6][7], int player,int pick)
{
	for (int i = 6; i >= 0; i--)
	{
		if (grid[i][pick - 1] == 0)
		{
			grid[i][pick - 1] = player;
			break;
		}
	}
}

void checkbot(int grid[6][7], int player)
{
	int x;
	bool check = false;
	cout << grid[0][4] << endl;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			//แนวตั้ง
			if (grid[i][j] == 1 && grid[i + 1][j] == 1 && grid[i ][j+1] == 0 && grid[i][j] != 0)
			{
				//cout << grid[i + 2][j] << endl;
				x = j + 1;
				cout << "****" << x << endl;
				update(grid,player,x);
				check = true;
				break;
			}
			//แนวนอน
			if (grid[i][j] == 1 && grid[i][j + 1] == 1  && grid[i][j + 2] == 0 && grid[i][j] != 0)
			{
				x = j + 3;
				cout << "-----" << x << endl;
				update(grid, player, x);
				check = true;
				break;
			}
		}
	}
	for (int i = 6; i >= 0; i--)
	{
		for (int j = 0; j <= 6; j++)
		{
			//แนวเฉียง
			if (grid[i][j] == 1 && grid[i - 1][j + 1] == 1 && grid[i - 2][j + 2] == 1 && grid[i-3][j + 3] == 0 && grid[i][j] != 0)
			{
				x = j + 4;
				cout << "[[[[" << x << endl;
				update(grid,player,x);
				check = true;
				break;
			}
			
			if (grid[i][j] == 1 && grid[i - 1][j - 1] == 1 && grid[i - 2][j - 2] == 1 && grid[i - 3][j - 3] == 0 && grid[i][j] != 0)
			{
				x = j -4;
				cout << "/////" << x << endl;
				update(grid,player,x);
				check = true;
				break;
			}
			
		}
	}
	if (check == false)
	{
		x = rand() % 7 + 1;
		cout << "rand" << x << endl;
		update(grid, player, x);
	}
}


void turn(int grid[6][7], int player)
{
	int pick;
	srand(time(NULL));
	if (player == 1)
	{
		cout << " Player : Please pick a square (1-7) " << endl;
		cin >> pick;
		while (pick > 7 || pick < 1  ) {
			cout << "sry,it out of range." << endl;
			cout << "Again : ";
			cin >> pick;
		}
		update(grid, player, pick);
		cout << endl;
	}
	else if (player == 2)
	{
		cout << "Computer Turn's  ";
		
		//cout << "Computer pick : " << pick << endl;
		checkbot(grid,player);
		cout << endl;
	}



	
}


int checkwin(int grid[6][7])
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (grid[i][j] == 1 && grid[i + 1][j] == 1 && grid[i + 2][j] == 1 && grid[i + 3][j] == 1)
			{
				return 1;
			}
			if (grid[i][j] == 2 && grid[i + 1][j] == 2 && grid[i + 2][j] == 2 && grid[i + 3][j] == 2)
			{
				return 1;
			}
			if (grid[i][j] == 1 && grid[i][j + 1] == 1 && grid[i][j + 2] == 1 && grid[i][j + 3] == 1)
			{
				return 1;
			}
			if (grid[i][j] == 2 && grid[i][j + 1] == 2 && grid[i][j + 2] == 2 && grid[i][j + 3] == 2)
			{
				return 1;
			}
		}
	}
	for (int i = 6; i >= 0; i--)
	{
		for (int j = 0; j <= 6; j++)
		{
			if (grid[i][j] == 1 && grid[i - 1][j + 1] == 1 && grid[i - 2][j + 2] == 1 && grid[i - 3][j + 3] == 1)
			{
				return 1;
			}
			if (grid[i][j] == 2 && grid[i - 1][j + 1] == 2 && grid[i - 2][j + 2] == 2 && grid[i - 3][j + 3] == 2)
			{
				return 1;
			}
			if (grid[i][j] == 1 && grid[i - 1][j - 1] == 1 && grid[i - 2][j - 2] == 1 && grid[i - 3][j - 3] == 1)
			{
				return 1;
			}
			if (grid[i][j] == 2 && grid[i - 1][j - 1] == 2 && grid[i - 2][j - 2] == 1 && grid[i - 3][j - 3] == 2)
			{
				return 1;
			}
		}
	}

}

int main() {
	int grid[6][7];
	init(grid);
	int player = 1;
	while (checkwin(grid) != 1)
	{
		display(grid);
		turn(grid, player);
		if (player == 1)
		{
			player = 2;
		}

		else
		{
			player = 1;
		}
		if (checkwin(grid) == 1)
		{
			if (player == 1)
			{
				display(grid);
				cout << "Computer Win" << endl;
			}
			else
			{
				display(grid);
				cout << "Player Win" << endl;
			}
		}
	}

}
