#include <iostream>
#include <string>

using namespace std;

// User 클래스
class User
{
private:
	// 멤버 변수
	int hp;
public:
	// 멤버 함수
	void DecreaseHP(int dec_hp);
	void IncreaseHP(int inc_hp);
	int GetHP();
	virtual void doAttack() {
		cout << "공격합니다" << endl;
	}
	// 생성자
	User(int first_hp = 20) {
		hp = first_hp;
	}

};

class Magician : public User {
public:
	void doAttack() override {
		cout << "마법 사용" << endl;
	}
};

class Warrior : public User {
public:
	void doAttack() override {
		cout << "베기 사용" << endl;
	}
};

// 클래스 외부 함수 정의
void User::DecreaseHP(int dec_hp) {
	hp -= dec_hp;
}
void User::IncreaseHP(int inc_hp) {
	hp += inc_hp;
}
int User::GetHP() {
	return hp;
}

const int mapX = 5; // 지도의 가로축 크기
const int mapY = 5; // 지도의 세로축 크기

// 추가 기능 요구사항 1. 유저는 체력 20을 가지고 게임 시작
// int user_hp = 20; // 더 이상 필요하지 않아 주석 처리

// 사용자 정의 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(int map[][mapX], int magician_x, int magician_y, int warrior_x, int warrior_y);
bool checkGoal(int map[][mapX], int user_x, int user_y, User& user);
// 추가 기능 요구사항 4에 대한 함수 원형
bool CheckUser(User user);
// 추가 기능 요구사항 5에 대한 함수 원형 
void checkState(int map[][mapX], int user_x, int user_y, User& user);
void handleUserInput(int map[][mapX], string user_input, int& user_x, int& user_y, User& my_user, string playerType);

// Magician과 Warrior 객체 생성 및 초기 hp 설정(20)
Magician magician_user;
Warrior warrior_user;

// 각 플레이어의 위치 초기화
int magician_x = 0, magician_y = 0;
int warrior_x = 0, warrior_y = 0;

// 현재 턴을 나타내는 변수
bool isMagicianTurn = true;

// 메인  함수
int main() {
	// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
	int map[mapY][mapX] = { {0, 1, 2, 0, 4},
					{1, 0, 0, 2, 0},
					{0, 0, 0, 0, 0},
					{0, 2, 3, 0, 0},
					{3, 0, 0, 0, 2} };

	// 게임 시작 
	while (1) { // 사용자에게 계속 입력받기 위해 무한 루프

		// 사용자의 턴을 알림
		if (isMagicianTurn) {
			cout << "Magician의 턴입니다." << endl;
		}
		else {
			cout << "Warrior의 턴입니다." << endl;
		}


		// 사용자의 입력을 저장할 변수
		string user_input = "";

		// 명령어를 입력할 것을 안내
		cout << "명령어를 입력하세요 (상,하,좌,우,지도,종료): ";
		cin >> user_input;
		// 사용자가 입력으로 "종료"를 입력했다면
		if (user_input == "종료") {
			// 종료 메세지 출력
			cout << "종료합니다.";
			return 0;
		}
		// 사용자에 따른 명령어 처리
		if (isMagicianTurn) {
			handleUserInput(map, user_input, magician_x, magician_y, magician_user, "Magician");
		}
		else {
			handleUserInput(map, user_input, warrior_x, warrior_y, warrior_user, "Warrior");
		}


		// 각 플레이어의 생존 확인 함수
		bool isAlive;
		if (isMagicianTurn) {
			isAlive = CheckUser(magician_user);
		}
		else {
			isAlive = CheckUser(warrior_user);
		}

		if (isAlive == false) {
			cout << "HP가 0 이하가 되었습니다. 실패했습니다." << endl;
			cout << "게임을 종료합니다." << endl;
			return 0;
		}

		// 목적지에 도달했는지 체크
		bool finish;

		if (isMagicianTurn) {
			finish = checkGoal(map, magician_x, magician_y, magician_user);
			if (finish == true) {
				cout << "Magician 플레이어가 목적지에 도착했습니다! 축하합니다!" << endl;
				cout << "게임을 종료합니다." << endl;
				break;
			}
		}
		else {
			finish = checkGoal(map, warrior_x, warrior_y, warrior_user);
			if (finish == true) {
				cout << "Warrior 플레이어가 목적지에 도착했습니다! 축하합니다!" << endl;
				cout << "게임을 종료합니다." << endl;
				break;
			}
		}


		// 턴 변경
		isMagicianTurn = !isMagicianTurn;
	}
	return 0;
}

void displayMap(int map[][mapX], int magician_x, int magician_y, int warrior_x, int warrior_y) {
	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			// Magician 위치 확인 및 출력
			if (i == magician_y && j == magician_x) {
				cout << "  M   |";
			}
			// Warrior 위치 확인 및 출력
			else if (i == warrior_y && j == warrior_x) {
				cout << "  W   |";
			}
			// 그 외 지도 요소 출력
			else {
				int posState = map[i][j];
				switch (posState) {
				case 0:
					cout << "      |";
					break;
				case 1:
					cout << "아이템|";
					break;
				case 2:
					cout << "  적  |";
					break;
				case 3:
					cout << " 포션 |";
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
bool checkGoal(int map[][mapX], int user_x, int user_y, User& user) {
	// 목적지 도착하면
	if (map[user_y][user_x] == 4) {
		return true;
	}
	return false;
}

// 추가 기능 요구사항 5. 아이템, 적, 포션이 있을 때 출력하는 함수
void checkState(int map[][mapX], int user_x, int user_y, User& user) {

	if (map[user_y][user_x] == 1) { // 아이템이 있을 때
		cout << "아이템이 있습니다." << endl;
	}
	else if (map[user_y][user_x] == 2) { // 적이 있을 때
		cout << "적이 있습니다. HP가 2 줄어듭니다." << endl;
		// my_user의 HP 2만큼 감소
		user.DecreaseHP(2);
		user.doAttack();
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

void handleUserInput(int map[][mapX], string user_input, int& user_x, int& user_y, User& my_user, string playerType) {
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
			// 지도 보여주기
			displayMap(map, magician_x, magician_y, warrior_x, warrior_y);
			// 추가 기능 요구사항 5. 아이템, 적, 포션이 있을 때 출력
			checkState(map, user_x, user_y, my_user);
			// 추가 기능 요구사항 2, 3. 이동할 때마다 체력 1씩 감소, HP 출력
			// my_user의 HP 1만큼 감소
			my_user.DecreaseHP(1);
			// 현재 HP를 받아와 출력
			cout << "현재 HP: " << my_user.GetHP() << endl << endl;
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
			// 지도 보여주기
			displayMap(map, magician_x, magician_y, warrior_x, warrior_y);
			// 추가 기능 요구사항 5. 아이템, 적, 포션이 있을 때 출력
			checkState(map, user_x, user_y, my_user);
			// 추가 기능 요구사항 2, 3. 이동할 때마다 체력 1씩 감소, HP 출력
			// my_user의 HP 1만큼 감소
			my_user.DecreaseHP(1);
			// 현재 HP를 받아와 출력
			cout << "현재 HP: " << my_user.GetHP() << endl << endl;
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
			// 지도 보여주기
			displayMap(map, magician_x, magician_y, warrior_x, warrior_y);
			// 추가 기능 요구사항 5. 아이템, 적, 포션이 있을 때 출력
			checkState(map, user_x, user_y, my_user);
			// 추가 기능 요구사항 2, 3. 이동할 때마다 체력 1씩 감소, HP 출력
			// my_user의 HP 1만큼 감소
			my_user.DecreaseHP(1);
			// 현재 HP를 받아와 출력
			cout << "현재 HP: " << my_user.GetHP() << endl << endl;
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
			// 지도 보여주기
			displayMap(map, magician_x, magician_y, warrior_x, warrior_y);
			// 추가 기능 요구사항 5. 아이템, 적, 포션이 있을 때 출력
			checkState(map, user_x, user_y, my_user);
			// 추가 기능 요구사항 1-2, 1-3. 이동할 때마다 체력 1씩 감소, HP 출력
			// my_user의 HP 1만큼 감소
			my_user.DecreaseHP(1);
			// 현재 HP를 받아와 출력
			cout << "현재 HP: " << my_user.GetHP() << endl << endl;
		}
	}
	// 사용자가 입력으로 "지도"를 입력했다면
	else if (user_input == "지도") {
		// 지도 보여주기 함수 호출
		displayMap(map, magician_x, magician_y, warrior_x, warrior_y);
		// 자동 턴 변경을 방지하기 위해 턴 변경을 한번 더 함
		isMagicianTurn = !isMagicianTurn;
	}
	// 사용자가 존재하지 않는 명령을 입력했다면
	else {
		// 에러 메세지 출력 후 재입력 받도록 한다.
		cout << "잘못된 입력입니다." << endl;
		// 자동 턴 변경을 방지하기 위해 턴 변경을 한번 더 함
		isMagicianTurn = !isMagicianTurn;
		return;
	}
}