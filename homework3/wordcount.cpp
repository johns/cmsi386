#include <iterator>
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cctype>

using namespace std;

string getNextChar(istream in) {
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

int main() {
  string filename;
  cout << "What text file do you want to find the wordcounts of? ";
  cin >> filename;
  vector<string,int> words;
  ifstream fin(filename);

  string s;
  while((s = getNextChar(fin))!= "")
    ++words[s];

  for(map<string,int>::iterator iter = words.begin(); iter != words.end(); ++iter)
    cout << iter->first << " " << iter->second << endl;
}
