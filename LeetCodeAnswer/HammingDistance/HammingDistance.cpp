#include <iostream>

using namespace std;

class Solution {
public:
	int hammingDistance(int x, int y) {
		////1st solution
		//int xo = x ^ y;
		//int res = 0;

		//while (xo != 0)
		//{
		//	xo &= (xo -1);
		//	res += 1;
		//}

		//return res;

		////2nd solution
		//int n = x ^ y;
		//int tmp = n - ((n >> 1) & 033333333333) - ((n >> 2) & 011111111111);
		//return ((tmp + (tmp >> 3)) & 030707070707) % 63;

		//3rd solution
		int z = (x ^ y);
		int m1 = 0x55555555;
		int m2 = 0x33333333;
		int m3 = 0x0f0f0f0f;

		z = (z & m1) + ((z >> 1) & m1);
		z = (z & m2) + ((z >> 2) & m2);
		z = (z & m3) + ((z >> 4) & m3);
		z += (z >> 8);
		z += (z >> 16);

		return z & 0x3f;
	}
};

void main()
{
	Solution sol;

	cout << sol.hammingDistance(4, 1) << endl;

	system("pause");
}