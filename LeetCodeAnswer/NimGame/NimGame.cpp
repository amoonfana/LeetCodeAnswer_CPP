#include <iostream>

using namespace std;

class Solution {
public:
	bool canWinNim(int n) {
		return n & 3;
	}
};

void main()
{
	Solution sol;

	cout << sol.canWinNim(4) << endl;

	system("pause");
}