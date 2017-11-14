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
  cout << "All tests passed!\n";
}

// // auto lambda = [](int x, int y) -> int { return x + y; };
// // auto say = std::bind(lambda, 5, std::placeholders::_1);
// int say (int x) {
//     return x;
// };

// //
// string say (string firstWord) {
//   if (firstWord.empty()) {
//     return firstWord;
//   }
//   string sayNext = (string secondWord) {
//     if(firstWord.empty()) {
//       return firstWord;
//     }
//     return say(firstWord + " " + secondWord);
//   };
//   return sayNext;
// };
// //

// int main () {
// }
// //     assert(say() == "");
// //     assert(say("hey") == "hey");
// //     assert(say("I")("was")("doing")("just")("fine") == "I was doing just fine");
// //     assert(say("before")("I")("met")("you")) == "before I met you");
// // }
