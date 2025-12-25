#include <bits/stdc++.h>
using namespace std;

#define INF 0x7FFFFFFF
#define SUP 0x80000000

typedef long long ll;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;

const int N = 209;

// for(LinkList p=L,int j=0;p&&j+1<i;p=p->next,++j);
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

void solve(){
  int n; cin>>n;
  VI a(1,1), b(1,2);
  while(n){
    if(n&1) mul(a,b,a);
    mul(b,b,b);
    n >>= 1;
  }
  for(int i=0;i<a.size();i++){
    if(a[i]<=0) a[i]=9,a[i+1]--;
    else{
      a[i]--;
      break;
    }
  }
  VI c(1,2);
  mul(a,c,a);
  for(int i=a.size()-1;~i;i--) cout<<a[i];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int T = 1;
	// cin>>T;
	while(T--) solve();
	return 0;
}