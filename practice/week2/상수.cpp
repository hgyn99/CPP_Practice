#include <iostream>
#define PI 3.14159265359 // 기호 상수 PI 값을 3.14159265359로 정의한다.

using namespace std;

int main() {

	int income = 1000; // int 타입 변수 income을 선언하고 1000을 저장한다.
	const double TAX_RATE = 0.25; // 상수 변수 TAX_RATE를 선언하고 0.25를 저장한다.
	income = income - TAX_RATE * income; // 수식을 통해 income 값을 변환하고 그 값을 income에 다시 업데이트한다.

	double x = 100; // double 타입 변수 x를 선언하고 100을 저장한다.
	x = x * PI; // x에 기호 상수 PI 값을 곱하여 x 값을 업데이트 한다.

	cout << x << endl; // x를 출력한다.

	return 0; // 0을 반환하여 프로그램을 종료한다.
}