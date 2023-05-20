//음식메뉴를 보여주는 UI라고 가정
#define MAX 15
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

typedef struct {
    int num;
    string name; // 메뉴 이름
    int price; // 가격
    string memo; // 기타 사항
}menu; // 메뉴 출력을 위한 struct

void createMenu();
void showMenu(menu *m[], int num);
void updateMenu(menu *m[], int num);
