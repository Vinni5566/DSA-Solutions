#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int findMin(vector<int>& arr) {
        
        int n = arr.size();

        int l = 0;
        int r = n-1;

        while(l < r) {

            int mid = l + (r-l)/2;

            if(arr[mid] <= arr[r]) { //min element is in left half
                r = mid;
            } else {  //min element is in right half
                l = mid + 1; 
            }
        }

        // l will point to index of min element
        return arr[l];
    }
};