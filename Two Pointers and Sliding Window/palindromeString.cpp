//Problem link: https://www.geeksforgeeks.org/problems/palindrome-string0817/1

#include <iostream>
using namespace std;

class Solution {
  public:
    bool isPalindrome(string& s) {
        
        int l = s.length();
        
        int left = 0;
        int right = l-1;
        
        while(left < right) {
            if(s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        
        return true;
        
    }
};