#include <bits/stdc++.h>
using namespace std;

#define INF 0x7FFFFFFF
#define SUP 0x80000000

typedef long long ll;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;

const int N = 10009;
const int M = 2e5+9;
const int mod = 998244353;

void mul(VI a,VI b,VI &c){
  VI d(a.size()+b.size());
  for(int i=0;i<a.size();i++){
    for(int j=0;j<b.size();j++){
      d[i+j] += a[i] * b[j];
      d[i+j+1] += d[i+j]/10;
      d[i+j] %= 10;
    }
  }
  while(d.size()&&d[d.size()-1]==0) d.pop_back();
  c=d;
}

unsigned long long fun(unsigned long long i){
  if(i==1) return 1;
  return i*(fun(i-1));
}

int a[]={1,2,6,4,2,2,4,2,8,8,8,6,8,2,8,8,6,8,2,4,8,4,4,6,6,2,8,6,4,2,6,4,2,4,6,4,8,8,2,6,6,2,4,6,4,2,8,8,2,2};

void solve(){
  int n; cin>>n;
  // VI a(1,1);
  // for(int i=1;i<=n;i++){
  //   VI b(1,i);
  //   mul(a,b,a);
  // }
  // for(int i=0;i<a.size();i++){
  //   if(a[i]){
  //     cout<<a[i]<<'\n';
  //     break;
  //   }
  // }
  for(unsigned long long i=1;i<=(unsigned long)n;i++){
    unsigned long long x=fun(i);
    while(x%10==0) x/=10;
    cout<<x%10<<',';
  }
  // cout<<a[(n%50)-1]<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int T = 1;
	// cin>>T;
	while(T--) solve();
	return 0;
}