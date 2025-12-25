#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

int cnt[N];

inline ll read(){
  ll r=0,w=1;
  char ch = getchar();
  while(ch>'9'||ch<'0'){
    if(ch=='-') w*=-1;
    ch=getchar();
  }
  while(ch>='0'&&ch<='9'){
    r = (r<<3)+(r<<1)+ch-'0';
    ch=getchar();
  }
  return r*w;
}

void qaq_(){
	int n=read();
  for(int i = 1; i <= n; i++) {
    int x=read();
    cnt[x]++;
  }
  queue<ll> h, t;
  for(int i = 1; i <= 100000; i++) 
    for(int j = 1; j <= cnt[i]; j++)
      h.push(i);

  ll ans = 0;
  while(h.size()+t.size()>1){
    ll a, b;
    if(t.empty() || (h.front()<=t.front() && h.size())) a = h.front(), h.pop();
    else a = t.front(), t.pop();

    if(t.empty() || (h.front()<=t.front() && h.size())) b = h.front(), h.pop();
    else b = t.front(), t.pop();

    ans += a + b;
    t.push(a + b);
  }
  cout << ans << '\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) qaq_();
	return 0;
}