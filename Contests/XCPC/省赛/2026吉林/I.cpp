#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 3e5+9;

int stk[N];

inline void solve(){
  int n; cin>>n;
  int idx = 0;
  vector<int> cnt(n+1);
  for(int i=1;i<=n+n;i++){
    int x; cin>>x;
    cnt[x]++;
  }
  vector<int> a;
  for(int i=1;i<=n;i++){
    if(cnt[i]){
      if(cnt[i]==1){
        stk[++idx] = i;
      }
      else{
        for(int j=1;j<=cnt[i];j++){
          if(j == 1){
            a.push_back(i);
            j++;
            continue;
          }
          if(idx){
            a.push_back(stk[idx--]);
          }
          else{
            if(j+2 <= cnt[i]){
              a.push_back(i);
              j++;
            }
            else stk[++idx] = i;
          }
        }
      }
    }
  }

  while(idx) a.push_back(stk[idx--]);

  if(a.size() > n){
    cout << "NO\n";
    return;
  }

  cout << "YES\n";
  for(int x : a) cout << x << ' '; cout << '\n';
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