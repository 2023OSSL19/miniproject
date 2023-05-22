#include <iostream>
#include <fstream>
#include <string>
#include "Room.h"
#include "Menu.h"
#include "Controller.h"


using namespace std;

bool logIn(string* user);

int main(){
    //시나리오를 위한 방 하나 제작
    Menu* m = new Menu();
    Controller* l = new Controller();
    Room* a = new Room();
    Order* b = new Order();
    Store* c = new Store();
    string id;
    //a->createBaseRoom(); // 시험을 위해 제작(프로토 타입)
    string selection;
    while(1){
        selection = m-> loginSelection();
        if(selection =="A"){
            if(l->logIn(&id)){
                cout << "\n로그인에 성공하셨습니다!" << endl;
                if(id == "admin"){
                    while(1){
                        selection = m-> adminSelection();
                        if(selection== "A"){ // 가게의 메뉴 출력 
                            c-> showAllStore();
                            string storeName;
                            cout << "가게 이름을 입력하세요: ";
                            cin >> storeName;
                            c->showMenu(storeName);
                        }
                        else if (selection =="B"){ // 가게 메뉴 만들기
                            c->createMenu(); 
                        }
                        else if (selection =="C"){ // 가게 메뉴 업데이트
                            string storeName;
                            c->showAllStore();
                            cout <<"가게 이름을 입력하세요: ";
                            cin >> storeName;
                            c->updateMenu(storeName);
                        }
                        else if (selection =="D"){ // 모든 룸 출력
                            a-> printAllRoom();
                        }
                        else if(selection == "E"){ // 모든 주문 출력
                            b->printAllOrder();
                        }
                        else if (selection =="0"){ // 뒤로 가기
                            break;
                        }
                        else { // 이상 값이 들어올 때
                            cout << "다시 입력하세요"<<endl;
                        }
                    }
                    continue;
                }
                while(1){
                    selection = m->fristSelection();
                    if (selection == "A"){
                        while(1){
                            selection = m->leaderSelection();
                            if(selection == "A") // Room 제작
                                a->createRoom(*c, id);
                            else if (selection == "B") // Room update
                                a->updateRoom(*c, id); 
                            else if (selection == "C") // Room 삭제
                                a->deleteRoom(id);
                            else if (selection == "D") // Room print
                                a->printRoom(id);
                            else if (selection == "E"){ // Room 찾기
                                if(!(a->isEmpty(id))){
                                    c->showAllStore();
                                    a->searchRoom(id);
                                }
                            }

                            else if (selection == "F"){ // 본인의 방에 있는 주문 목록을 출력
                                if(!a->isEmpty(id)){
                                    a->printRoom(id);
                                    string name;
                                    string storeName;
                                    roomNode* r = a->getRoomNodeWithStoreName(id);
                                    if(r ==nullptr){ // 방이 없으면 취소
                                        continue;
                                    }
                                    storeName = a-> getStoreName(r);
                                    name = a->getLeader(r);
                                    b-> printOrderForMaster(name, storeName);
                                }
                                else{
                                    cout<< "주문 목록이 없습니다."<<endl;
                                }

                            }
                            else if (selection == "G"){ // 가게 메뉴를 출력
                                c-> showAllStore();
                                string storeName;
                                cout << "가게 이름을 입력하세요: ";
                                cin >> storeName;
                                c->showMenu(storeName);
                            }
                            else if (selection == "0"){ // 뒤로 가기
                                break;
                            }
                            else { // 이상 값 처리
                                cout << "다시 입력하세요"<<endl;
                            }
                        }
                    }
                    else if (selection == "B"){
                        while(1){
                            selection = m->memberSelection();
                            if(selection == "A"){ // 주문 생성
                                if(!a->isEmptyForMaster()){
                                    c->showAllStore();
                                    a->printAllRoom();
                                    string name; // 검색 받을 이름
                                    string storeName;
                                    a-> setStoreNameAndLeader(&storeName, &name);
                                    b->createOrder(storeName, name, *c, id);
                                }
                                else{
                                    cout << "방이 존재하지 않습니다."<<endl;
                                }

                            }
                            else if (selection== "B"){ // 주문 업데이트
                                b->updateOrder(*c,id); 
                            }
                            else if (selection =="C"){ // 주문 삭제
                                b->deleteOrder(id);
                            }
                            else if(selection == "D"){ // 주문 출력 
                                b->printOrder(id);
                            }
                            else if (selection == "E"){ // 가게 메뉴 출력
                                c-> showAllStore();
                                string storeName;
                                cout << "가게 이름을 입력하세요: ";
                                cin >> storeName;
                                c->showMenu(storeName);
                            }
                            else if(selection == "0"){ // 뒤로 가기
                                break; 
                            }
                            else { // 이상값 처리
                            cout << "다시 입력하세요";
                            }
                        }

                    }
                    else if (selection =="0"){ // 뒤로 가기
                        break;
                    }
                    else {
                        cout << "다시 입력하세요"<<endl;
                    }
                }
            }
            else{
                cout << "로그인에 실패하였습니다!"<< endl;
            }
        }
        else if(selection == "B"){ // 로그인
            l->join();
        }
        else if (selection == "0"){ // 종료시
            delete a;
            delete b;
            delete l;
            delete m;
            exit(0);
        }
        else { // 이상 값 처리
            cout <<"다시 입력하세요."<<endl;
        }
    }



    return 0;
}
