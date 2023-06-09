#include <iostream>
#include <string>
#include <iomanip>
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

void Room::createBaseRoom(){
    //동적할당을 통해 새로운 노드를 만든다.
    roomNode* newRoom = new roomNode();
    newRoom->orderer = "handong";
    newRoom->storeName = "교폰치킨";
    newRoom->account = 123456789;
    newRoom -> bank = "kakao";
    newRoom->phoneNum = 01011111111;
    newRoom->place = "handong";
    newRoom->t1.hour = 12;
    newRoom->t1.min = 10;
    newRoom -> id = "hyukjin0419";
    
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
}
void Room::createRoom(Store& store, string id){
    string storeName;
    cout << "\n주문 가능한 가게 목록" << endl;
    store.showAllStore(); // store 안의 함수를 호출하는 방식으로 가게를 출력
    while(1){
        cout << "주문을 진행할 가게를 선택하세요: "; 
        cin >> storeName;
        if(fileExists(storeName)){ // 해당 가게가 존재하는지 확인
            break;
        }
        else{
            cout << "존재하지 않는 가게 입니다."<<endl;
        }
    }
    if(alreadyExistRoom(id, storeName)){ // 방이 중복되는지 확인
        cout<< "이미 방이 존재합니다"<<endl;
        return;
    }
    //동적할당을 통해 새로운 노드를 만든다.
    roomNode* newRoom = new roomNode();
   //새로운 노드에 입력할 데이터를 입력받는다 (출력 + 입력)

    newRoom -> id = id;
    newRoom-> storeName = storeName;



    cout << "주문자 이름을 입력하세요: ";
    cin >> newRoom->orderer;
    cout << "방장의 계좌번호를 입력하세요: ";
    cin >> newRoom->account;
    cout << "방장의 은행을 입력하세요: ";
    cin >> newRoom -> bank;
    cout << "방장의 핸드폰 번호를 입력하세요: ";
    cin >> newRoom->phoneNum;
    cout << "주문을 배달 받을 장소의 주소를 입력하세요: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, newRoom->place);
    while(1){
        cout << "주문 마감 시간을 입력하세요 (x시 x분), x만 입력해주세요";
        cin >> newRoom -> t1.hour >> newRoom->t1.min;
        if(newRoom ->t1.hour>=0 && newRoom ->t1.hour<24 &&newRoom->t1.min>=0&&newRoom->t1.min<60){ // 시간이 잘못 입력되었을 경우
            break;
        }
        else{
            cout<< "시간을 다시 입력해주세요."<<endl;
        }
    }

     
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
};


void Room::deleteRoom(string id){
    if(isEmpty(id)){ // id로 만든 방이 존재하는지 확인
        cout<< "방이 존재하지 않습니다."<<endl;
        return;
    }
    printRoom(id); // 방 출력
    string name; // 검색 받을 이름
    cout<< "===> 삭제할 방의 가게 이름을 입력하세요: ";
    cin >> name;
    roomNode * prev = nullptr;
    roomNode* current = head;
    while(current != nullptr && !(current -> storeName == name&&current ->id == id)){ // 값을 찾을 때까지 OR 값이 없으면
        prev = current;
        current = current ->next;
    }
    if (current!=nullptr){ // 값을 찾았다면 삭제
        if(current == head)
            head = current->next;
        else
            prev ->next = current ->next;
        delete current;
        this->count--;
        cout << "삭제 되었습니다!"<<endl;
    } 
    else{
        cout<<"방을 찾을 수 없습니다."<<endl;
    }

};
void Room::printRoom(string id){
    if(isEmpty(id)){ // id로 만든 방이 존재하는지 확인
        cout<< "방이 존재하지 않습니다."<<endl;
        return;
    }
    bool exist =false;
    roomNode * prev = nullptr;
    roomNode* current = head;
    for(current =head; current != nullptr; current = current->next){ // 데이터의 끝까지 출력
        if(current -> id == id){
            if(exist == false){
                cout<<endl<<setw(10)<<left<<"Orderer" << setw(10)<<left<< "Store"<< setw(10)<<left<< "Bank"<< setw(10)<<left<<"Account"  << setw(12)<<left<<"Phonenumber" <<setw(10)<<left<<"Place"   <<setw(10)<<left<<"Time"<<endl;
            }
            exist = true;
            cout <<left<<setw(10) <<current-> orderer << setw(15)<<left<<current->storeName  <<setw(10)<<left<<current->bank<< setw(10)<<left<<current ->account  << setw(10)<<left<<current-> phoneNum  << setw(10)<<left<<current ->place <<setw(0)<<left<<current->t1.hour<<setw(0)<<left<<":"<<current->t1.min << endl;
        }
    }
    if(exist ==false){
        cout<< "방이 존재하지 않습니다."<< endl;
    }   
}
void Room::printAllRoom(){
    if(isEmptyForMaster()){ // 방 자체가 존재하는지 확인
        cout<< "방이 존재하지 않습니다."<<endl;
        return;
    }
    roomNode *cur = nullptr;
    cout<<endl<<setw(10)<<left<<"Orderer" << setw(10)<<left<< "Store"<< setw(10)<<left<< "Bank"<< setw(10)<<left<<"Account"  << setw(12)<<left<<"Phonenumber" <<setw(10)<<left<<"Place"   <<setw(10)<<left<<"Time"<<endl;
    for(cur =head; cur != nullptr; cur = cur->next){ // 데이터의 끝까지 출력
        cout <<left<<setw(10) <<cur-> orderer << setw(15)<<left<<cur->storeName  <<setw(10)<<left<<cur->bank<< setw(10)<<left<<cur ->account  << setw(10)<<left<<cur-> phoneNum  << setw(10)<<left<<cur ->place <<setw(0)<<left<<cur->t1.hour<<setw(0)<<left<<":"<<cur->t1.min << endl;
    }
};

bool Room::isEmpty(string id){ // id로 만든 방이 있는지 확인
    if(head == nullptr){
        return true;
    }
    roomNode * prev = nullptr;
    roomNode* current = head;
    for(current =head; current != nullptr; current = current->next){ // 데이터의 끝까지 출력
        if(current -> id == id){
            return false;
        }
    }
    return true;
    
};
bool Room::isEmptyForMaster(){ // 방 자체가 존재하는지 확인
    return (head == nullptr);
}


void Room::updateRoom(Store& store, string id){
    string storeName;
    if(isEmpty(id)){ // 방 존재하는지 확인
        cout<< "방이 존재하지 않습니다."<<endl;
        return;
    }
    printRoom(id); // 전체 방 출력
    roomNode* current = head;
    roomNode* prev = nullptr;
    string name; // 검색 받을 이름
    cout<< "===> 업데이트할 방의 가게 이름을 입력하세요: ";
    cin >> name;
    while(current != nullptr && !(current -> storeName == name&&current ->id == id)){ // 값을 찾을 때까지 OR 값이 없으면
        prev = current;
        current = current ->next;
    }
    if (current!=nullptr){
        cout << "주문자 이름을 입력하세요: ";
        cin >> current->orderer;
        cout << "\n주문 가능한 가게 목록" << endl;
        store.showAllStore(); // store 안의 함수를 호출하는 방식으로 가게를 출력
        while(1){
            while(1){
                cout << "주문을 진행할 가게를 선택하세요: "; 
                cin >> storeName;
                if(fileExists(storeName)){ // 가게가 존재하는지
                    break;
                }
                else{
                    cout << "존재하지 않는 가게 입니다."<<endl;
                }
            }
            if(alreadyExistRoom(id, storeName)){ // 방이 이미 존재하는지 확인ㄴ
                cout<< "이미 방이 존재합니다"<<endl;
            }
            else{
                current->storeName = storeName;
                break;
            }
        }

        cout << "은행을 입력하세요: ";
        cin >> current -> bank;
        cout << "방장의 계좌번호를 입력하세요: ";
        cin >> current->account;
        cout << "방장의 핸드폰 번호를 입력하세요: ";
        cin >> current->phoneNum;
        cout << "주문을 배달 받을 장소의 주소를 입력하세요: ";
        cin >> current->place;
        while(1){
            cout << "주문 마감 시간을 입력하세요 (x시 x분), x만 입력해주세요";
            cin >> current -> t1.hour >> current->t1.min;
            if(current ->t1.hour>=0 && current ->t1.hour<24 && current->t1.min>=0&&current->t1.min<60){
                break;
            }
            else{
                cout<< "시간을 다시 입력해주세요."<<endl;
            }
        }

        printRoom(id);
        cout << "업데이트가 완료 되었습니다." << endl;
    } 
    else{
        cout << "방을 찾을 수 없습니다." << endl;
    }
};


bool Room::fileExists(string storeName){ // 가게 이름이 있는지 확인
    string fileName = storeName + ".txt";
    ifstream file(fileName);
    return file.good();
}
void Room::searchRoom(string id){
    if(isEmpty(id)){ // 방이 존재하는지 확인
        cout<< "방이 존재하지 않습니다."<<endl;
        return;
    }
    string name; // 검색 받을 이름
    bool exist =false;
    cout<< "===> 찾을 가게를 입력하세요: ";
    cin >> name;
    roomNode * prev = nullptr;
    roomNode* current = head;
    for(current =head; current != nullptr; current = current->next){ // 데이터의 끝까지 출력
        if(current -> storeName == name && current ->id == id){
            if(exist == false){
                cout<<endl<<setw(10)<<left<<"Orderer" << setw(10)<<left<< "Store"<< setw(10)<<left<< "Bank"<< setw(10)<<left<<"Account"  << setw(12)<<left<<"Phonenumber" <<setw(10)<<left<<"Place"   <<setw(10)<<left<<"Time"<<endl;
            }
            exist = true;
            cout <<left<<setw(10) <<current-> orderer << setw(15)<<left<<current->storeName  <<setw(10)<<left<<current->bank<< setw(10)<<left<<current ->account  << setw(10)<<left<<current-> phoneNum  << setw(10)<<left<<current ->place <<setw(0)<<left<<current->t1.hour<<setw(0)<<left<<":"<<current->t1.min << endl;
        }
    }
}
bool Room::alreadyExistRoom(string id, string storeName){ // id로 만들 수 있는 방은 가게 마다 1개
    roomNode * prev = nullptr;
    roomNode* current = head;
    for(current =head; current != nullptr; current = current->next){ // 데이터의 끝까지 출력
        if(current -> id == id && current->storeName==storeName){
            return true;
        }

    }
    return false;
};
void Room::searchAllRoom(){ // id와 관계없이 모든 방을 출력, admin에서 사용
    if(isEmptyForMaster()){
        cout<< "방이 존재하지 않습니다."<<endl;
        return;
    }
    string name; // 검색 받을 이름
    bool exist =false;
    cout<< "===> 찾을 가게를 입력하세요: ";
    cin >> name;
    roomNode * prev = nullptr;
    roomNode* current = head;
    for(current =head; current != nullptr; current = current->next){ // 데이터의 끝까지 출력
        if(current -> storeName == name){
            if(exist == false){
                cout<<endl<<setw(10)<<left<<"Orderer" << setw(10)<<left<< "Store"<< setw(10)<<left<< "Bank"<< setw(10)<<left<<"Account"  << setw(12)<<left<<"Phonenumber" <<setw(10)<<left<<"Place"   <<setw(10)<<left<<"Time"<<endl;
            }
            exist = true;
            cout <<left<<setw(10) <<current-> orderer << setw(15)<<left<<current->storeName  <<setw(10)<<left<<current->bank<< setw(10)<<left<<current ->account  << setw(10)<<left<<current-> phoneNum  << setw(10)<<left<<current ->place <<setw(0)<<left<<current->t1.hour<<setw(0)<<left<<":"<<current->t1.min << endl;
        }
    }
}
void Room::setStoreNameAndLeader(string *originStoreName, string *originName){ //order를 위한 정보 세팅 함수
    string name; // 검색 받을 이름
    string storeName;
    while(1){
        cout<< "===> 참가하고 싶은 방의 방장 이름을 입력하세요: ";
        cin >> name;
        cout <<"===> 참가하고 싶은 가게 이름을 입력하세요: ";
        cin >> storeName;
        roomNode * prev = nullptr;
        roomNode* current = head;
        while(current != nullptr && !(current -> orderer == name&&current->storeName == storeName)){ // 값을 찾을 때까지 OR 값이 없으면
            prev = current;
            current = current->next;
        }
        if (current!=nullptr){ // 값을 찾았다면
            // 필요한 값 세팅
            *originStoreName = storeName;
            *originName = name;
            return;
        }
        else cout<< "방을 찾을 수 없습니다."<<endl;
    }
}
roomNode* Room::getRoomNodeWithStoreName(string id){
    string storeName;
    while(1){
        cout<< "===> 가게 이름을 입력하세요: ";
        cin >> storeName;
        roomNode * prev = nullptr;
        roomNode* current = head;
        while(current != nullptr && !(current -> id == id&&current->storeName == storeName)){ // 값을 찾을 때까지 OR 값이 없으면
            prev = current;
            current = current->next;
        }
        if (current!=nullptr){ // 값을 찾았다면
            return current; // node return
        }
        else cout<< "방을 찾을 수 없습니다."<<endl;
            return nullptr;
    } 
}
roomNode* Room::getRoomNodeWithLeader(string id){
    string name;
    while(1){
        cout<< "===> 방장 이름을 입력하세요: ";
        cin >> name;
        roomNode * prev = nullptr;
        roomNode* current = head;
        while(current != nullptr && !(current -> id == id&&current->orderer == name)){ // 값을 찾을 때까지 OR 값이 없으면
            prev = current;
            current = current->next;
        }
        if (current!=nullptr){ // 값을 찾았다면
            return current;
        }
        else cout<< "방을 찾을 수 없습니다."<<endl;
            return nullptr;
    } 
}
string Room::getStoreName( roomNode* current){ // store 이름을 얻어오는 함수
    return current-> storeName;
}
string Room::getLeader(roomNode* current){ // 방장 정보를 얻어오는 함수
    return current->orderer;
}
bool Room::checkID(string id, roomNode* current){ // id가 일치하는지 확인하는 함수
    if(current ->id == id ){
        return true;
    }
    return false;
}