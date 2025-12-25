#include <bits/stdc++.h>
using namespace std;

#define INF 0x7FFFFFFF
#define SUP 0x80000000

typedef long long ll;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;

const int N = 2e4+9;
// int A[N],B[N];
// int la,lb;
VI a,b;

// 2^15000-1

void mul(VI a,VI b,VI &c){
  VI r(N,0);
  for(int i=0;i<a.size();i++){
    for(int j=0;j<b.size();j++){
      r[i+j] += a[i]*b[j];
      r[i+j+1] += r[i+j] / 10;
      r[i+j] %= 10;
    }
  }
  while(r.size()&&r[r.size()-1]==0) r.pop_back();
  c=r;
}

void solve(){
  int n; cin>>n;
  // A[0]=1; B[0]=2;
  a.push_back(1),b.push_back(2);
  while(n){
    if(n&1) mul(a,b,a);
    mul(b,b,b);
    n >>= 1;
  }
  for(int i=0;i<a.size();i++){
    if(a[i]==0) a[i]=9,a[i+1]--;
    else{
      a[i]--;
      break;
    }
  }
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