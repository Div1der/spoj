#include <iostream>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;

#define ll long long
#define sz(s) (int)(s.size())
#define all(s) s.begin(), s.end()
#define mkp make_pair
#define eb emplace_back

const int N = 1e6 + 69;
const int NN = 2e3 + 69;
const int INF = 1e6 + 9;
const int mod = 1e9 + 7;
const int BLOCK = 174;

#define int ll

int a[N];

stack <pair <int, int> > st;

void solve() {
	int n;
	while(cin >> n) {
		if (n == 0)
			break;
		for (int i = 1; i <= n; ++ i)
			cin >> a[i];
		int ans = 0;
		for (int i = 1; i <= n; ++ i) {
			if (st.empty() or a[i] >= st.top().first)
				st.push(mkp(a[i], 1));
			else {
				int w = 0;
				while(sz(st) and a[i] < st.top().first) {
					w += st.top().second;
					ans = max(ans, w * st.top().first);
					st.pop();
				}
				st.push(mkp(a[i], w + 1));
			}
		}
		int w = 0;
		while(!st.empty()) {
			w += st.top().second;
			ans = max(ans, w * st.top().first);
			st.pop();
		}
		cout << ans << '\n';
	}
	
}

main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
	return 0;
}
