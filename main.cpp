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



