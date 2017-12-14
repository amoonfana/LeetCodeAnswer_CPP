#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool isOneBitCharacter(vector<int>& bits) {
		int i = 0;

		int e = bits.size() - 1;
		while (i < e) {
			i += bits[i] + 1;
		}

		return (i == e);
	}
};

void main()
{
	Solution sol;

	vector<int> bits = {1, 1, 1, 0};

	cout << sol.isOneBitCharacter(bits) << endl;

	system("pause");
}