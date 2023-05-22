#include <iostream>
#include <string>
#include "Menu.h"
string Menu::fristSelection(){ // 로그인 이후 나오는 화면
    string m;
    cout << "\nA: 방장 권한으로 참여하기" << endl;
    cout << "B: 팀원 권한으로 참여하기" << endl;
    cout << "원하시는 기능을 선택하세요(로그아웃 하려면 0): ";
    cin >> m;

    return m;
}
string Menu::leaderSelection(){ // 방장 메뉴
    string m;
    cout << "\nA: 방 만들기" << endl;
    cout << "B: 방정보 수정하기" << endl;
    cout << "C: 방 삭제하기" << endl;
    cout << "D: 방 정보 보기" << endl;
    cout << "E: 방 찾기" << endl;
    cout << "F: 주문 목록 보기"<< endl;
    cout << "G: 메뉴판 보기" << endl;
    cout << "원하시는 기능을 선택하세요(전으로 돌아가려면 0): ";
    cin >> m;
    return m;
}
string Menu::memberSelection(){ // 멤버 기능
    string m;
    cout << "\nA: 주문 추가하기" << endl;
    cout << "B: 주문 수정하기" << endl;
    cout << "C: 주문 삭제하기" << endl;
    cout << "D: 주문 출력하기" << endl;
    cout << "E: 메뉴판 보기" << endl;
    cout << "원하시는 기능을 선택하세요(전으로 돌아가려면 0): ";
    cin >> m;

    return m;
}
string Menu::adminSelection(){ // 관리자 기능
    string m;
    cout<< "\nA: 메뉴 출력하기"<< endl;
    cout<< "B: 가게 추가하기" << endl;
    cout<< "C: 가게 메뉴 수정하기" << endl;
    cout<< "D: 전체 방 출력하기" << endl;
    cout << "E: 전체 주문 출력" << endl;
    cout << "원하시는 기능을 선택하세요(로그아웃 하려면 0): ";
    cin >> m;
    return m;

}
string Menu::loginSelection(){ // 초기 로그인 화면
    string m;
    cout<< "\nA: 로그인하기"<< endl;
    cout << "B: 회원 가입하기" <<endl;
    cout << "원하시는 기능을 선택하세요(종료하려면 0): ";
    cin >> m;
    return m;
}