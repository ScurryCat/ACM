#include <bits/stdc++.h>
using namespace std;

inline void solve(){
  int n, k;
  cin >> n >> k;
  if(k & 1) cout << "-1\n";
  else{
    if(4 * n >= 3 * k) cout << "3\n";
    else cout << "-1\n";
  }
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