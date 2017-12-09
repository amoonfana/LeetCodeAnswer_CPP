#include <iostream>

using namespace std;

class Solution {
public:
	bool hasAlternatingBits(int n) {
		int c = n % 2;
		n /= 2;

		while (n) {
			if (c == n % 2) { return false; }
			c = n % 2;
			n /= 2;
		}

		return true;
	}
};

void main()
{
	Solution sol;

	cout << sol.hasAlternatingBits(4) << endl;

	system("pause");
}