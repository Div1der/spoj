#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 9;
const int INF = 500;
const int mod = 1e9;
const int K = 25;
const int SZ = (1 << 17) - 1;

#define eb emplace_back
#define sz(s) (int)(s.size())

pair <int, pair <int, int> > g[N];

int p[N];

int get(int v) {
	return p[v] == v ? v : p[v] = get(p[v]);
}

void merge(int a, int b) {
	a = get(a);
	b = get(b);
	p[a] = b;
}


void solve() {
	while(true) {
		int n, m;
		cin >> n >> m;
		if (!n and !m)
			break;
		int sum = 0;
		for (int i = 1; i <= m; ++ i) {
			int x, y, w;
			cin >> x >> y >> w;
			g[i].first = w;
			g[i].second.first = x;
			g[i].second.second = y;
			sum += w;
		}
		sort(g + 1, g + 1 + m);
		for (int i = 1; i <= n; ++ i)
			p[i] = i;
		int ans = 0;
		for (int i = 1; i <= m; ++ i) {
			int a = g[i].second.first;
			int b = g[i].second.second;
			int l = g[i].first;
			if (get(a) != get(b)) {
				ans += l;
				merge(a, b);
			}
		}
		cout << sum - ans << '\n';
	}
}
main() {
	ios_base::sync_with_stdio(false);
	solve();
	return 0;
}
