//음식메뉴를 보여주는 UI라고 가정
#define MAX 15
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Store{
    private :
        int count = 4;
        string store[15] ={"교폰치킨", "덥덥팦", "어디야커피", "치코파덕"};
    public :
    void createMenu(); // 스토어 생성
    void showMenu(menu *m[], int num); // 메뉴 출력
    void updateMenu(menu *m[], int num); // 업데이트 메뉴
    void showAllStore();
    bool fileExists(string fileName); // 파일 존재 유무 확인
};