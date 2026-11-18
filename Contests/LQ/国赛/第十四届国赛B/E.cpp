#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e6+9;

inline bool cmp(pair<int,int> x, pair<int,int> y){
  if(x.first != y.first) return x.first < y.first;
  return x.second < y.second;
}

inline void solve(){
  int n; cin >> n;
  vector<pair<int, int>> p(n+1);

  for(int i=1; i<=n; i++){
    cin >> p[i].first >> p[i].second;
  }

  int ans = 0;
  vector<double> a(3);
  for(int i=1; i<=n; i++){
    int x1 = p[i].first, y1 = p[i].second;
    for(int j=i+1; j<=n; j++){
      if(j > n) break;
      int x2 = p[j].first, y2 = p[j].second;
      for(int k=j+1; k<=n; k++){
        if(k > n) break;
        int x3 = p[k].first, y3 = p[k].second;

        a[0] = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        a[1] = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
        a[2] = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));

        sort(a.begin(), a.end());

        if(a[0] + a[1] > a[2] && a[2] - a[1] < a[0] && a[0] == a[1] || a[1] == a[2] || a[0] == a[2]){
          // cout << "(" << x1 << "," << y1 << ") " << "(" << x2 << "," << y2 << ") " << "(" << x3 << "," << y3 << ") ";
          // for(int ii=0; ii<3; ii++) cout << a[ii] << ' '; cout << '\n';
          ans++;
        }
      }
    }
  }

  cout << ans;

}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int t = 1;
  // cin >> t;
  while(t--){
    solve();
  }

  return 0;
}