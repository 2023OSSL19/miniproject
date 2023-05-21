#include <iostream>
#include <string>
#include "Room.h"

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
    newRoom->status = "방장";
    cout << "\n주문 가능한 가게 목록" << endl;
    cout << "A: 교폰치킨" << endl;
    cout << "B: 덥덥팝" << endl;
    cout << "C: 어디야커피" << endl;
    cout << "D: 치코파덕" << endl;
    while(1){
        cout << "주문을 진행할 가게를 선택하세요: "; 
        cin >> newRoom->storeSelection;
        if(newRoom->storeSelection>="A" && newRoom->storeSelection<="D"){ // 1~4 이하의 값을 입력받을 때 까지
            break;
        }
    }
    if (newRoom->storeSelection == "A"){
        newRoom->storeName = "교폰치킨";
    } else if (newRoom->storeSelection == "B") {
        newRoom->storeName = "덥덥팦";
    } else if (newRoom->storeSelection == "C") {
        newRoom->storeName = "어디야커피";
    } else if (newRoom->storeSelection == "D") {
        newRoom->storeName = "치코파덕";
    }

    cout << "방장의 계좌번호를 입력하세요: ";
    cin >> newRoom->account;
    cout << "방장의 은행을 입력하세요: ";
    cin >> newRoom -> bank;
    cout << "방장의 핸드폰 번호를 입력하세요: ";
    cin >> newRoom->phoneNum;
    cout << "주문을 배달 받을 장소의 주소를 입력하세요: ";
    cin >> newRoom->place;
    cout << "주문 마감 시간을 입력하세요 (x시 x분), x만 입력해주세요";
    cin >> newRoom->t1.hour >> newRoom->t1.min;
    
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
    cout << "\n방이 생성되었습니다!" << endl;
    this->count ++;
    printRoom();
};


void Room::deleteRoom(){
    printRoom(); // 전체 방 출력
    string name; // 검색 받을 이름
    cout<< "===> 삭제할 방의 방장 이름을 입력하세요: ";
    cin >> name;
    roomNode * prev = nullptr;
    roomNode* current = head;
    while(current != nullptr && current -> orderer != name){ // 값을 찾을 때까지 OR 값이 없으면
        prev = current;
        current = current ->next;
    }
    if (current!=nullptr){ // 값을 찾았다면 삭제
        if(current == head)
            head = current->next;
        else
            prev ->next = current ->next;
        delete current;
    } else{
        cout<<"방을 찾을 수 없습니다."<<endl;
    }
    this->count--;
};
void Room::printRoom(){
    roomNode *cur = nullptr;
    cout<< endl<<"Orderer   Status   Store  Bank Account   Phonenumber    Place   Time"<<endl;
    for(cur =head; cur != nullptr; cur = cur->next){ // 데이터의 끝까지 출력
        cout << cur-> orderer << "   " << cur->status << "  " << cur->storeName << "   " <<cur->bank<<"   "<< cur ->account << "   " << cur-> phoneNum << "    " << cur ->place << "    "<< cur->t1.hour<<":"<<cur->t1.min<<"    \n" << endl; // time 구현 못함
    }
};

bool Room::isEmpty(){
    return (head == nullptr);
};


void Room::updateRoom(){
    printRoom(); // 전체 방 출력
    roomNode* current = head;
    roomNode* prev = nullptr;
    string name; // 검색 받을 이름
    cout<< "===> : 업데이트할 방의 방장 이름을 입력하세요: ";
    cin >> name;
    while(current != nullptr && current -> orderer != name){ // 값을 찾을 때까지 OR 값이 없으면
        prev = current;
        current = current ->next;
    }
    if (current!=nullptr){
        cout << "주문자 이름을 입력하세요: ";
        cin >> current->orderer;
        cout << "가게 이름을 입력하세요: ";
        cin >> current->storeName;
        cout << "은행을 입력하세요: ";
        cin >> current -> bank;
        cout << "방장의 계좌번호를 입력하세요: ";
        cin >> current->account;
        cout << "방장의 핸드폰 번호를 입력하세요: ";
        cin >> current->phoneNum;
        cout << "주문을 배달 받을 장소의 주소를 입력하세요: ";
        cin >> current->place;
        cout << "주문 마감 시간을 입력하세요 (x시 x분), x만 입력해주세요";
        cin >> current -> t1.hour >> current->t1.min;
        printRoom();
        cout << "업데이트가 완료 되었습니다." << endl;
    } else{
        cout << "방을 찾을 수 없습니다." << endl;
    }
};

int Room::getStoreSeletion(){
    return 0; //임시 변수 
    //return this->storeSeletion;
}

roomNode* Room::returnHead(){
    return head;

}

bool fileExists(string fileName)
{
    ifstream file(fileName);
    return file.good();
}