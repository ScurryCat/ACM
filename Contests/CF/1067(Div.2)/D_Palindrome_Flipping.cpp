#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

// void qwq_(){
// 	int n;
// 	cin >> n;
// 	string a, b;
// 	cin >> a >> b;
// 	if(a==b) cout<<"0\n";
// 	else{
// 		vector<pair<int,int>> ans;
// 		vector<int> cnt(n);
// 		for(int i=0;i<n;i++){
// 			if(a[i] != b[i]) cnt[i]++;
// 		}
// 		for(int i=0;i<n-1;i++){
// 			if(cnt[i]){
// 				for(int j=i+1;j<n;j++){
// 					if(cnt[j]==0){
// 						// cout<<i+1<<' '<<j+1<<'\n';
// 						ans.push_back({i+1,j+1});
// 						cnt[j]=1;
// 						i=j-1;
// 						break;
// 					}
// 					if(j==n-1){
// 						// cout<<i+1<<' '<<j+1<<'\n';
// 						ans.push_back({i+1,j+1});
// 						cout<<ans.size()<<'\n';
// 						for(auto x : ans) cout<<x.first<<' '<<x.second<<'\n';
// 						return;
// 					}
// 				}
// 			}
// 		}
// 		cout<<ans.size()<<'\n';
// 		for(auto x : ans) cout<<x.first<<' '<<x.second<<'\n';
// 	}
// }

void fun(string s, vector<pair<int, int>> &ans){
	if(count(s.begin(), s.end(), '1')==0) return;
	int l = 0;
	while(l<s.size() && s[l]=='0') l++;
	int r = l+1;
	while(r<s.size() && s[r]=='0') r++;
	if(r >= s.size()){
		if(l>1){
			ans.push_back({l-1, l});
			ans.push_back({l-1, l+1});
			return;
		}
		else{
			ans.push_back({l+2, l+3});
			ans.push_back({l+1, l+3});
			return;
		}
	}
	ans.push_back({l+1, r+1});
	for(int i=l; i<=r; i++) s[i] = (s[i] == '1' ? '0' : '1');
	fun(s, ans);
}

void qwq_(){
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	vector<pair<int,int>> ans1, ans2;
	fun(a, ans1);
	fun(b, ans2);
	cout << ans1.size() + ans2.size() << '\n';
	for(int i=0; i<ans1.size(); i++){
		cout << ans1[i].first << ' ' << ans1[i].second << '\n';
		// for(int j=ans1[i].first-1;j<ans1[i].second;j++) a[j]= a[j]=='1'?'0':'1';
		// cout<<a<<'\n';
	}
	for(int i=ans2.size()-1; i>=0; i--){
		cout << ans2[i].first << ' ' << ans2[i].second << '\n';
		// for(int j=ans2[i].first-1;j<ans2[i].second;j++) a[j]= a[j]=='1'?'0':'1';
		// cout<<a<<'\n';
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int yyy = 1;
	cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}