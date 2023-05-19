#define MAX 10 // 최대 주문 개수는 10개로 제한
//#include "menu.h"
//#include "order.h"
#include <string>

using namespace std;

struct time{
    int hour;
    int min;
}; // 시간 출력용 st

struct roomNode{
    string orderer; // 검색 삭제를 위한 변수 -> 입력 받기
    string storeName; // 가게 이름 -> 입력 받기
    int account; // 계좌 번호 -> 입력 받기
    string bank; // 은행
    //int totalPrice; // 총 가격 -> 계산 인데, 일단 입력
    int phoneNum; // 핸드폰 번호 -> 입력
    string place; // 도착 장소 -> 입력
    struct time t1; // 마감 시간 출력용 변수 -> 입력
    int storeSelection; //어떤 음식점을 선택할 것인가? -> 4~5개 가게 만들어야 함 -> 입력 -> 메뉴 4개 만들어야 함
    //Order* order; // 주문을 담는 공간
    //int menuCount; // 메뉴 개수
    roomNode* next; // 
}; // 각 방에 담기는 정보



class Room{
    private :
        int count; // 방의 개수
        roomNode* head; // linked list로 구현 head

    public: 
        Room(); // constructor, 최대 방 개수 100개로 제한, 메뉴 개수 15개로 제한
        ~Room(); // destructor
        //void searchRoom(); // 메뉴를 입력하면 방을 해당 방을 출력, 사용자에서 사용
        void createRoom(); // 방 생성, 방장에서만 사용
        void deleteRoom(); // 방 삭제, 방장에서만 사용
        void updateRoom(); // 방 정보 업데이트, 방장에서만 사용
        void printRoom(); // 전체 방 정보 출력, 사용자에서 사용
        //void showMenu(); // 메뉴 출력 기능
        bool isEmpty(); // 방 유무 확인
};