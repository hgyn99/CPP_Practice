#include <iostream>

using namespace std;

int main() {

	int a, b, c, smallest; // int 타입 변수 a, b, c, smallest를 선언한다.

	cout << "3개의 정수를 입력하시오: ";
	cin >> a >> b >> c;
	// 3개의 정수를 입력하라는 메세지를 출력한 후 a, b, c 3개의 변수를 입력받는다.

	if (a < b && a < c) // 만약 a가 b보다 작고 a가 c보다 작다면
		smallest = a; // 가장 작은 숫자인 smallest는 a가 된다.
	else if (b < a && b < c) // 만약 b가 a보다 작고 b가 c보다 작다면
		smallest = b; // smallest는 b가 된다.
	else // 위 조건식이 모두 아니라면
		smallest = c; // smallest는 c가 된다.

	cout << "가장 작은 정수는 " << smallest << endl; // 가장 작은 정수인 smallest를 출력한다.

	return 0; // 0을 반환하여 프로그램을 종료한다.
}