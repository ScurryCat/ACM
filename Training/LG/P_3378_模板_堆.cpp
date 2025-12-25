#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

const int N = 1e6+9, mod = 998244353;

int q;
int h[N],idx;

void solve(){
	cin>>q;
  while(q--){
    int op; cin>>op;
    if(op==1){
      int x; cin>>x;
      h[++idx]=x;
      int cur=idx;
      while(cur>1 && h[cur]<h[cur>>1]) swap(h[cur],h[cur>>1]),cur>>=1;
    }
    else if(op==2){
      cout<<h[1]<<'\n';
    }
    else{
      swap(h[1],h[idx--]);
      for(int i=1; i<<1 <= idx; ){
        int j=i<<1;
        if(j+1<=idx && h[j+1] < h[j]) j++;
        if(h[j]<=h[i]) swap(h[i],h[j]),i=j;
        else break;
      }
    }
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