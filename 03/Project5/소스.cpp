#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	int n, m, start;
	int a, b;

	cin >> n >> m >> start;

	vector<vector<int>> v(n + 1, vector<int>());
	vector<bool> chk(n + 1, false);

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		sort(v[i].begin(), v[i].end());
	}

	stack<int> s;
	s.push(start);
	chk[start] = true;
	
	while (!s.empty()) {
		int top = s.top();
		cout << top << " ";
		s.pop();
		for (auto j : v[top]) {
			if (!chk[j]) {
				s.push(j);
				chk[j] = true;
				break;
			}
		}
	}
	cout << "\n";

	chk.assign(n + 1, false);
	queue<int> q;
	q.push(start);
	chk[start] = true;

	while (!q.empty()) {
		int top = q.front();
		cout << top << " ";

		for (auto j : v[top]) {
			if (!chk[j]) {
				q.push(j);
				chk[j] = true;
			}
		}
		q.pop();
	}

	return 0;
}