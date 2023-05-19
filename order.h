#include <iostream>
#include <string>

using namespace std;

struct orderNode{
    string storeName;
    string menu;
    int price;
    string phoneNum;
    string accout;
    //bool paid = false; //결제 여부 
    orderNode* next;
};


class Order{
    private :
        int count; // 총 주문 갯수
        orderNode* head; // linked list로 구현 head

    public: 
        Order(); // constructor, 최대 방 개수 100개로 제한, 메뉴 개수 15개로 제한
        ~Order(); // destructor
        //void searchOrder(); 
        void createOrder();
        //void deleteOrder();
        //void updateOrder();  
        //void printMenu();
        //void printOrder(); 
        //void showOrder();  
        //bool isEmpty();   
};
