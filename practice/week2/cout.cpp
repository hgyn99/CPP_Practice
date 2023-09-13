#include <iostream> // 헤더파일 iostream 포함

using namespace std; // 이름 공간 설정

int main() { // main 함수를 선언한다.

	int number = 0; // int 타입 변수 number를 선언하고 0으로 초기화한다.
	cin >> number; // number 값을 입력받는다. 
	cout << "입력한 숫자는 " << number << "입니다." << endl; // 형식을 갖추어 입력 받은 number 변수를 출력한다.

	return 0; // 0을 반환하여 프로그램을 종료한다.
}