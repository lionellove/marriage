#include"marriage.h"
#include<fstream>
#include<sstream>
#include <vector>
#include <algorithm>
#include <cstring>
using std::stringstream;
using std::vector;
using std::string;



vector<person> initial_person(const vector<vector<string>>& v){
    vector<person> vp;
    for(auto i: v){
    
    std::pair<std::string,size_t> pair1;
    size_t p=stoi(i[1]);
   
    pair1.first=i[0];
    pair1.second=p;
    person man(pair1);
    
    
    for(size_t j=2;j<i.size();j++){
        man.add_hobby(i[j]);
        
    }
    
    vp.push_back(man);
    
    

    }
    
    
    return vp;
}

vector<vector<std::string>> read_in_people(const std::string& filename){
    std::ifstream input_file("name.txt");
    vector<vector<string>> out_vector;
    std::vector<std::string> info_vector;
   
    if(input_file.is_open()){
        std::string string1;
        std::getline(input_file,string1);
        std::string string2;
        while(std::getline(input_file,string2)){
            
            std::istringstream line_stream(string2);
            string token;
            while(std::getline(line_stream,token,',')){
                info_vector.push_back(token);
               
            }
            out_vector.push_back(info_vector);
            info_vector.clear();
            
        }
        
    }
    return out_vector;
}

int main(){
    

    
    std::cout<<"请输入姓名和年龄，用空格隔开";
    std::pair<std::string,size_t> pair2;
    std::string s;
    size_t p;
    std::cin>>s>>p;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
   
    
    pair2.first=s;
    pair2.second=p;
    person user(pair2); 
   
    
    vector<string> hobbies;
    string token;
    std::cout<<"请输入爱好，用逗号隔开";
    string input_string;
    if(std::getline(std::cin,input_string)){
        std::istringstream iss(input_string);
        while(std::getline(iss,token,',')){
        hobbies.push_back(token);
    }
    
    }
    
    
    for(auto& i: hobbies){
        user.add_hobby(i);
    }
    
   
    
   
    vector<vector<string>> v=read_in_people("name.txt");
    
    vector<person> vp =initial_person(v);
    
    
    for(int i=0;i<vp.size();i++){
        
        if(user.hobby_match(vp[i]) and user.age_match(vp[i])){
            
        std::cout<<"success"<<std::endl;
        lover man(vp[i]);
        
        std::cout<<man.get_favorability();
        
    }
        else{
        std::cout<<"loser"<<std::endl;
    }
    }
    
}