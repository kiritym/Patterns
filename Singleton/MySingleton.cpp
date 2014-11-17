#include<iostream>

using namespace std;

class MySingleton{
private:
    static bool flag;  //static flag to check single instance
    static MySingleton *single;  //static instance
    MySingleton(){
    //Private constructor
    cout << "object created " <<"\n";
    }
public:
    static MySingleton* getInstance();
    void method();
    ~MySingleton(){     //DESTRUCTOR
        flag = false;
    }
};

bool MySingleton::flag = false;
MySingleton* MySingleton::single = NULL;
MySingleton* MySingleton::getInstance(){
    cout << "inside getinstance: " << "\n";
    if(!flag){
        single = new MySingleton();
        flag = true;
        cout<<"new object created"<<endl;
        return single;
    }
    else{
        cout<<"object is already exist"<<endl;
        return single;
    }
}

void MySingleton::method(){
    cout << "This is a method of the singleton class" << "\n";
}

int main(){
    MySingleton *ms1, *ms2;
    ms1 = MySingleton::getInstance();
    ms1->method();
    ms2 = MySingleton::getInstance();
    ms2->method();

    return 0;
}   
