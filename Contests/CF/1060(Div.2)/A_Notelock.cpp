#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

void solve(){
	int n,k,ans=0;
  cin>>n>>k;
  string s;
  cin>>s;
  for(int i=0,pos=-k;i<n;i++){
    if(s[i]=='1'){
      if(i-pos+1>k){
        ans++;
      }
      pos=i;
    }
  }
  cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	cin >> yyy;
	while(yyy--) solve();
	return 0;
}