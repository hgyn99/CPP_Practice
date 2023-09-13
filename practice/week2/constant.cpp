#include <iostream> // 헤더파일 iostream 포함

using namespace std; // 이름 공간 설정

int main() { // main 함수를 선언한다.

	const int GREATE_VICTORY_SALSU = 612; // 상수 GREATE_VICTORY_SALSU를 선언하여 값을 612로한다.
	const int GREATE_VICTORY_GWIJU = 1019; // 상수 GREATE_VICTORY_GWIJU를 선언하여 값을 1019로한다.

	cout << "고구려 살수대첩 연도 : " << GREATE_VICTORY_SALSU << "년" << endl; // 형식에 맞추어 고구려 살수대첩 연도를 출력한다.
	cout << "고려 귀주대첩 연도 : " << GREATE_VICTORY_GWIJU << "년" << endl; // 형식에 맞추어 고려 귀주대첩 연도를 출력한다.

	return 0; // 0을 반환하여 프로그램을 종료한다.
}