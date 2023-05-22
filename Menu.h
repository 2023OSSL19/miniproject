#include <iostream>
#include <string>
using namespace std;

class Menu{
    private :
    public :
        string fristSelection(); // 방장 or 멤버 참여할지 
        string leaderSelection(); // 방장 메뉴 출력
        string memberSelection(); // 멤버 메뉴 출력
        string adminSelection(); // 관리자 메뉴 출력
        string loginSelection(); // 초기 로그인 메뉴 출력
        
};