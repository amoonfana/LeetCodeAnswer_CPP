#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		int oldColor = image[sr][sc];

		if (oldColor != newColor) {
			int n = image.size(), m = image[0].size();
			queue<pair<int, int>> s;

			int i, j, d, u, l, r;
			pair<int, int> c;
			for (s.push(make_pair(sr, sc)); !s.empty(); s.pop()) {
				c = s.front();
				i = c.first;
				j = c.second;
				d = i - 1;
				u = i + 1;
				l = j - 1;
				r = j + 1;

				image[i][j] = newColor;
				if (d >= 0 && image[d][j] == oldColor) { s.push(make_pair(d, j)); }
				if (u < n && image[u][j] == oldColor) { s.push(make_pair(u, j)); }
				if (l >= 0 && image[i][l] == oldColor) { s.push(make_pair(i, l)); }
				if (r < m && image[i][r] == oldColor) { s.push(make_pair(i, r)); }
			}
		}

		return image;
	}
};

void main()
{
	Solution sol;
	vector<vector<int>> image = {{0, 0, 0},
								 {0, 1, 1}};

	sol.floodFill(image, 1, 1, 2);

	int n = image.size(), m = image[0].size();
	for (int i = 0; i < n; ++i) {
		cout << "[";
		for (int j = 0; j < m; ++j) {
			cout << " " << image[i][j] << " ";
		}
		cout << "]" << endl;
	}

	system("pause");
}