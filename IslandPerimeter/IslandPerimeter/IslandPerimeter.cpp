#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int islandPerimeter(vector<vector<int>>& grid) {
		int perimeter = 0;
		int n = grid.size();
		int m = grid[0].size();

		bool isWater = true;
		for (int i = 0; i < n && isWater; ++i)
		{
			for (int j = 0; j < m && isWater; ++j)
			{
				if (grid[i][j] == 1)
				{
					isWater = false;
					perimeter = DFS(i, j, grid);
				}
			}
		}

		return perimeter;
	}

	int DFS(int i, int j, vector<vector<int>>& grid)
	{
		grid[i][j] = 2;

		int perimeter = 0;
		int dir[4];
		dir[0] = i - 1;
		dir[1] = j - 1;
		dir[2] = i + 1;
		dir[3] = j + 1;

		if (dir[0] < 0 || grid[dir[0]][j] == 0)
		{
			perimeter += 1;
		}
		else if(grid[dir[0]][j] == 1)
		{
			perimeter += DFS(dir[0], j, grid);
		}

		if (dir[1] < 0 || grid[i][dir[1]] == 0)
		{
			perimeter += 1;
		}
		else if (grid[i][dir[1]] == 1)
		{
			perimeter += DFS(i, dir[1], grid);
		}

		if (dir[2] >= grid.size() || grid[dir[2]][j] == 0)
		{
			perimeter += 1;
		}
		else if (grid[dir[2]][j] == 1)
		{
			perimeter += DFS(dir[2], j, grid);
		}

		if (dir[3] >= grid[i].size() || grid[i][dir[3]] == 0)
		{
			perimeter += 1;
		}
		else if (grid[i][dir[3]] == 1)
		{
			perimeter += DFS(i, dir[3], grid);
		}

		return perimeter;
	}
};

void main()
{
	Solution sol;

	vector<vector<int>> grid(4);
	for (int i = 0; i < 4; ++i)
	{
		grid[i] = vector<int>(4);
	}

	grid[0][0] = 0, grid[0][1] = 1, grid[0][2] = 0, grid[0][3] = 0;
	grid[1][0] = 1, grid[1][1] = 1, grid[1][2] = 1, grid[1][3] = 0;
	grid[2][0] = 0, grid[2][1] = 1, grid[2][2] = 0, grid[2][3] = 0;
	grid[3][0] = 1, grid[3][1] = 1, grid[3][2] = 0, grid[3][3] = 0;

	cout << sol.islandPerimeter(grid) << endl;

	system("pause");
}