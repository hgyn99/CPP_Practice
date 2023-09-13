#include <iostream>
#include <string>

using namespace std;

int main() {

	string s1 = "Good"; // string 타입 변수 s1을 선언하고, 문자열 "Good"을 저장한다.
	string s2 = "Bad"; // string 타입 변수 s2를 선언하고, 문자열 "Bad"를 저장한다.
	bool b = (s1 == s2); // bool 타입 변수 b를 선언하고, 값으로는 s1과 s2가 같지 않으므로 false가 저장된다.
	cout << b << endl; // b를 출력한다.

	s2 = "Good"; // s2에 문자열 "Good"을 저장한다.
	b = (s1 == s2); // s1과 s2가 같아졌으므로 b에 true 값이 저장된다.
	cout << b << endl; // b를 출력한다.

	return 0; // 0을 반환하여 프로그램을 종료한다.
}