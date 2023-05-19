#include <iostream>
#include <string>
#include "Order.h"

using namespace std;

Order::Order(){
    head = nullptr;
    count = 0;
};

Order::~Order(){
    orderNode* current = head;
    //헤드부터 시작해 하나씩 노드를 건너가며 동적할당 된 메모리를 지워준다
    //만약 현재 노드가 비워져있다면 반복문을 종료한다.
    while(current != nullptr){
        orderNode* next = current -> next;
        delete current;
        current = next;
    }
    //마지막으로 헤드만 남았다면 헤드를 초기화 해준다.
    head = nullptr;
};

void Order::createOrder(){
    //동적할당을 통해 새로운 노드를 만든다.
    orderNode* newOrder = new orderNode();
   //새로운 노드에 입력할 데이터를 입력받는다 (출력 + 입력)
    cout << "가게를 선택하세요: ";
    cin >> newOrder->storeName;
    cout << "메뉴를 선택하세요: ";
    cin >> newOrder->menu;
    cout << "계좌번호를 입력하세요: ";
    cin >> newOrder->accout;
    cout << "핸드폰 번호를 입력하세요: ";
    cin >> newOrder->phoneNum;
    //newOrder->price 계산하는 함수 생성해야함
    //paid는 어떻게 구별할 건지?
    
    //새로운 노드의 연결고리를 비워둔다.
    newOrder->next = nullptr;
    //만약 헤드뒤에 노드가 하나도 없다면 헤드 뒤로 새로 생성된 노드를 연결한다.
    if (head == nullptr){
        head = newOrder;
    }
    //그렇지 않다면 헤드부터 시작하여 하나씩 노드를 건너가며 꼬리가 빈 노드를 찾는다.
    else {
        orderNode* current = head;
        while (current->next != nullptr){
            current = current->next;
        }
        //꼬리가 빈 노드를 찾았다면 그 노드에 newNode를 연결시킨다
        current->next = newOrder;
    }
    cout << "\n 주문이 추가되었습니다!" << endl;
  //  printOrder();
};
/*
void Order::deleteOrder(){

};

void Order::updateOrder(){

};

void Order::printMenu(){

};

void Order::printOrder(){

};
*/