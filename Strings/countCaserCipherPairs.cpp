//link: https://leetcode.com/contest/weekly-contest-484/problems/count-caesar-cipher-pairs/description/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//brute force approach : O(N^2 * M) where N is number of words and M is length of each word

class Solution {
public:
    long long countPairs(vector<string>& words) {

        int n = words.size();

        long long count = 0;

        for(int i = 0; i < n-1; i++) {
            for(int j = i+1; j < n; j++) {
                if(words[i] == words[j]) {
                    count++;
                    continue;
                }

                int diff = -1;
                bool similar = true;
                
                for(int k = 0; k < words[i].length(); k++) {
                    int d = abs(words[i][k] - words[j][k]);
                    int difference = min(d, 26-d);

                    if(diff != -1 && diff != difference) {
                        similar = false;
                        break;
                    }

                    if(diff == difference) {
                        continue;
                    }
                    
                    if(diff == -1) {
                        diff = difference;
                    }
                }

                if(similar) {
                        
                    for(int c = 0; c < words[i].length(); c++) {

                        char n = (((words[i][c]-'a'+diff)%26)+'a');

                        if(n != words[j][c]) {
                            similar = false;
                            break;
                        }
                    }
                

                    if(!similar) {

                        similar = true;
                        
                        for(int c = 0; c < words[i].length(); c++) {

                            char n = (((words[j][c]-'a'+diff)%26)+'a');

                            if(n != words[i][c]) {
                                similar = false;
                                break;
                            }
                        }
                    }
                }

                if(similar) count++;
            }
        }

        return count;
    }
};

//optimal approach : O(N * M) where N is number of words and M is length of each word

class Solution {
public:
    long long countPairs(vector<string>& words) {

        int n = words.size();
        int m = words[0].size();

        unordered_map<string, long long> mp;
        
        long long count = 0;

        for(auto& w : words) {
            string s;
            for(int i = 0; i < m; i++) {
                int currD = (w[i] - w[0] + 26) % 26;
                s.push_back('a' + currD);
            }

            count += mp[s];

            mp[s]++;
        }

        return count;
    }
};