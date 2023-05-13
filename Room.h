# define MAX 10 // 최대 주문 개수는 10개로 제한
# include "Menu.h"
typedef struct {
        char storeName[50]; // 가게 이름
        int account; // 계좌 번호
        int totalPrice; // 총 가격
        char place[100]; // 도착 장소
        int phoneNumber; // 핸드폰 번호
        time t1; // 마감 시간 출력용 변수
        menu* MenuList[15]; //메뉴 공간
        int menuCount; // 메뉴 개수
        room* link; // 다음 정보를 담는 공간
}room; // 각 방에 담기는 정보

typedef struct{
    int hour;
    int min;
}time; // 시간 출력용 struct


class Room{
    private :
        int count; // 방의 개수
        room* head =NULL; // linked list로 구현 head

    public: 
        Room(); // constructor, 최대 방 개수 100개로 제한, 메뉴 개수 15개로 제한
        ~Room(); // destructor
        void SearchRoom(); // 메뉴를 입력하면 방을 해당 방을 출력, 사용자에서 사용
        void CreateRoom(); // 방 생성, 방장에서만 사용
        void DeleteRoom(); // 방 삭제, 방장에서만 사용
        void UpdateRoom(); // 방 정보 업데이트, 방장에서만 사용
        void Print(); // 전체 방 정보 출력, 사용자에서 사용
        void ShowMenu(); // 메뉴 출력 기능
        bool IsEmpty(); // 방 유무 확인
        
}
