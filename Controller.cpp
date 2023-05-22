#include "Controller.h"
Controller::Controller(){
    count =4;
}
bool Controller::logIn(string *user){
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

    while(inputFile >> id >> pw){
        if (id == inputId && pw == inputPw){
            *user = inputId;
            return true;
        }

    }
    return false;
}
void Controller ::join(){
    if (count >15){
        cout << "저장할 수 있는 id를 초과했습니다.(최대 15개)"; // 최대로 저장할 수 있는 가게 수는 15개
        return;
    }
    string id;
    string pw;
    cout << "id? ";
    cin >> id;
    cout << "pw? ";
    cin >> pw;
    ofstream file("id_pw.txt", ios::app);

    if (file.is_open()) {
        // id와 pw를 파일에 추가
        file << id << " " << pw << endl;

        cout << "추가 되었습니다." << endl;

        // 파일 닫기
        file.close();
    } else {
        cerr << "Failed to open the file." << endl;
    }
    count ++;
};