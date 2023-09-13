#include <iostream> // 헤더파일 iostream 포함

using namespace std; // 이름 공간 설정

int main() { // main 함수를 선언한다.

	int one = 1; // int형 변수 one을 선언하고 값에 1을 저장한다.
	int two = 2; // int형 변수 two를 선언하고 값에 1을 저장한다.
	int sum = one + two; // int형 변수 sum을 선언하고 one과 two를 더한 값을 저장한다.

	cout << "1 + 2 = " << sum << endl; // 형식을 갖추어 1 + 2 값인 sum을 출력한다.

	return 0; // 0을 반환하여 프로그램을 종료한다.
}