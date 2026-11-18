#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

const int N = 1e6+9, mod = 100003;

int n,m,ans;
int vis[N];
int d[N];
vector<int> e[N];

// int bfs(int x){
//   // if(d[x]) return d[x];
//   ans=0;
//   memset(vis,0,sizeof vis);
//   int cnt=(1<<31)-1;
//   queue<pair<int,int>> q;
//   q.push({1,0});
//   while(q.size()){
//     int u=q.front().first;
//     int cur=q.front().second;
//     q.pop();
//     if(u==x){
//       if(cnt>=cur) cnt=cur;
//       else return ans;
//       ans++;
//       ans%=mod;
//       continue;
//     }
//     vis[u]=1;
//     for(auto v : e[u]){
//       if(vis[v]) continue;
//       q.push({v,cur+1});
//     }
//   }
// }

// int bfs(int x){
//   if(~d[x]) return d[x];
//   memset(vis,0,sizeof vis);
//   queue<int> q;
//   q.push(x);
//   int cur=(1<<31)-1,cnt=0;
//   while(q.size()){
//     int u=q.front();
//     q.pop();
//     for(auto v : e[u]){
//       if(vis[v]) continue;
//       vis[v]=1;
//       q.push(v);
//       if(d[v]>=0&&d[v]<cur){
//         cur=d[v];
//         cnt=max(cnt,(int)count(e[u].begin(),e[u].end(),v));
//       }
//       else if(d[v]>=0&&d[v]==cur){
//         cur+=d[v];
//         cnt=max(cnt,(int)count(e[u].begin(),e[u].end(),v));
//       }
//       else{
//         return d[u]=cnt*cur%mod;
//       }
//     }
//   }
//   return d[x]=cnt*cur%mod;
// }

priority_queue<pair<int,int>> q;

void Dijkstra(int s){
  memset(d,127,sizeof d);
  d[s]=1;
}

void solve(){
	cin>>n>>m;
  for(int i=1;i<=m;i++){
    int u,v;
    cin>>u>>v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  memset(d,255,sizeof d);
  d[1]=1;
  Dijkstra(1);
  for(int i=1;i<=n;i++){
    // cout<<bfs(i)<<'\n';
    cout<<d[i]<<'\n';
  }
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) solve();
	return 0;
}