#include <iostream>
#include <map>
#include <tuple>
#include <variant>
#include <vector>

template<class... T>
struct TypeMap {
  std::tuple<std::string, int> map;

  TypeMap(std::vector<std::string> names) {

  }
};


int main() {
  std::cout << "Hello World!\n";
  std::map<std::string, int> map = {
    {"int", 0},
    {"float", 1}
  };
  std::tuple<int, float> types;
  int d = map.at(0);
  int x = std::get<d>(types);

  //Make("int") -> int
}