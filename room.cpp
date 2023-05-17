#include <iostream>
#include <string>
#include "room.h"


Room::Room(){
    head = nullptr;
    count = 0;
};

Room::~Room(){
    //빈 노트를 하나 만들어 헤드의 주솟값을 넣어준다.
    roomNode* current = head;
    //헤드부터 시작해 하나씩 노드를 건너가며 동적할당 된 메모리를 지워준다
    //만약 현재 노드가 비워져있다면 반복문을 종료한다.
    while(current != nullptr){
        roomNode* next = current -> next;
        delete current;
        current = next;
    }
    //마지막으로 헤드만 남았다면 헤드를 초기화 해준다.
    head = nullptr;
};

void Room::createRoom(){
    //동적할당을 통해 새로운 노드를 만든다.
    roomNode* newRoom = new roomNode();
    //새로운 노드에 입력할 데이터를 입력받는다 (출력 + 입력)
    cout << "주문자 이름을 입력하세요: ";
    cin >> newRoom->orderer;
    cout << "가게 이름을 입력하세요: ";
    cin >> newRoom->storeName;
    cout << "방장의 계좌번호를 입력하세요: ";
    cin >> newRoom->account;
    cout << "방장의 핸드폰 번호를 입력하세요: ";
    cin >> newRoom->phoneNum;
    cout << "주문을 배달 받을 장소의 주소를 입력하세요";
    cin >> newRoom->place;
    //cout << "주문 마감 시간을 입력하세요 (x시 x분), x만 입력해주세요";
   // cin >> newRoom->time->hour >> newRoom->time->min;
    
    //새로운 노드의 연결고리를 비워둔다.
    newRoom->next = nullptr;
    //만약 헤드뒤에 노드가 하나도 없다면 헤드 뒤로 새로 생성된 노드를 연결한다.
    if (head == nullptr){
        head = newRoom;
    }
    //그렇지 않다면 헤드부터 시작하여 하나씩 노드를 건너가며 꼬리가 빈 노드를 찾는다.
    else {
        roomNode* current = head;
        while (current->next != nullptr){
            current = current->next;
        }
        //꼬리가 빈 노드를 찾았다면 그 노드에 newNode를 연결시킨다
        current->next = newRoom;
    }
};
void Room::deleteRoom(){
    print(); // 전체 방 출력
    string name; // 검색 받을 이름
    cout<< "===> Type student name : ";
    cin >> name;
    roomNode * prev;
    roomNode* curr = head;
    while(curr != NULL && curr -> orderer != name){ // 값을 찾을 때까지 OR 값이 없으면
    prev = curr;
    curr = curr ->link;
    }
    if (curr!=NULL){ // 값을 찾았다면 삭제
    if(curr == head) head = curr->link;
    else prev ->link = curr ->link;
    delete curr;
    }
    else{
    cout<<"There is no data"<<endl;
    }
};

void Room::updateRoom(){

}; 
void Room::print(){
  roomNode *cur = NULL;
  cout<< endl<<"Orderer   Store   Account   Phonenumber    Place   Time"<<endl;
  for(cur =head; cur != NULL; cur = cur->link){ // 데이터의 끝까지 출력
    cout << cur-> orderer<<"   "<<cur->storeName <<"   "<< cur ->account<< "   "<< cur-> phoneNum<<"    " <<cur ->place<<"    "<< <<endl; // time 구현 못함
  }
};
void Room::showMenu(){

};
bool Room::isEmpty(){
    return (head == NULL);
};
void Room::updateMenu(){
    print(); // 전체 방 출력
    string name; // 검색 받을 이름
    cout<< "===> Type student name : ";
    cin >> name;
    while(curr != NULL && curr -> orderer != name){ // 값을 찾을 때까지 OR 값이 없으면
    prev = curr;
    curr = curr ->link;
    }
    if (curr!=NULL)

};