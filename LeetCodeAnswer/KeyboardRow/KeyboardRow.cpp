#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool isRow(string s)
	{
		int flag = 0;
		for (int i = 0; i < s.size();++i)
		{
			switch (s[i])
			{
			case 'q':
			case 'w':
			case 'e':
			case 'r':
			case 't':
			case 'y':
			case 'u':
			case 'i':
			case 'o':
			case 'p':
			case 'Q':
			case 'W':
			case 'E':
			case 'R':
			case 'T':
			case 'Y':
			case 'U':
			case 'I':
			case 'O':
			case 'P':
				if (flag == 1) { break; }
				else if (flag == 0) { flag = 1; }
				else { flag = 0; }
				break;

			case 'a':
			case 's':
			case 'd':
			case 'f':
			case 'g':
			case 'h':
			case 'j':
			case 'k':
			case 'l':
			case 'A':
			case 'S':
			case 'D':
			case 'F':
			case 'G':
			case 'H':
			case 'J':
			case 'K':
			case 'L':
				if (flag == 2) { break; }
				else if (flag == 0) { flag = 2; }
				else { flag = 0; }
				break;

			case 'z':
			case 'x':
			case 'c':
			case 'v':
			case 'b':
			case 'n':
			case 'm':
			case 'Z':
			case 'X':
			case 'C':
			case 'V':
			case 'B':
			case 'N':
			case 'M':
				if (flag == 3) { break; }
				else if (flag == 0) { flag = 3; }
				else { flag = 0; }
				break;
			}

			if (flag == 0) { return false; }
		}

		return true;
	}

	vector<string> findWords(vector<string>& words) {
		vector<string> res;

		for (int i = 0; i < words.size(); ++i)
		{
			if (isRow(words[i]))
			{
				res.push_back(words[i]);
			}
		}

		return res;
	}
};

void main()
{
	Solution sol;

	vector<string> words;
	words.push_back("Hello");
	words.push_back("Alaska");
	words.push_back("Dad");
	words.push_back("Peace");

	vector<string> res = sol.findWords(words);

	for (int i = 0; i < res.size(); ++i)
	{
		cout << res[i].c_str() << endl;
	}

	system("pause");
}