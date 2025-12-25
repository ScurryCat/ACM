#include <bits/stdc++.h>
using namespace std;

void solve(){
  string s;
  cin>>s;
  int a=0,b=0;
  bool ok=true;
  for(int i=0;i<s.size();i++){
    if(s[i]=='(') a++;
    else if(s[i]==')'){
      if(a>0) a--;
      else if(b>0){
        b--;
      }
      else{
        ok=false;
        break;
      }
    }
    else b++;
  }
  if(a){
    if(b<a) ok=false;
  }
  if(ok) cout<<"true";
  else cout<<"false";
}

int main(){
  ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

  int qaq=1;
  // cin>>qaq;
  while(qaq--) solve();
  return 0;
}