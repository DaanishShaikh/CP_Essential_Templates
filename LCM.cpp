#include<bits/stdc++.h>
using namespace std;
i64 gcd(i64 a, i64 b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

i64 lcm(i64 a, i64 b) {
    return (a * b) / gcd(a, b);
}

i64 lcmOfGroup(const vector<i64>& numbers) {
    i64 result = 1;
    for (i64 num : numbers) {
        result = lcm(result, num);
    }
    return result;
}



