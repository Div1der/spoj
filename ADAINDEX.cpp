#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define sz(s) (int)(s.size())
#define all(s) s.begin(), s.end()
#define ll long long
#define mkp make_pair

const int N = 2e6 + 9;
const int INF = 1e9 + 9;
const int mod = 1e9;

int sz = 1;
int trie[N][30];
int cnt[N][30];

void add(string s) {
	int len = sz(s);
	int node = 0;
	for (int i = 0; i < len; ++ i) {
		char c = s[i] - 'a';
		if (trie[node][c] == -1)
			trie[node][c] = sz++;
		node = trie[node][c];
		cnt[node][c]++;
	}
}

int find(string s) {
	int len = sz(s);
	int node = 0;
	int ans = 0;
	for (int i = 0; i < len; ++ i) {
		char c = s[i] - 'a';
		if (trie[node][c] == -1)
			return 0;
		node = trie[node][c];
		if (i == len - 1)
			return cnt[node][c];
	}
	return 0;
}

void solve() {
	int n, q;
	cin >> n >> q;
	memset(trie, -1, sizeof(trie));
	for (int i = 1; i <= n; ++ i) {
		string s;
		cin >> s;
		add(s);
	}
	while(q--) {
		string s;
		cin >> s;
		cout << find(s) << '\n';
	}
}

main() {
	cerr << "Ready\n";
	solve();
	return 0;
}
