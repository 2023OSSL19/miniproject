#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "order.h"

using namespace std;

#define Max 20

storeMenu* chikenStore = new storeMenu[Max];
storeMenu* riceStore = new storeMenu[Max];
storeMenu* coffeeStore = new storeMenu[Max];
storeMenu* padackStore = new storeMenu[Max];

Order::Order(){
    head = nullptr;
    count = 0;
    //교폰치킨 정보 불러오기
    ifstream chieken("교폰치킨.txt");

    int index = 0;
    string menuName;
    int price;

    while(index < Max && chieken >> menuName >> price){
        chikenStore[index].menuName = menuName;
        chikenStore[index].price = price;
        index++;
    }
    chieken.close();
    //덥덥팦 정보 불러오기
    ifstream rice("덥덥팦.txt");
    
    index = 0;

    while(index < Max && rice >> menuName >> price){
        riceStore[index].menuName = menuName;
        riceStore[index].price = price;
        index++;
    }
    rice.close();
    //어디야커피 정보 불러오기
    ifstream coffee("어디야커피.txt");
        
    index = 0;

    while(index < Max && coffee >> menuName >> price){
        coffeeStore[index].menuName = menuName;
        coffeeStore[index].price = price;
        index++;
    }
    coffee.close();
    //치코파턱정보 불러오기
    ifstream padack("치코파덕.txt");
    
    index = 0;

    while(index < Max && padack >> menuName >> price){
        padackStore[index].menuName = menuName;
        padackStore[index].price = price;
        index++;
    }
    padack.close();
    
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
    cout << "\n주문 가능한 가게 목록" << endl;
    cout << "A: 교폰치킨" << endl;
    cout << "B: 덥덥팝" << endl;
    cout << "C: 어디야커피" << endl;
    cout << "D: 치코파덕" << endl;
    cout << "주문을 진행할 가게를 선택하세요: ";    
    string selectStore;
    cin >> selectStore;
    if (selectStore == "A"){
        newOrder->storeName = "교폰치킨";
        printMenu(chikenStore,7);
    }
    else if (selectStore == "B"){
        newOrder->storeName = "덥덥팦";
    }
    else if (selectStore == "C"){
        newOrder->storeName = "어디야커피";
    }
    else if (selectStore == "D"){
        newOrder->storeName = "치코파덕";
    }
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
    //printOrder();
};
/*
void Order::deleteOrder(){

};

void Order::updateOrder(){

};
*/
void Order::printMenu(){
    
    cout << "\n메뉴" << setw(30) << "가격" << endl;
    cout << "---------------교폰치킨---------------" << endl;
    for(int i=0;i<7;i++){
        cout << setw(15) << left << chikenStore[i].menuName;
        cout << setw(20) << right << chikenStore[i].price << endl;
    }

    cout << "\n메뉴" << setw(30) << "가격" << endl;
    cout << "---------------덥덥팦---------------" << endl;
    for(int i=0;i<7;i++){
        cout << setw(15) << left << riceStore[i].menuName;
        cout << setw(20) << right << riceStore[i].price << endl;
    }

    cout << "\n메뉴" << setw(30) << "가격" << endl;
    cout << "---------------어디야커피---------------" << endl;
    for(int i=0;i<7;i++){
        cout << setw(15) << left << coffeeStore[i].menuName;
        cout << setw(20) << right << coffeeStore[i].price << endl;
    }

    cout << "\n메뉴" << setw(30) << "가격" << endl;
    cout << "---------------치코파덕---------------" << endl;
    for(int i=0;i<7;i++){
        cout << setw(15) << left << padackStore[i].menuName;
        cout << setw(20) << right << padackStore[i].price << endl;
    }

};

/*
void Order::printOrder(){

};
*/