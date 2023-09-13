#include <iostream>
#include <string>

using namespace std;

int main() {

	string s1 = "Good"; // string 타입 변수 s1을 선언하고, 문자열 "Good"을 저장한다.
	string s2 = "Morning"; // string 타입 변수 s2를 선언하고, 문자열 "Morning"을 저장한다.
	string s3 = s1 + " " + s2 + "!"; // s1과 s2에 저장된 문자열을 합하여 새로운 문자열을 재가공한다.

	cout << s3 << endl; // 새로 만들어진 문자열 s3를 출력한다.

	return 0; // 0을 반환하며 프로그램을 종료한다.
}