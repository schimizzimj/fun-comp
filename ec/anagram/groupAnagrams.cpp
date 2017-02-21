// groupAnagrams.cpp
// Class interface for the Solution class
//
// Marcus Schimizzi
// 11/14/16

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
      vector< vector<string> > groupAnagrams(vector<string>& strs) {
        vector< vector<string> > groups;  
        int count = 0;
        string sorted;
        while (strs.size() != 0) {
          vector<string> row;
          row.push_back(strs[count]);
          sorted = strs[count];
	  sort(sorted.begin(), sorted.end());
          string temp;  
          for (int i = 1; i < strs.size(); i++) {
              temp = strs[i];
              sort(temp.begin(), temp.end());
              if (sorted.compare(temp) == 0) {
                row.push_back(strs[i]);
                strs.erase(strs.begin() + i);
              }
          }
          strs.erase(strs.begin() + count);
          groups.push_back(row);
        }
        return groups;
      }
};
