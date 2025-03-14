#include <iostream>
#include<set>
class person{
    public:
    person()=default;
    person(const person& p);
    person(const std::pair<std::string,size_t>& p);
    person& operator=(const person& p);
    size_t get_size();
    size_t get_capacity();
    size_t get_age();
    std::string ex_hobby();
    void add_hobby(const std::string& s);
    bool hobby_match(const person& p2);
    bool age_match(const person& p2);
     ~person();
    private:
    std::string name;
    std::string* hobby;
    size_t age;
    size_t size;
    size_t capacity;
};
