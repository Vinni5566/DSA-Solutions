//Problem link: https://takeuforward.org/plus/dsa/problems/xor-of-numbers-in-a-given-range

#include <iostream>
using namespace std;

class Solution{	
	public:
		int findRangeXOR(int l,int r){
			int a = xorUptoN(l-1);
            int b = xorUptoN(r);
            
            return a ^ b;
		}

        int xorUptoN (int n) {
            if(n% 4 == 0) return n;
            else if(n%4 == 1) return 1;
            else if(n%4 == 2) return n+1;

            return 0;
        }
};