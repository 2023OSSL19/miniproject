#include <iostream>
#include <string>
//아무래도 방은 구조체로 생성해야 할 것 같음.

using namespace std;

typedef struct {
    string name;
    string menu;
    int price;
    string phoneNum;
    string accout;
    Order* next;
}Order;

class GroupDelivery{
    private:
        
    public:
        GroupDelivery();
        ~GroupDelivery();
        void chooseMenu();
};