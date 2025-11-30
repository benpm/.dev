#include <iostream>
#include <unordered_set>

int main() {
	std::unordered_set<int> set;
	set.emplace(2);
	set.emplace(2);
	set.emplace(3);
	set.emplace(4);
  	for (auto i : set) {
		std::cout << i << std::endl;
	}
} 