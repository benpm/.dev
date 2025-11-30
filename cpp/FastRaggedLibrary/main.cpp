#include <iostream>
#include <variant>
#include <vector>
#include <string>

template<typename... Types>
class VList : public std::vector<std::variant<Types...>> {};

int main() {
  VList<int, std::string> vlist;
  vlist.push_back(100);
  vlist.push_back("string");
  for (auto& v : vlist) {
    if (std::holds_alternative<int>(v)) {
      std::cout << "[int] " << std::get<int>(v) << std::endl;
    } else if (std::holds_alternative<std::string>(v)) {
      std::cout << "[string] " << std::get<std::string>(v) << std::endl;
    }
  }
}