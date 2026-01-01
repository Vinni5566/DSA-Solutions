#include <iostream>
#include <vector>
using namespace std;

int Search(vector<int> vec, int K) {
    
    int n = vec.size();

    int l = 0;
    int r = n-1;

    while(l <= r) {
        int mid = l + (r-l)/2;

        //if target found, return immediately
        if(vec[mid] == K) {
            return mid;
        } 

        //left half is sorted
        if(vec[l] <= vec[mid]) {
            if(vec[l] <= K && K < vec[mid]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        //right half is sorted
        else {
            if(vec[mid] < K && K <= vec[r]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
    }

    //if target not found
    return -1;
    
}