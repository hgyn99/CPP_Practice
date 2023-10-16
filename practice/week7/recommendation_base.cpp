#include <iostream>

using namespace std;

int main() {

	const int NUM_USERS = 3; // 유저의 수를 상수로 선언
	const int NUM_ITEMS = 3; // 항목의 수를 상수로 선언
	int userPreferences[NUM_USERS][NUM_ITEMS]; // 유저의 선호도를 저장할 2차원 배열 선언

	// 사용자와 항목 간의 선호도를 입력 받아 2차원 배열 초기화
	for (int i = 0; i < NUM_USERS; ++i) { // 반복문을 유저 수만큼 반복한다.
		// 형식을 갖추어 사용자에게 입력을 안내한다.
		cout << "사용자 " << (i + 1) << "의 선호도를 입력하세요 (";
		cout << NUM_ITEMS << "개의 항목에 대해): ";

		// 각 항목에 대한 유저의 선호도를 하나씩 입력 받는다.
		for (int j = 0; j < NUM_ITEMS; ++j) {
			cin >> userPreferences[i][j];
		}
	}

	// 각 사용자에 대한 추천 항목 찾기
	for (int i = 0; i < NUM_USERS; ++i) { // 반복문을 유저 수만큼 반복한다.
		int maxPreferenceIndex = 0; // 유저의 최대 선호도에 대한 인덱스를 저장할 변수 선언
		for (int j = 1; j < NUM_ITEMS; ++j) { // 반복문을 항목의 수 만큼 반복한다.
			// 만약 인덱스 i를 가진 유저의 최대 선호도가 기존에 담고 있는 선호도보다 크다면
			// 유저의 최대 선호도를 j 값으로 업데이트한다.
			if (userPreferences[i][j] > userPreferences[i][maxPreferenceIndex]) {
				maxPreferenceIndex = j;
			}
		}

		// 사용자에게 추천하는 항목 출력
		cout << "사용자 " << (i + 1) << "에게 추천하는 항목: ";
		cout << (maxPreferenceIndex + 1) << endl;
	}

	return 0;
}