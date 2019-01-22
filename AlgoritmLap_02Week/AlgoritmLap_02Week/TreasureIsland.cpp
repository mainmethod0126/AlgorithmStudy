#include "pch.h"
#include <iostream>

int DFS(int i, int j, int nSum);

#define W 0
#define L 1

static bool arrTreasureIsland_Map[50][50];
static bool arrCheckIndex[50][50];

// За
static int arrDirectionX[] = { 0, 1, 0, - 1 };

// ї­
static int arrDirectionY[] = { 1, 0, -1, 0 };

int x = 0, y = 0;

int MAX = 0;

using namespace std;


int main()
{
	std::cout << "Hello World!\n";

	cin >> x >> y;

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cin >> arrTreasureIsland_Map[i][j];
		}
	}


	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			arrCheckIndex[i][j] = true;
			DFS(i, j, 0);
			arrCheckIndex[i][j] = false;
		}
	}

	cout << MAX << endl;




	for (int i = 0; i < x; i++)
	{
		cout << endl;

		for (int j = 0; j < y; j++)
		{
			cout << arrTreasureIsland_Map[i][j] ;
		}
	}
}

int DFS(int i, int j, int nSum)
{
	if (!arrTreasureIsland_Map[i][j])
	{
		return false;
	}

	nSum++;

	for (int k = 0; k < 4; k++)
	{
		int Dx = i;
		int Dy = j;

		Dx = Dx + arrDirectionX[k];
		Dy = Dy + arrDirectionY[k];

		if (Dx < x && Dy < y)
		{
			if (arrCheckIndex[Dx][Dy] == false)
			{
				arrCheckIndex[Dx][Dy] = true;
				
				int nReturn = DFS(Dx, Dy, nSum);
		
				if (nReturn != false)
				{
					nSum = nReturn;
				}
				arrCheckIndex[Dx][Dy] = false;
			}
		}

		if (i == 3 && j == 0)
		{
			int Dump = 0;
		}
	}
	
	if (MAX <= nSum)
	{
		MAX = nSum;
	}

	nSum = 0;

	return nSum;
}
