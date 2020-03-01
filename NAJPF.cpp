#include <iostream>
#include <vector>
#include <string>

#define sz(x) (int)(x.size())
#define eb emplace_back

using namespace std;

vector <int> pos;

vector <int> z_func(string s) {
	int len = int(s.size());
	vector <int> z(len);
	for (int i = 1, l = 0, r = 0; i < len; ++ i) {
		if (i <= r)
			z[i] = min(r - i + 1, z[i - l]);
		while(i + z[i] < len and s[z[i]] == s[i + z[i]])
			++z[i];
		if (i + z[i] - 1 > r)
			l = i, r = i + z[i] - 1;
	}
	return z;
}

int main () {
	clog << "Ready\n";
	
	int n;
	cin >> n;
	
	while(n--) {
		string s, t;
		cin >> s >> t;
		string sum = t + "#" + s;
		vector <int> ans = z_func(sum);
		int cnt = 0;
		pos.clear();
		for (int i = sz(t) + 1; i < sz(ans); ++ i) {
			if (ans[i] == sz(t)) {
				pos.eb(i - sz(t));
				++cnt;
			}
		}
		if (!cnt)
			cout << "Not Found";
		else
			cout << cnt << '\n';
		for (auto to : pos)
			cout << to << " ";
		
		cout << '\n';
	}
	
	return 0;
}
