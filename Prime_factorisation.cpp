// time complexity= Nloglog(N) + (q*log base 2 (N))
#include<bits/stdc++.h>
using namespace std;

vector<int> sieve_of_smallest_prime_factors(int x){
    vector<int>sieve(x+1);
    for(int i=0 ; i<=x ; i++){
        sieve[i]=i;
    }
    for(int i=2 ; i<=x ; i++){
        if(sieve[i]==i){
            for(int j=i*i ; j<=x ; j+=i){
                if(sieve[j]==j){
                sieve[j]=i;
                }
            }
        }
    }
    return sieve;
}

int main(){
    cout<<"Enter the queries you want prime factors of = ";
    int n;
    cin >> n;
    vector<int>q(n);
    int x=INT_MIN;
    for(int i=0 ; i<n; i++){
        cin >>q[i];
        x=max(q[i],x);
    }
    vector<int>sieve=sieve_of_smallest_prime_factors(x);
    for(int i=0 ; i<n ; i++){
        cout<<q[i]<<"= ";
        int temp=q[i];
        while(temp!=1){
            cout<<sieve[temp]<<' ';
            temp/=sieve[temp];
        }
        cout<<endl;
    }
    return 0;
}