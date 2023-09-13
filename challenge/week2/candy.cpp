#include <iostream>

using namespace std;

int main() {

	int money, price; // int 타입 변수 money, price를 선언한다.
	cout << "현재 가지고 있는 돈: ";
	cin >> money;
	// 현재 가지고 있는 돈 money를 입력받는다.
	cout << "캔디의 가격: ";
	cin >> price;
	// 캔디의 가격 price를 입력받는다.
	cout << "최대로 살 수 있는 캔디 = " << money / price << endl;
	// 최대로 살 수 있는 캔디(몫)을 출력한다.
	cout << "캔디 구입 후 남은 돈 = " << money % price << endl;
	// 캔디 구입 후 남은 돈(나머지)를 출력한다.
	return 0; // 0을 반환하며 프로그램을 종료한다.
}