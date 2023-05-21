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
    string id; // login 정보를 확인하고, 각자에게 보여지는 정보를 제한
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
        Room(); // constructor, 메뉴 개수 15개로 제한
        ~Room(); // destructor
        void searchRoom(string id); // 메뉴를 입력하면 방을 해당 방을 출력, 사용자에서 사용
        void createBaseRoom(); //시나리오를 위해 기본적으로 생성 된 방
        void createRoom(Store& store, string id); // 방 생성, 방장에서만 사용
        void deleteRoom(string id); // 방 삭제, 방장에서만 사용
        void updateRoom(Store& store, string id); // 방 정보 업데이트, 방장에서만 사용
        void printRoom(string id); // 전체 방 정보 출력, 사용자에서 사용
        bool isEmpty(string id); // 방 유무 확인, id에 일치하는 방이 없으면 false
        void printAllRoom(); // 모든 방을 출력, 보통 admin에서 사용
        void searchAllRoom(); // 방을 검색하고 출력, 단 id 제한 없음
        bool fileExists(string storeName); // 파일 존재 유무 확인
        bool alreadyExistRoom(string id, string storeName); //해당 방이 이미 있는지 확인, 비교 변수는 id와 가게 이름
        void setStoreNameAndLeader(string *originStoreName, string *originName); // order를 생성할 때 필요한 정보를 return하는 함수
        string getLeader(roomNode* current); //return orderer
        string getStoreName(roomNode* current); // return 가게 이름
        bool checkID(string id, roomNode* current); // 입력받은 id와 node의 id가 일치하는지 확인한다.
        roomNode* getRoomNodeWithLeader(string id); // roomleader 정보를 활용하여 RoomNode를 알아내는 함수
        roomNode* getRoomNodeWithStoreName(string id); // // 가게 이름 정보를 활용하여 RoomNode를 알아내는 함수
        bool isEmptyForMaster(); // room이 비어있는지 확인, 이때는 room자체가 없는지 확인한다.
};