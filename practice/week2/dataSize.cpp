#include <iostream> // 헤더파일 iostream 포함

using namespace std;

int main() {

	cout << "char 크기 : " << sizeof('p') << endl; // char의 크기를 출력한다.
	cout << "int 크기 : " << sizeof(10) << endl; // int의 크기를 출력한다.
	cout << "double 크기 : " << sizeof(10.0) << endl; // double의 크기를 출력한다.

	return 0; // 0을 반환하여 프로그램을 종료한다.
}