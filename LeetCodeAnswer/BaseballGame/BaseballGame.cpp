#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int calPoints(vector<string>& ops) {
		int n = ops.size();
		vector<int> s(n);
		int sum = 0, e = -1;

		int t;
		for (int i = 0; i < n; ++i) {
			if (ops[i].compare("+") == 0) {
				t = s[e] + s[e - 1];
				sum += t;
				s[++e] = t;
			}
			else if (ops[i].compare("D") == 0) {
				t = s[e] + s[e];
				sum += t;
				s[++e] = t;
			}
			else if (ops[i].compare("C") == 0) {
				sum -= s[e--];
			}
			else {
				t = atoi(ops[i].c_str());
				sum += t;
				s[++e] = t;
			}
		}

		return sum;
	}
};

void main()
{
	Solution sol;

	vector<string> ops;
	ops.push_back("5");
	ops.push_back("-2");
	ops.push_back("4");
	ops.push_back("C");
	ops.push_back("D");
	ops.push_back("9");
	ops.push_back("+");
	ops.push_back("+");

	cout << sol.calPoints(ops) << endl;

	system("pause");
}