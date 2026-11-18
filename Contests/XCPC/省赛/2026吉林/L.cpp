#include <bits/stdc++.h>
using namespace std;

inline void solve(){
  vector<int> cnt(17), f(17);
  for(int i=0; i<17; i++){
    int idx;
    string s; cin >> s;
    if(s == "SJ" || s == "BJ" || s == "2") continue;
    if(s == "10") cnt[10]++;
    else if(s == "J") cnt[11]++;
    else if(s == "Q") cnt[12]++;
    else if(s == "K") cnt[13]++;
    else if(s == "A") cnt[14]++;
    else cnt[s[0] - '0']++;
  }

  int ans = 0;
  for(int i=3; i<=14; i++){
    if(cnt[i]) f[i] = f[i-1] + 1;
    if(f[i] >= 5) ans = max(ans, f[i]);
  }

  cout << ans << '\n';
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