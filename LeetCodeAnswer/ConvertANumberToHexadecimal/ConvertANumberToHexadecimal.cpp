#include <iostream>

using namespace std;

class Solution {
public:
	const char hex[16] = { '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f' };

	string toHex(int num) {
		string res;
		unsigned int n = num;

		while (n) {
			res = hex[n % 16] + res;
			n /= 16;
		}

		return res.empty() ? "0" : res;
	}
};

void main()
{
	Solution sol;

	int num = 26;

	cout << sol.toHex(num).c_str() << endl;

	system("pause");
}