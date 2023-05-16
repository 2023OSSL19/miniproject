#include <iostream>
#include <string>

using namespace std;

string functions(char *&m){
    cout << "A: 방 만들기" << endl;
    cout << "B: 방 참여하기" << endl;
    cout << "C: 방 목록보기" << endl;
    cout << "원하시는 기능을 선택하세요: ";
    cin >> m;

    return m;
}

int main(){
    cout << "어플에 오신걸 환영합니다" << endl;
    char *m = new char[5];
    functions(m);

    return 0;
}



/*
프로그램이 시작되면 어떤 역할로 참여한 것인지 묻는 함수

Ex)

어플에 오신 걸 환영합니다
A: 방 만들기 //방장으로 활동 -> 방장 함수 제공
B: 방 참여하기 //팀원으로 활동 -> 팀원 함수 제공
C: 방 목록 보기 //결정을 위한 정보 제공
Choose Menu: //Input 입력받기
*/