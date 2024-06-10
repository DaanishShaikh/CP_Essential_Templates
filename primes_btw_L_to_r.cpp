#include<bits/stdc++.h>
using namespace std;

bool is_prime(int x){
    if(x==1||x==0){
        return 0;
    }
    for(int i=2 ; i*i<=x ; i++){
        if(x%i==0){
            return 0;
        }
    }
    return 1;
}
int brute_for_L_to_R_primes(int l, int r){
    int count=0;
    for(int i=l ; i<=r ; i++){
        if(is_prime(i)){
            count++;
        }
    }
    return count;
}

vector<int> getsieve(int x){
    vector<int>sieve(x+1,1);
    sieve[0]=0;
    sieve[1]=0;
    for(int i=2 ; i*i<=x ; i++){
        if(sieve[i]==1){
            for(int j=i*i ; j<=x ; j+=i){
                sieve[j]=0;
            }
        }
    }
    return sieve;
}
int optimized_brute_for_L_to_r_primes(int l, int r){
    int count=0;
    vector<int>sieve=getsieve(r);
    for(int i=l ; i<=r ; i++){
        if(sieve[i]==1){
            count++;
        }
    }
    return count;
}

vector<int> get_sieve_prefix_sum(int x){
    vector<int>v=getsieve(x);
    for(int i=1 ; i<v.size() ; i++){
        v[i]=v[i-1]+v[i];
    }
    return v;
}
int most_optimized_soltution_for_L_to_R_primes(int l, int r, int maxi){
    vector<int>ans=get_sieve_prefix_sum(maxi);
    return ans[r]-ans[l-1];
}
int main(){
    int a,b;
    cin >> a >> b;
    cout<<"type the maximum value of r in given queries = ";
    int maxi;
    cin >> maxi;
    cout<<brute_for_L_to_R_primes(a,b)<<endl;
    cout<<optimized_brute_for_L_to_r_primes(a,b)<<endl;
    cout<<most_optimized_soltution_for_L_to_R_primes(a,b,maxi)<<endl;

    return 0;
}