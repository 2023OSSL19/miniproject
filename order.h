#include <iostream>
#include <string>
#include "Store.h"

using namespace std;
//주문 정보를 저장하는 구조체
struct orderNode{
    string roomLeader;
    string id;
    string orderer;
    string storeName;
    string menu[20];
    int menuCount;
    int price;
    string phoneNum;
    string accout;
    string bank;
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
        void createOrder(string storeName, string leader, Store& store, string id);
        void deleteOrder(string id);
        void updateOrder(Store& store , string id);
        void printOrder(string id);
        void printAllOrder();
        //void showOrder();
        bool isEmpty();
        storeMenu* setMenuInformation(string storeName, orderNode* o); 
        bool alreadyExistOrder(string id, string storeName);
        void printOrderForMaster(string name, string storeName);
};
