#include <iostream>
#include <string>
//아무래도 방은 구조체로 생성해야 할 것 같음.

using namespace std;

typedef struct {
    string name;
    string menu;
    int price;
    string phoneNum;
    string accout;
    Order* next;
}order;


class Order{
    private :
        int count; // 총 주문 갯수
        room* head =NULL; // linked list로 구현 head

    public: 
        Room(); // constructor, 최대 방 개수 100개로 제한, 메뉴 개수 15개로 제한
        ~Room(); // destructor
        void searchRoom(); // 메뉴를 입력하면 방을 해당 방을 출력, 사용자에서 사용
        void createRoom(); // 방 생성, 방장에서만 사용
        void deleteRoom(); // 방 삭제, 방장에서만 사용
        void updateRoom(); // 방 정보 업데이트, 방장에서만 사용
        void print(); // 전체 방 정보 출력, 사용자에서 사용
        void showMenu(); // 메뉴 출력 기능
        bool isEmpty(); // 방 유무 확인
        void updateMenu(); //메뉴 정보 업데이트
}
