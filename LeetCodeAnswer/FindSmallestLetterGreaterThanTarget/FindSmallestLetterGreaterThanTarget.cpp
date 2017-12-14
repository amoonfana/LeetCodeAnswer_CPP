#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	char nextGreatestLetter(vector<char>& letters, char target) {
		int s = 0, e = letters.size() - 1;
		if (target < letters[s] || letters[e] <= target) { return letters[s]; }

		for (int i = (s + e) / 2; s < i; i = (s + e) / 2) {
			if (target < letters[i]) { e = i; }
			else { s = i; }
		}

		return letters[e];
	}
};

void main()
{
	Solution sol;

	vector<char> letters = {'c', 'f', 'j'};
	char target = 'a';

	cout << sol.nextGreatestLetter(letters, target) << endl;

	system("pause");
}