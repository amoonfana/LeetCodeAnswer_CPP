#include <iostream>

using namespace std;

class Solution {
public:
	bool judgeCircle(string moves) {
		int n = moves.length();
		int x = 0, y = 0;

		for (int i = 0; i < n; ++i) {
			switch (moves[i]) {
			case 'U':
				y += 1;
				break;
			case 'D':
				y -= 1;
				break;
			case 'L':
				x -= 1;
				break;
			case 'R':
				x += 1;
				break;
			default:
				break;
			}
		}

		return (x == 0 && y == 0);
	}
};

void main()
{
	Solution sol;
	string moves = "UD";

	cout << sol.judgeCircle(moves) << endl;

	system("pause");
}