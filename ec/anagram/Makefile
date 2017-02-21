
CMP = g++
FLAGS = -std=c++14 -Wall

all: isAnagram groupAnagrams

isAnagram: isAnagramMain.cpp isAnagram.cpp
	$(CMP) $(FLAGS) -o $@ isAnagramMain.cpp

groupAnagrams: groupAnagramsMain.cpp groupAnagrams.cpp
	$(CMP) $(FLAGS) -o $@ groupAnagramsMain.cpp

# clean up
clean : 
	rm -f isAnagram groupAnagrams

