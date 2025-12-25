#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 30, mod = 998244353;

int n,ans;    // 用n来存储点的个数，用ans来存储最大值
int w[N];     // 用数组w存储各地窖的地雷数
vector<int> e[N],cp,path; //用邻接表e来存储图，用path来存储答案路径，用cp来暂存当前路径

// 解法1，dfs搜索
void dfs(int u,int ww){
  if(ww>ans){
    ans=ww;
    path=cp;
  }
  for(auto v : e[u]){
    cp.push_back(v);
    dfs(v,ww+w[v]);
    cp.pop_back();
  }
}


// 解法2，dp递推
int dp[N];  // 数组dp用来存储以各点为终点时，最大能收集多少个地雷
void DP(){
  for(int i=1;i<=n;i++) dp[i]=w[i];
  for(int u=1;u<=n;u++){
    for(auto v : e[u]){
      dp[v]=max(dp[v],dp[u]+w[v]);
    }
  }
  for(int i=1;i<=n;i++) cout<<dp[i]<<' ';
}

void solve(){
  cin>>n; // 输入点的个数
  for(int i=1;i<=n;i++) cin>>w[i];
  for(int i=1;i<=n;i++){
    for(int j=i+1;j<=n;j++){
      int ok;
      cin>>ok;
      if(ok) e[i].push_back(j);
    }
  }

  // 解法1，dfs搜索
  for(int u=1;u<=n;u++){
    cp.push_back(u);
    dfs(u,w[u]);
    cp.clear();
  }
  for(auto x : path) cout<<x<<' ';
  cout<<'\n';
  cout<<ans;

  // 解法2，动态规划
  // cout<<'\n';
  // DP();
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) solve();

	return 0;
}