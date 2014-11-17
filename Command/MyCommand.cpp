#include<iostream>
#include<sstream>
#include<bitset>
#include<climits>
#include<map>
using namespace std;

class converter{
public:
virtual std::string convert(int i) = 0;
virtual ~converter() {}
};

class hex_converter : public converter {
public:
std::string convert(int i){
    std::stringstream ss;
    ss << std::hex << i;
    return ss.str();
}

};

class oct_converter : public converter {
public:
std::string convert(int i){
    std::stringstream ss;
    ss << std::oct << i;
    return ss.str();

}

};

class bin_converter : public converter {
public:
std::string convert(int i){
    std::bitset< sizeof(i) * CHAR_BIT > bits(i);
    std::stringstream ss;
    ss << bits;
    return ss.str();

}

};

class dictionary {
    std::map<char, converter*>dict;
public:
    dictionary(){
        dict.insert(std::make_pair('H', new hex_converter));
        dict.insert(std::make_pair('O', new oct_converter));
        dict.insert(std::make_pair('B', new bin_converter));
    }

    converter* lookup(char x){
        std::map<char, converter*>::const_iterator iter;
        iter = dict.find(toupper(x));
        if (iter != dict.end()){
            return iter->second;
        }
        else
            return NULL;
    }

    ~dictionary(){
        while (dict.begin() != dict.end()){
            delete dict.begin()->second;
            dict.erase(dict.begin());
        }
    }
};

int main(){

    int num;
    cout << "Enter number in decimal: "<< "\n";
    cin >> num;
    char x;
    cout << "Enter conversion mode : B for binary, H for hex, O for Oct  "<<"\n";
    cin >> x;
    string output = "";
/*    hex_converter *h1 = new hex_converter();
    oct_converter *o1 = new oct_converter();
    bin_converter *b1 = new bin_converter();
    cout << "hex num is : " << h1->convert(num) << "\n";
    cout << "oct num is : " << o1->convert(num) << "\n";
    cout << "bin num is : " << b1->convert(num) << "\n";
    */
    dictionary dict;
    converter* con = dict.lookup(x);
    if(con != NULL)
        output = con->convert(num);
    else
        output = "Invalid";
    cout << "Result is:  "<< output << "\n";
    return 0;
}
 
