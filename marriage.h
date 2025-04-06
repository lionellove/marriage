#include <iostream>
#include<set>
#include<vector>
#include<thread>

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
    std::string show_name();
    void add_hobby(const std::string& s);
    bool hobby_match(const person& p2);
    bool age_match(const person& p2);
    virtual ~person();
    private:
    std::string name;
    std::unique_ptr<std::string[]> hobby;
    size_t age;
    size_t size;
    size_t capacity;
};
class lover: public person{
    public:
    size_t get_favorability();
    lover(const person& p);
    ~lover();
    private:
    size_t favorability=0;
};
