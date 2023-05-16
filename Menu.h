typedef struct {
    char name[50]; // 메뉴 이름
    int price; // 가격
    char memo[150]; // 기타 사항
}menu; // 메뉴 출력을 위한 struct

void createMenu(Menu *m[], int *num);
void showMenu(Menu *m[], int num);
void deleteMenu(Menu *m[], int *num);
void updateMenu(Menu *m[], int num);