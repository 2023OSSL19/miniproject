#include <iostream>
#include <string>
#include "Store.h"

using namespace std;
//주문 정보를 저장하는 구조체
struct orderNode{
    string roomLeader; //roomleader
    string id; // 사용자의 id 값
    string orderer; // 주문자 이름
    string storeName; // 가게 이름
    int menuKind; // 스토어의 메뉴 종류 개수
    string menu[20]; // 어떤 메뉴를 시킬지에 대한 정보를 담는다.
    int menuCount; // menu를 몇 개 시켰는지 확인
    int price; // 총 가격
    string phoneNum; // 핸드폰 번호
    string accout; // 계좌
    string bank; // 은행
    orderNode* next; // 다음 node를 담는다.
};

//메뉴판 정보를 불러오기 위한 구조체
struct storeMenu{
    string menuName; // 메뉴
    int price;
};


class Order{
    private :
        int count; // 총 주문 갯수
        orderNode* head; // linked list로 구현 head

    public: 
        Order(); // constructor, 최대 방 개수 100개로 제한, 메뉴 개수 15개로 제한
        ~Order(); // destructor
        void createOrder(string storeName, string leader, Store& store, string id);//order를 만드는 함수
        void deleteOrder(string id);//order를 만드는 함수
        void updateOrder(Store& store , string id);// order를 업데이트 하는 함수
        void printOrder(string id);// 자신이 주문한 order를 print
        void printAllOrder(); // 모든 주문 정보를 print, 보통 amin에서 쓰인다.
        bool isEmpty(string id); // order가 비어있는지 확인
        storeMenu* setMenuInformation(string storeName, orderNode* o); // menu의 대한 정보를 struct에 저장하는 함수 
        bool alreadyExistOrder(string id, string storeName); // order가 이미 존재하는지 확인하는 함수
        void printOrderForMaster(string name, string storeName); // room에서 모든 주문을 확인할 때 사용하는 함수
        bool isEmptyForMaster(); // room이 비어있는지 확인, 이때는 room자체가 없는지 확인한다.

};
