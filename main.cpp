#include <iostream>
#include <fstream>
#include <string>
#include "Room.h"
#include "Order.h"

using namespace std;

string fristSelection(){
    string m;
    cout << "\nA: 방장 권한으로 참여하기" << endl;
    cout << "B: 팀원 권한으로 참여하기" << endl;
    cout << "C: 방 목록보기" << endl;
    cout << "0: 종료" << endl;
    cout << "원하시는 기능을 선택하세요: ";
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
    cout << "D: 방정보 보기" << endl;
    cout << "원하시는 기능을 선택하세요: ";
    cin >> m;

    return m;
}
/*
string memberSelection(){
}*/

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

int main(){
    if(logIn()){
        cout << "\n로그인에 성공하셨습니다!" << endl;
        Room* a = new Room;
        Order* b = new Order;
        string menu;
        while(1){
            menu = fristSelection();
            if (menu == "A"){
                if(leaderSelection() == "A")
                    a->createRoom();
                else if (leaderSelection() == "B")
                    a->deleteRoom();
                else if (leaderSelection() == "C")
                    a->updateRoom();
                else if (leaderSelection() == "D")
                    a->printRoom();
            }
            else if (menu == "B"){
                cout << "working fine.";
                b->createOrder();
            }
        }
    }
    else{
        cout << "로그인에 실패하셨습니다." << endl;
    }


    return 0;
}