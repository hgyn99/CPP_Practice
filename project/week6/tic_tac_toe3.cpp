#include <iostream>

using namespace std;

int main() {

	const int numCell = 3;
	const int num_player = 3;
	int count = 0; // 돌을 둔 횟수를 체크하는 변수 count
	char board[numCell][numCell]{};
	int x, y; // 사용자에게 입력받는 x, y 좌표를 저장할 변수

	// 보드판 초기화
	for (x = 0; x < numCell; x++) {
		for (y = 0; y < numCell; y++) {
			board[x][y] = ' ';
		}
	}

	// 게임하는 코드
	int k = 0; // 누구 차례인지 체크하기 위한 변수
	char currentUser = 'X'; // 현재 유저의 볼을 저장하기 위한 문자 변수
	while (true) {
		//1. 누구 차례인지 출력
		switch (k % num_player) {
		case 0:
			cout << k % num_player + 1 << "번 유저(X)의 차례입니다 -> ";
			currentUser = 'X';
			break;
		case 1:
			cout << k % num_player + 1 << "번 유저(O)의 차례입니다 -> ";
			currentUser = 'O';
			break;
		case 2:
			cout << k % num_player + 1 << "번 유저(A)의 차례입니다 -> "; // '△'가 제대로 출력되지 않고 빈칸이 나오는 경우도 있어 '△'를 'A'로 대체했습니다.
			currentUser = 'A';
			break;
		}
		// 2. 좌표 입력 받기
		cout << "(x, y) 좌표를 입력하세요: ";
		cin >> x >> y;
		count++;

		// 3. 입력받은 좌표의 유효성 체크
		if (x >= numCell || y >= numCell) {
			cout << x << ", " << y << ": ";
			cout << " x 와 y 둘 중 하나가 칸을 벗어납니다." << endl;
			continue;
		}
		if (board[x][y] != ' ') {
			cout << x << ", " << y << ": 이미 돌이 차있습니다." << endl;
			continue;
		}

		// 4. 입력받은 좌표에 현재 유저의 돌 뽑기
		board[x][y] = currentUser;

		// 5. 현재 보드 판 출력
		for (int i = 0; i < numCell; i++) {
			cout << "---|---|---" << endl;
			for (int j = 0; j < numCell; j++) {
				cout << board[i][j];
				if (j == numCell - 1) {
					break;
				}
				cout << "  |";
			}
			cout << endl;
		}
		cout << "---|---|---" << endl;
		k++;

		// 추가 기능
		// 6. 빙고 시 승자 출력 후 종료
		for (int i = 0; i < numCell; i++) {
			// 6-1. 가로 줄의 돌이 모두 같다면
			if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) && board[i][0] != ' ') {
				if (board[i][0] == 'X') {
					cout << "가로에 모두 돌이 놓였습니다!: 1번 유저(X)의 승리입니다!" << endl; // 가로에 모두 놓인 돌이 X라면 X의 승리 출력
					cout << "종료합니다" << endl;
					return 0;
				}
				else if (board[i][0] == 'O') {
					cout << "가로에 모두 돌이 놓였습니다!: 2번 유저(O)의 승리입니다!" << endl; // 가로에 모두 놓인 돌이 O라면 O의 승리 출력
					cout << "종료합니다" << endl;
					return 0;
				}
				else{
					cout << "가로에 모두 돌이 놓였습니다!: 3번 유저(A)의 승리입니다!" << endl; // 가로에 모두 놓인 돌이 A라면 A의 승리 출력
					cout << "종료합니다" << endl;
					return 0;
				}
			}
			for (int j = 0; j < numCell; j++) {
				// 6-2. 세로 줄의 돌이 모두 같다면
				if ((board[0][j] == board[1][j]) && (board[1][j] == board[2][j]) && board[0][j] != ' ') {
					if (board[0][j] == 'X') {
						cout << "세로에 모두 돌이 놓였습니다!: 1번 유저(X)의 승리입니다!" << endl; // 세로에 모두 놓인 돌이 X라면 X의 승리 출력
						cout << "종료합니다" << endl;
						return 0;
					}
					else if (board[0][j] == 'O') {
						cout << "세로에 모두 돌이 놓였습니다!: 2번 유저(O)의 승리입니다!" << endl; // 세로에 모두 놓인 돌이 O라면 O의 승리 출력
						cout << "종료합니다" << endl;
						return 0;
					}
					else {
						cout << "세로에 모두 돌이 놓였습니다!: 3번 유저(A)의 승리입니다!" << endl; // 세로에 모두 놓인 돌이 A라면 A의 승리 출력
						cout << "종료합니다" << endl;
						return 0;
					}
				}
			}
		}
		// 6-3. 대각선의 돌이 모두 같다면
		// 왼쪽 위에서 오른쪽 아래 대각선의 돌이 모두 같은 경우
		if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) && board[1][1] != ' ') {
			if (board[0][0] == board[1][1] && board[1][1] == 'X') { // 위 조건을 만족하면서 놓인 돌이 X일 경우
				cout << "왼쪽 위에서 오른쪽 아래 대각선으로 모두 돌이 놓였습니다!: 1번 유저(X)의 승리입니다!" << endl; // X의 승리 출력
				cout << "종료합니다" << endl;
				return 0;
			}
			else if (board[0][0] == board[1][1] && board[1][1] == 'O') { // // 위 조건을 만족하면서 놓인 돌이 O일 경우(특정 좌표 1개만을 비교하므로 단순히 else문이 아닌 else if를 사용함)
				cout << "왼쪽 위에서 오른쪽 아래 대각선으로 모두 돌이 놓였습니다!: 2번 유저(O)의 승리입니다!" << endl; // O의 승리 출력
				cout << "종료합니다" << endl;
				return 0;
			}
			else if (board[0][0] == board[1][1] && board[1][1] == 'A') { // // 위 조건을 만족하면서 놓인 돌이 A일 경우(특정 좌표 1개만을 비교하므로 단순히 else문이 아닌 else if를 사용함)
				cout << "왼쪽 위에서 오른쪽 아래 대각선으로 모두 돌이 놓였습니다!: 3번 유저(A)의 승리입니다!" << endl; // A의 승리 출력
				cout << "종료합니다" << endl;
				return 0;
			}
		}
		// 오른쪽 위에서 왼쪽 아래 대각선의 돌이 모두 같은 경우
		if ((board[0][2] == board[1][1] && board[1][1] == board[2][0]) && board[1][1] != ' ') {
			if (board[0][2] == board[1][1] && board[1][1] == 'X') { // 위 조건을 만족하면서 놓인 돌이 X일 경우
				cout << "오른쪽 위에서 왼쪽 아래 대각선으로 모두 돌이 놓였습니다!: 1번 유저(X)의 승리입니다!" << endl; // X의 승리 출력
				cout << "종료합니다" << endl;
				return 0;
			}
			else if (board[0][2] == board[1][1] && board[1][1] == 'O') { // // 위 조건을 만족하면서 놓인 돌이 O일 경우(특정 좌표 1개만을 비교하므로 단순히 else문이 아닌 else if를 사용함)
				cout << "오른쪽 위에서 왼쪽 아래 대각선으로 모두 돌이 놓였습니다!: 2번 유저(O)의 승리입니다!" << endl; //  O의 승리 출력
				cout << "종료합니다" << endl;
				return 0;
			}
			else if (board[0][2] == board[1][1] && board[1][1] == 'A') { // // 위 조건을 만족하면서 놓인 돌이 A일 경우(특정 좌표 1개만을 비교하므로 단순히 else문이 아닌 else if를 사용함)
				cout << "오른쪽 위에서 왼쪽 아래 대각선으로 모두 돌이 놓였습니다!: 3번 유저(A)의 승리입니다!" << endl; //  A의 승리 출력
				cout << "종료합니다" << endl;
				return 0;
			}
		}

		// 7. 모든 칸이 찼으면 종료
		if (count == 9) { // 돌을 둔 횟수가 9회이면서, 위의 모든 승리 조건이 만족되지 않은 경우에만 실행
			cout << "모든 칸이 다 찼습니다. 종료합니다." << endl;
			return 0;
		}

	}
	return 0;
}