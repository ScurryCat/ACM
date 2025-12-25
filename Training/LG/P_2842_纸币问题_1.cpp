#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353, inf = 0x3f3f3f3f;

int n,m;

void qwq_(){
	cin>>n>>m;
  vector<int> f(m+1,inf); // f[i]表示凑出i元最少需要几张钞票。  f[i]=min(f[i],f[i-x]+1)
  f[0]=0;
  for(int i=1;i<=n;i++){
    int x; cin>>x;
    for(int j=x;j<=m;j++){
      f[j]=min(f[j],f[j-x]+1);
    }
  }
  cout<<f[m];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}