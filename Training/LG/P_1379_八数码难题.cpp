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
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
string s;
unordered_map<string,int> d;
queue<string> q;

int bfs(){
  q.push(s);
  string end="123804765";
  while(!q.empty()){
    string str=q.front();
    q.pop();
    if(str==end) return d[str];
    int p=str.find('0');
    int x=p/3,y=p%3;
    for(int i=0;i<4;i++){
      int xx=x+dx[i],yy=y+dy[i];
      if(xx<0||xx>2||yy<0||yy>2) continue;
      int dis=d[str];
      swap(str[p],str[3*xx+yy]);
      if(!d.count(str)) d[str]=dis+1,q.push(str);
      swap(str[p],str[3*xx+yy]);
    }
  }
}

void solve(){
  cin>>s;
  cout<<bfs();
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int T = 1;
	// cin>>T;
	while(T--) solve();
	return 0;
}
