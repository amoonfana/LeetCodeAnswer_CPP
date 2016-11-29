#include <iostream>

using namespace std;

class Solution {
public:
	int addDigits(int num) {
		return num % 9 ? num % 9 : (num ? 9 : 0);
	}
};

void main()
{
	Solution sol;

	cout << sol.addDigits(38) << endl;

	system("pause");
}