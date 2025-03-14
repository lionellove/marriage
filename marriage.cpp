#include "marriage.h"
#include <cmath>
using std::pair;
using std::string;
person::person(const pair<string,size_t>& p)
:name(p.first)
,hobby(nullptr)
,age(p.second)
,size(0)
,capacity(0)
{

}

person::person(const person& p){
    name=p.name;
    age=p.age;
    hobby=new string[p.size];
    for(int i=0;i<p.size;i++){
        hobby[i]=p.hobby[i];
    }
    size=p.size;
    capacity=p.capacity;
}


person& person::operator=(const person& p){
    if(this!=&p){
        name=p.name;
        age=p.age;
    delete[] hobby;
    hobby=new string[p.capacity];
    for(int i=0;i<p.size;i++){
        hobby[i]=p.hobby[i];
    }
    size=p.size;
    capacity=p.capacity;
}
    return *this;
}
size_t person::get_size(){
    return size;
}
size_t person::get_capacity(){
    return  capacity;
}
void  person::add_hobby(const std::string& s){
    if(size==capacity){
        capacity=2*capacity+1;
    
        string* new_hobby=new string[capacity];
        for(int i=0;i<size;i++){
            new_hobby[i]=hobby[i];
        }

            delete[] hobby;
            hobby=new_hobby;
        
    
}
    hobby[size++]=s;
    
}
bool person::hobby_match(const person& p2){
    std::set<string> set1;
    int count=0;
    if(p2.size==0){
        throw std::invalid_argument("hobby can't be empty");
    }
    for(int i=0;i<p2.size;i++){
        set1.insert(p2.hobby[i]);
    }
    for(int i=0;i<size;i++){
        if(set1.contains(hobby[i])){
            count+=1;
        }
    }
    if(size>1 && count>=static_cast<int>(count/2+1)){
        return true;
    }
    else if(size==1 && count==1){
        return true;
    }
    return false;

} 
bool person::age_match(const person& p2){
    if(age==18){
        throw std::invalid_argument("age can't be under 18");
    }
    int a=static_cast<int>(age);
    int b=static_cast<int>(p2.age);
    if(std::abs(a-b)<=5){
        return true;
    }
    else{return false;}
}
std::string person::ex_hobby(){
    return hobby[0];
}    
size_t person::get_age(){
    return age;
}
person::~person(){
        delete[] hobby;
    }
