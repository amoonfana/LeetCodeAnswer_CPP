#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
	int numberOfBoomerangs(vector<pair<int, int>>& points) {
		int n = points.size();
		int res = 0;

		for (int i = 0; i < n; ++i)
		{
			unordered_map<int, int> um(n);

			for (int j = 0; j < n; ++j)
			{
				if (j == i)
				{
					continue;
				}

				int d = dist(points[i].first, points[i].second, points[j].first, points[j].second);

				++um[d];
			}

			for (unordered_map<int, int>::iterator itr = um.begin(); itr != um.end(); ++itr)
			{
				if (itr->second > 1)
				{
					res += itr->second*(itr->second - 1);
				}
			}
		}

		return res;
	}

	int dist(int x1, int y1, int x2, int y2)
	{
		int dx = x1 - x2;
		int dy = y1 - y2;

		return dx*dx + dy*dy;
	}
};

void main()
{
	Solution sol;

	vector<pair<int, int>> points(3);

	points[0] = pair<int, int>(0, 0);
	points[1] = pair<int, int>(1, 0);
	points[2] = pair<int, int>(2, 0);

	cout << sol.numberOfBoomerangs(points) << endl;

	system("pause");
}