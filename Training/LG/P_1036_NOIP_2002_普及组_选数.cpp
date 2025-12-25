#include <bits/stdc++.h>
using namespace std;

inline int read(){
	int r = 0, w = 1; char ch = getchar();
	while(ch < '0' || ch > '9') { if(ch == '-') w *= -1; ch = getchar();}
	while('0' <= ch && ch <= '9') {r = (r << 1) + (r << 3) + ch - 48; ch = getchar();}
	return r * w;
}

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

const int N = 20+9;
const int mod = 998244353;

int n,m,ans;
int a[N],vis[N];

bool check(int x){
  for(int i=2;i*i<=x;i++)
    if(x%i==0) return false;
  return true;
}

void dfs(int idx,int k,int x){
  if(k==m){
    if(check(x)) ans++;
    return ;
  }
  for(int i=idx;i<=n;i++){
    if(vis[i]) continue;
    vis[i] = 1;
    dfs(i+1,k+1,x+a[i]);
    vis[i] = 0;
  }
}

void solve(){
  n=read(),m=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
  }
  dfs(1,0,0);
  cout<<ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// yyy = read();
	while(yyy--) solve();
	return 0;
}