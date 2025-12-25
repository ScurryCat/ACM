#include <bits/stdc++.h>
using namespace std;

#define INF 0x7FFFFFFF
#define SUP 0x80000000

typedef long long ll;
typedef unsigned long long ull;

const int N = 1e5+9;
const int M = 2e5+9;
const int mod = 998244353;

int n,m,ans;
string today[]={"Monday","Tuesday","Wednesday","Thursday","Friday"};
int b[]={4,3,2,1,0};

void solve(){
  ll yy,mm,dd;
  string s;
	cin>>yy>>mm>>dd>>s;
  if(s=="Monday") n=0;
  else if(s=="Tuesday") n=1;
  else if(s=="Wednesday") n=2;
  else if(s=="Thursday") n=3;
  else n=4;
  ll day=(yy*12+mm)*30+dd;
  ll y,m,d;
  cin>>y>>m>>d;
  ll day2=(y*12+m)*30+d;
  if(dd>d) cout<<today[((n-(dd-d)%5)+5)%5]<<'\n';
  else cout<<today[((n+(d-dd)%5)+5)%5]<<'\n';
  // if(day<day2){
  //   cout<<today[(day2-day+n)%5]<<'\n';
  // }
  // else{
  //   cout<<today[b[(day-day2+n)%5]]<<'\n';
  // }
  // if(abs(day-day2)%5==0) cout<<s<<'\n';
  // else if(day>day2) cout<<today[5-((day-day2+n)%5)]<<'\n';
  // else cout<<today[(day2-day+n)%5]<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    int T = 1;
    cin>>T;
    while(T--) solve();
    return 0;
}