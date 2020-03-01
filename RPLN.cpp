#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <utility>
#include <iomanip>

using namespace std;

const int MAXN = 2 * 105000;
const int MAXLOG = 20;

int n, m;
int a[MAXN];
int table[MAXLOG][MAXN];
int numlog[MAXN];

void build() {
    numlog[1] = 0;
    for (int i = 2; i <= n; i++)
        numlog[i] = numlog[i / 2] + 1;

    for (int i = 0; i <= numlog[n]; i++) {
        int curlen = 1 << i;
        for (int j = 1; j <= n; j++) {
            if (i == 0) {
                table[i][j] = a[j];
                continue;
            }
            table[i][j] = min(table[i - 1][j], table[i - 1][j + curlen / 2]);
        }
    }
}

int get(int l, int r) {
    int curlog = numlog[r - l + 1];
    return min(table[curlog][l], table[curlog][r - (1 << curlog) + 1]); 
}

int main() {
	cerr << "Ready\n";
    //assert(freopen("input.txt","r",stdin));
    //assert(freopen("output.txt","w",stdout));

    int T;
    cin >> T;
    
    for (int it = 1; it <= T; ++ it) {
    	int q;
    	cin >> n >> q;
    	for (int i = 1; i <= n; ++ i)
    		cin >> a[i];
    	build();
    	
    	cout << "Scenario #" << it << ":\n";
    	
    	while(q--) {
    		int l, r;
    		cin >> l >> r;
    		cout << get(l, r) << "\n";
    	}
    	
    	cout << '\n';
    }
    
    return 0;
}
