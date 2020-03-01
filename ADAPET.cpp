#include <iostream>
#include <vector>
using namespace std;

#define sz(s) (int)(s.size())
#define all(s) s.begin(), s.end()
#define ll long long
#define mkp make_pair

const int N = 1e6 + 9;
const int INF = 1e9 + 9;
const int mod = 1e9;

#define int ll

void solve() {
	string s;
	int k;
	cin >> s >> k;
	int n = sz(s);
	vector <int> p(n);
	int pos = 0;
	for (int i = 1; i < n; ++ i) {
		int j = p[i - 1];
		while(j > 0 and s[i] != s[j])
			j = p[j - 1];
		if (s[i] == s[j])
			++j;
		p[i] = j;
		pos = p[i];
	}
	int res = sz(s);
	res += (sz(s) - pos) * (k - 1);
	cout << res << '\n';
}

main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int q;
	cin >> q;
	while(q--)
		solve();
	return 0;
}
