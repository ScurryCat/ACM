#include <bits/stdc++.h>
using namespace std;

#define INF 0x7FFFFFFF
#define SUP 0x80000000

typedef long long ll;
typedef vector<int> VI;

const int N = 5e5+9;
const int M = 2e5+9;
const int mod = 998244353;

int n,m;
int L[N],R[N];

void solve(){
  L[0]=R[0]=1;
  L[1]=R[1]=0;
	cin>>n>>m;
  while(m--){
    int op; cin>>op;
    if(op==1){
      int x,y; cin>>x>>y;
      if(x==y) continue;
      L[y]=x;
      R[y]=
    }
    else if(op==2){
      int x,y;  cin>>x>>y;
      if(x==y) continue;
      // L[y]=x;
      // R[y]=R[x];
      // L[R[x]]=y;
      // R[x]=y;   
    }
    else if(op==3){
      int x;  cin>>x;
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