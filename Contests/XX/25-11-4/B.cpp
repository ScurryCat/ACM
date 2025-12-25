#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;  

const int N = 1e5+9, mod = 998244353;

int n,k;
vector<ll> m,ans;

void qwq_(){
	cin>>k>>n;
  // for(int i=0;i<100;i++){
  //   m.push_back(pow(k,(ll)i));
  //   ll x=m[i];
  //   ans.push_back(x);
  //   for(int j=0;j<m.size()-1;j++){
  //     for(int k=0;k<j;k++){
  //       ans.push_back(x+m[j]);
  //     }
  //   }
  // }
  // sort(ans.begin(),ans.end());
  // for(int i=0;i<ans.size();i++) cout<<ans[i]<<' ';cout<<'\n';
  ll res=0;
  for(int i=0;i<10;i++){
    if(n&(1<<i)) res += pow(k,i);
  }
  cout<<res;
  // cout<<ans[n];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}