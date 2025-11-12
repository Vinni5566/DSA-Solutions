//Problem link: https://www.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        // code here
        int l = arr.size();

        if(l == 1) return arr[0];
        if(l == 2) {
            if(arr[0] == arr[1]) {
                return arr[0]*2;
            } else {
                int a1 = max(arr[0], arr[1]);
                int a2 = min(arr[0], arr[1])*2;
                
                return max(a1, a2);
            }
            
        }

        
        stack<int> st;
        int maxarea = 0;
        int i = 0;

        while(i <= l) {
            int currHeight = (i == l ? 0 : arr[i]);
            if(st.empty() || arr[st.top()] < currHeight) {
                st.push(i);
                i++;
            } else {
                int topEle = st.top();
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                int area = arr[topEle] * width;
                maxarea = max(area, maxarea);
            }
        }

        return maxarea;
    }
};
