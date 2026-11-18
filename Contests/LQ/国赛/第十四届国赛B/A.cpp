#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e6+9;

int cnt[11];
ll ans;
string s;

int stk[5], idx;

inline void solve(){
  for(int i=1; i<=2023; i++){
    int n = i;
    while(n){
      // cnt[n%10]++;
      // if(n%10 == 3){
      //   ans += cnt[0]
      // }
      stk[++idx] = n % 10;
      n /= 10;
    }
    while(idx) s += stk[idx--] + '0';
    // cout << i << ": " << cnt[0] << ' ' << cnt[2] << ' ' << cnt[3] << '\n';
  }

  for(int i=0; i<s.size(); i++){
    if(s[i] == '3'){
      for(int j=0; j<i; j++){
        if(s[j] == '0'){
          int l = 0, r = 0;
          for(int k=0; k<j; k++){
            if(s[k] == '2'){
              l++;
            }
          }
          for(int k=j+1; k<i; k++){
            if(s[k] == '2'){
              r++;
            }
          }
          ans += l * r;
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