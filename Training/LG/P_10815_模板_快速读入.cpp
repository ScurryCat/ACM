#include <bits/stdc++.h>
using namespace std;

char buf[1 << 20], *p1, *p2;
#define gc() \
(p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin), p1 == p2) ? EOF : *p1++) \

char pbuf[1 << 20], *pp = pbuf;
void push(const char &c) {
  if (pp - pbuf == 1 << 20) fwrite(pbuf, 1, 1 << 20, stdout), pp = pbuf;
  *pp++ = c;
}

inline int read(){
  int s=0,w=1; char ch=gc();
  while(ch<'0'||ch>'9') {if(ch=='-') w*=-1;ch=gc();}
  while('0'<=ch&&ch<='9') {s=(s<<1)+(s<<3)+(ch^48);ch=gc();}
  return s*w;
}

typedef long long ll;
const int N = 1e5+9, mod = 998244353;

void solve(){
	int n=read();
  int ans=0;
  for(int i=1;i<=n;i++){
    int x=read();
    ans+=x;
  }
  cout<<ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int T = 1;
	// cin>>T;
	while(T--) solve();
	return 0;
}