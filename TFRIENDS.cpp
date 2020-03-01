#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 9;
const int INF = 500;
const int mod = 1e9;
const int K = 25;
const int SZ = (1 << 17) - 1;

#define eb emplace_back
#define sz(s) (int)(s.size())

vector <vector <int> > g, g1;

int u[N];
stack <int> st;

void dfs(int v) {
	u[v] = true;
	for (auto to : g[v])
		if (!u[to])
			dfs(to);
	st.push(v);
}

void dfs1(int v) {
	u[v] = true;
	for (auto to : g1[v])
		if (!u[to])
			dfs1(to);
}

void solve() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		g.resize(n);
		g1.resize(n);
		int cnt = 0;
		for (int i = 0; i < n; ++ i) {
			string s;
			cin >> s;
			for (int j = 0; j < sz(s); ++ j) {
				if (s[j] == 'Y') {
					g[i].eb(j);
					g1[j].eb(i);
				}
			}
		}
		memset(u, 0, sizeof u);
		for (int i = 0; i < n; ++ i) {
			if (!u[i])
				dfs(i);
		}
		memset(u, 0, sizeof u);
		while(true) {
			if (st.empty())
				break;
			int v = st.top();
			st.pop();
			if (!u[v]) {
				++cnt;
				dfs1(v);
			}
		}
		cout << cnt << '\n';
		g.clear();
		g1.clear();
	}
}
main() {
	ios_base::sync_with_stdio(false);
	solve();
	return 0;
}
