#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		int n = grid.size(), m = grid[0].size();
		stack<pair<int,int>> s;
		int sum, res = 0;

		pair<int, int>* p;
		int	d, u, l, r;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (grid[i][j] == 1) {
					sum = 1;
					grid[i][j] = 2;
					s.push(make_pair(i, j));

					while (!s.empty()) {
						p = &s.top();
						s.pop();

						i = p->first;
						j = p->second;
						d = i - 1;
						u = i + 1;
						l = j - 1;
						r = j + 1;
						
						if (d > -1 && grid[d][j] == 1) {
							sum += 1;
							grid[d][j] = 2;
							s.push(make_pair(d, j));
						}
						if (u < n && grid[u][j] == 1) {
							sum += 1;
							grid[u][j] = 2;
							s.push(make_pair(u, j));
						}
						if (l > -1 && grid[i][l] == 1) {
							sum += 1;
							grid[i][l] = 2;
							s.push(make_pair(i, l));
						}
						if (r < m && grid[i][r] == 1) {
							sum += 1;
							grid[i][r] = 2;
							s.push(make_pair(i, r));
						}
					}

					if (sum > res) { res = sum; }
				}
			}
		}

		return res;
	}
};

void main()
{
	Solution sol;

	vector<vector<int>> grid = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
								{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
								{0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
								{0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
								{0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
								{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
								{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
								{0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};

	cout << sol.maxAreaOfIsland(grid) << endl;

	system("pause");
}