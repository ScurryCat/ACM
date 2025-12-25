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
const int mod = 1e9+7;

ll n,m;

struct matrix{
	ll c[20][20];
	matrix(){memset(c,0,sizeof c);}
};

matrix operator*(matrix x,matrix y){
	matrix r;
	for(int i=1;i<=m+1;i++)
		for(int k=1;k<=m+1;k++)
			for(int j=1;j<=m+1;j++)
				r.c[i][j] = (r.c[i][j] + x.c[i][k] * y.c[k][j]) % mod;
	return r;
}

void qpow(ll b){
	matrix A,R;
	for(int i=1;i<=m+1;i++) A.c[1][i]=1;
	for(int i=2;i<=m+1;i++) R.c[i-1][i]=1;
	R.c[1][1]=R.c[m+1][1]=1;
	while(b){
		if(b&1LL) A = A * R;
		R = R * R;
		b >>= 1;
	}
	cout<<A.c[1][1]<<'\n';
}

void solve(){
	cin>>n>>m;
	if(n+1<=m) cout<<1;
	else qpow(n);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// yyy = read();
	while(yyy--) solve();
	return 0;
}