#include "user.h"

const int mapX = 5; // 지도의 가로축 크기
const int mapY = 5; // 지도의 세로축 크기

// 추가 기능 요구사항 1. 유저는 체력 20을 가지고 게임 시작
// int user_hp = 20; // 더 이상 필요하지 않아 주석 처리

// 사용자 정의 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(int map[][mapX], int user_x, int user_y);
bool checkGoal(int map[][mapX], int user_x, int user_y);
// 추가 기능 요구사항 4에 대한 함수 원형
bool CheckUser(User user);
// 추가 기능 요구사항 5에 대한 함수 원형 
void checkState(int map[][mapX], int user_x, int user_y, User& user);

// 메인  함수
int main() {
	// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
	int map[mapY][mapX] = { {0, 1, 2, 0, 4},
					{1, 0, 0, 2, 0},
					{0, 0, 0, 0, 0},
					{0, 2, 3, 0, 0},
					{3, 0, 0, 0, 2} };


	// 유저의 위치를 저장할 변수
	int user_x = 0; // 가로 번호
	int user_y = 0; // 세로 번호

	// 유저 생성 및 초기 hp 설정(20)
	User my_user;



	// 게임 시작 
	while (1) { // 사용자에게 계속 입력받기 위해 무한 루프


		// 사용자의 입력을 저장할 변수
		string user_input = "";

		// 명령어를 입력할 것을 안내
		cout << "명령어를 입력하세요 (상,하,좌,우,지도,종료): ";
		cin >> user_input;

		if (user_input == "상") { // 사용자가 입력으로 "상"을 입력했다면
			// 위로 한 칸 올라가기
			user_y -= 1; // 사용자의 y 좌표를 -1만큼 변경하여 위치를 위로 올림
			bool inMap = checkXY(user_x, mapX, user_y, mapY); // 사용자의 위치에 대한 유효성을 bool 변수로 저장함
			// 지도를 벗어났을 시 에러 메세지 출력 후 위치 복구
			if (inMap == false) {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				user_y += 1;
			}
			// 정상적인 입력이라면 위치 이동
			else {
				cout << "위로 한 칸 올라갑니다." << endl;
				displayMap(map, user_x, user_y);
				// 추가 기능 요구사항 5. 아이템, 적, 포션이 있을 때 출력
				checkState(map, user_x, user_y, my_user);
				// 추가 기능 요구사항 2, 3. 이동할 때마다 체력 1씩 감소, HP 출력
				// my_user의 HP 1만큼 감소
				my_user.DecreaseHP(1);
				// 현재 HP를 받아와 출력
				cout << "현재 HP: " << my_user.GetHP() << " ";
			}
		}
		else if (user_input == "하") { // 사용자가 입력으로 "하"를 입력했다면
			// 아래로 한 칸 내려가기
			user_y += 1; // 사용자의 y 좌표를 +1만큼 변경하여 위치를 아래로 올림
			bool inMap = checkXY(user_x, mapX, user_y, mapY); // 사용자의 위치에 대한 유효성을 bool 변수로 저장함
			// 지도를 벗어났을 시 에러 메세지 출력 후 위치 복구
			if (inMap == false) {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				user_y -= 1;
			}
			// 정상적인 입력이라면 위치 이동
			else {
				cout << "아래로 한 칸 내려갑니다." << endl;
				displayMap(map, user_x, user_y);
				// 추가 기능 요구사항 5. 아이템, 적, 포션이 있을 때 출력
				checkState(map, user_x, user_y, my_user);
				// 추가 기능 요구사항 2, 3. 이동할 때마다 체력 1씩 감소, HP 출력
				// my_user의 HP 1만큼 감소
				my_user.DecreaseHP(1);
				// 현재 HP를 받아와 출력
				cout << "현재 HP: " << my_user.GetHP() << " ";
			}
		}
		else if (user_input == "좌") { // 사용자가 입력으로 "좌"를 입력했다면
			// 왼쪽으로 이동하기
			user_x -= 1; // 사용자의 x 좌표를 -1만큼 변경하여 위치를 왼쪽으로 이동함
			bool inMap = checkXY(user_x, mapX, user_y, mapY); // 사용자의 위치에 대한 유효성을 bool 변수로 저장함
			// 지도를 벗어났을 시 에러 메세지 출력 후 위치 복구
			if (inMap == false) {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				user_x += 1;
			}
			// 정상적인 입력이라면 위치 이동
			else {
				cout << "왼쪽으로 이동합니다." << endl;
				displayMap(map, user_x, user_y);
				// 추가 기능 요구사항 5. 아이템, 적, 포션이 있을 때 출력
				checkState(map, user_x, user_y, my_user);
				// 추가 기능 요구사항 2, 3. 이동할 때마다 체력 1씩 감소, HP 출력
				// my_user의 HP 1만큼 감소
				my_user.DecreaseHP(1);
				// 현재 HP를 받아와 출력
				cout << "현재 HP: " << my_user.GetHP() << " ";
			}
		}
		else if (user_input == "우") { // 사용자가 입력으로 "우"를 입력했다면
			// 오른쪽으로 이동하기
			user_x += 1; // 사용자의 x 좌표를 +1만큼 변경하여 위치를 오른쪽으로 이동함
			bool inMap = checkXY(user_x, mapX, user_y, mapY); // 사용자의 위치에 대한 유효성을 bool 변수로 저장함
			// 지도를 벗어났을 시 에러 메세지 출력 후 위치 복구
			if (inMap == false) {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				user_x -= 1;
			}
			// 정상적인 입력이라면 위치 이동
			else {
				cout << "오른쪽으로 이동합니다." << endl;
				displayMap(map, user_x, user_y);
				// 추가 기능 요구사항 5. 아이템, 적, 포션이 있을 때 출력
				checkState(map, user_x, user_y, my_user);
				// 추가 기능 요구사항 1-2, 1-3. 이동할 때마다 체력 1씩 감소, HP 출력
				// my_user의 HP 1만큼 감소
				my_user.DecreaseHP(1);
				// 현재 HP를 받아와 출력
				cout << "현재 HP: " << my_user.GetHP() << " ";
			}
		}
		// 사용자가 입력으로 "지도"를 입력했다면
		else if (user_input == "지도") {
			// 지도 보여주기 함수 호출
			displayMap(map, user_x, user_y);
		}
		// 사용자가 입력으로 "종료"를 입력했다면
		else if (user_input == "종료") {
			// 종료 메세지 출력
			cout << "종료합니다.";
			break;
		}
		// 사용자가 존재하지 않는 명령을 입력했다면
		else {
			// 에러 메세지 출력 후 재입력 받도록 continue
			cout << "잘못된 입력입니다." << endl;
			continue;
		}

		// 추가 기능 요구사항 4. HP가 0 이하가 되면 "실패"를 출력하고 종료 - 함수 변환
		bool isAlive = CheckUser(my_user);

		if (isAlive == false) {
			cout << "HP가 0 이하가 되었습니다. 실패했습니다." << endl;
			cout << "게임을 종료합니다." << endl;
			return 0;
		}

		// 목적지에 도달했는지 체크
		bool finish = checkGoal(map, user_x, user_y);
		if (finish == true) {
			cout << "목적지에 도착했습니다! 축하합니다!" << endl;
			cout << "게임을 종료합니다." << endl;
			break;
		}

	}
	return 0;
}


// 지도와 사용자 위치 출력하는 함수
void displayMap(int map[][mapX], int user_x, int user_y) {
	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			if (i == user_y && j == user_x) {
				cout << " USER |"; // 양 옆 1칸 공백
			}
			else {
				int posState = map[i][j];
				switch (posState) {
				case 0:
					cout << "      |"; // 6칸 공백
					break;
				case 1:
					cout << "아이템|";
					break;
				case 2:
					cout << "  적  |"; // 양 옆 2칸 공백
					break;
				case 3:
					cout << " 포션 |"; // 양 옆 1칸 공백
					break;
				case 4:
					cout << "목적지|";
					break;
				}
			}
		}
		cout << endl;
		cout << " -------------------------------- " << endl;
	}
}

// 이동하려는 곳이 유효한 좌표인지 체크하는 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY) {
	bool checkFlag = false;
	if (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY) {
		checkFlag = true;
	}
	return checkFlag;
}

// 유저의 위치가 목적지인지 체크하는 함수
bool checkGoal(int map[][mapX], int user_x, int user_y) {
	// 목적지 도착하면
	if (map[user_y][user_x] == 4) {
		return true;
	}
	return false;
}

// 추가 기능 요구사항 5. 아이템, 적, 포션이 있을 때 출력하는 함수
void checkState(int map[][mapX], int user_x, int user_y, User & user) {

	if (map[user_y][user_x] == 1) { // 아이템이 있을 때
		cout << "아이템이 있습니다." << endl;
	}
	else if (map[user_y][user_x] == 2) { // 적이 있을 때
		cout << "적이 있습니다. HP가 2 줄어듭니다." << endl;
		// my_user의 HP 2만큼 감소
		user.DecreaseHP(2);
	}
	else if (map[user_y][user_x] == 3) { // 포션이 있을 때
		cout << "포션이 있습니다. HP가 2 늘어납니다." << endl;
		// my_user의 HP를 2만큼 증가
		user.IncreaseHP(2);
	}
}

// 유저의 HP 상태를 체크하는 함수
bool CheckUser(User user) {

	if (user.GetHP() <= 0) return false;

	return true;
}
