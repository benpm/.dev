#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <variant>

template<typename Derived> struct Packable {
    //Pack data into packet
    template<typename T> void pack(const T& m) {
        std::cout << "Packable::pack<T>" << m << std::endl;
        static_cast<Derived*>(this)->Derived::pack(m);
    }
    //Unpack data from packet
    template<typename T> void unpack(T& m) {
        std::cout << "Packable::unpack<T>" << m << std::endl;
        static_cast<Derived*>(this)->Derived::unpack(m);
    }
    virtual ~Packable() = default;
};

template<typename Derived> struct PackedBase : public Packable<PackedBase<Derived>> {

};

struct PackedA : public PackedBase<PackedA> {
    std::string val;

    PackedA(std::string val) : val(val) {}

    void pack(const std::string& m) {
        std::cout << "PackedA::pack(std::string&) " << m << std::endl;
        this->val += m;
    }
    void unpack(std::string& m) {
        std::cout << "PackedA::unpack(const std::string&) " << m << std::endl;
        m += this->val;
    }
};

struct PackedB : public PackedBase<PackedB> {
    std::string val;

    PackedB(std::string val) : val(val) {}
    
    void pack(const std::string& m) {
        std::cout << "PackedB::pack(std::string&) " << m << std::endl;
        this->val += m;
    }
    void unpack(std::string& m) {
        std::cout << "PackedB::unpack(const std::string&) " << m << std::endl;
        m += this->val;
    }
};

struct PackedWrapper {
    std::variant<
        std::shared_ptr<PackedA>,
        std::shared_ptr<PackedB>> v;
    template<typename T> PackedWrapper(T&& t) : v(std::forward<T>(t)) {}
    template<typename T> void pack(const T& m) {
        std::visit([&m](auto& p) { p->pack(m); }, this->v);
    }
    template<typename T> void unpack(T& m) {
        std::visit([&m](auto& p) { p->unpack(m); }, this->v);
    }
};

int main(int argc, char const *argv[])
{
    std::vector<PackedWrapper> list;
    list.push_back(std::make_shared<PackedA>("a_1"));
    list.push_back(std::make_shared<PackedB>("b_1"));
    list.push_back(std::make_shared<PackedB>("b_2"));
    list.push_back(std::make_shared<PackedA>("a_2"));
    list[0].pack("*");
    list[1].pack("%");
    list[2].pack("$");
    list[3].pack("&");
    std::string str;
    for (auto& p : list) {
        p.unpack(str);
        str += "\n";
    }
    std::cout << str << std::endl;
    return 0;
}
