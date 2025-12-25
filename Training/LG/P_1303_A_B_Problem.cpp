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

const int N = 4e3+9;
const int mod = 998244353;

int la,lb,lc;
int a[N],b[N],c[N];

void mul(int a[],int b[],int c[]){
  for(int i=0;i<la;i++){
    for(int j=0;j<lb;j++){
      c[i+j] += a[i] * b[j];
      c[i+j+1] += c[i+j] / 10;
      c[i+j] %= 10;
    }
  }
  while(lc&&c[lc]==0) lc--;
}

void solve(){
  string A,B;
  cin>>A>>B;
  la=A.size();
  lb=B.size();
  lc=la+lb;
  for(int i=0;i<la;i++) a[la-1-i] = A[i]-'0';
  for(int i=0;i<lb;i++) b[lb-1-i] = B[i]-'0';
  mul(a,b,c);
  for(int i=lc;~i;i--) cout<<c[i];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// yyy = read();
	while(yyy--) solve();
	return 0;
}