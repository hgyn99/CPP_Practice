#include <iostream>

using namespace std;

int main() {

	int vowel = 0;
	int consonant = 0;
	// 모음의 갯수를 저장할 vowel, 자음의 갯수를 저장할 consonant를 선언하고 0으로 초기화한다.

	cout << "영문자를 입력하고 ctrl+z를 치세요" << endl;
	// 입력 안내메세지 출력

	char ch; // 사용자 입력을 저장하기 위한 변수
	while (cin >> ch) {
		switch (ch) {
		case 'a': case 'e': case 'i': case 'o': case 'u':
			vowel++;
			break;
		// 만약 입력 값이 a, e, i, o ,u 중 하나라면 모음의 갯수를 증가시키고, 반복문을 탈출한다.
		default:
			consonant++;
		// 만약 입력 값이 모음이 아닌 자음이라면 자음의 갯수를 증가시킨다.
		}
	}
	cout << "모음: " << vowel << endl;
	cout << "자음: " << consonant << endl;
	// 모음의 갯수와 자음의 갯수를 출력하고 프로그램을 종료한다.

	return 0;
}