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
string s;

// 时间复杂度8！
// 利用map剪枝
unordered_map<string,string> h;

void print(string str){
  cout<<h[str].size()<<'\n';
  for(int i=0,j=1;i<h[str].size();i++,j++){
    if(j%60==0) cout<<'\n';
    cout<<h[str][i];
  }
}

string op1(string str){
  swap(str[0],str[7]);
  swap(str[1],str[6]);
  swap(str[2],str[5]);
  swap(str[3],str[4]);
  return str;
}

string op2(string str){
  swap(str[0],str[3]);
  swap(str[1],str[2]);
  swap(str[1],str[3]);
  swap(str[7],str[4]);
  swap(str[6],str[5]);
  swap(str[6],str[4]);
  return str;
}

string op3(string str){
  swap(str[1],str[2]);
  swap(str[5],str[6]);
  swap(str[1],str[5]);
  return str;
}

void bfs(){
  queue<string> q;
  q.push({"12345678"});
  while(q.size()){
    string str=q.front(),to;
    q.pop();
    if(str==s){
      print(str);
      return ;
    }
    to=op1(str);
    if(h[to].empty()) h[to]=h[str]+'A',q.push(to);
    to=op2(str);
    if(h[to].empty()) h[to]=h[str]+'B',q.push(to);
    to=op3(str);
    if(h[to].empty()) h[to]=h[str]+'C',q.push(to);
  }
}

void solve(){
  s.resize(8);
	for(int i=0;i<=7;i++) cin>>s[i];
  bfs();
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int T = 1;
	// cin>>T;
	while(T--) solve();
	return 0;
}
