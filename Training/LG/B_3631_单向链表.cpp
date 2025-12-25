#include <bits/stdc++.h>
using namespace std;

#define INF 0x7FFFFFFF
#define SUP 0x80000000

typedef long long ll;
typedef vector<int> VI;

const int N = 1e6+9;
const int M = 2e5+9;
const int mod = 998244353;

int q;
int ne[N],idx;
// struct Node{
//   int v;
//   Node *ne;
// };

void solve(){
  ne[1]=0;
	cin>>q;
  while(q--){
    int op,x,y;
    cin>>op;
    if(op==1){
      cin>>x>>y;
      ne[y]=ne[x];
      ne[x]=y;
    }
    else if(op==2){
      cin>>x;
      cout<<ne[x]<<'\n';
    }
    else if(op==3){
      cin>>x;
      ne[x]=ne[ne[x]];
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