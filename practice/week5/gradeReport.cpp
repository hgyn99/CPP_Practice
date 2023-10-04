#include <iostream>
#include <string>

using namespace std;

int main() {

	const int STUDENT = 5; // 학생수를 상수 5로 선언
	const int SUBJECT = 3; // 과목 수를 상수 3으로 선언

	int scores[STUDENT][SUBJECT]; // 학생들의 과목별 성적을 담을 2차원 배열 scores 선언
	string studentNames[STUDENT]
		= { "영수", "영희", "철수", "미미", "쥬쥬" };
	// 학생들의 이름을 배열 studentNames에 저장
	string subjectNames[SUBJECT]
		= { "수학", "영어", "CPP" };
	// 과목 이름들을 배열 subjectNames에 저장

	for (int i = 0; i < STUDENT; i++) {
		cout << studentNames[i] << "의 성적을 하나씩 입력하세요." << endl;
		for (int j = 0; j < SUBJECT; j++) {
			cout << subjectNames[j] << ":";
			cin >> scores[i][j];
		}		
	}
	// 반복문을 학생 수만큼 반복하며, 학생의 해당 과목 성적들을 차례대로 입력 받아 성적 배열에 저장한다.
	for (int i = 0; i < STUDENT; i++) {
		cout << studentNames[i] << "의 평균 점수는 ";
		double sum = 0;
		double average = 0;
		for (int j = 0; j < SUBJECT; j++) {
			sum += scores[i][j];
		}
		average = sum / SUBJECT;
		cout << average << "입니다" << endl;
	}
	// 학생들의 각 과목 점수들의 합을 과목 수로 나누어 평균을 구하고, 각 학생의 평균 점수를 차례대로 출력한다.
	return 0;
}