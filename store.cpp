#include "Store.h"

void Store ::createMenu(){
    if (count >MAX){
        cout << "저장할 수 있는 가게 개수를 초과했습니다.(최대 15개)";
        return;
    }
    string storeName;
    string menu;
    string con;
    int price;

    cout << "가게: ";
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
        store[count] = storeName; // 가게 이름 저장
        count = count +1; // 총 개수 한개 증가
    }
    else
    {
        cout << "파일을 열 수 없습니다." << endl;
    } 
};
void Store::showAllStore(){
    for(int i =0; i< count ; i++){
        cout <<  store[count]<< endl;
    }
}
void Store::showMenu(string storeName){ // 메뉴 번호를 받아서 해당 음식 메뉴 출력
    string fileName = storeName + ".txt";
    ifstream file(fileName);
    
    if(!fileExists(fileName)){
        cout << "해당 가게가 존재하지 않습니다."<<endl;
        return;
    }

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
void Store::updateMenu(string storeName){
    string fileName = storeName+ ".txt";
    ofstream file(fileName);
    if(!fileExists(fileName)){
        cout << "해당 가게가 존재하지 않습니다."<<endl;
        return;
    }
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
bool Store:: fileExists(string fileName)
{
    ifstream file(fileName);
    return file.good();
}