// isAnagram.cpp
// Class implementation for the Solution class
// 
// Marcus Schimizzi
// 11/14/16

#include <iostream>
#include <string>
using namespace std;

class Solution {
  public:
    bool isAnagram(string s, string t) {
      if (s.length() != t.length()) return false;
      // Check to see if strings are same length; can't be anagrams if not
        else {
          char temp;
          for (int i = 1; i < s.length(); i++) {
            // Uses bubble sort to sort both strings alphabetically 
            for (int j = 0; j < s.length() - 1; j++) {
	      if (s[j] > s[j + 1]) {
	        temp = s[j];
	        s[j] = s[j + 1];
                s[j + 1] = temp;
	      }
              if (t[j] > t[j + 1]) {
                temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;	
              }
            }
          }
          if (s.compare(t) == 0) return true;
            //Use string compare to determine if the strings are anagrams
          else return false;
        }
    }
};
