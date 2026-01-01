#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    bool search(vector<int>& arr, int key) {
        
        int n = arr.size();

        int l = 0;
        int r = n-1;

        while(l <= r) {

            int mid = l + (r-l)/2;

            //target found
            if(arr[mid] == key) return true;

            //cannot decide because of duplicates
            if(arr[l] == arr[mid] && arr[mid] == arr[r]) {
                l++;
                r--;
            }

            //left half sorted
            else if(arr[l] <= arr[mid]) {
                if(arr[l] <= key && key < arr[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } 
            
            //right half sorted
            else {
                if(arr[mid] < key && key <= arr[r]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

        }

        //target not found
        return false;
    }
};