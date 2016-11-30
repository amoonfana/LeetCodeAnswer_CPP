#include <iostream>

using namespace std;

class Solution {
public:
	int getSum(int a, int b) {
		return b == 0 ? a : getSum(a^b, (a&b) << 1);
	}
};

void main()
{
	Solution sol;

	cout << sol.getSum(3, 5) << endl;

	system("pause");
}