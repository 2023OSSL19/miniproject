#include "order.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct time{
    int hour;
    int min;
}; // 시간 출력용 st

struct roomNode{
    string orderer; // 검색 삭제를 위한 변수 -> 입력 받기
    string storeName; // 가게 이름 -> 입력 받기
    long int account; // 계좌 번호 -> 입력 받기
    string id;
    string bank; // 은행
    int phoneNum; // 핸드폰 번호 -> 입력
    string place; // 도착 장소 -> 입력
    struct time t1; // 마감 시간 출력용 변수 -> 입력
    roomNode* next; // 다음 방 주소를 담는다

}; // 각 방에 담기는 정보



class Room{
    private :
        int count; // 방의 개수
        roomNode* head; // linked list로 구현 head

    public: 
        Room(); // constructor, 최대 방 개수 100개로 제한, 메뉴 개수 15개로 제한
        ~Room(); // destructor
        void searchRoom(string id); // 메뉴를 입력하면 방을 해당 방을 출력, 사용자에서 사용
        void createBaseRoom(); //시나리오를 위해 기본적으로 생성 된 방
        void createRoom(Store& store, string id); // 방 생성, 방장에서만 사용
        void deleteRoom(string id); // 방 삭제, 방장에서만 사용
        void updateRoom(Store& store, string id); // 방 정보 업데이트, 방장에서만 사용
        void printRoom(string id); // 전체 방 정보 출력, 사용자에서 사용
        bool isEmpty(string id); // 방 유무 확인
        void printAllRoom();
        void searchAllRoom();
        bool fileExists(string storeName); // 파일 존재 유무 확인
        bool alreadyExistRoom(string id, string storeName);
        void setStoreNameAndLeader(string *originStoreName, string *originName);
        string getLeader(roomNode* current);
        string getStoreName(roomNode* current);
        bool checkID(string id, roomNode* current);
        roomNode* getRoomNodeWithLeader(string id);
        roomNode* getRoomNodeWithStoreName(string id); 
        bool isEmptyForMaster();
};