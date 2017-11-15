#include <iterator>
#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

string get_next_char(istream &in) {
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

template<typename A,typename B>
pair<B,A> flip_pair(const pair<A,B> &w) {
  return pair<B,A>(w.second, w.first);
}

template<typename A,typename B>
multimap<B,A> flip_map(const map<A,B> &s) {
  multimap<B,A> sorted;
  transform(s.begin(), s.end(), inserter(sorted, sorted.begin()), flip_pair<A,B>);
  return sorted;
}

int main() {
  string filename;
  cin >> filename;
  map<string,int> words;
  ifstream fin(filename);

  string s;
  while((s = get_next_char(fin))!= "")
    ++words[s];

  multimap<int,string> sortedwords = flip_map(words);

  for(multimap<int,string>::reverse_iterator riter = sortedwords.rbegin(); riter != sortedwords.rend(); ++riter)
    cout << riter->second << " " << riter->first << endl;
  return 0;
}
