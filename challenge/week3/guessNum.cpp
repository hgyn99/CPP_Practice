#include <iostream>
#include <time.h>

using namespace std;

int main() {

	srand(time(NULL)); // random 함수 관련 설정

	int answer = rand() % 100; // 정답
	int tries = 0; // 시도 횟수 저장하는 변수

	int guess; // 사용자 입력 저장하기 위한 변수

	do {
		cout << "정답을 추측하여 보시오:"; // 정답을 맞춰보라는 메세지를 출력한다.
		cin >> guess; // 추측 값을 입력 받는다.
		if (answer == guess) {
			tries++;
			break;
		}
		// 만약 정답과 추측 값이 같다면, 횟수를 증가시키고 반복문을 탈출한다.
		if (guess < answer) {
			cout << "제시한 정수가 낮습니다." << endl;
			tries++;
		}
		// 만약 추측 값이 정답보다 낮다면, 메세지를 출력하고 횟수를 증가시킨다.
		if (guess > answer) {
			cout << "제시한 정수가 높습니다." << endl;
			tries++;
		}
		// 만약 추측 값이 정답보다 높다면, 메세지를 출력하고 횟수를 증가시킨다.
	} while (true); // 정답을 맞출 때까지 무한 반복한다.


	cout << "축하합니다. 시도 횟수=" << tries << endl;
	// 축하 메세지 및 시도 횟수를 출력하고 프로그램을 종료한다.

	return 0;
}