#include <bits/stdc++.h>
using namespace std;

#define INF 0x7FFFFFFF
#define SUP 0x80000000

typedef long long ll;
typedef unsigned long long ull;

const int N = 2e5+9;
const int M = 2e5+9;
const int mod = 998244353;

int n,m,ans;

// void solve(){
//   cin>>n;
//   vector<int> a(n),c,d;
//   vector<bool> b(n+1,0);
//   for(int i=0;i<n;i++){
//     cin>>a[i];
//     if(a[i]) b[a[i]]=true;
//   }
//   for(int i=0;i<n;i++){
//     if(!a[i]){
//       c.push_back(i);
//     }
//   }
//   for(int i=0;i<n;i++){
//     if(a[i]&&a[i]!=i+1){
//       d.push_back(i);
//     }
//   }
//   if(c.size()==1){
//     int idx=c[0],x=idx+1;
//     if(b[x]) d.push_back(idx);
//   }
//   else{
//     for(int idx:c){
//       d.push_back(idx);
//     }
//   }
//   if(d.empty()){
//     cout<<0<<'\n';
//   }
//   else{
//     int l=*min_element(d.begin(),d.end());
//     int r=*max_element(d.begin(),d.end());
//     cout<<r-l+1<<'\n';
//   }
// }

int a[N];
bool b[N];

void solve(){
  int cnt=0;
  cin>>n;
  memset(b,0,sizeof b);
  for(int i=1;i<=n;i++){
    cin>>a[i];
    if(a[i]) b[a[i]]=true;
    else cnt++;
  }
  ans=0;
  int l=1,r=n;
  while(a[l]==l&&l<r) l++;
  while(a[r]==r&&l<r) r--;
  if(a[l]==0&&cnt==1) l++;
  else ans=r-l+1; 
  cout<<ans<<'\n'; 
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    int T = 1;
    cin>>T;
    while(T--) solve();
    return 0;
}