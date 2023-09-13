#include <iostream>

using namespace std;

int main() {

	int c, f; // int 타입 변수인 섭씨온도 c, 화씨온도 f를 선언한다.

	cout << "섭씨온도: ";
	cin >> c;
	// 섭씨온도를 c를 입력 받는다.

	f = c * 1.8 + 32; // 섭씨온도를 수식을 통해 화씨온도로 변환하여 에 저장한다.

	cout << "화씨온도 = " << f << endl; // 변환한 화씨온도 f를 출력한다.
	
	return 0; // 0을 반환하며 프로그램을 종료한다.
}