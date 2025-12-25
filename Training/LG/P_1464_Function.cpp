#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll ans[21][21][21];

int fun(ll a,ll b,ll c){
  if(a<=0||b<=0||c<=0) return 1;
  if(a>20||b>20||c>20) return fun(20,20,20);
  if(ans[a][b][c]) return ans[a][b][c];
  if(a<b&&b<c) return ans[a][b][c]=fun(a,b,c-1)+fun(a,b-1,c-1)-fun(a,b-1,c);
  return ans[a][b][c]=fun(a-1,b,c)+fun(a-1,b-1,c)+fun(a-1,b,c-1)-fun(a-1,b-1,c-1);
}

void solve(){
	ll a,b,c;
  while(scanf("%lld%lld%lld",&a,&b,&c)){
    if(a==-1&&a==b&&b==c) return;
    printf("w(%lld, %lld, %lld) = %lld\n",a,b,c,fun(a,b,c));
  }
}

int main(){
	int yyy = 1;
	// yyy = read();
	while(yyy--) solve();
	return 0;
}