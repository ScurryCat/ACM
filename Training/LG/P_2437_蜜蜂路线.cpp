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

const int N = 1e5+9;
const int mod = 998244353;

int n,m;
VI a,b,fib;

void add(VI a,VI b,VI c){
  
}

void Fib(int n){
  for(int i=1;i<=n;i++){
    add(a,b,fib);
    a=b;
    b=fib;
  }
}

void solve(){
  n=read();
  m=read();
  fib.push_back(1);
  Fib(m-n+1);
  for(int i=fib.size()-1;~i;i--) cout<<fib[i];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// yyy = read();
	while(yyy--) solve();
	return 0;
}