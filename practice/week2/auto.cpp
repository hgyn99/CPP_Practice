#include <iostream>

using namespace std;

auto add(int x, int y) {
	return x + y; 
}
// 매개변수 x, y를 받아와 x + y를 반환하는 auto 타입 함수 add를 정의한다.

int main() {

	auto sum = add(5, 6); // auto 타입 변수 sum을 선언하고 매개변수 x에 5, y에 6을 넘겨주며 add 함수를 실행하여 나온 반환 값을 sum에 저장한다.
	cout << sum; // sum을 출력한다.

	return 0; // 0을 반환하여 프로그램을 종료한다.
}