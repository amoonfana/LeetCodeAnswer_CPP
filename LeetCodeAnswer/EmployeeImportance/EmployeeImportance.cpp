#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Employee {
public:
	int id;
	int importance;
	vector<int> subordinates;
};

class Solution {
public:
	int dfs(unordered_map<int, Employee*> & m, int id) {
		int sum = m[id]->importance;

		for (int i : m[id]->subordinates) { sum += dfs(m, i); }

		return sum;
	}

	int getImportance(vector<Employee*> employees, int id) {
		unordered_map<int, Employee*> m;

		for (Employee* e : employees) { m[e->id] = e; }

		return dfs(m, id);
	}
};

void main()
{
	Solution sol;

	Employee* e1 = new Employee;
	e1->id = 1;
	e1->importance = 5;
	e1->subordinates.push_back(2);
	e1->subordinates.push_back(3);
	Employee* e2 = new Employee;
	e2->id = 2;
	e2->importance = 3;
	Employee* e3 = new Employee;
	e3->id = 3;
	e3->importance = 3;

	vector<Employee*> employees;
	employees.push_back(e1);
	employees.push_back(e2);
	employees.push_back(e3);


	cout << sol.getImportance(employees, 1) << endl;

	system("pause");
}