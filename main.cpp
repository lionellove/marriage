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
    person lover(pair1);
    
    
    for(size_t j=2;j<=v.size();j++){
        lover.add_hobby(i[j]);
       
    }
    
    vp.push_back(lover);
    std::cout<<vp.size()<<std::endl;
    
    }
  
    
    return vp;
}

vector<vector<std::string>> read_in_people(const std::string& filename){
    std::ifstream input_file;
    vector<vector<string>> out_vector;
    std::vector<std::string> info_vector;
    input_file.open(filename);
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
    

    
    std::cout<<"输入名字和年龄";
    std::pair<std::string,size_t> pair2;
    std::string s;
    size_t p;
    std::cin>>s>>p;
   
    
    pair2.first=s;
    pair2.second=p;
    person user(pair2); 
    vector<string> hobbies;
    string token;
    std::cout<<"输入爱好（按重要性递减的程度）";
    while(std::getline(std::cin,token,',')){
        hobbies.push_back(token);
    }
    
    for(auto& i: hobbies){
        user.add_hobby(std::move(i));
    }
    std::cout<<user.ex_hobby();
   
    
   
    vector<vector<string>>v=read_in_people("name.txt");
    
    vector<person> vp =initial_person(v);
    
    
    for(auto i: vp){
        
        if(user.hobby_match(i) and user.age_match(i)){
        std::cout<<"success"<<std::endl;
    }
        else{
        std::cout<<"loser"<<std::endl;
    }
    }
    
}