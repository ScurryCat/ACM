#include <bits/stdc++.h>
using namespace std;

#define INF 0x7FFFFFFF
#define SUP 0x80000000

typedef long long ll;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;

const int N = 1e5+9;
const int M = 2e5+9;
const int mod = 998244353;

int n,m;

// Kato_Shoko
void solve(){
	cin>>n;
  char s[n],cmp[]={"Kato_Shoko"};
  int cnt[300]={0};
  for(int i=0;i<10;i++){
    cnt[cmp[i]]++;
  }
  for(int i=0;i<n;i++){
    cin>>s[i];
    cnt[s[i]]++;
  }
  bool ok=true;
  for(int i=0;i<10;i++){
    if(cnt[cmp[i]]==1) ok=false;
  }
  if(ok){
    cout<<"YES "<<n-10<<'\n';
  }
  else cout<<"NO\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int T = 1;
	// cin>>T;
	while(T--) solve();
	return 0;
}