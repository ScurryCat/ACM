#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

void solve(){
	string s;
  cin>>s;
  ll l = s.size();
  for(int i=0;i<l;i++){
    if(i==(l-1)/2) continue;
    cout<<s[i];
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