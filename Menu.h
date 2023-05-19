//음식메뉴를 보여주는 UI라고 가정
#define MAX 15
#include <iostream>
#include <string>
using namespace std;

typedef struct {
    int num;
    string name; // 메뉴 이름
    int price; // 가격
    string memo; // 기타 사항
}menu; // 메뉴 출력을 위한 struct

void createMenu(Menu *m[], int *num);
void showMenu(Menu *m[], int num);
void updateMenu(Menu *m[], int num);
;;
;;
;;
;;