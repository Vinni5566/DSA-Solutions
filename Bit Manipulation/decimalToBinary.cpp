//Problem link: https://www.geeksforgeeks.org/batch/skill-up-dsa/track/su-dsa-topic-wise-week20/problem/decimal-to-binary-1610434291

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void toBinary(int n) {
    
    string res;
    
    while(n > 0) {
        res.append(to_string(n%2));
        n /= 2;
    }
    
    reverse(res.begin(), res.end());
    
    cout<<res;
    
}