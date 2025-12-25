#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

void solve(){
	int n,ans=0;
  cin>>n;
  while(n){
    if(n<=2) break;
    else if(n%3==2) ans+=n/3,n=n/3+2;
    else if(n%3==1) ans+=n/3,n=n/3+1;
    else if(n%3==0) ans+=n/3,n=n/3;
  }
  cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	cin >> yyy;
	while(yyy--) solve();
	return 0;
}