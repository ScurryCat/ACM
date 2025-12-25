#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

const int N = 1e2+9, mod = 998244353;

int n;
int d[N][N];

void Floyd(){
  for(int k=1;k<=n;k++)
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
        d[i][j] |= (d[i][k] & d[k][j]);    
}

void solve(){
	cin>>n;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      cin>>d[i][j];
  Floyd();
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++)
      cout<<d[i][j]<<' ';
    cout<<'\n';
  }
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) solve();
	return 0;
}