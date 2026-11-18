#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 128;

int n;
double vic[N][N], f[N][N];

inline void solve(){
  memset(f, 0, sizeof f);
  int m = 1 << n;
  for(int i=0; i<m; i++){
    for(int j=0; j<m; j++){
      cin >> vic[i][j];
    }
  }
  for(int i=0; i<m; i++){
    f[0][i] = vic[i][i ^ 1];
    // cout << f[0][i] << ' ';
  }

  for(int i=1; i<n; i++){
    for(int j=0; j<m; j++){
      for(int k=0; k<m; k++){
        if((j >> i) == ((k >> i) ^ 1)){
          f[i][j] += f[i-1][j] * f[i-1][k] * vic[j][k];
        }
      }
    }
  }

  // for(int i=0; i<n; i++){
  //   for(int j=0; j<m; j++){
  //     cout << f[i][j] << " \n"[j == m - 1];
  //   }
  // }

  pair<int, double> ans = {0, 0};
  for(int i=0; i<m; i++){
    if(f[n-1][i] > ans.second) ans = {i+1, f[n-1][i]};
  }

  cout << ans.first << '\n';

}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  while(cin >> n){
    if(~n) solve();
    else break;
  }

  return 0;
}