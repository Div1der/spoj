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

int primes[N], p[N], sum[N];

void solve() {
	sum[1] = 1;
	for (int i = 2; i < INF; ++ i)
		if (!p[i])
			for (int j = i + i; j < INF; j += i)
				p[j] = 1;
	
	for (int i = 2; i < INF; ++ i)
		sum[i] = sum[i - 1] + 1 - p[i];
	
	int q;
	cin >> q;
	for (int test = 1; test <= q; ++ test) {
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < k; ++ i)
			cin >> primes[i];

		int cnt = 0;
		for (int mask = 0; mask < (1 << k); ++ mask) {
			int ans = 1;
			for (int i = 0; i < k && ans <= n; ++ i)
				if(mask & (1 << i))
					ans *= primes[i];
			
			if(__builtin_popcount(mask) & 1)
				cnt -= n / ans;

			else
				cnt += n / ans;
		}
		
		for (int i = 0; i < k; ++ i)
			if (primes[i] <= n)
				++cnt;

		cnt -= sum[n];
		cout << "Case " << test << ": " << cnt << '\n';
	}
}

main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	cerr << "Ready\n";
	solve();
	return 0;
}
