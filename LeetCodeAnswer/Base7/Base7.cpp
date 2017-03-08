#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string convertToBase7(int num) {
		string res;

		int x = abs(num);
		do
		{
			res = to_string(x % 7) + res;
		} while (x /= 7);

		return num >= 0 ? res : "-" + res;
	}
};

void main()
{
	Solution sol;

	int num = -7;

	cout << sol.convertToBase7(num).c_str() << endl;

	system("pause");
}