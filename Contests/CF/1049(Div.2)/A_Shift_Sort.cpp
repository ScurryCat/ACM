#include <bits/stdc++.h>
using namespace std;

#define INF 0x7FFFFFFF
#define SUP 0x80000000

typedef long long ll;
typedef unsigned long long ull;

const int N = 1e5+9;
const int M = 2e5+9;
const int mod = 998244353;

int n,m,ans;

void solve(){
	cin>>n;
  string s;
  s.resize(n);
  int cnt=0;
  for(int i=0;i<n;i++){
    cin>>s[i];
    if(s[i]=='1') cnt++;
  }
  ans=0;
  for(int i=0,j=n-1;i<j;i++,j--){
    while(s[i]=='0'&&i<j) i++;
    while(s[j]=='1'&&j>i) j--;
    if(s[i]=='1'&&s[j]=='0') ans++;
  }
  cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int T = 1;
	cin>>T;
	while(T--) solve();
	return 0;
}
