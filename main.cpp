#include <iostream>
#include <fstream>
#include <string>
#include "Room.h"

using namespace std;

Room* functions(){
    string m;
    cout << "A: 방 만들기" << endl;
    cout << "B: 방 참여하기" << endl;
    cout << "C: 방 목록보기" << endl;
    cout << "원하시는 기능을 선택하세요: ";
    cin >> m;

    Room* order = new Room();

    return order;
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

int main(){
    if (logIn()){
        cout << "로그인에 성공하셨습니다" << endl;
        Room* a = functions();
        a->createRoom();
        a->createRoom();
        a->deleteRoom();
        a->updateRoom();
    }
    else{
        cout << "로그인에 실패하셨습니다." << endl;
    }


    return 0;
}



