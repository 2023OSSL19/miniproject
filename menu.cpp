#include "Menu.h"

void createMenu(){
    string storeName;
    string menu;
    string con;
    int price;

    cout << "가계: ";
    cin >> storeName;
    // 파일명을 입력받은 이름으로 생성
    string fileName = storeName + ".txt";

    // 파일 열기
    ofstream file(fileName);

    if (file.is_open())
    {
        while(1){
            cout<< "메뉴: ";
            cin >> menu;
            file << menu;
            cout << "가격: ";
            cin >> price;
            file << price<<endl;
            cout<< "입력을 종료하려면 0을 입력하세요. 계속하려면 아무키나 눌러주세요";
            cin >>con;
            if(con=='0'){
                break;
            }
        }
        // 메뉴 항목 작성

        // 파일 닫기
        file.close();

        cout << "메뉴가 파일에 저장되었습니다." << endl;
    }
    else
    {
        cout << "파일을 열 수 없습니다." << endl;
    } 
};
void showMenu(string storeName){ // 메뉴 번호를 받아서 해당 음식 메뉴 출력
    string fileName = storeName + ".txt";
    ifstream file(fileName);

    if (file.is_open())
    {
        string line;
        while (getline(file, line)){
            cout << line << endl;
        }
        file.close();
    }
    else
    {
        cout << "파일을 열 수 없습니다." << endl;
    }
}
void updateMenu(string storeName){
    string fileName = storeName+ ".txt";
    ofstream file(fileName);

    if (file.is_open())
    {
        string newContent;
        cout << "파일에 새로 입력할 내용을 입력하세요 (종료하려면 빈 줄 입력):" << endl;
        while (getline(cin, newContent))
        {
            if (newContent.empty())
            {
                break;
            }
            file << newContent << endl;
        }
        file.close();
        cout << "파일이 덮어쓰기 되었습니다." << endl;
    }
    else
    {
        cout << "파일을 열 수 없습니다." << endl;
    }
}