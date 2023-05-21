#include <iostream>
#include <fstream>
#include <string>
#include "Room.h"


using namespace std;
string fristSelection();
string leaderSelection();
string memberSelection();
bool logIn();

int main(){
    //시나리오를 위한 방 하나 제작
    Room* a = new Room();
    Order* b = new Order();
    Store* c = new Store();
    a->createBaseRoom();
    if(logIn()){
        cout << "\n로그인에 성공하셨습니다!" << endl;
        string big_selection;
        string leader;
        string member;
        while(1){
            big_selection = fristSelection();
            if (big_selection == "A"){
                while(1){
                    leader = leaderSelection();
                    if(leader == "A")
                        a->createRoom(*c);
                    else if (leader == "B")
                        a->deleteRoom();
                    else if (leader == "C")
                        a->updateRoom(*c);
                    else if (leader == "D")
                        a->printRoom();
                }
            }
            else if (big_selection == "B"){
                while(1){
                    member = memberSelection();
                    if(member == "A"){
                        c->showAllStore();
                        a->searchRoom();
                        string name; // 검색 받을 이름
                        string storeName;
                        cout<< "===> 참가하고 싶은 방의 방장 이름을 입력하세요: ";
                        cin >> name;
                        roomNode * prev = nullptr;
                        roomNode* current = a->returnHead();
                        while(current != nullptr && current -> orderer != name){ // 값을 찾을 때까지 OR 값이 없으면
                            prev = current;
                            current = current->next;
                        }
                        if (current!=nullptr){ // 값을 찾았다면
                            storeName = current->storeName;
                        } else{
                            cout<<"방을 찾을 수 없습니다."<<endl;
                        }
                        b->createOrder(storeName, name, *c);
                    }
                    else if(member == "D"){
                        a->printRoom();
                        b->printOrder();
                    }
                    else if (member == "E"){
                        string name;
                        c->showAllStore();
                        cout << "가게 이름을 입력하세요: ";
                        cin >> name;
                        c->showMenu(name);
    
                    }
                }

            }
            else if (big_selection == "C"){
                a->printRoom();
                b->printOrder();
                cout << "\n----------주문 내역----------" << endl;

            }
        }
    }
    else{
        cout << "로그인에 실패하셨습니다." << endl;
    }

    delete a;
    delete b;
    return 0;
}
string fristSelection(){
    string m;
    cout << "\nA: 방장 권한으로 참여하기" << endl;
    cout << "B: 팀원 권한으로 참여하기" << endl;
    cout << "원하시는 기능을 선택하세요(종료하려면 0): ";
    cin >> m;
    if (m == "0")
        exit(0);

    return m;
}
string leaderSelection(){
    string m;
    cout << "\nA: 방 만들기" << endl;
    cout << "B: 방정보 수정하기" << endl;
    cout << "C: 방 삭제하기" << endl;
    cout << "D: 방 정보 보기" << endl;
    cout << "E: 방 주문 보기" << endl;
    cout << "원하시는 기능을 선택하세요(종료하려면 0): ";
    cin >> m;
    if(m == "0"){
        exit(0);
    }
    return m;
}
string memberSelection(){
    string m;
    cout << "\nA: 주문 추가하기" << endl;
    cout << "B: 주문 수정하기" << endl;
    cout << "C: 주문 삭제하기" << endl;
    cout << "D: 주문 출력하기" << endl;
    cout << "E: 메뉴판 보기" << endl;
    cout << "원하시는 기능을 선택하세요(종료하려면 0): ";
    cin >> m;
    if (m == "0")
        exit(0);

    return m;
}
bool logIn(){
    string inputId;
    string inputPw;

    cout << "어플에 오신걸 환영합니다!" << endl;
    cout << "id와 비밀번호를 입력해주세요." << endl;
    cout << "id: ";
    cin >> inputId;
    cout << "pw: ";
    cin >> inputPw;

    ifstream inputFile("id_pw.txt");
    string id, pw;

    while(inputFile >> id >> pw){
        if (id == inputId && pw == inputPw)
            return true;
    }
    return false;
}