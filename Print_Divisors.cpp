#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin >> n;
    vector<int>ans;
    for(int i=1 ; i*i<=n ; i++){
        if(n%i==0){
            if(i==n/i){
                ans.push_back(i);
            } else {
            ans.push_back(i);
            ans.push_back(n/i);
            }
        }
    }
    sort(ans.begin(),ans.end());
    for(auto s:ans){
        cout<<s<<' ';
    }
    return 0;
}