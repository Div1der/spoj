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
const int K = 25;

#define int ll

int a[N];

int s[N][K];

int log[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++ i) {
		cin >> a[i];
		s[i][0] = a[i];
	}
	log[1] = 0;
	for (int i = 2; i <= n; ++ i)
		log[i] = log[i / 2] + 1;
	for (int j = 1; j <= K; ++ j) 
		for (int i = 0; i + (1 << j) <= n; ++ i)
			s[i][j] = min(s[i][j - 1], s[i + (1 << (j - 1))][j - 1]);
	int q;
	cin >> q;
	while(q--) {
		int l, r;
		cin >> l >> r;
		int j = log[r - l + 1];
		cout << min(s[l][j], s[r - (1 << j) + 1][j]) << '\n';
	}
}

main() {
	ios_base::sync_with_stdio(false);
	solve();
	return 0;
}
