typedef struct {
    char name[50]; // 메뉴 이름
    int price; // 가격
    char memo[150]; // 기타 사항
    

}menu; // 메뉴 출력을 위한 struct
void CreateMenu(Menu *m[], int *num);
void ShowMenu(Menu *m[], int num);
void DeleteMenu(Menu *m[], int *num);
void UpdateMenu(Menu *m[], int num);