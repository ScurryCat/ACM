#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// void solve(){
//   ll n, x, y;
//   cin >> n >> x >> y;
//   ll res = 0, mn = 1e9, mx = 0, mxi, mni;
//   vector<int> a(n+1);
//   map<int, int> b;
//   for(int i=1; i<=n; i++){
//     cin >> a[i];
//     b[a[i]]++;
//     if(a[i] > n){
//       res += y;
//     }
//     if(a[i] >= mx){
//       mx = a[i];
//       mxi = i;
//     }
//     if(mn > a[i]){
//       mn = a[i];
//       mni = i;
//     }
//   }
//   int cur = 0;
//   for(auto z : b) cur = max(cur, z.second);
//   cout << min((mx - mn) * x + res, (n - cur) * y) << '\n';
// }

void solve(){
  ll n, x, y;
  cin >> n >> x >> y;
  vector<int> a(n);
  for(auto &it : a){
    cin >> it;
  }

  sort(a.begin(), a.end());

  int cur = 1, mx = 1;
  for(int i=1; i<n; i++){
    cur = (a[i] == a[i-1]) ? cur+1 : 1;
    mx = max(mx, cur);
  }
  ll res = (n - mx) * y;
  for(int i=1; i<=n; i++){
    res = min(res, a[i-1] * x + (n-i) * y);
  }
  cout << res << '\n';
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