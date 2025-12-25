#include <bits/stdc++.h>
using namespace std;

#define INF 0x7FFFFFFF
#define SUP 0x80000000

typedef long long ll;
typedef unsigned long long ull;

const int N = 1e5+9;
const int M = 1e5;
const int mod = 998244353;

int n,m,ans;
int dx[]={1,-1};

// struct aaa{int x,t;};
// bool vis[N];
// int bfs(){
//   queue<aaa> q;
//   q.push({n,0});
//   while(!q.empty()){
//     auto k=q.front();
//     q.pop();
//     vis[k.x]==true;
//     if(k.x==m) return k.t;
//     for(int i=0;i<2;i++){
//       int x=k.x+dx[i],t=k.t+1;
//       if(x<=0||x>m) continue;
//       if(vis[x]) continue;
//       q.push({x,t});
//     }
//     int x=k.x+k.x,t=k.t+1;
//     if(x<=0||x>m) continue;
//     if(vis[x]) continue;
//     q.push({x,t});
//   }
// }

// 时间复杂度O(N)
int dis[N];   // 剪枝
int bfs(){
  memset(dis,-1,sizeof dis);
  dis[n]=0;
  queue<int> q;
  q.push(n);
  while(q.size()){
    int x=q.front();
    q.pop();
    if(x==m) return dis[x];
    if(x+1<M&&!(~dis[x+1])){
      dis[x+1]=dis[x]+1;
      q.push(x+1);
    }
    if(x-1>0&&!(~dis[x-1])){
      dis[x-1]=dis[x]+1;
      q.push(x-1);
    }
    if(x+x<M&&!(~dis[x+x])){
      dis[x+x]=dis[x]+1;
      q.push(x+x);
    }
  }
}

void solve(){
	cin>>n>>m;
  cout<<bfs()<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int T = 1;
	cin>>T;
	while(T--) solve();
	return 0;
}
