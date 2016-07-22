//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2016 CQU_CST_WuErli. All rights reserved.
//
//#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <sstream>
#include <bitset>
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define MEM(x,a) memset((x),(a),sizeof(x))
#define BUG cout << "I am here" << endl
#define lookln(x) cout << #x << "=" << x << endl
#define SI(a) scanf("%d", &a)
#define SII(a,b) scanf("%d%d", &a, &b)
#define SIII(a,b,c) scanf("%d%d%d", &a, &b, &c)
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7f7f7f7f;
const int MOD=1e9+7;
const double eps=1e-10;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N = 200020;
int n, k;
vector<int> g[N];
int w[N];
int mx[N];
int sz[N];
int centroid;
int dep[N];

void find(int fa, int u) {
	mx[u] = 0; sz[u] = w[u];
	for (auto & v: g[u]) {
		if (v == fa) continue;
		find(u, v);
		sz[u] += sz[v];
		mx[u] = max(mx[u], sz[v]);
	}
	mx[u] = max(mx[u], 2 * k - sz[u]);
	if (!centroid || mx[u] < mx[centroid]) centroid = u;
}


void dfs(int fa, int u, int cnt) {
	dep[u] = cnt;
	for (auto& v : g[u]) {
		if (fa == v) continue;
		dfs(u, v, cnt + 1);
	}
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    SII(n, k);
    CLR(w);
    for (int i = 1; i <= 2 * k; i++) {
		int x; SI(x);
		w[x] = 1;
    }
    for (int i = 1; i < n; i++) {
    	int u, v;
    	SII(u, v);
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    centroid = 0;
    find(-1, 1);
    // lookln(centroid);
    dfs(-1, centroid, 0);
	ll sum = 0;
	for (int i = 1; i <= n; i++) if (w[i]) sum += dep[i];
	cout << sum << endl;
	return 0;
}