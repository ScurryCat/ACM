#include <bits/stdc++.h>
using namespace std;

#define INF 0x7FFFFFFF
#define SUP 0x80000000

typedef long long ll;
typedef unsigned long long ull;

const int N = 1e4+9;
const int M = 2e5+9;
const int mod = 998244353;

int n;
int q[N],tt=-1,hh;

void solve(){
	cin>>n;
  while(n--){
    int op;
    cin>>op;
    if(op==1){
      int x;
      cin>>x;
      q[++tt]=x;
    }
    else if(op==2){
      if(hh<=tt) hh++;
      else cout<<"ERR_CANNOT_POP\n";
    }
    else if(op==3){
      if(hh<=tt) cout<<q[hh]<<'\n';
      else cout<<"ERR_CANNOT_QUERY\n";
    }
    else if(op==4){
      cout<<tt-hh+1<<'\n';
    }
  }
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int T = 1;
	// cin>>T;
	while(T--) solve();
	return 0;
}
