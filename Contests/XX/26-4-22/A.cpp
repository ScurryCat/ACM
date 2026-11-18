#include <bits/stdc++.h>
using namespace std;

using ll = long long;

inline void solve(){
  ll n;  cin >> n;
  ll cnt = 0;
  for(ll i = 1; ; i++){
    cnt += i*i;
    if(cnt >= n){
      cout << i << ' ' << i*i;
      break;
    }
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int t = 1;
  // cin >> t;
  while(t--) solve();

  return 0;
}