#include <iostream>
#include <string>

using namespace std;

int main() {

	string s1 = "사과"; // string 타입 변수 s1을 선언하고, 문자열 "사과"를 저장한다.
	string s2; // string 타입 변수 s2를 선언한다.
	// s2 = s1 + " " + 10 + "개";
	s2 = s1 + " " + to_string(10) + "개"; // s2에 s1 문자열과 숫자 10을 문자열로 변환한 값을 포함해 다시 재가공한다.
	cout << s2 << endl; // s2를 출력한다.

	return 0; // 0을 반환하여 프로그램을 종료한다.
}