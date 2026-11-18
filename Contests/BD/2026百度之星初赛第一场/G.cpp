#include <bits/stdc++.h>
using namespace std;

int n, m, cnt, mx, id, ok;

void solve(){
  cin >> n;
  vector<int> a(n);
  for(int i=0; i<n; i++){
    cin >> a[i];
    if(a[i] * 2 >= n){
      cout << i + 1;
      return;
    }
    if(a[i] != -1) cnt += a[i];
    else m++;
    if(mx < a[i]){
      mx = a[i];
      id = i + 1;
      ok = 1;
    }
    else if(mx == a[i]){
      ok = 0;
    }
  }
  if(mx + cnt >= n) cout << id;
  else{
    if(n - cnt + m > m * mx){
      for(int i=0; i<n; i++){
        if(a[i] == -1){
          cout << i + 1 << ' ';
        }
      }
    }
    else if(ok){
      for(int i=0; i<n; i++){
        if(a[i] == -1 || a[i] == mx){
          cout << i + 1 << ' ';
        }
      }
    }
    else{
      for(int i=0; i<n; i++){
        if(a[i] == -1){
          cout << i + 1 << ' ';
        }
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}