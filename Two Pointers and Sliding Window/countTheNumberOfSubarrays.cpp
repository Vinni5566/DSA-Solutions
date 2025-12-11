#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    long long countSubarray(int N, vector<int> A, long long L, long long R) {
        
        return atmost(R, A) - atmost(L-1, A);
        
    }
    
    long long atmost(long long n, vector<int>& A) {
        
        long long l = 0, sum = 0, count = 0;
        
        for(long long r = 0; r < A.size(); r++) {
            
            sum += A[r];
            
            while(sum > n) {
                sum -= A[l];
                l++;
            }
            
            count += (r-l+1);
        }
        
        return count;
    }
};