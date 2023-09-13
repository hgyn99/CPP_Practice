#include <iostream> // 헤더파일 iostream 포함

using namespace std; // 이름 공간 설정

int main() { // main 함수를 선언한다.

	int two = 2; // int형 변수 two를 선언하고 값에 2를 저장한다.
	int eight = 8; // int형 변수 eight을 선언하고 값에 8을 저장한다.
	int sum1 = 2; // int형 변수 sum1을 선언하고 값에 2를 저장한다.
	int sum2 = 2; // int형 변수 sum2를 선언하고 값에 2를 저장한다.

	sum1 = sum1 + two; // sum1과 two를 더한 값을 sum1에 저장한다.
	sum2 += eight; // sum2과 eight을 더한 값을 sum2에 저장한다.

	cout << "sum1 = " << sum1 << endl; // 형식을 갖추어 sum1 값을 출력한다.
	cout << "sum2 = " << sum2 << endl; // 형식을 갖추어 sum2 값을 출력한다.

	return 0; // 0을 반환하여 프로그램을 종료한다.
}