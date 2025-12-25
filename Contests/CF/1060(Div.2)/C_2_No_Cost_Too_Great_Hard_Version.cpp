#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

const int N = 2e5+9, mod = 998244353;

int pri[N];
bool ok;

void decompose(int x){
  for(int i=2;i*i<=x;i++){
		if(x%i==0&&pri[i]){
			ok=true;
		}
    while(x%i==0){
			pri[i]++,x/=i;
		}
  }
  if(x>1){
		if(pri[x]) ok=true;
		pri[x]++;
	}
}

void decompose2(int x){
  for(int i=2;i*i<=x;i++){
    if(x%i==0){
      if(pri[i]){ 
				ok=true;  
			}
      while(x%i==0) x/=i;
    }
  }
  if(x>1&&pri[x]){
    ok=true;
  }
}

bool cmp(pair<int,int> x,pair<int,int> y){
	return x.second<y.second;
}

void solve(){
	int n;
	ll ans=2e9;
	cin>>n;
	vector<pair<int,int>> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i].first;
	}
	for(int i=0;i<n;i++){
		cin>>a[i].second;
	}
	sort(a.begin(),a.end(),cmp);
	memset(pri,0,sizeof pri);
	ok=false;
	for(int i=0;i<n;i++){
		decompose(a[i].first);
		if(ok){
			cout<<"0\n";
			return;
		}
	}
	for(int i=0;i<n;i++){
		decompose2(a[i].first+1);
		if(ok){
			ans = min(ans,(ll)a[i].second);
		}
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	cin >> yyy;
	while(yyy--) solve();
	return 0;
}