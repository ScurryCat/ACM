#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

void solve(){
	int n;  cin>>n;
  VI a(101,0);
  for(int i=0;i<n;i++){
    int x;  cin>>x;
    a[x]++;
  }
  for(int i=0;i<=100;i++){
    if(!a[i]){
      cout<<i<<'\n';
      return;
    }
  }
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	cin >> yyy;
	while(yyy--) solve();
	return 0;
}