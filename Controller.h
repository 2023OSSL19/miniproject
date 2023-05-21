#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Controller{
    private :
        int count;
    public :
        Controller();
        bool logIn(string *user);
        void join();
        
};