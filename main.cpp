#include <iostream>
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
    cout << "d"
    Room* order = new Room();
    

    return order;
}

int main(){
    cout << "어플에 오신걸 환영합니다" << endl;
    Room* a = functions();
    a->createRoom();
    a->createRoom();
    a->printRoom();


    return 0;
}



