#include <iostream>
#include <string>

using namespace std;
//주문 정보를 저장하는 구조체
struct orderNode{
    string roomLeader;
    string orderer;
    string part;
    string storeName;
    string menu;
    int price;
    string phoneNum;
    string accout;
    //bool paid = false; //결제 여부
    orderNode* next;
};

//메뉴판 정보를 불러오기 위한 구조체
struct storeMenu{
    string menuName;
    int price;
};


class Order{
    private :
        int count; // 총 주문 갯수
        orderNode* head; // linked list로 구현 head

    public: 
        Order(); // constructor, 최대 방 개수 100개로 제한, 메뉴 개수 15개로 제한
        ~Order(); // destructor
        //void searchOrder(); 
        void createOrder(string storeName, string leader, store& store);
        //void deleteOrder();
        //void updateOrder();  
        void printMenu();
        void printOrder();
        //void showOrder();  
        //bool isEmpty();
        storeMenu* setMenuInformation(string storeName);   
};