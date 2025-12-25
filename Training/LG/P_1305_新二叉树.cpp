#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

const int N = 1e3+9, mod = 998244353;

struct tree{
  int l,r;
}tr[N];

void pre(int n){
  if(n=='*') return;
  cout<<(char)n;
  pre(tr[n].l);
  pre(tr[n].r);
}

void solve(){
	int n;
  cin>>n;
  char r;
  for(int i=1;i<=n;i++){
    char a,b,c;
    cin>>a>>b>>c;
    if(i==1) r=a;
    tr[a].l=b;
    tr[a].r=c;
  }
  pre(r);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) solve();
	return 0;
}