#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 317847191;

int n,m;
int h1[N],h2[N],idx;
ll s;

void solve(){
	cin>>n>>m;
  s=1;
  for(int i=1;i<=n;i++){
    int x; cin>>x;
    s = (s * x) % mod;
    idx++;
    h1[idx]=h2[idx]=x;
    int j=idx;
    while(h1[j]<h1[j>>1]) swap(h1[j],h1[j>>1]),j>>=1;
    j=idx;
    while(h2[j]>h2[j>>1]) swap(h2[j],h2[j>>1]),j>>=1;
  }

  for(int i=1;i<=m;i++){
    char op; cin>>op;
    
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