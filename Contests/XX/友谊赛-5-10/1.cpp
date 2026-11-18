#include <iostream>

using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  int n;
  while(cin >> n){
    long long r = 0;
    for(int i=1;i<=n;i++) r+=i;
    cout<<r<<'\n';
  }
  return 0;
}