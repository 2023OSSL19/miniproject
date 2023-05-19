#include <iostream>
#include <fstream>
#include <string>
#include "Room.h"
#include "order.h"

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

string memberSelection(){
    string m;
    cout << "\nA: 주문 추가하기" << endl;
    cout << "B: 주문 수정하기" << endl;
    cout << "C: 주문 삭제하기" << endl;
    cout << "D: 메뉴판보기" << endl;
    cout << "원하시는 기능을 선택하세요: ";
    cin >> m;

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

int main(){
    if(logIn()){
        cout << "\n로그인에 성공하셨습니다!" << endl;
        Room* a = new Room;
        Order* b = new Order;
        string big_selection;
        string leader;
        string member;
        while(1){
            big_selection = fristSelection();
            if (big_selection == "A"){
                leader = leaderSelection();
                if(leader == "A")
                    a->createRoom();
                else if (leader == "B")
                    a->deleteRoom();
                else if (leader == "C")
                    a->updateRoom();
                else if (leader == "D")
                    a->printRoom();
            }
            else if (big_selection == "B"){
                member = memberSelection();
                if(member == "A")
                    b->createOrder();
            }
        }
    }
    else{
        cout << "로그인에 실패하셨습니다." << endl;
    }


    return 0;
}