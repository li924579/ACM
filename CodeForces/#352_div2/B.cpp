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

int n;
string s;

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while(SI(n) == 1) {
    	cin >> s;
    	if (s.size() > 26) puts("-1");
    	else {
    		map<char, int> mp;
    		for (int i = 0; i < s.size(); i++) mp[s[i]]++;
    		int one = 0, second = 0, no = 0;
    		for (char i = 'a'; i <= 'z'; i++) {
    			if (mp[i] == 1) one++;
    			else if (mp[i] >= 2) second += mp[i] - 1;
    			else if (!mp[i]) no++;
    		}
    		int ans = 0;
    		if (second <= no) {
    			ans = second;
    			cout << ans << endl;
    		}
    		else puts("-1");
    	}
    }
	return 0;
}