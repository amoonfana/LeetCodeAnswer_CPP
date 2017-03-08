#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> constructRectangle(int area) {
		for (int i = sqrt(area); i > 0; --i)
		{
			if (area % i == 0)
			{
				return vector<int> {area / i, i};
			}
		}
	}
};

void main()
{
	Solution sol;

	vector<int> res;
	res = sol.constructRectangle(21);

	for (int i = 0; i < res.size(); ++i)
	{
		cout << res[i] << endl;
	}

	system("pause");
}