#include <bits/stdc++.h>
using namespace std;

using ll = long long;
void solve(){
  ll n, s;
  cin >> n >> s;
  for(int i=1; i<=n; i++){
    int r;
    cin >> r;
    if(r > s){
      s = (s + r + 1) / 2;
    }
  }
  cout << s << '\n';
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int t = 1;
  cin >> t;

  while(t--){
    solve();
  }

  return 0;
}