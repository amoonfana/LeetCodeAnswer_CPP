#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
		int ht[100001];
		vector<int> res(A.size());

		for (int i = 0; i < B.size(); ++i) { ht[B[i]] = i; }

		for (int i = 0; i < A.size(); ++i) { res[i] = ht[A[i]]; }

		return res;
	}
};

void main()
{
	Solution sol;

	vector<int> A = { 12, 28, 46, 32, 50 };
	vector<int> B = { 50, 12, 32, 46, 28 };

	vector<int> res = sol.anagramMappings(A, B);

	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << endl;
	}

	system("pause");
}