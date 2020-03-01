#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <sstream>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef vector <vector <int>> vii;
typedef vector <long long> vll;
typedef vector <string> vs;
typedef vector <char> vc;
typedef set <int> si;
typedef set <string> ss;
typedef queue <int> qi;
typedef queue <long long> qll;
typedef queue <string> qs;
typedef queue <char> qc;
typedef struct board board;
typedef pair <int, int> pi;
typedef pair <long long, long long> pll;
typedef pair <int, pair<int, int>> pii;

#define eb emplace_back
#define ppb pop_back
#define clr(a) a.clear()
#define F first
#define S second
#define mkp make_pair

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

#define left(x) x * 2
#define right(x) x * 2 + 1

#define meme(a, b, c) fill(a + 1, a + 1 + b, c)

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define abs(a) (a > 0? a : -(a))

#define move(s) s += "#"

#define fr(i, a, b) for (ll i = a; i <= b; ++ i)
#define rf(i, a, b) for (ll i = a; i >= b; -- i)

#define eprintf(...) fprintf(stderr, __VA_ARGS__);

void to_pray() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cerr << "Ready\n";
}

const int N = 4e6 + 10;
const int NN = 1e3 + 10;
const int NNN = 2e3 + 9;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const ll LLINF = 1e12 + 7;
const ll P = 53;
const int EPS = 1e-9 - 8;
const int vN = 2e4 + 10;
const int sz = (1 << 22) - 1;
const double PI = acos(-1);


ll t[sz * 4];
int n;

ll get(int r) {
	ll res = 0;
	for (; r >= 0; r = (r & (r + 1)) - 1) {
		res += t[r];
	}
	return res;
}

void update(int pos, int x) {
	for (; pos < n; pos = (pos | (pos + 1))) {
		t[pos] += x;
	}
}

ll sum(int l, int r) {
	return get(r) - get(l - 1);
}

int main () {
    to_pray();
    
    int q;
    cin >> n >> q;
    
    for (int i = 1; i <= n; ++ i) {
    	update(i, 0);
    }
    while(q--) {
    	string type;
    	cin >> type;
    	if (type == "find") {
    		int l, r;
    		cin >> l >> r;
    		cout << sum(l, r) << '\n';
    	}
    	if (type == "add") {
    		int x, y;
    		cin >> x >> y;
    		update(x, y);
    	}
    }

    //eprintf("%.18lf seconds\n", (double)clock() / CLOCKS_PER_SEC);
    cout << '\n';
    return 0;
}
