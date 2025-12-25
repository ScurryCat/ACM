#include<bits/stdc++.h>
using namespace std;

int main(){

    int t; cin>>t;
    while(t--){
        string s;
        cin>>s;
        vector<int> a(30,0);
        bool ok=true;
        for(int i=0;i<s.size();i++){
            a[s[i]-'a']++;
        }
        for(int i=0,flag=0;i<26;i++){
            if(a[i]==0) ok=false;
            else if(a[i]==1) flag|=0;
            else flag=1;
            if(!flag) ok=false;
            else ok=true;
        }
        if(ok) cout<<"YES\n";
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}