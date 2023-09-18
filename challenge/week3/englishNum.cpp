#include <iostream>

using namespace std;

int main() {

	int number; // int 타입 변수 number를 선언한다.

	cout << "숫자를 입력하시오: ";
	cin >> number;
	// 숫자 number를 입력받는다.
	
	if (number == 0) cout << "zero" << endl; // 만약 number가 0이라면, zero를 출력한다.
	else if (number == 1) cout << "one" << endl; // 만약 number가 1이라면, one을 출력한다.
	else cout << "many" << endl; // 모두 해당되지 않으면, many를 출력한다.

	return 0;
}