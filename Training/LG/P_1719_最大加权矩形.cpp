#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 120+9, mod = 998244353;

int n,ans;
int a[N][N],s[N][N];

void qwq_(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
		}
	}
	for(int x=1;x<=n;x++){
		for(int y=1;y<=n;y++){
			for(int i=x;i<=n;i++){
				for(int j=y;j<=n;j++){
					ans=max(ans,s[i][j]-s[i][j-y-1]-s[i-x-1][j]+s[i-x-1][j-y-1]);
				}
			}
		}
	}
	cout<<ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}