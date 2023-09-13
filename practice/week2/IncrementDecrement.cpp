#include <iostream> // 헤더파일 iostream 포함

using namespace std; // 이름 공간 설정

int main() { // main 함수를 선언한다.

	int x = 1; // int 타입 변수 x를 선언하고 1을 저장한다.
	
	cout << "x = " << x++ << endl; // 1을 출력하고 x 값을 증가시킨다.
	cout << "x = " << x++ << endl; // 2를 출력하고 x 값을 증가시킨다.
	cout << "x = " << ++x << endl; // x 값을 먼저 증가시킨 후 값을 출력한다.(x=4)
	cout << "x = " << x-- << endl; // 4를 출력하고 x 값을 감소시킨다.
	cout << "x = " << x-- << endl; // 3을 출력하고 x 값을 감소시킨다.
	cout << "x = " << --x << endl; // x 값을 먼저 감소시킨 후 값을 출력한다.(x=1)

	return 0; // 0을 반환하여 프로그램을 종료한다.
}