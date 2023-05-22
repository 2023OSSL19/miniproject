#include "Controller.h"
bool Controller::logIn(string *user){ // 로그인 기능 구현
    string inputId;
    string inputPw;
    char login;

    cout << "\n어플에 오신걸 환영합니다!" << endl;
    cout << "id와 비밀번호를 입력해주세요." << endl;
    cout << "id: ";
    cin >> inputId;
    cout << "pw: ";
    cin >> inputPw;

    ifstream inputFile("id_pw.txt");
    string id, pw;

    while(inputFile >> id >> pw){ // 한 줄씩 읽어서 id와 pw에 넣고
        if (id == inputId && pw == inputPw){ 
            *user = inputId; // 일치한다면 id를 부여
            return true;
        }

    }
    return false;
}
void Controller ::join(){
    string id;
    string pw;
    cout << "id? ";
    cin >> id;
    cout << "pw? ";
    cin >> pw;
    ofstream file("id_pw.txt", ios::app); // 추가하기로 파일을 연다.

    if (file.is_open()) {
        // id와 pw를 파일에 추가
        file << id << " " << pw << endl;

        cout << "추가 되었습니다." << endl;

        // 파일 닫기
        file.close();
    } else {
        cerr << "Failed to open the file." << endl;
    }
};