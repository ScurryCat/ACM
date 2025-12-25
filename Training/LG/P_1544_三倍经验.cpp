#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

void qwq_(){
	int n,m;
	cin>>n>>m;
	int f[n+2][n+2][m+2]; // 表示a[i][j]在已经放大过k次时的最大值
	memset(f,0,sizeof f);
	vector<vector<int>> a(n+1,vector<int>(n+1));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cin>>a[i][j];
		}
	}
	for(int i=n;i>=1;i--){
		for(int j=i;j>=1;j--){
			f[i][j][0]=max(f[i+1][j][0],f[i+1][j+1][0])+a[i][j];
			for(int k=1;k<m;k++){
				if(n-i<k) f[i][j][k+1]=max(f[i+1][j][k+1],f[i+1][j+1][k+1])+3*a[i][j];
				else f[i][j][k+1]=max(max(f[i+1][j][k+1],f[i+1][j+1][k+1])+a[i][j],max(f[i+1][j][k],f[i+1][j+1][k])+3*a[i][j]);
				// f[i][j][0]=max(f[i+1][j][0],f[i+1][j+1][0])+a[i][j];
				// f[i][j][1]=max(max(f[i+1][j][1],f[i+1][j+1][1])+a[i][j],max(f[i+1][j][0],f[i+1][j+1][0])+3*a[i][j]);
				// f[i][j][2]=max(max(f[i+1][j][2],f[i+1][j+1][2])+a[i][j],max(f[i+1][j][1],f[i+1][j+1][1])+3*a[i][j]);
			}
		}
	}
	// cout<<f[1][1][m];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cout<<f[i][j][m]<<' ';
		}
		cout<<'\n';
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}