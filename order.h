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
    bool paid = false; //결제 여부 
    Order* next;
}order;


class Order{
    private :
        int count; // 총 주문 갯수
        room* head = nullptr; // linked list로 구현 head

    public: 
        Order(); // constructor, 최대 방 개수 100개로 제한, 메뉴 개수 15개로 제한
        ~Order(); // destructor
        void searchOrder(); 
        void createOrder();  
        void deleteOrder();  
        void updateOrder();  
        void print(); 
        void showOrder();  
        bool isEmpty();  
        void updateOrder(); 
}
