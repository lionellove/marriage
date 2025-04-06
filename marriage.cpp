#include "marriage.h"
#include <cmath>
#include<cstdio>
#include <sstream>
#include <vector>
#include <cstring>
#include <algorithm>
using std::vector;

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
string streamToPython(const std::string& data, const std::string& compare){
    std::string cmd = "python openrouter.py \"" + data + "\" \"" + compare + "\"";
    FILE* pipe = _popen(cmd.c_str(),"r");
    if(!pipe){
        std::cerr<<"Pipe open failed"<<std::endl;
        return "Pipe open failed";
    } 
    
    std::cout<<"pipe open success"<<std::endl;
    
   
    
    std::stringstream result;
    char buffer[128];
    while (fgets(buffer,sizeof(buffer),pipe)!=nullptr){
        result<<buffer;
    }
    std::cout<<"pipe read success"<<std::endl;
    int status=_pclose(pipe);
    if(status!=0){
        std::cerr<<"Pipe close failed"<<std::endl;
        return "Pipe close failed";
    }
    std::cout<<"pipe close success"<<std::endl;
    
    std::string cleaned_result = result.str();
    cleaned_result.erase(std::remove_if(cleaned_result.begin(), cleaned_result.end(), 
                       [](unsigned char c) { return !std::isdigit(c); }),
                      cleaned_result.end());
    
    return cleaned_result.empty() ? "0" : cleaned_result;
    
}

person::person(const person& p){
    name=p.name;
    age=p.age;
    hobby=std::make_unique<std::string[]>(p.size);
    for(int i=0;i<p.size;i++){
        hobby[i] = p.hobby[i];  
    }
    size=p.size;
    capacity=p.capacity;
}


person& person::operator=(const person& p){
    if(this!=&p){
        name=p.name;
        age=p.age;
    hobby=std::make_unique<std::string[]>(p.capacity);
    
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
    
        auto new_hobby=std::make_unique<std::string[]>(capacity);
        for(int i=0;i<size;i++){
            new_hobby[i]=hobby[i];
        }

           
            hobby=std::move(new_hobby);
        
    
}
    hobby[size++]=s;
    
}
bool person::hobby_match(const person& p2){
    
    int count=0;
    if(p2.size==0){
        throw std::invalid_argument("hobby can't be empty");
    }
    std::cout<<"in progress"<<std::endl;
    /*for(int i=0;i<p2.size;i++){
        set1.insert(p2.hobby[i]);
    }
    for(int i=0;i<size;i++){
        if(set1.contains(hobby[i])){
            count+=1;
        }
    }
    if(count>1){
        return true;
    }
    else if(size==1 && count==1){
        return true;
    }
    return false;*/
    for(int i=0;i<size;i++){
        vector<int> numbers;
        for(int j=0;j<p2.size;j++){
            string result=streamToPython(hobby[i],p2.hobby[j]);
            numbers.push_back(stoi(result));
        }
        int max=0;
        for(int i=0;i<numbers.size();i++){
            if(numbers[i]>max){
                max=numbers[i];
            }
        }
    
        count+=max;
    } 
      
    if(count>5*size){
        return true;
    }
    return false;
    

    
    
}    


bool person::age_match(const person& p2){
    if(age<18){
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
    if(size==0){
        throw std::invalid_argument("hobby can't be empty");
    }
    return hobby[0];
}    
size_t person::get_age(){
    return age;
}
string person::show_name(){
    return name;
}
person::~person(){
       
}
lover::~lover()=default;
lover::lover(const person& p):
person(p),favorability(0){}
size_t lover::get_favorability(){
        return favorability;
}
