#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;  

const int N = 1e5+9, mod = 998244353;

struct st{
  string name;
  int av,py,l;
  char g,p;
}a[N];

int n,mx,tot;
string name;

void qwq_(){
	cin>>n;
  for(int i=1;i<=n;i++){
    cin>>a[i].name>>a[i].av>>a[i].py>>a[i].g>>a[i].p>>a[i].l;
    int x=0;
    if(a[i].av>80&&a[i].l) x+=8000;
    if(a[i].av>85&&a[i].py>80) x+=4000;
    if(a[i].av>90) x+=2000;
    if(a[i].av>85&&a[i].p=='Y') x+=1000;
    if(a[i].py>80&&a[i].g=='Y') x+=850;
    tot+=x;
    if(x>mx){
      mx=x;
      name=a[i].name;
    }
  }
  cout<<name<<'\n'<<mx<<'\n'<<tot;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}