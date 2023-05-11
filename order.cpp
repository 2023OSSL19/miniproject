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
}