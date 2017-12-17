#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
		unordered_map<string, int> um;
		int idsm = INT_MAX;

		for (int i = 0; i < list1.size(); ++i) {
			um[list1[i]] = (i + 1);
		}

		vector<pair<string, int>> vt;
		for (int i = 0; i < list2.size(); ++i) {
			int& t = um[list2[i]];
			
			if (t > 0) {
				t += (i - 1);

				if (t <= idsm) {
					idsm = t;
					vt.push_back(make_pair(list2[i], t));
				}
			}
		}

		vector<string> res;
		for (int i = 0; i < vt.size(); ++i) {
			if (vt[i].second == idsm) { res.push_back(vt[i].first); }
		}

		return res;
	}
};

void main()
{
	Solution sol;

	vector<string> list1 = { "Shogun", "Tapioca Express", "Burger King", "KFC" };
	vector<string> list2 = { "KFC", "Burger King", "Tapioca Express", "Shogun" };
	vector<string> res;
	res = sol.findRestaurant(list1, list2);

	for (int i = 0; i < res.size(); ++i) {
		cout << res[i].c_str() << endl;
	}

	system("pause");
}