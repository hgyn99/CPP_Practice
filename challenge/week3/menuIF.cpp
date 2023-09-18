#include <iostream>

using namespace std;

int main() {

	int choice; // int 타입 변수 choice를 선언한다.

	cout << "1. 파일 저장" << endl;
	cout << "2. 저장 없이 닫기" << endl;
	cout << "3. 종료" << endl;
	// 입력 숫자에 따른 기능 안내
	cin >> choice; // 선택 번호인 choice를 입력 받는다.

	if (choice == 1) cout << "파일 저장을 선택했습니다." << endl;
	// 만약 choice가 1이라면, 파일 저장을 선택했다는 메세지를 출력한다.
	else if (choice == 2) cout << "파일 닫기를 선택했습니다." << endl; 
	// 만약 choice가 2라면, 파일 닫기를 선택했다는 메세지를 출력한다.
	else if (choice == 3) cout << "프로그램을 종료합니다." << endl; 
	// 만약 choice가 3이라면, 프로그램을 종료한다는 메시지를 출력한다.
	else cout << "잘못된 선택입니다." << endl; 
	// 모두 아니라면, 잘못된 선택이라는 메시지를 출력한다.

	return 0;
}