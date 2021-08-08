#include <bits/stdc++.h>
using namespace std;

void clean_column(vector<int> &column)
{
	for (int i = 0; i < column.size(); ++i)
	{
		if (column[i]) // if 2 change to 1, if 1 change to 0
			column[i]--;
	}
}

void backtrack(vector<vector<int>> &columns, vector<char> &stack, int column, int &kth_password)
{
	if (column == 5 && kth_password)
	{
		kth_password--;
		if (!kth_password)
		{
			string password(stack.begin(), stack.end());
			cout << password << endl;
		}
		return;
	}
	for (int i = 0; i < columns[column].size() && kth_password > 0; ++i)
	{
		if (columns[column][i])
		{
			stack.push_back('A' + i);
			backtrack(columns, stack, column + 1, kth_password);
			stack.pop_back();
		}
	}
}

int main()
{
	int num_tests;
	cin >> num_tests;
	while (num_tests--)
	{
		int kth_password;
		cin >> kth_password;
		vector<vector<int>> columns(5, vector<int>(26, false));

		for (int i = 0; i < 6; ++i)
		{
			string row;
			cin >> row;
			for (int j = 0; j < row.length(); ++j)
			{
				int index = int(row[j]) - 65;
				columns[j][index] = 1;
			}
		}
		for (int i = 0; i < 6; ++i)
		{
			string row;
			cin >> row;
			for (int j = 0; j < row.length(); ++j)
			{
				int index = int(row[j]) - 65;
				if (columns[j][index])
					columns[j][index]++;
			}
		}

		for (auto &column : columns)
			clean_column(column);
		vector<char> stack;
		backtrack(columns, stack, 0, kth_password);
		if (kth_password > 0)
			cout << "NO" << endl;
	}
}