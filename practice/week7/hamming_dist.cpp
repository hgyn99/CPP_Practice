#include <iostream>
#include <string>

using namespace std;

int main() {
	string s1, s2; // DNA를 저장할 문자열 s1, s2를 선언
	int count = 0; // 해밍 거리를 카운팅할 변수 count 선언

	// 형식에 맞추어 DNA1, DNA2 문자열 입력 받음
	cout << "DNA1: ";
	cin >> s1;
	cout << "DNA2: ";
	cin >> s2;

	// 만약 입력 받은 두 문자열의 길이가 서로 다르다면
	if (s1.length() != s2.length())
		cout << "오류: 길이가 다름" << endl; // 길이가 다르다는 오류 메세지 출력
	else { // 길이가 같다면 (정상적인 입력이라면)
		// 반복문을 문자열의 길이만큼 반복하여 값을 하나씩 꺼내어 두 문자열을 비교한다.
		for (int i = 0; i < s1.length(); i++) {
			if (s1[i] != s2[i])
				count += 1; // 만약 같은 위치의 두 문자가 다르다면 count를 1 증가시킨다.
		}
		cout << "해밍 거리는 " << count << endl; // 최종 count 값을 출력한다.
	}
	return 0;
}