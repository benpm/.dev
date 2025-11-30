#include <cmath>
#include <iostream>
#include <vector>

struct TrieSet {
  std::vector<uint64_t> v;
  // Number of bits per element
  uint8_t n;

  TrieSet(uint32_t size) { resize(size); }
  void resize(uint32_t size) {
    n = std::ceil(std::log2(size));
    v.resize(std::max((n + 1) >> 5, 1));
  }
  void insert(uint64_t k) {
    for (uint8_t i = 0; i < n-1; i += 1) {
			k = (k << 1 & (~0 << i)) | ~(~0 << i);
			v[k >> 6] |= 1 << (k & 63);
    }
  }
	uint64_t prev(uint64_t k) {
		uint64_t kk = 0;
		for (uint8_t i = 0; i < n-1; i++) {
			k = (k << 1 & (~0 << i)) | ~(~0 << i);
			kk |= (v[k >> 6] & 1 << (k & 63));
		}
		return kk;
	}
};

int main() {
  TrieSet s(1000000);
  s.insert(480239);
	std::cout << s.v[0] << std::endl;
	std::cout << s.prev(950000) << std::endl;
  return 0;
}