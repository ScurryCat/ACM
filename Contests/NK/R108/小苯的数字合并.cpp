#include <bits/stdc++.h>
using namespace std;

#define INF 0x7FFFFFFF
#define SUP 0x80000000

typedef long long ll;
typedef unsigned long long ull;

const int N = 5e3+9;
const int M = 2e5+9;
const int mod=998244353;

int n,m;
int a[N];

void solve(){
  cin>>n;
  for(int i=0;i<n;i++) cin>>a[i];
  set<vector<ll>> st;
  int t=1<<(n-1);
  for(int i=0;i<t;i++){
    vector<ll> ans;
    ll sum=a[0];
    for(int j=0;j<n-1;j++){
      if(i&(1<<j)){
        ans.push_back(sum);
        sum=a[j+1];
      }
      else{
        sum+=a[j+1];
      }
    }
    ans.push_back(sum);
    st.insert(ans);
  }
  cout<<st.size()%mod<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int T = 1;
	cin>>T;
	while(T--) solve();
	return 0;
}