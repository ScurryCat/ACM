#include <bits/stdc++.h>
using namespace std;



int main(){
  int n,m;
  cin>>n>>m;
  vector<int> bitset((n+31)/32);
  for(int i=1;i<=m;i++){
    int x;
    cin>>x;
    bitset[x/32]|=1<<(x%32);
  }
  for(int i=0;i<=n;i++){
    if(bitset[i/32]&1<<(i%32)) cout<<i<<' ';
    //else cout<<"0 ";
  }
  return 0;
}