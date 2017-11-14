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

Adder f;

int main() {
  assert(f() == "");
  assert(f("Hi!")() == "Hi!");
  assert(f("Hello")("there")() == "Hello there");
  assert(f("My")("name")("is")("Jeff")() == "My name is Jeff");
  assert(f(" ")() == " ");
  assert(f("")() == "");
  cout << "All tests passed!\n";
  return 0;
}
