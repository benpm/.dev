#include <iostream>
#include <functional>
#include <unordered_map>

//Function which can transform an std::unordered_map of one type to another with a given transform function
template<typename Kout, typename Vout, typename Kin, typename Vin>
std::unordered_map<Kout, Vout> transformMap(
    const std::unordered_map<Kin, Vin>& inMap,
    const std::function<std::pair<Kout, Vout>(const std::pair<Kin, Vin>&)> mapfunc) {
    std::unordered_map<Kout, Vout> outMap;
    std::for_each(inMap.begin(), inMap.end(),
        [&outMap, &mapfunc] (const std::pair<Kin, Vin> &p) {
            outMap.insert(mapfunc(p));
        }
    );
    return outMap;
}

//Works at compile time!
const std::unordered_map<int, std::string> mapA = {
    {1, "ayy"},
    {2, "bee"},
    {3, "cee"},
    {4, "dee"}
};
const std::unordered_map<std::string, int> mapB = transformMap(mapA,
    std::function([](const std::pair<int, std::string>& p) {
        return std::make_pair(p.second, p.first);
    })
);

//Example
int main() {
    std::cout << "mapA:" << std::endl;
    for (const auto& p : mapA) {
        std::cout << p.first << ":" << p.second << std::endl;
    }
    std::cout << "\nmapB:" << std::endl;
    for (const auto& p : mapB) {
        std::cout << p.first << ":" << p.second << std::endl;
    }
}