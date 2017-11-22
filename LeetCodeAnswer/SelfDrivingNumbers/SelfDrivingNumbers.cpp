#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> selfDividingNumbers(int left, int right) {
		vector<int> res;

		bool flag;
		for (int i = left; i <= right; ++i) {
			flag = true;

			for (int j = i, k = i % 10; j > 0; j /= 10, k = j % 10) {
				if (k == 0 || i%k != 0) {
					flag = false;
					break;
				}
			}

			if (flag) { res.push_back(i); }
		}

		return res;
	}
};

void main()
{
	Solution sol;

	vector<int> res;
	res = sol.selfDividingNumbers(1, 22);

	for (int i = 0; i < res.size(); ++i)
	{
		cout << res[i] << endl;
	}

	system("pause");
}