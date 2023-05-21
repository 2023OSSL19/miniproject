//음식메뉴를 보여주는 UI라고 가정
#define MAX 15
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Store{
    private :
        int count;
        string store[15];
    public :
        Store();
        ~Store();
        void createMenu(); // 스토어 생성
        void showMenu(string storeName); // 메뉴 출력
        void updateMenu(string storeName); // 업데이트 메뉴
        void showAllStore();
        bool fileExists(string storeName); // 파일 존재 유무 확인
};