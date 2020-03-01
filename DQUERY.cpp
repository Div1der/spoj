#include <iostream>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <vector>
#include <set>
#include <map>
#include <queue>
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

int answer;
struct query{
    int l, r, pos;
}q[200010];
int ans[200010];
int a[30010];
int cnt[1000010];

void add(int index){
    cnt[a[index]]++;
    if(cnt[a[index]] == 1) answer++;
}

void remove(int index){
    cnt[a[index]]--;
    if(cnt[a[index]] == 0) answer--;
}

bool cmp(query f,query s){
    if((f.l / BLOCK) != (s.l / BLOCK))
        return (f.l / BLOCK) < (s.l / BLOCK);
    else
        return f.r < s.r;
}


void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++ i)
		cin >> a[i];
	int k;
	cin >> k;
	for (int i = 0; i < k; ++ i) {
		cin >> q[i].l >> q[i].r;
		q[i].pos = i;
		q[i].l--;
		q[i].r--;
	}
	sort(q, q + k, cmp);
	int L = 0, R = 0;
	for (int i = 0; i < k; ++ i) {
		int left = q[i].l, right = q[i].r;
		while(L < left)
            remove(L), L++;
        while(L > left)
            add(L - 1), L--;
        while(R <= right)
            add(R), R++;
        while(R > (right + 1))
            remove(R - 1), R--;
        ans[q[i].pos] = answer;
	}
	for (int i = 0; i < k; ++ i)
		cout << ans[i] << '\n';
}

main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
	return 0;
}
