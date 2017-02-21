#include<iostream>
#include<fstream>
#include"isAnagram.cpp"

using namespace std;

int main() {
  ifstream f("anagram.txt", ifstream::in);
  if (!f) {
    cout << "File anagram.txt could not be found." << endl;
    return 1;
  }
  string s1, s2;
  f >> s1;
  Solution S;
  int count = 0;
  while (f >> s2) {
    if (S.isAnagram(s1, s2)) {
      count++;
      cout << "Anagram " << count << ":\t" << s1 << "\t" << s2 << endl;
    }
    s1 = s2;
  }
}

