#include <iostream>
using namespace std;

// 게임을 진행하는 데 필요한 변수 선언 -> 함수에서의 사용을 위해 모두 전역 변수화

const int numCell = 3; // 보드판의 가로 세로 길이
int k = 0; // 누구 차례인지 체크하기 위한 변수
char currentUser = 'X'; // 현재 유저의 돌을 저장하기 위한 변수
char board[numCell][numCell]{}; // 보드판을 나타내는 2차원 배열
int x, y = 0; // 사용자에게 xy좌표값을 입력받기 위한 변수
bool isWin = false; // 승리 여부를 확인하는 변수 isWin

// 입력한 좌표가 유효한지 유효성을 체크하는 함수
bool isValid(int x, int y) {
	if (x >= numCell || y >= numCell) { // 좌표 범위를 벗어날때
		cout << x << "," << y << ": x와 y둘중 하나가 칸을 벗어납니다. " << endl;
		return false;
	}
	if (board[x][y] != ' ') { // 좌표범위의 입력값이 중복될때
		cout << x << "," << y << ": 이미 돌이 차있습니다. " << endl;
		return false;
	}
	return true;
}

// 매개변수로 받은 user가 승리 조건을 만족했는지 확인하는 함수
bool checkWin(char user) {

	// 가로 돌 승리조건: countHor의 값이 보드판의 크기인 numCell과 같아지면 해당 user의 가로 돌이 모두 같은 것이므로 승리 메세지 출력 후 isWin을 true로 반환한다.
	for (int i = 0; i < numCell; i++) {
		int countHor = 0;
		for (int j = 0; j < numCell; j++) {
			if (board[i][j] == user) { // 해당 유저의 가로 돌이 같은지 확인하는 조건
				countHor++;
			}
		}
		if (countHor == numCell) {
			isWin = true;
			cout << "가로에 모두 돌이 놓였습니다!!" << endl;
			return isWin;
		}
	}

	// 세로 돌 승리조건: countVer의 값이 보드판의 크기인 numCell과 같아지면 해당 user의 세로 돌이 모두 같은 것이므로 승리 메세지 출력 후 isWin을 true로 반환한다.
	for (int i = 0; i < numCell; i++) {
		int countVer = 0;
		for (int j = 0; j < numCell; j++) {
			if (board[j][i] == user) { // 해당 유저의 세로 돌이 같은지 확인하는 조건
				countVer++;
			}
		}
		if (countVer == numCell) {
			isWin = true;
			cout << "세로에 모두 돌이 놓였습니다!!" << endl;
			return isWin;
		}
	}

	// 대각선 돌 승리조건1 (왼쪽 위에서 오른쪽 아래로): countDiag1의 값이 보드판의 크기인 numCell과 같아지면 해당 user의 대각선 돌이 모두 같은 것이므로 승리 메세지 출력 후 isWin을 true로 반환한다.
	int countDiag1 = 0;
	for (int i = 0; i < numCell; i++) {
		if (board[i][i] == user) { // 해당 유저의 대각선(왼쪽 위에서 오른쪽 아래로) 돌이 같은지 확인하는 조건
			countDiag1++;
		}
	}
	if (countDiag1 == numCell) {
		isWin = true;
		cout << "왼쪽 위에서 오른쪽 아래 대각선으로 모두 돌이 놓였습니다!" << endl;
		return isWin;
	}

	// 대각선 돌 승리조건2 (오른쪽 위에서 왼쪽 아래로): countDiag2의 값이 보드판의 크기인 numCell과 같아지면 해당 user의 대각선 돌이 모두 같은 것이므로 승리 메세지 출력 후 isWin을 true로 반환한다.
	int countDiag2 = 0;
	for (int i = 0; i < numCell; i++) {
		if (board[i][numCell - 1 - i] == user) { // 해당 유저의 대각선(오른쪽 위에서 왼쪽 아래로) 돌이 같은지 확인하는 조건
			countDiag2++;
		}
	}
	if (countDiag2 == numCell) {
		isWin = true;
		cout << "오른쪽 위에서 왼쪽 아래 대각선으로 모두 돌이 놓였습니다!" << endl;
		return isWin;
	}

	return isWin;
}


int main() {

	// 보드판 초기화
	for (int i = 0; i < numCell; i++) {
		for (int j = 0; j < numCell; j++) {
			board[i][j] = ' ';
		}
	}

	// 게임을 무한 반복
	while (true) {
		// 1. 누구 차례인지 출력
		// TODO 1.1: 3인용 게임으로 변경 - 완료
		switch (k % 3) {
		case 0:
			currentUser = 'X';
			break;
		case 1:
			currentUser = 'O';
			break;
		case 2:
			currentUser = 'H';
			break;
		}
		cout << k % 3 + 1 << "번 유저(" << currentUser << ")의 차례입니다. -> ";

		// 2. 좌표 입력 받기
		cout << "(x, y) 좌표를 입력하세요: ";
		int x, y;
		cin >> x >> y;

		// 3. 입력받은 좌표의 유효성 체크
		// TODO FUNC 1: isValid 함수 생성 후 호출 - 완료

		// x, y 좌표에 대해 isValid 함수를 실행한 반환 값을 validResult에 저장한다.
		bool validResult = isValid(x, y);
		// 만약 isValid 함수의 반환 값이 false라면(유효한 좌표가 아니라면)
		if (validResult == false) {
			continue; // 다시 입력을 받도록 반복문으로 돌아간다.
		}


		// 4. 입력받은 좌표에 현재 유저의 돌 놓기
		board[x][y] = currentUser;

		// 5. 현재 보드 판 출력
		// TODO 1.2: numCell 숫자에 맞춘 보드판 출력 - 완료

		// numCell의 숫자에 맞게끔 형식에 맞추어 보드판을 출력
		for (int i = 0; i < numCell; i++) {
			cout << "---";
			for (int k = 0; k < numCell - 1; k++) {
				cout << "|---";
			}
			cout << endl;
			for (int j = 0; j < numCell; j++)
			{
				cout << board[i][j];
				if (j == numCell - 1) {
					break;
				}
				cout << "  |";
			}
			cout << endl;
		}
		cout << "---";
		for (int k = 0; k < numCell - 1; k++) {
			cout << "|---";
		}
		cout << endl;

		// TODO FUNC2: 6.1부터 6.2까지 checkWin 함수 생성 후 호출 - 완료
		// 6.1. 가로/세로 돌 체크하기

		// 현재 유저가 가로, 세로, 대각선1, 대각선2 승리 조건을 만족하는지 확인하는 함수 checkWin을 실행한다.
		checkWin(currentUser);

		// 6.2. 대각선을 체크하기
		// TODO 1.3: numCell에 맞춘 대각선 빙고 체크 코드로 확장 - 완료
		// HINT: for 문

		// 위 함수에서 대각선 조건까지 검사하였다.

		// 승리자가 결정되었으면 해당 플레이어를 출력하고 게임을 종료한다.
		if (isWin == true) {
			cout << k % 3 + 1 << "번 유저(" << currentUser << ")의 승리입니다!" << endl;
			break;
		}

		// 7. 모든 칸 다 찼는지 체크하기
		int checked = 0;
		for (int i = 0; i < numCell; i++) {
			for (int j = 0; j < numCell; j++) {
				if (board[i][j] == ' ') {
					checked++;
				}
			}
		}

		// 모든 칸이 다 찼다면 반복문을 탈출하여 프로그램을 종료한다.
		if (checked == 0) {
			cout << "모든 칸이 다 찼습니다.  종료합니다. " << endl;
			break;
		}

		k++;
	}

	return 0;
}