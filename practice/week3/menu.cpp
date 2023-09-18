#include <iostream>

using namespace std;

int main() {

	int choice; // int 타입 변수 choice를 선언한다.

	cout << "1. 파일 저장" << endl;
	cout << "2. 저장 없이 닫기" << endl;
	cout << "3. 종료" << endl;
	// 입력 숫자에 따른 기능 안내
	cin >> choice; // 선택 번호인 choice를 입력 받는다.

	switch (choice) {
		case 1: // 1을 입력했을 경우
			cout << "파일 저장을 선택했습니다." << endl;
			break;
			// 파일 저장을 선택했다는 메세지를 출력하고 switch 문을 빠져나온다.
		case 2: // 2를 입력했을 경우
			cout << "파일 닫기를 선택했습니다." << endl;
			break;
			// 파일 닫기를 선택했다는 메세지를 출력하고 switch 문을 빠져나온다.
		case 3: // 3을 입력했을 경우
			cout << "프로그램을 종료합니다." << endl;
			break;
			// 프로그램을 종료한다는 메세지를 출력하고 switch 문을 빠져나온다.
		default: // 그 외의 경우
			cout << "잘못된 선택입니다." << endl;
			break;
			// 잘못된 선택이라는 메세지를 출력하고 switch 문을 빠져나온다.
	}

	return 0;
}