#include <iostream> // 헤더파일 iostream 포함

using namespace std; // 이름 공간 설정

int main() { // main 함수를 선언한다.

	int one = 1; // int형 변수 one을 선언하고 값에 1을 저장한다.
	int two = 2; // int형 변수 two를 선언하고 값에 2를 저장한다.
	int three = 3; // int형 변수 three를 선언하고 값에 3을 저장한다.
	int four = 4; // int형 변수 four를 선언하고 값에 4를 저장한다.

	cout << "1 + 3 = " << one + three << endl; // 형식에 맞추어 결과 값을 출력한다.
	cout << "4 - 2 = " << four - two << endl; // 형식에 맞추어 결과 값을 출력한다.
	cout << "2 * 3 = " << two * three << endl; // 형식에 맞추어 결과 값을 출력한다.
	cout << "4 / 2 = " << four / two << endl; // 형식에 맞추어 결과 값을 출력한다.

	cout << "2 + 3 * 4 = " << two + three * four << endl; // 형식에 맞추어 결과 값을 출력한다.
	cout << "2 + 3 * 4 = " << two + three * four << endl; // 형식에 맞추어 결과 값을 출력한다.
	cout << "1 + 4 / 2 = " << one + four / two << endl; // 형식에 맞추어 결과 값을 출력한다.

	return 0; // 0을 반환하여 프로그램을 종료한다.
}