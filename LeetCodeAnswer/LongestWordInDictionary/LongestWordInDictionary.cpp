#include <iostream>
#include <vector>

using namespace std;

class TrieNode {
public:
	int dp;
	int idx;
	TrieNode* child[26];

	TrieNode(int deep) : dp(deep), idx(-1) { memset(child, 0, sizeof(child)); }
};

class Solution {
public:
	int buildTrie(TrieNode* tn, string& word, int j, int i) {
		if (!tn->child[word[j] - 97]) { tn->child[word[j] - 97] = new TrieNode(-1); }

		if ((j + 1) < word.size()) {
			int dp = buildTrie(tn->child[word[j] - 97], word, j + 1, i);

			if (tn->dp < dp) { tn->dp = dp; }
		}
		else {
			tn->child[word[j] - 97]->idx = i;

			if (tn->child[word[j] - 97]->dp < 0) { tn->child[word[j] - 97]->dp = j + 1; }
			if (tn->dp < tn->child[word[j] - 97]->dp) { tn->dp = tn->child[word[j] - 97]->dp; }
		}

		if (tn->idx > -1) { return tn->dp; }
		else { return -1; }
	}

	int findLongestWord(TrieNode* tn) {
		int c = -1;
		int max = INT_MIN;

		for (int i = 0; i < 26; ++i) {
			if (tn->child[i] && tn->child[i]->idx > -1) {
				if (max < tn->child[i]->dp) {
					c = i;
					max = tn->child[i]->dp;
				}
				else if (max == tn->child[i]->dp) {
					if (i < c) { c = i; }
				}
			}
		}

		if (c > -1) { return findLongestWord(tn->child[c]); }
		else { return tn->idx; }
	}

	string longestWord(vector<string>& words) {
		int n = words.size(), m;
		TrieNode* root = new TrieNode(0);

		for (int i = 0; i < n; ++i) { buildTrie(root, words[i], 0, i); }

		return words[findLongestWord(root)];
	}
};

void main()
{
	Solution sol;

	vector<string> words = { "ogz","eyj","e","ey","hmn","v","hm","ogznkb","ogzn","hmnm","eyjuo","vuq","ogznk","og","eyjuoi","d" };

	cout << sol.longestWord(words).c_str() << endl;

	system("pause");
}