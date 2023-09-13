#include <iostream> // 헤더파일 iostream 포함

using namespace std;

int main() {

	int x = 1; // int 타입 변수 x를 선언하고 1을 저장한다.
	int y = -1; // int 타입 변수 y를 선언하고 -1을 저장한다.
	int z = -2; // int 타입 변수 z를 선언하고 -2를 저장한다.

	cout << "1 + (-1) = " << x + y << endl; // 형식을 갖추어 값을 출력한다.
	cout << "-1 + -2 = " << y + z << endl; // 형식을 갖추어 값을 출력한다.

	return 0; // 0을 반환하여 프로그램을 종료한다.
}