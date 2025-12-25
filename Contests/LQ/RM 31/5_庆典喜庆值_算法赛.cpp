#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;

inline ll modmul(ll a, ll b){
	return (ll)((__int128)a * b % mod);
}
ll modpow(ll a, ll b){
  ll r = 1 % mod;
  while(b){
    if(b & 1) r = modmul(r, a);
    a = modmul(a, a);
    b >>= 1;
  }
  return r;
}

void solve(){
  ll inv2 = (mod + 1) / 2;          // 模逆
  ll inv6 = modpow(6, mod-2);
  ll n; cin>> n;
  n %= mod;
  ll sum1 = modmul(modmul(n, (n+1+mod)%mod), inv2);
  ll sum2 = modmul(modmul(n, (n+1+mod)%mod), ( (2*n+1) % mod + mod ) % mod);
  sum2 = modmul(sum2, inv6);
  ll ans = ( (3 * sum2) % mod + (3 * sum1) % mod + n ) % mod;
  cout<<ans<<"\n";
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int T;  cin>>T;
  while(T--) solve();
  return 0;
}