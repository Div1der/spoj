#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <numeric>
#include <algorithm>
using namespace std;

#define ll long long

const int N = 1e6 + 9;
const int INF = 1e6 + 25;

#define int ll

int a[N];

void solve() {
	int n;
	cin >> n;
	int ans = 0;
	int cnt = 0;
	for (int i = 1; i <= 1024; ++ i)
		a[i] = 0;
	for (int i = 1; i <= n; ++ i) {
		int x;
		cin >> x;
		while(x) {
			cnt |= (1 << x % 10);
			x /= 10;
		}
		a[cnt]++;
		cnt = 0;
	}
	for (int i = 1; i < (1 << 10); ++ i) 
		for (int j = 1; j < (1 << 10); ++ j) 
			if (i != j && (i & j)) 
				ans += a[i] * a[j];
	for (int i = 1; i < 1024; ++ i)
		ans += (a[i] * (a[i] - 1));
	cout << ans / 2 << '\n';
}

main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	cerr << "Ready\n";
	int q;
	cin >> q;
	while(q--)
		solve();
	return 0;
}
