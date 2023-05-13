# define MAX 10 // 최대 주문 개수는 10개로 제한
typedef struct {
    char name[50];
    int price;
    char memo[150];

}menu; // 메뉴 출력을 위한 struct
class Room{
    private :
        char storeName[50]; // 가게 이름
        int account; // 계좌 번호
        int totalPrice; // 총 가격





    public: 
        Room(); // constructor
        ~Room(); // destructor
        void SearchRoom(); // 메뉴를 입력하면 방을 해당 방을 출력
        void createList(); // 
        
        
}
