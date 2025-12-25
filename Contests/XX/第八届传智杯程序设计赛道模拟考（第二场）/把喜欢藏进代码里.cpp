#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

void qwq_(){
	string s,str;
	cin>>str;
	for(int i=str.size()-1;i;i--){
		if(str[i-1]=='.'){
			for(int j=i;j<str.size();j++)
				s.push_back(str[j]);
			break;
		}
	}
	int n; cin>>n;
	cin.ignore();
	if(s=="c"||s=="cpp"||s=="cxx"||s=="cc"||s=="js"||s=="go"||s=="java"){
		for(int i=1;i<=n;i++){
			getline(cin,s);
			for(int j=0,cnt=0;j<s.size();j++){
				if(s[j]=='"') cnt++;
				if(s[j]=='\'') {j++; continue;}
				if(cnt%2==0){
					if(s[j]=='/' && s[j+1]=='/'){
						string ans;
						cout<<'#'<<i<<':'<<' ';
						for(int k=j+2;k<s.size();k++){
							ans.push_back(s[k]);
						}
						cout<<quoted(ans)<<'\n';
						break;
					}
					if(s[j]=='/' && s[j+1]=='*'){
						string ans;
						cout<<'#'<<i<<':'<<' ';
						for(int k=j+2;k<s.size();k++){
							if(s[k]=='*' && s[k+1]=='/'){
								cout<<quoted(ans)<<'\n';
								j=k+1;
								break;
							}
							ans.push_back(s[k]);
						}
					}
				}
			}
		}
	}
	else if(s=="php"){
		for(int i=1;i<=n;i++){
			getline(cin,s);
			for(int j=0,cnt=0;j<s.size();j++){
				if(s[j]=='"') cnt++;
				if(s[j]=='\'') {j++; continue;}
				if(cnt%2==0){
					if(s[j]=='/' && s[j+1]=='/'){
						string ans;
						cout<<'#'<<i<<':'<<' ';
						for(int k=j+2;k<s.size();k++){
							ans.push_back(s[k]);
						}
						cout<<quoted(ans)<<'\n';
						break;
					}
					if(s[j]=='/' && s[j+1]=='*'){
						string ans;
						cout<<'#'<<i<<':'<<' ';
						for(int k=j+2;k<s.size();k++){
							if(s[k]=='*' && s[k+1]=='/'){								
								cout<<quoted(ans)<<'\n';
								j=k+1;
								cnt=0;
								break;
							}
							ans.push_back(s[k]);
						}
					}
					if(s[j]=='#'){
						string ans;
						cout<<'#'<<i<<':'<<' ';
						for(int k=j+1;k<s.size();k++){
							ans.push_back(s[k]);
						}
						cout<<quoted(ans)<<'\n';
						break;
					}
				}
			}
		}
	}
	else if(s=="py"){
		for(int i=1;i<=n;i++){
			getline(cin,s);
			for(int j=0,cnt=0;j<s.size();j++){
				if(s[j]=='"') cnt++;
				if(s[j]=='\'') {j++; continue;}
				if(cnt%2==0){
					if(s[j]=='#'){
						string ans;
						cout<<'#'<<i<<':'<<' ';
						for(int k=j+1;k<s.size();k++){
							ans.push_back(s[k]);
						}
						cout<<quoted(ans)<<'\n';
						break;
					}
					if(s[j]=='"' && s[j+1]=='"' && s[j+2]=='"'){
						string ans;
						cout<<'#'<<i<<':'<<' ';
						for(int k=j+3;k<s.size();k++){
							if(s[k]=='"' && s[k+1]=='"' && s[k+2]=='"'){								
								cout<<quoted(ans)<<'\n';
								j=k+2;
								cnt=0;
								break;
							}
							ans.push_back(s[k]);
						}
					}
				}
				else{
					if(s[j]=='"' && s[j+1]=='"' && s[j+2]=='"'){
						string ans;
						cout<<'#'<<i<<':'<<' ';
						for(int k=j+3;k<s.size();k++){
							if(s[k]=='"' && s[k+1]=='"' && s[k+2]=='"'){								
								cout<<quoted(ans)<<'\n';
								j=k+2;
								cnt=0;
								break;
							}
							ans.push_back(s[k]);
						}
					}
				}
			}
		}
	}
	else if(s=="html"){
		for(int i=1;i<=n;i++){
			getline(cin,s);
			for(int j=0,cnt=0;j<s.size();j++){
				if(s[j]=='"') cnt++;
				if(s[j]=='\'') {j++; continue;}
				if(cnt%2==0){
					string ans;
					if(s[j]=='<' && s[j+1]=='!' && s[j+2]=='-' && s[j+3]=='-'){
						cout<<'#'<<i<<':'<<' ';
						for(int k=j+4;k<s.size();k++){
							if(s[k]=='-' && s[k+1]=='-' && s[k+2]=='>'){
								cout<<quoted(ans)<<'\n';
								j=k+2;
								break;
							}
							ans.push_back(s[k]);
						}
					}
				}
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}