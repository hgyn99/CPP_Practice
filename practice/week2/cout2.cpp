#include <iostream> // 헤더파일 iostream 포함
#include <string> // 헤더파일 string 포함

using namespace std; // 이름 공간 설정

int main() { // main 함수를 선언한다.

	char character = 'C'; // char 타입 변수 character를 선언하고 'C'를 저장한다.
	int integer = 100; // int 타입 변수 integer를 선언하고 100을 저장한다.
	double precision = 3.14159; // double 타입 변수 precision을 선언하고 3.14159를 저장한다.
	bool is_true = true; // bool 타입 변수 is_true를 선언하고 true 값을 저장한다.
	string word = "Hello World"; // string 타입 변수 word를 선언하고 문자열 "Hello World"를 저장한다.

	cout << "char : " << character << endl; // 형식을 갖추어 값을 출력한다.
	cout << "int : " << integer << endl; // 형식을 갖추어 값을 출력한다.
	cout << "double : " << precision << endl; // 형식을 갖추어 값을 출력한다.
	cout << "bool : " << is_true << endl; // 형식을 갖추어 값을 출력한다.
	cout << "string : " << word << endl; // 형식을 갖추어 값을 출력한다.


	return 0; // 0을 반환하여 프로그램을 종료한다.
}