#include "order.h"
#include <iostream>
#include <string>

using namespace std;

GroupDelivery::GroupDelivery(){

}

GroupDelivery::~GroupDelivery(){

}

void GroupDelivery::chooseMenu(){
    string M;
    cout << "원하는 메뉴를 입력해주세요: " << endl;
    cout << "A: 방 만들기" << endl;
    cout << "B: 방 참여하기" << endl;
    cout << "C: 방 목록보기" << endl;
    cout << "D: 내 예약내역 확인하기" << endl;

    cin >> M;

    if (M=="A"){
        cout << "방장으로써 기능 시행시키는 함수로 연결" << endl;
    }
    else if (M=="B"){
        cout << "팀원으로써 기능 시행시키는 함수로 연결" << endl;
    }
    else if (M=="C"){
        cout << "현재까지 추가된 방 (구조체)를 출력" << endl;
    }
    else if (M=="D"){
        cout << "내 예약내역은 어떤 형태로 저장할건지 먼저 정해야함" << endl;
    }
    else{
        cout << "잘못 입력 하셨습니다." << endl;
    }
}