#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll k,n,c=0;
    cin>>k>>n;
    while(k){
			c=c*10+9;
			k--;
		}
    if(n%c) cout<<"baka\n";
    else cout<<"aya\n";
}

int main(){
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}