#include <iterator>
#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

string getNextChar(istream &in) {
  char c;
  string ans = "";
  c = in.get();
  while(!isalpha(c) && !in.eof()) {
    c = in.get();
  }
  while(isalpha(c)) {
    ans.push_back(tolower(c));
    c = in.get();
  }
  return ans;
}

pair<int,string> flip_pair(const pair<string,int> &p) {
  return pair<int,string>(p.second, p.first);
}

multimap<int,string> flip_map(const map<string,int> &words) {
  multimap<int,string> sortedwords;
  transform(words.begin(), words.end(), inserter(sortedwords, sortedwords.begin()), flip_pair(pair<string,int>));
  return sortedwords;
}

int main() {
  string filename;
  cout << "What text file do you want to find the wordcounts of? ";
  cin >> filename;
  map<string,int> words;
  ifstream fin(filename);

  string s;
  while((s = getNextChar(fin))!= "")
    ++words[s];

  multimap<int,string> sortedwords = flip_map(words);

  for(multimap<int,string>::iterator iter = sortedwords.begin(); iter != sortedwords.end(); ++iter)
    cout << iter->second << " " << iter->first << endl;
}
