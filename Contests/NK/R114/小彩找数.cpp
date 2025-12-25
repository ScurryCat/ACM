#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

void solve(){
	VI a(3);
  cin>>a[0]>>a[1]>>a[2];
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      if(a[j]==i+1){
        cout<<j+1<<' ';
        break;
      }
    }
  }
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) solve();
	return 0;
}