#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int N = 4e5+9, mod = 998244353;
using ll = long long; using ld = long double; using i128 = __int128; int t_ = 1;

#ifndef ONLINE_JUDGE
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {os << "["; for(int i=0; i<v.size(); i++) os << (i?", ":"") << v[i]; return os << "]";}
template<typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& p) {return os << "(" << p.first << ", " << p.second << ")";}
void debug_out(vector<string> names, int idx) { cerr << endl;} template <typename Head, typename... Tail>
void debug_out(vector<string> names, int idx, Head H, Tail... T) {if (idx > 0) cerr << ", ";string name = names[idx]; name.erase(0, name.find_first_not_of(' ')); name.erase(name.find_last_not_of(' ') + 1);cerr << name << "=" << H;debug_out(names, idx + 1, T...);}
#define debug(...) {string _s = #__VA_ARGS__, _tmp; vector<string> _names; int _p = 0;for (char c : _s) {if (c == '(' || c == '{') _p++;else if (c == ')' || c == '}') _p--;else if (c == ',' && _p == 0) { _names.push_back(_tmp); _tmp = "";continue;}_tmp += c;} _names.push_back(_tmp);cerr << "T" << t_<< " Line " << __LINE__ << ": "; debug_out(_names, 0, __VA_ARGS__);}
#else
#define debug(...)
#endif

int n,m;
int h[N],to[N],w[N],ne[N],tot=1;
ll d[N<<1];

inline void add(int u,int v,int ww){
  to[++tot]=v; w[tot]=ww; ne[tot]=h[u]; h[u]=tot;
}

inline void dijk(int s){
  memset(d,0x3f,sizeof d);
  d[s]=0;
  priority_queue<pair<ll,int>> q;
  q.push({0,s});
  while(q.size()){
    int u=q.top().second;
    q.pop();
    for(int i=h[u<=n?u:u-n];i;i=ne[i]){
      ll v=to[i], ww=w[i];
      if(u<=n){
        if(d[v]>d[u]+ww){
          d[v]=d[u]+ww;
          q.push({-d[v],v});
        }
        if(d[v+n]>d[u]+ww/2){
          d[v+n]=d[u]+ww/2;
          q.push({-d[v+n],v+n});
        }
      }
      else{
        if(d[v+n]>d[u]+ww){
          d[v+n]=d[u]+ww;
          q.push({-d[v+n],v+n});
        }
      }
    }
  }
}

inline void qwq_(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
    int u,v,ww;
    cin>>u>>v>>ww;
    add(u,v,ww);
  }
  dijk(1);
  if(d[n]==0x3f3f3f3f3f3f3f3f) cout<<-1;
  else cout<<min(d[n],d[n+n]);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--){
		qwq_();
		t_+=1;
	}
	return 0;
}