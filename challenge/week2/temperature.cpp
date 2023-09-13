#include <iostream>

using namespace std;

int main() {

	int f; // int 타입 변수 f를 선언한다.
	double c; // double 타입 변수 c를 선언한다.

	cout << "화씨온도: ";
	cin >> f;
	// 화씨온도를 f를 입력 받는다.

	c = (5.0 / 9.0) * (f - 32); // 화씨온도를 수식을 통해 섭씨온도로 변환하여 c에 저장한다.

	cout << "섭씨온도 = " << c << endl; // 변환한 섭씨온도 c를 출력한다.

	return 0; // 0을 반환하며 프로그램을 종료한다.
}