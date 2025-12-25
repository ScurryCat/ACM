#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

void solve(){
	int n;
  ll ans=0;
  cin>>n;
  string s;
  s.resize(n);
  for(int i=0;i<n;i++){
    cin>>s[i];
  }

  for(int i=0;i<n;i++){
    int cnt[4]={0};
    for(int j=i;j<n;j++){
      cnt[s[j]-'0']++;
      // cout<<cnt[1]<<' '<<cnt[2]<<' '<<cnt[3]<<'\n';
      if(cnt[1]==cnt[2]&&cnt[2]==cnt[3]&&cnt[1]){
        ans++;
      }
    }
  }
  cout<<ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) solve();
	return 0;
}