#include <bits/stdc++.h>
using namespace std;

#define INF 0x7FFFFFFF
#define SUP 0x80000000

typedef long long ll;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;
typedef pair<int,int> PII;

const int N = 2e5+9;
const int M = 2e5+9;
const int mod = 998244353;

ll n,t,ans,cnt;
PII a[N];

bool cmp(PII x,PII y){
  return x.first>y.first;
}

void solve(){
	cin>>n>>t;
  for(int i=1;i<=n;i++){
    cin>>a[i].first;
    ans+=a[i].first;
  }
  for(int i=1;i<=n;i++){
    cin>>a[i].second;
  }
  sort(a+1,a+n+1,cmp);
  for(int i=1;i<=n;i++){
    for(int j=1;j<=a[i].second;j++){
      if(ans>=t){
        cout<<cnt;
        return;
      }
      ans+=a[i].first;
      cnt++;
    }
  }
  if(ans>=t) cout<<cnt;
  else cout<<-1;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int T = 1;
	// cin>>T;
	while(T--) solve();
	return 0;
}