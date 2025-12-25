#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

int n,m;
ll s,r;

void qwq_(){
	cin>>n>>m;
  for(int i=1;i<=min(n,m);++i){
    s += (n-i+1) * (m-i+1);
  }
  for(int i=1;i<=n;++i){
    for(int j=1;j<=m;++j){
      r += i*j;
    }
  }
  cout<<s<<' '<<r-s;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}