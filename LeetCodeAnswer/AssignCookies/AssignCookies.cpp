#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
		int c = 0;
		int gs = g.size();
		int ss = s.size();

		sort(g.begin(), g.end());
		sort(s.begin(), s.end());

		for (int i = 0, j = 0;i < gs && j < ss;)
		{
			if (g[i] <= s[j])
			{
				c += 1;
				i += 1;
			}

			j += 1;
		}

		return c;
	}
};

void main()
{
	Solution sol;

	vector<int> g(3), s(3);

	g[0] = 1;
	g[1] = 3;
	g[2] = 2;

	s[0] = 1;
	s[1] = 1;
	s[2] = 2;

	cout << sol.findContentChildren(g, s) << endl;

	system("pause");
}