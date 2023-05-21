#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Controller{
    private :
        int count;
    public :
        Controller(); // constructor
        bool logIn(string *user); // login 함수
        void join(); // 회원가입 함수
        
};