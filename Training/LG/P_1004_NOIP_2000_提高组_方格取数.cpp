#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 11, mod = 998244353;

int n,x,y,z;
int m[N][N];
int f[N][N][N][N];

inline int dfs(int x1, int y1, int x2, int y2){
	int r = m[x1][y1] + m[x2][y2];
	if(x1==n && y1==n && x2==n && y2==n) return m[n][n];
	if(x1==x2 && y1==y2) r = m[x1][y1];

	if(f[x1][y1][x2][y2]) return f[x1][y1][x2][y2];
	
	int k = 0;
	if(x1<n && x2<n) k = max(k, dfs(x1+1, y1, x2+1, y2));
	if(y1<n && x2<n) k = max(k, dfs(x1, y1+1, x2+1, y2));
	if(x1<n && y2<n) k = max(k, dfs(x1+1, y1, x2, y2+1));
	if(y1<n && y2<n) k = max(k, dfs(x1, y1+1, x2, y2+1));

	return f[x1][y1][x2][y2] = r + k;
}

void qwq_(){
	cin>>n;
	while(cin>>x>>y>>z){
		if((x|y|z) == 0) break;
		m[x][y]=z;
	}

	// 从(1,1)开始走
	cout << dfs(1, 1, 1, 1);
	
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}
