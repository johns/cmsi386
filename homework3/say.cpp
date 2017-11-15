#include <iostream>
#include <cassert>
#include <string>

using namespace std;

struct Adder {
private:
  string result = "";
public:
  Adder(string s = ""): result(s) {}
  Adder operator()(string word) {
    return Adder(result + " " + word);
  }
  string operator()() {
    if (result.length()) {
      result = result.substr(1);
    }
    return result;
    }
};

int main() {
  Adder sayFunction;
  assert(sayFunction() == "");
  assert(sayFunction("Hi!")() == "Hi!");
  assert(sayFunction("Hello")("there")() == "Hello there");
  assert(sayFunction("My")("name")("is")("Jeff")() == "My name is Jeff");
  assert(sayFunction(" ")() == " ");
  assert(sayFunction("")() == "");
  cout << "All tests passed!\n";
  return 0;
}
