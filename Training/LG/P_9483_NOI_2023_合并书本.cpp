#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

void qaq_(){
	int n; cin >> n;
  priority_queue<pair<ll,ll>> h; 
  for(int i = 1; i <= n; i++) {
    ll x; cin>>x;
    h.push({-x,0});
  }
  ll ans = 0;
  while(h.size()>1){
    pair<ll,ll> a = h.top(); h.pop();
    pair<ll,ll> b = h.top(); h.pop();
    ans += -max(a.first,b.first) + a.second + b.second;
    h.push({a.first+b.first,(max(a.second,b.second)<<1)+1});
  }
  cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	cin >> yyy;
	while(yyy--) qaq_();
	return 0;
}