/*#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct Sentence {
  int n = 0;
  string s = "";
};

Sentence * wordcount_from_file(string filename) {
  ifstream file;
  file.open(filename.c_str());
  if (!file) {
    throw string("File '" + filename + "' not found");
  }
  static Sentence phrase[];
  //to do
  return phrase;
}

int main() {
  try {
    string filename;
    cout << "What text file do you want to find the wordcounts of? ";
    cin >> filename;
    Sentence *words;
    words = wordcount_from_file(filename);
    int i = 0;
    while (i < words.size()) {
      cout << *(words + i).s << " " << *(words + i).n << '\n';
    }
  } catch (string s) {
    cerr << "Error: " << s << "\n";
    return -1;
  }
}*/

#include <iterator>
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cctype>

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

int main() {
  string filename;
  cout << "What text file do you want to find the wordcounts of? ";
  cin >> filename;
  map<string,int> words;
  ifstream fin(filename);

  string s;
  while((s = getNextChar(fin))!= "" )
    ++words[s];

  for(map<string,int>::iterator iter = words.begin(); iter != words.end(); ++iter)
    cout << iter->first << " " << iter->second << endl;
}
