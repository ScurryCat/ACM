#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2e5+9;

int n;
char s[N];

inline void solve(){
  cin >> n;
  for(int i=1; i<=n; i++){
    cin >> s[i];
  }
  vector<int> a, b;
  int a1 = 3, a2 = 2;
  int b1 = 1, b2 = 4;
  a.push_back(1);
  b.push_back(2);
  for(int i=1; i<=n; i++){
    if(s[i] == '1'){
      if(a.back() & 1){
        a.push_back(a2);
        a2 += 2;
      }
      else{
        a.push_back(a1);
        a1 += 2;
      }
      if(b.back() & 1){
        b.push_back(b2);
        b2 += 2;
      }
      else{
        b.push_back(b1);
        b1 += 2;
      }
    }
    else{
      if(!(a.back() & 1)){
        a.push_back(a2);
        a2 += 2;
      }
      else{
        a.push_back(a1);
        a1 += 2;
      }
      if(!(b.back() & 1)){
        b.push_back(b2);
        b2 += 2;
      }
      else{
        b.push_back(b1);
        b1 += 2;
      }
    }
  }
  vector<int> ans;
  int f1=0, f2=0, c = 0;
  for(int i=0; i<n; i++){
    if(a[i] < b[i]) c = 1;
    if(a[i] > n) f1 = 1;
    if(b[i] > n) f2 = 1;
  }
  if(f1 && f2){
    cout << -1;
    return;
  }
  if(f1) ans = b;
  else if(f2) ans = a;
  else{
    if(c) ans = a;
    else ans = b;
  }
  for(int i=0; i<n; i++) cout << ans[i] << ' ';
}

int main(){

  solve();

  return 0;
}