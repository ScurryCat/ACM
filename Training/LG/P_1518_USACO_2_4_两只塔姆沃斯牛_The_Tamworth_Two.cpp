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

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int dir1,dir2;
PII c_pos,f_pos;
char m[11][11];

void solve(){
  for(int i=1;i<=10;i++){
    for(int j=1;j<=10;j++){
      cin>>m[i][j];
      if(m[i][j]=='C') c_pos={i,j};
      if(m[i][j]=='F') f_pos={i,j};
    }
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