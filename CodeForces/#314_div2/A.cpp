//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2015�� CQU_CST_WuErli. All rights reserved.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <ctime>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <sstream>
#include <functional>
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define MEM(x,a) memset((x),(a),sizeof(x))
#define ALL(x) x.begin(),x.end()
#define at(i,v) for (auto &i:v)
#define for_uva if (kase!=1) cout << endl
#define BUG(x) cout << "I am in line" << x << endl
#define look(x) cout << #x << "= " << x << endl
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define INF 0x3f3f3f3f
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;
const int N=1e5+10;
int n;
ll a[N]; 

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif	
	while (cin >> n){
		for (int i=1;i<=n;i++) cin >> a[i];
		for (int i=1;i<=n;i++){
			if (i==1) cout << a[i+1]-a[i] << " " << a[n]-a[i] << endl;
			else if (i==n) cout << a[i]-a[i-1] << " " << a[n]-a[1] << endl;
			else {
				ll maxi,mini;
				maxi=max(a[i]-a[1],a[n]-a[i]);
				mini=min(a[i]-a[i-1],a[i+1]-a[i]);
				cout << mini << " " << maxi << endl;
			}
		}
	}
	return 0;
}


