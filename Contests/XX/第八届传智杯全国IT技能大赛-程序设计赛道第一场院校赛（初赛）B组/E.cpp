#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

void qwq_(){
	int n; cin>>n;
	vector<pair<int,int>> p(n+1), ans(n+1);
  for(int i=1;i<=n;i++) cin >> p[i].first >> p[i].second;
  sort(p.begin()+1,p.begin()+n+1);
  for(int i=1;i<=n;i++){
    ans[i].first=p[i].first;
    ans[i].second=max(ans[i-1].second,p[i].second);
  }
  int q; cin>>q;
  while(q--){
    int x; cin>>x;
    if(x<p[1].first){
      cout<<"-1\n";
      continue;
    }
    int l=0,r=n+1,mid;
    while(l+1<r){
      mid=l+r>>1;
      if(ans[mid].first<=x) l=mid;
      else r=mid;
    }
    cout<<ans[l].second<<'\n';
  }
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}