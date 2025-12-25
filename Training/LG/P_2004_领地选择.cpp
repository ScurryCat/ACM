#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

void qwq_(){
	int n,m,c;
	cin>>n>>m>>c;
	vector<vector<int>> a(n+1,vector<int>(m+1)), s(n+1,vector<int>(m+1));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
		}
	}
	int mx=-2e9,x,y;
	for(int i=1;i+c-1<=n;i++){
		for(int j=1;j+c-1<=m;j++){
			if(s[i+c-1][j+c-1]-s[i+c-1][j-1]-s[i-1][j+c-1]+s[i-1][j-1]>mx){
				mx=s[i+c-1][j+c-1]-s[i+c-1][j-1]-s[i-1][j+c-1]+s[i-1][j-1];
				x=i; y=j;
			}
		}
	}
	cout<<x<<' '<<y;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}