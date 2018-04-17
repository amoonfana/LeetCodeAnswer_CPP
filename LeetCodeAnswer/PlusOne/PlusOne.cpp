#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int i = 0;
		for (i = digits.size() - 1; i >= 0; --i) {
			digits[i] += 1;

			if (digits[i] > 9) { digits[i] = 0; }
			else { break; }
		}

		if (i < 0) {
			digits.push_back(0);

			for (int i = digits.size() - 2; i >= 0; --i) { digits[i + 1] = digits[i]; }
			digits[0] = 1;
		}

		return digits;
	}
};

void main()
{
	Solution sol;

	vector<int> digits = { 9 };

	vector<int> res = sol.plusOne(digits);

	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << endl;
	}

	system("pause");
}