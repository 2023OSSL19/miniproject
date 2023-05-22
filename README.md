# 주제 : 배달비 분담을 위한 공동 구매 시스템

## 주제 소개 : 한동에서 거주하다 보면, 비싼 배달비 때문에 배달음식을 먹기 힘들때가 있다. 특히 혼밥의 중요도가 높아진 요즘, 어플을 통해 손쉽게 공동구매를 할 수 있도록 하여 배달비의 부담을 줄이려고 한다.

![KakaoTalk_Photo_2023-05-08-22-33-31](https://user-images.githubusercontent.com/130913514/236838869-7a047d40-76c1-4ffa-8425-8385276b268c.jpeg)
- 참고한 메커니즘: ITAXI


## 기능
  ### 관리자 기능
    - 배달 받을 수 있는 가게의 종류와 메뉴를 관리한다.
    - 이후 배달의 민족등 다른 어플과 연계할 수 있도록 업데이트 할 예정
    '''
    string Menu::adminSelection(){
    string m;
    cout<< "\nA: 메뉴 출력하기"<< endl;
    cout<< "B: 가게 추가하기" << endl;
    cout<< "C: 가게 메뉴 수정하기" << endl;
    cout<< "D: 전체 방 출력하기" << endl;
    cout << "E: 전체 주문 출력" << endl;
    cout << "원하시는 기능을 선택하세요(로그아웃 하려면 0): ";
    cin >> m;
    return m;
    }
    '''
  ### 방장 기능
    - 배달 받을 수 있는 가게의 종류를 선택하고 팀원이 참가할 수 있는 방을 만든다.
    '''
    string Menu::leaderSelection(){
    string m;
    cout << "\nA: 방 만들기" << endl;
    cout << "B: 방정보 수정하기" << endl;
    cout << "C: 방 삭제하기" << endl;
    cout << "D: 방 정보 보기" << endl;
    cout << "E: 방 찾기" << endl;
    cout << "F: 주문 목록 보기"<< endl;
    cout << "G: 메뉴판 보기" << endl;
    cout << "원하시는 기능을 선택하세요(전으로 돌아가려면 0): ";
    cin >> m;
    return m;
    }
    '''
  ### 팀원 기능
    - 만들어진 방에 참가하여 주문한다.
    '''
    string Menu::memberSelection(){
    string m;
    cout << "\nA: 주문 추가하기" << endl;
    cout << "B: 주문 수정하기" << endl;
    cout << "C: 주문 삭제하기" << endl;
    cout << "D: 주문 출력하기" << endl;
    cout << "E: 메뉴판 보기" << endl;
    cout << "원하시는 기능을 선택하세요(전으로 돌아가려면 0): ";
    cin >> m;

    return m;
    }
    '''
  ### 공통 기능
    - 로그인
    - 로그인을 통해 주문 정보에 접근 범위를 제한한다. 다른 id로 로그인하여 추가한 정보들에 부분적으로 접근과 수정을 제한한다.
    '''
    string Menu::loginSelection(){
    string m;
    cout<< "\nA: 로그인하기"<< endl;
    cout << "B: 회원 가입하기" <<endl;
    cout << "원하시는 기능을 선택하세요(종료하려면 0): ";
    cin >> m;
    return m;
    }
    '''
    '''
    string Menu::fristSelection(){
    string m;
    cout << "\nA: 방장 권한으로 참여하기" << endl;
    cout << "B: 팀원 권한으로 참여하기" << endl;
    cout << "원하시는 기능을 선택하세요(로그아웃 하려면 0): ";
    cin >> m;

    return m;
    }
    '''

 
## 개발 환경 및 언어
- C++
- Git, GitHub
- Visual Studio Code

## 팀 소개 및 역할
### 최혁진
  - 기본 CRUD 기획 및 구현
  - 에러 처리
  - wiki 작성
  - Readme 작성
### 유진우
  - 프로젝트 기획
  - 심화 CRUD 구현
