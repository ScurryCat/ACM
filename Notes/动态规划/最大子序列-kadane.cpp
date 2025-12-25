#include <bits/stdc++.h>
using namespace std;

int kadane(vector<int> &a){
  int r=a[1], mx=a[1];
  for(int i=2;i<a.size();i++){
    mx = max(mx+a[i], a[i]);
    r = max(r, mx);
  }
  return r;
}

int main(){
  int n; 
  cin >> n;
  vector<int> a(n+1);
  for(int i=1;i<=n;i++) cin >> a[i];
  cout << kadane(a);
  return 0;
}