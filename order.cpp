#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "order.h"
//#include "Room.h"

using namespace std;

#define Max 20

Order::Order(){ // 초기값 세팅
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

void Order::createOrder(string storeName,string leader, Store& store, string id){
    int menuNum;
    int i=0; // menu 저장을 위한 변수
    //동적할당을 통해 새로운 노드를 만든다.
    if(alreadyExistOrder(id, storeName)){ // 사용자는 가게마다 한 개씩 방을 만들 수 있음
        cout << "이미 방이 존재합니다."<<endl;
        return;
    }
    orderNode* newOrder = new orderNode();
    cout << leader << "님의 " << storeName << "방에 참가하셨습니다." << endl;
    cout << "주문을 진행해 주세요." << endl;
    newOrder->roomLeader = leader;
    newOrder->storeName = storeName;
    newOrder -> id = id;
    cout << "이름을 입력해주세요: ";
    cin >> newOrder-> orderer;
    store.showMenu(newOrder->storeName); // 해당 가게의 메뉴 출력
    storeMenu* storeInformation= setMenuInformation(storeName, newOrder); // 해당 가게의 가격과 메뉴 이름을 struct 배열에 저장
    newOrder->price =0; 
    newOrder ->menuCount =0;
    while(1){
        cout << "메뉴를 번호로 선택하세요 (종료하려면 0 입력): ";
        cin >> menuNum;
        if(menuNum==0 || i >=20){ // menuNum이 0이거나 최대 넣을 수 있는 계수는 20개
            break;
        }
        if(menuNum>20|| newOrder->menuKind<menuNum){ // 잘못 입력되었을 경우
            cout << "다시 입력해주세요."<<endl;
            continue;
        }
        // price와 메뉴이름을 추가
        newOrder->price += storeInformation[menuNum-1].price; 
        newOrder -> menu[i] = storeInformation[menuNum-1].menuName;
        newOrder->menuCount++;
        i++;
    }
    cout<< "은행을 입력하세요: ";
    cin >> newOrder -> bank;
    cout << "계좌번호를 입력하세요: ";
    cin >> newOrder->accout;
    cout << "핸드폰 번호를 입력하세요: ";
    cin >> newOrder->phoneNum;
    
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
    count++;
    cout << "\n주문이 추가되었습니다!" << endl;
};

void Order::deleteOrder(string id){
    if(isEmpty(id)){ // 해당 id로 만든 주문이 없으면 취소
        cout <<"주문 목록이 없습니다!"<<endl;
        return;
    }
    printOrder(id); // order를 출력
    string storeName; // 검색 받을 가게 이름
    cout<<"===> 삭제할 주문의 가게 이름을 입력하세요: ";
    cin >> storeName;
    orderNode* prev = nullptr;
    orderNode* current = head;
    while(current != nullptr && !(current -> id == id &&current -> storeName == storeName)){ // 값을 찾을 때까지 OR 값이 없으면
        prev = current;
        current = current ->next;
    }
    if (current != nullptr){
        if(current == head)
            head = current->next;
        else
            prev -> next = current ->next;
        delete current;
    }
    else{
        cout<<"해당 주문이 존재하지 않습니다"<<endl;
    }

};


void Order::printOrder(string id){
    if(isEmpty(id)){ // id로 만든 주문이 없으면 취소
        cout <<"주문 목록이 없습니다!"<<endl;
        return;
    }
    bool exist =false;
    orderNode *prev = nullptr;
    orderNode *cur = head;
    for(cur =head; cur != nullptr; cur = cur->next){ // 데이터의 끝까지 출력
        if(cur -> id == id){ // id가 같으면 모두 출력
            if(exist == false){ // 처음만 밑의 줄 출력
                cout<< endl<<setw(11)<<left<<"RoomLeader" <<setw(10)<<left << "Store" <<setw(10) <<left  <<"Orderer"    <<setw(10)<<left <<"PhoneNum" <<setw(10)<<left<<  "Bank"<<setw(10)<<left << "Account"<<setw(10)<<left <<"Price"<<setw(10)<<left<<"menu"<<endl;
            }
            exist = true;
            cout << setw(11)<< left<<cur->roomLeader<<setw(15)<< left<<cur->storeName<<setw(10)<<left<<cur-> orderer <<setw(10)<<left<< cur->phoneNum <<setw(10)<<left<<cur->bank<< setw(10)<<left<<cur-> accout <<setw(10)<<left<<cur->price;
            for(int i=0; i<cur->menuCount; i++){
                cout<< cur->menu[i];
                if(!(i == cur->menuCount-1)){
                    cout<< ", ";
                }

            }
            cout<< endl;
        }
    }
    if(exist ==false){
        cout<< "해당 주문이 존재하지 않습니다."<< endl;
    }

};

storeMenu* Order::setMenuInformation(string storeName, orderNode *o){
    storeMenu* storeInformation = new storeMenu[Max]; // 받을 struct 선언
    string fileName = storeName +".txt"; // file name 설정
    ifstream file(fileName);
    int index =0;
    string menuName;
    int price;
    while(index <20 && file >>menuName >>price){ // 줄을 읽어서 이름과 가격을 넣음
        storeInformation[index].menuName = menuName;
        storeInformation[index].price = price;
        index++;
    }
    o->menuKind = index; // 메뉴 종류가 몇 가지인지 부여
    file.close();
    return storeInformation;

}
bool Order::alreadyExistOrder(string id, string storeName){ // 한 id로 만들 수 있는 방은 가게마나 한 개씩임, 두 값을 동시에 가지면 true
    orderNode * prev = nullptr;
    orderNode* current = head;
    for(current =head; current != nullptr; current = current->next){ // 데이터의 끝까지 출력
        if(current -> id == id && current->storeName==storeName){
            return true;
        }

    }
    return false;
}
void Order::updateOrder(Store& store , string id){
    if(isEmpty(id)){ // id로 만든 주문이 없으면 취소
        cout <<"주문 목록이 없습니다!"<<endl;
        return;
    }
    string storeName;
    int menuNum;
    int i=0;
    printOrder(id); // 전체 방 출력
    orderNode* current = head;
    orderNode* prev = nullptr;
    string name; // 검색 받을 이름
    cout<< "===> : 업데이트할 방의 가게 이름을 입력하세요: ";
    cin >> name;
    while(current != nullptr && !(current -> storeName == name&&current ->id == id)){ // 값을 찾을 때까지 OR 값이 없으면
        prev = current;
        current = current ->next;
    }
    if (current!=nullptr){
        cout << "이름을 입력해주세요: ";
        cin >> current-> orderer;
        store.showMenu(current->storeName); // 해당 가게의 메뉴 출력
        storeMenu* storeInformation= setMenuInformation(current->storeName, current); // 가격과 메뉴 이름 세팅
        current->price =0;
        current->menuCount =0;
        while(1){
            cout << "메뉴를 번호로 선택하세요(종료하려면 0 입력): ";
            cin >> menuNum;
            if(menuNum==0 || i >=20){ // 0이거나 최대 개수를 넘으면 취소
                break;
            }
            if(menuNum>20|| current->menuKind<menuNum){ // 잘못 되었을 경우
                cout << "다시 입력해주세요."<<endl;
                continue;
            }
            current->price += storeInformation[menuNum-1].price;
            current -> menu[i] = storeInformation[menuNum-1].menuName;
            current->menuCount++;
            i++;
        }
        cout<< "은행을 입력하세요: ";
        cin >> current -> bank;
        cout << "계좌번호를 입력하세요: ";
        cin >> current->accout;
        cout << "핸드폰 번호를 입력하세요: ";
        cin >> current->phoneNum;
        cout << "업데이트가 완료 되었습니다." << endl;
    } 
    else{
        cout << "방을 찾을 수 없습니다." << endl;
    }
}
void Order::printOrderForMaster(string name, string storeName){
    if(isEmptyForMaster()){ // 주문목록 자체가 없으면 취소
        cout <<"주문 목록이 없습니다!"<<endl;
        return;
    }
    bool exist =false;
    orderNode *prev = nullptr;
    orderNode *cur = head;
    for(cur =head; cur != nullptr; cur = cur->next){ // 데이터의 끝까지 출력하면서 정보를 출력
        if(cur -> roomLeader == name && cur ->storeName == storeName){
            if(exist == false){
                cout<< endl<<setw(11)<<left<<"RoomLeader" <<setw(10)<<left << "Store" <<setw(10) <<left  <<"Orderer"    <<setw(10)<<left <<"PhoneNum" <<setw(10)<<left<<  "Bank"<<setw(10)<<left << "Account"<<setw(10)<<left <<"Price"<<setw(10)<<left<<"menu"<<endl;
            }
            exist = true;
            cout << setw(11)<< left<<cur->roomLeader<<setw(15)<< left<<cur->storeName<<setw(10)<<left<<cur-> orderer <<setw(10)<<left<< cur->phoneNum <<setw(10)<<left<<cur->bank<< setw(10)<<left<<cur-> accout <<setw(10)<<left<<cur->price;
            for(int i=0; i<cur->menuCount; i++){
                cout<< cur->menu[i];
                if(!(i == cur->menuCount-1)){
                    cout<< ", ";
                }

            }
            cout<< endl;
        }
    }
    if(exist ==false){
        cout<< "해당 주문이 존재하지 않습니다."<< endl;
    } 
}
void Order::printAllOrder(){ // admin에서 보통 사용
    if(isEmptyForMaster()){ // 주문 목록 자체가 없으면 취소
        cout <<"주문 목록이 없습니다!"<<endl;
        return;
    }
    bool exist =false;
    orderNode *prev = nullptr;
    orderNode *cur = head;
    for(cur =head; cur != nullptr; cur = cur->next){ // 데이터의 끝까지 출력
        if(exist == false){
            cout<< endl<<setw(11)<<left<<"RoomLeader" <<setw(10)<<left << "Store" <<setw(10) <<left  <<"Orderer"    <<setw(10)<<left <<"PhoneNum" <<setw(10)<<left<<  "Bank"<<setw(10)<<left << "Account"<<setw(10)<<left <<"Price"<<setw(10)<<left<<"menu"<<endl;
        }
        exist = true;
        cout << setw(11)<< left<<cur->roomLeader<<setw(15)<< left<<cur->storeName<<setw(10)<<left<<cur-> orderer <<setw(10)<<left<< cur->phoneNum <<setw(10)<<left<<cur->bank<< setw(10)<<left<<cur-> accout <<setw(10)<<left<<cur->price;
        for(int i=0; i<cur->menuCount; i++){
            cout<< cur->menu[i];
            if(!(i == cur->menuCount-1)){
                cout<< ", ";
            }

        }
        cout<< endl;
    }
    if(exist ==false){
        cout<< "해당 주문이 존재하지 않습니다."<< endl;
    }

};
bool Order::isEmpty(string id){ // id로 만든 주문 목록이 있는지 확인
    if(head == nullptr){
        return true;
    }
    orderNode * prev = nullptr;
    orderNode* current = head;
    for(current =head; current != nullptr; current = current->next){ // 데이터의 끝까지 출력
        if(current -> id == id){
            return false;
        }
    }
    return true;
    
};
bool Order::isEmptyForMaster(){ // 주문이 있는지
    return (head==nullptr);
}