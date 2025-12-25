#include <bits/stdc++.h>
using namespace std;

#define INF 0x7FFFFFFF
#define SUP 0x80000000

typedef long long ll;
typedef unsigned long long ull;

const int N = 5e2+9;
const int M = 2e5+9;
const int mod = 998244353;

int n,m,ans;
char ma[N][N];

// 双端队列BFS
// 更优解从队头入队，不优的从队尾入队，保证先算最优解
bool vis[N][N];
int price[N][N];
// int dx[]={0,1,0,-1};
// int dy[]={1,0,-1,0};

// 错误做法，按照格点走
// void bfs(){
//   deque<pair<int,int>> dq;
//   dq.push_front({1,1});
//   while(dq.size()){
//     auto p=dq.front();
//     dq.pop_front();
//     int x=p.first,y=p.second;
//     if(x==n&&y==m){
//       cout<<price[x][y]<<'\n';
//       return ;
//     }
//     for(int i=0;i<4;i++){
//       int xx=x+dx[i],yy=y+dy[i];
//       if(xx<1||xx>n||yy<1||yy>m) continue;
//       if(vis[xx][yy]) continue;
//       vis[xx][yy]=true;
//       price[xx][yy]=price[x][y]+(ma[xx][yy]=='\\'?0:1);
//       if(ma[xx][yy]=='\\') dq.push_front({xx,yy});
//       else dq.push_back({xx,yy});
//     }
//   }
// }


char es[]="\\/\\/";
int dx[]={-1,1,1,-1},dy[]={-1,-1,1,1};
int ex[]={-1,0,0,-1},ey[]={-1,-1,0,0};    // 格子增量，用来判断是否联通

// 正确做法，按照对角线走
// 每个格点只会走一次，时间复杂度O(nm)
void bfs(){
  memset(price,-1,sizeof price);
  price[0][0]=0;
  deque<pair<int,int>> dq;
  dq.push_back({0,0});
  while(dq.size()){
    pair<int,int> u=dq.front();
    dq.pop_front();
    int x=u.first,y=u.second;
    if(vis[x][y]) continue;
    vis[x][y]=true;
    for(int i=0;i<4;i++){
      int xx=x+dx[i],yy=y+dy[i];
      if(xx<0||xx>n||yy<0||yy>m) continue;
      int gx=x+ex[i],gy=y+ey[i];
      int p=price[x][y]+(ma[gx][gy]!=es[i]);
      if(p<price[xx][yy]||price[xx][yy]==-1){
        price[xx][yy]=p;
        if(ma[gx][gy]!=es[i]) dq.push_back({xx,yy});
        else dq.push_front({xx,yy});
      }
    }
  }
}

void solve(){
	cin>>n>>m;
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      cin>>ma[i][j];
  bfs();
  if(price[n][m]==-1) cout<<"NO SOLUTION";
  else cout<<price[n][m];
  // for(int i=0;i<4;i++){
  //   cout<<es[i]<<' ';
  //   printf("(%d,%d) ",0+dx[i],0+dy[i]);
  //   printf("(%d,%d)\n",0+ex[i],0+ey[i]);
  // }
  // for(int i=0;i<=n;i++){
  //   for(int j=0;j<=m;j++) 
  //     cout<<price[i][j]<<' ';
  //   cout<<'\n';
  // }
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int T = 1;
	// cin>>T;
	while(T--) solve();
	return 0;
}