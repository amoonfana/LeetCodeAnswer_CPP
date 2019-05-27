#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
	int uniqueMorseRepresentations(vector<string>& words) {
		vector<string> mc = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };
		set<string> r;

		string t="";
		for (int i = 0; i < words.size(); ++i) {
			t.clear();

			for (int j = 0; j < words[i].size(); ++j) {
				t += mc[words[i][j] - 97];
			}

			r.insert(t);
		}

		return r.size();
	}
};

void main()
{
	Solution sol;

	vector<string> words;
	words.push_back("gin");
	words.push_back("zen");
	words.push_back("gig");
	words.push_back("msg");

	cout << sol.uniqueMorseRepresentations(words) << endl;

	system("pause");
}