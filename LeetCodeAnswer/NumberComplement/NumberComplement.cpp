#include <iostream>

using namespace std;

class Solution {
public:
	int findComplement(unsigned int num) {
		int m = ~0;
		while (num & m) {
			m <<= 1;
		}

		return ~m ^ num;
	}
};

void main()
{
	Solution sol;

	cout << sol.findComplement(5) << endl;

	system("pause");
}