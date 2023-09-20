#include <iostream>

using namespace std;

int main() {

	int userInput; // 사용자의 입력값 userInput을 선언한다.

	cout << "정수를 10번 입력하세요 (0을 입력하면 종료):";
	// 정수를 입력할 것을 안내하는 메세지를 출력한다.

	for (int i = 0; i < 10; i++) { // 반복문을 10번 반복한다.
		cin >> userInput; // userInput을 입력받는다.
		if (userInput == 0) break; // 만약 입력 값이 0이라면 반복문을 탈출한다.
		cout << "입력값: " << userInput << " 횟수 :" << i << endl;
		// 사용자의 입력 값과 입력 횟수를 출력한다.
	}

	cout << "종료 되었습니다"; // 프로그램 종료 안내 메세지를 출력한다.


	return 0;
}