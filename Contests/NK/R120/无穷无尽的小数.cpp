#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

// 22222222
// 33333333
// 

vector<int> sub(vector<int> a,vector<int> b){
	vector<int> r(a.size());
	int k=0;
	for (int i=0;i<a.size();i++){
		int x=a[i]-k;
		if(i<b.size()) x-=b[i];		
		if(x<0){
			x+=10;
			k=1;
		} 
		else k=0;
		r[i]=x;
	}
	return r;
}

void qwq_(){
	int n,m;
	cin>>n>>m;
	string s1,s2;
	cin>>s1>>s2;
	vector<int> a,b;
	for(int i=0;i<s1.size();i++) a.push_back(s1[i]-'0');
	for(int i=0;i<s2.size();i++) b.push_back(s2[i]-'0');
	while(a.size()<20000) a.insert(a.end(),a.begin(),a.end());
	while(b.size()<20000) b.insert(b.end(),b.begin(),b.end());
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	vector<int> c=sub(a,b);
	reverse(c.begin(),c.end());
	cout<<n*m<<'\n';
	for(int i=0;i<n*m;i++) cout<<c[i];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}