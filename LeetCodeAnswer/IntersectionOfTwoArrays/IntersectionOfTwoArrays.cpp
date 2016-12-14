#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		unordered_set<int> m(nums1.begin(), nums1.end());
		vector<int> res;

		int n = nums2.size();
		for (int i = 0; i < n ; ++i)
		{
			if (m.count(nums2[i]))
			{
				res.push_back(nums2[i]);
				m.erase(nums2[i]);
			}
		}

		return res;
	}
};

void main()
{
	Solution sol;

	vector<int> g(4), s(2), res;

	g[0] = 1;
	g[1] = 2;
	g[2] = 2;
	g[3] = 1;

	s[0] = 2;
	s[1] = 2;

	res = sol.intersection(g, s);

	system("pause");
}