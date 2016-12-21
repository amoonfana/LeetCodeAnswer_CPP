#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size();
		int m = nums2.size();
		unordered_map<int, int> um(n);
		vector<int> res;

		for (int i = 0; i < n; ++i)
		{
			um[nums1[i]] += 1;
		}

		for (int i = 0; i < m; ++i)
		{
			if(um.find(nums2[i]) != um.end() && um[nums2[i]] > 0)
			{
				res.push_back(nums2[i]);
				um[nums2[i]] -= 1;
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

	res = sol.intersect(g, s);

	system("pause");
}