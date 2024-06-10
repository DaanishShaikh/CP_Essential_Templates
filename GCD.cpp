#include<bits/stdc++.h>
using namespace std;
int gcd_brute_force(int n, int m){
    int gcd=0;
    for(int i=1 ; i<=min(n,m) ; i++){
        if(n%i==0 && m%i==0){
            gcd=i;
        }
    }
    return gcd;
}
int gcd_optimal_brute_force(int n, int m){
    int gcd=0;
    for(int i=min(n,m) ; i>0 ; i--){
        if(n%i==0 && m%i==0){
            gcd=i;
            break;
        }
    }
    return gcd;
}
int euclidean_algorithm(int n, int m){
    while(n && m){
        if(n>=m){
            n%=m;
        } else {
            m%=n;
        }
    }
    if(m==0){
    return n;
    } else {
        return m;
    }
}
void solve(){
    int n,m;
    cin >> n >> m;
    cout<<gcd_brute_force(n,m)<<endl;
    cout<<gcd_optimal_brute_force(n,m)<<endl;
    cout<<euclidean_algorithm(n,m)<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

        solve();
    
    return 0;
}