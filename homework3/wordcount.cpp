#include <iostream>
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
}
