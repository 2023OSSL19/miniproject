//음식메뉴를 보여주는 UI라고 가정
#define MAX 15
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Store{
    private :
        int count; // 스토어가 몇 개가 있는지
        string store[15]; // store의 이름을 저장하는 배열
    public :
        Store(); // constructor
        ~Store(); // destructor
        void createMenu(); // 스토어를 생성, 메뉴를 txt 파일에 저장
        void showMenu(string storeName); // 가게를 입력받아 메뉴를 출력
        void updateMenu(string storeName); // 가게를 입력받아 메뉴를 업데이트
        void showAllStore(); // 모든 가게 이름을 출력
        bool fileExists(string storeName); // 파일 존재 유무 확인
};