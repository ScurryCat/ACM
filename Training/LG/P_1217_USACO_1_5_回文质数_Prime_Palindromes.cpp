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

const int N = 1e8+9;
const int M = 6e6+9;
const int mod = 998244353;

int a,b;
int pri[M],idx;
bool vis[N];

bool check(int n){
  int a=n,b=0;
  while(n){
    b = (b<<1)+(b<<3)+n%10;
    n /= 10;
  }
  return a==b;
}

void ora(int n){
  for(int i=2;i<=n;i++){
    if(!vis[i]) pri[++idx]=i;
    for(int j=1;i*pri[j]<=n;j++){
      vis[i*pri[j]]=true;
      if(i%pri[j]==0) break;
    }
  }
}

void solve(){
  a=read(),b=read();
  ora(b);
  int i=0;
  while(pri[i]<a) i++;
  for(;i<=idx;i++){
    if(check(pri[i])) cout<<pri[i]<<'\n';
  }
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// yyy = read();
	while(yyy--) solve();
	return 0;
}