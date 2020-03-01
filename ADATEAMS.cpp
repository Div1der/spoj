#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <numeric>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define sz(s) (int)(s.size())
#define all(s) s.begin(), s.end()
#define mkp make_pair
#define eb emplace_back

const int N = 1e6 + 69;
const int NN = 2e3 + 69;
const int INF = 1e6 + 9;
const int mod = 1000000007;
int f[N];

int v[N];

int bpow(int a, int b) {
    if(b == 0)
        return 1;
    if(b & 1)
        return 1LL * bpow(a, b - 1) * a % mod;
    int n = bpow(a, b >> 1);
    return 1LL * n * n % mod;
}
/*
int bpow(int a, int n) {
	if (n == 0)
		return 1;
	if (n & 1) {
		return 1LL * bpow(a, n - 1) * a % mod;
	}
	int b = bpow(a, n >> 1);
	return 1LL * b * b % mod;
}
*/
int cnk(int n, int k) {
	return 1ll * v[k] * f[n] % mod * v[n - k] % mod;
}

void solve() {
	f[0] = 1;
	v[0] = 1;
	for (int i = 1; i <= INF; ++ i) {
		f[i] = 1ll * f[i - 1] * i % mod;
		v[i] = bpow(f[i], mod - 2);
	}
	int n, a, b, d;
	while(cin >> n >> a >> b >> d) {
		int res = 1ll * cnk(n, a) * bpow(cnk(b, d), a) % mod;
		cout << res << '\n';
	}
}

main() {
	ios_base::sync_with_stdio(false);
	solve();
	return 0;
}
