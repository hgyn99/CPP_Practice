#include <iostream>
#include <string>

using namespace std;

// 입력 받은 문자열을 모두 소문자로 변환
string toLowerStr(string str) {
	for (char& c : str) {
		c = tolower(c);
	}
	return str;
}

// 입력 받은 문자열을 모두 대문자로 변환
string toUpperStr(string str) {
	for (char& c : str) {
		c = toupper(c);
	}
	return str;
}

int calcHammingDist(string s1, string s2) {
	int count = 0; // 해밍 거리를 카운팅할 변수 count 선언
	// 문자열 s1과 s2를 모두 소문자로 통일하여, 대소문자 관계 없이 계산하도록 한다.
	s1 = toLowerStr(s1);
	s2 = toLowerStr(s2);
	for (int i = 0; i < s1.length(); i++) {
		// 만약 같은 위치의 두 문자가 다르다면 count를 1 증가시킨다.
		if (s1[i] != s2[i])
			count += 1; 
	}
	return count; // 계산된 count 값을 반환한다.
}

int main() {
	string s1, s2; // DNA를 저장할 문자열 s1, s2를 선언
	
	// do-while 문을 이용해 최초의 s1, s2 입력을 받고, 입력이 같아질 때까지 입력을 반복하도록 한다.
	do {
		// 형식에 맞추어 s1, s2 문자열 입력 받는다.
		cout << "s1: ";
		cin >> s1;
		cout << "s2: ";
		cin >> s2;
		// 만약 두 문자열의 길이가 같다면 while문을 탈출한다.
		if (s1.length() == s2.length()) break;
		// 길이가 다르다면 오류 메세지 출력 후 while문을 반복한다.
		cout << "오류: 길이가 다름" << endl;
	} while (s1.length() != s2.length());

	// 대소문자 관계 없이 거리를 구하는 함수를 실행하여 count 값을 저장한다.
	int count = calcHammingDist(s1, s2); 
	// 최종 count 값을 출력한다.
	cout << "해밍 거리는 " << count << endl; 

	return 0;
}