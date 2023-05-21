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
    a->createBaseRoom(); // 시험을 위해 제작(프로토 타입)
    string selection;
    while(1){
        selection = m-> loginSelection();
        if(selection =="A"){
            if(l->logIn(&id)){
                cout << "\n로그인에 성공하셨습니다!" << endl;
                if(id == "admin"){
                    while(1){
                        selection = m-> adminSelection();
                        if(selection== "A"){
                            c-> showAllStore();
                            string storeName;
                            cout << "가게 이름을 입력하세요: ";
                            cin >> storeName;
                            c->showMenu(storeName);
                        }
                        else if (selection =="B"){
                            c->createMenu();
                        }
                        else if (selection =="C"){
                            string storeName;
                            cout <<"가게 이름을 입력하세요: ";
                            cin >> storeName;
                            c->updateMenu(storeName);
                        }
                        else if (selection =="D"){
                            a-> printAllRoom();
                        }
                        else if(selection == "E"){
                            b->printAllOrder();
                        }
                        else if (selection =="0"){
                            break;
                        }
                        else {
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
                            if(selection == "A")
                                a->createRoom(*c, id);
                            else if (selection == "B")
                                a->updateRoom(*c, id);
                            else if (selection == "C")
                                a->deleteRoom(id);
                            else if (selection == "D")
                                a->printRoom(id);
                            else if (selection == "E"){
                                c->showAllStore();
                                a->searchRoom(id);
                            }

                            else if (selection == "F"){
                                if(!a->isEmpty(id)){
                                    a->printRoom(id);
                                    string name;
                                    string storeName;
                                    roomNode* r = a->getRoomNodeWithStoreName(id);
                                    storeName = a-> getStoreName(r);
                                    name = a->getLeader(r);
                                    b-> printOrderForMaster(name, storeName);
                                }
                                else{
                                    cout<< "주문 목록이 없습니다."<<endl;
                                }

                            }
                            else if (selection == "G"){
                                c-> showAllStore();
                                string storeName;
                                cout << "가게 이름을 입력하세요: ";
                                cin >> storeName;
                                c->showMenu(storeName);
                            }
                            else if (selection == "0"){
                                break;
                            }
                            else {
                                cout << "다시 입력하세요"<<endl;
                            }
                        }
                    }
                    else if (selection == "B"){
                        while(1){
                            selection = m->memberSelection();
                            if(selection == "A"){
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
                            else if (selection== "B"){
                                b->updateOrder(*c,id);
                            }
                            else if (selection =="C"){
                                b->deleteOrder(id);
                            }
                            else if(selection == "D"){
                                b->printOrder(id);
                            }
                            else if (selection == "E"){
                                c-> showAllStore();
                                string storeName;
                                cout << "가게 이름을 입력하세요: ";
                                cin >> storeName;
                                c->showMenu(storeName);
                            }
                            else if(selection == "0"){
                                break;
                            }
                            else {
                            cout << "다시 입력하세요";
                            }
                        }

                    }
                    else if (selection =="0"){
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
        else if(selection == "B"){
            l->join();
        }
        else if (selection == "0"){
            delete a;
            delete b;
            delete l;
            delete m;
            exit(0);
        }
        else {
            cout <<"다시 입력하세요."<<endl;
        }
    }



    return 0;
}

