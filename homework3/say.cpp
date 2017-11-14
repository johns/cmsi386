#include <iostream>
#include <cassert>
#include <string>

using namespace std;
// auto lambda = [](int x, int y) -> int { return x + y; };
// auto say = std::bind(lambda, 5, std::placeholders::_1);
// int say (int x) {
//     return x;
// };


auto say = curry ( [](auto x, auto y, auto z) { return x + y + z} );

// _curry(std::function<R(T,Ts...)> fun)
// : result (
//     [=](const T& t) {
//         return _curry<std::function<R(Ts...)>>(
//             [=](const Ts&...ts){
//                 return fun(t, ts...);
//             }
//         ).result;
//     }
// ) {}





// //
// string say (string firstWord) {
//     if (firstWord.empty()) {
//           return firstWord;
//     }
//
//     return [firstWord](string secondWord) {
//         if(secondWord.empty()) {
//             return firstWord;
//         }
//         return say(firstWord + " " + secondWord);
//     };
// };


int main () {
}
//     assert(say() == "");
//     assert(say("hey") == "hey");
//     assert(say("I")("was")("doing")("just")("fine") == "I was doing just fine");
//     assert(say("before")("I")("met")("you")) == "before I met you");
// }
