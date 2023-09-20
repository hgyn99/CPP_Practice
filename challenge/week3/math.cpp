#include <iostream>
#include <time.h>

using namespace std;

int main() {

	int ans; // 변수 선언
	int ans_count = 0;

	cout << "산수 문제를 자동으로 출제합니다." << endl;
	// 문제 출제 안내 메세지를 출력한다.

	while (true) {

		int firstNum = rand() % 100;
		int secondNum = rand() % 100;
		// 첫 번째 숫자와 두 번째 숫자를 생성하고, 두 변수에 저장한다.

		cout << firstNum << "+" << secondNum << "=";
		// 문제를 출력한다.
		cin >> ans;
		// 답을 입력 받는다.

		if (ans == (firstNum + secondNum)) {
			cout << "맞았습니다." << endl;
			ans_count++;
			if (ans_count == 5) break;
		}
		// 만약 정답 값이 맞다면 맞았다는 메세지를 출력하고, 정답 횟수를 증가시키며 반복문을 탈출한다.
		// 정답 횟수가 5번이 되면, 반복문을 탈출하며 프로그램을 종료한다.
		else {
			cout << "틀렸습니다." << endl;
		}
		// 만약 정답 값이 틀렸다면 틀렸다는 메세지를 출력하고 반복문을 반복한다.

	}

	return 0;
}