#include <bits/stdc++.h>

using namespace std;

void populate(int i, int j, vector<vector<int>> &board)
{
	board[i][j]++; // posicion de reina
	for (int x = 1; x < board.size(); ++x)
	{
		if (j != x)
			board[i][x]++; // horizontal
		if (i != x)
			board[x][j]++; // vectical
		if (i + x < board.size() && j + x < board.size())
			board[i + x][j + x]++; // diagonal ne
		if (i + x < board.size() && j - x >= 0)
			board[i + x][j - x]++; // diagonal se
		if (i - x >= 0 && j + x < board.size())
			board[i - x][j + x]++; // diagonal nw
		if (i - x >= 0 && j - x >= 0)
			board[i - x][j - x]++; // diagonal sw
	}
}

void sanitize(int i, int j, vector<vector<int>> &board)
{
	board[i][j]--;
	for (int x = 1; x < board.size(); ++x)
	{
		if (j != x)
			board[i][x]--;
		if (i != x)
			board[x][j]--;
		if (i + x < board.size() && j + x < board.size())
			board[i + x][j + x]--;
		if (i + x < board.size() && j - x >= 0)
			board[i + x][j - x]--;
		if (i - x >= 0 && j + x < board.size())
			board[i - x][j + x]--;
		if (i - x >= 0 && j - x >= 0)
			board[i - x][j - x]--;
	}
}

int traverse(vector<vector<int>> &board, int queens, int r)
{
	if (!queens)
		return 1;
	int total = 0;
	for (int i = r; i < board.size(); ++i)
	{
		for (int j = 0; j < board.size(); ++j)
		{
			if (!board[i][j])
			{
				populate(i, j, board);
				total += traverse(board, queens - 1, i + 1);
				sanitize(i, j, board);
			}
		}
	}
	return total;
}

int nQueens(int n)
{
	vector<vector<int>> board(n, vector<int>(n, 0)); // tablero de zeros
	return traverse(board, n, 0);
}

int main()
{
	int n;
	cin >> n;
	cout << nQueens(n) << endl;
}