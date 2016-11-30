#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<string> fizzBuzz(int n) {
		vector<string> res = vector<string>(n);
		int fizz = 3;
		int buzz = 5;

		for (int i = 1, j = 0; i <= n; ++i, ++j)
		{
			if (i == fizz && i == buzz)
			{
				res[j] = "FizzBuzz";
				fizz += 3;
				buzz += 5;
			}
			else if (i == fizz)
			{
				res[j] = "Fizz";
				fizz += 3;
			}
			else if (i == buzz)
			{
				res[j] = "Buzz";
				buzz += 5;
			}
			else
			{
				res[j] = to_string(i);
			}
		}

		return res;
	}
};

void main()
{
	Solution sol;
	vector<string> res = sol.fizzBuzz(15);

	for (int i = 0; i < res.size(); ++i)
	{
		cout << res[i] << endl;
	}

	system("pause");
}