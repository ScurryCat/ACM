#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

int n, ans;
vector<int> num;
vector<int> a;

void dfs(int m,int s,int p){
  if(s>n) return;
  if(p==10 && s==n){
    ans++;
    for(auto x : num) a.push_back(x);
    return;
  }

  for(int i=1;i<=3;i++){
    num.push_back(i);
    dfs(i,s+i,p+1);
    num.pop_back();
  }
}

void qwq_(){
	cin>>n;
  if(n<10 || n>30){
    cout<<0;
    return;
  }
  dfs(0,0,0);
  cout<<ans<<'\n';
  for(int i=0,j=0;i<a.size();i++,j++){
    if(j && j%10==0) cout<<'\n';
    cout<<a[i]<<' ';
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