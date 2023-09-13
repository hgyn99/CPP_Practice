#include <iostream>
#include <string>


using namespace std;

int main() {

	string name; // string 타입 변수 name을 선언한다.
	cout << "이름을 입력하시오: ";
	cin >> name; // 이름을 입력 받아 name에 저장한다.
	cout << name << "을 환영합니다." << endl; // 형식을 갖추어 name을 출력한다.

	return 0; // 0을 반환하여 프로그램을 종료한다.
}