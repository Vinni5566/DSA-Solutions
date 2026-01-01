#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int search(vector<int>& arr, int key) {
        
        int n = arr.size();

        int l = 0;
        int r = n-1;

        while(l <= r) {
            int mid = l + (r-l)/2;

            //if target found, return immediately
            if(arr[mid] == key) {
                return mid;
            } 

            //left half is sorted
            if(arr[l] <= arr[mid]) {
                if(arr[l] <= key && key < arr[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }

            //right half is sorted
            else {
                if(arr[mid] < key && key <= arr[r]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }

        //if target not found
        return -1;
        
    }
};