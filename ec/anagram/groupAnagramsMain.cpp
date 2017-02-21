#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<iomanip>
#include"groupAnagrams.cpp"

using namespace std;

int main() {
  // Read in the word list.
  ifstream f("groupAnagrams.txt", fstream::in);
  if (!f) {
    cout << "File groupAnagrams.txt could not be found" << endl;
    return 1;
  }
  vector<string> words;
  string word;
  while (f >> word) {
    words.push_back(word);
  }

  // Group the anagrams.
  Solution S;
  auto result = S.groupAnagrams(words);

  // Print out the results;
  for (auto& group: result) {
    for (auto& word: group) {
      cout << setw(9) << word;
    }
    cout << endl;
  }
}

