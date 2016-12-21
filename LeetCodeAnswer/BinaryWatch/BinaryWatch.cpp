#include <iostream>
#include<string>
#include <vector>

using namespace std;

class Solution {
public:
	vector<string> readBinaryWatch(int num) {
		vector<vector<int>> hours
		{ 
			{ 0 },
			{ 1,2,4,8 },
			{ 3,5,9,6,10 },
			{ 7,11 }
		};
		vector<vector<int>> minutes
		{
			{ 0 },
			{ 1,2,4,8,16,32 },
			{ 3,5,9,17,33,6,10,18,34,12,20,36,24,40,48 },
			{ 7,11,19,35,13,21,37,25,41,49,14,22,38,26,42,50,28,44,52,56 },
			{ 15,23,39,27,43,51,29,45,53,57,30,46,54,58 },
			{ 31,47,55,59 }
		};
		vector<string> res;

		int t;
		for (int k = 0; k <= num; ++k)
		{
			t = num - k;
			if (k > 3 || t > 5) continue;
			for (int i = 0; i < hours[k].size(); ++i)
			{
				for (int j = 0; j < minutes[t].size(); ++j)
				{
					string str = minutes[t][j] < 10 ? "0" + to_string(minutes[t][j]) : to_string(minutes[t][j]);
					res.push_back(to_string(hours[k][i]) + ":" + str);
				}
			}
		}

		return res;
	}
};

void main()
{
	Solution sol;

	vector<string> res;

	res = sol.readBinaryWatch(1);

	system("pause");
}