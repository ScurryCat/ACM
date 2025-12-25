#include <bits/stdc++.h>
using namespace std;

#define INF 0x7FFFFFFF
#define SUP 0x80000000

typedef long long ll;
typedef unsigned long long ull;

const int N = 1e5+9;
const int M = 2e5+9;
const int mod = 998244353;

int n,m,ans;

struct btn{
  int l,r;
}bt[N];

void pre(int n){
  cout<<n<<' ';
  if(bt[n].l) pre(bt[n].l);
  if(bt[n].r) pre(bt[n].r);
}

void mid(int n){
  if(bt[n].l) mid(bt[n].l);
  cout<<n<<' ';
  if(bt[n].r) mid(bt[n].r);
}

void pos(int n){
  if(bt[n].l) pos(bt[n].l);
  if(bt[n].r) pos(bt[n].r);
  cout<<n<<' ';
}

void solve(){
  cin>>n;
  for(int i=1;i<=n;i++){
    int l,r;
    cin>>l>>r;
    bt[i].l=l;
    bt[i].r=r;
  }
  pre(1);
  cout<<'\n';
  mid(1);
  cout<<'\n';
  pos(1);
  cout<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int T = 1;
	// cin>>T;
	while(T--) solve();
	return 0;
}
