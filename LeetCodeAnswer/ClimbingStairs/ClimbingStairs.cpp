#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	//Fibonacci Formula
	int climbStairs(int n) {
		double sqrt5 = sqrt(5);
		double fibn = pow((1 + sqrt5) / 2, n + 1) - pow((1 - sqrt5) / 2, n + 1);
		return (int)(fibn / sqrt5);
	}

	////Fibonacci Number
	//int climbStairs(int n) {
	//	bool flg = true;
	//	int a = 1, b = 0;

	//	for (int i = 1; i <= n; ++i) {
	//		if (flg) {
	//			b += a;
	//			flg = false;
	//		}
	//		else {
	//			a += b;
	//			flg = true;
	//		}
	//	}

	//	return flg ? a : b;
	//}
};

void main()
{
	Solution sol;

	int n = 5;

	cout << sol.climbStairs(n) << endl;

	system("pause");
}