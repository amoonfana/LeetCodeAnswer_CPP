#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& A) {
		for (int i = 0, j = A.size() - 1; i < j; ++i, --j) {
			while (i < j && A[i] % 2 == 0) { ++i; }
			while (i < j && A[j] % 2 != 0) { --j; }
			swap(A[i], A[j]);
		}

		return A;
	}
};

void main()
{
	Solution sol;

	vector<int> A = { 3, 1, 2, 4 };
	vector<int> res = sol.sortArrayByParity(A);

	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << endl;
	}

	system("pause");
}