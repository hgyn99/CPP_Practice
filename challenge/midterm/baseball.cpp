#include <iostream>
#include <string>
using namespace std;

int randomNum; // 맞춰야 하는 3자리수의 숫자 저장 변수
int firstNum; // 정답의 첫번째 자리수
int secondNum; // 정답의 두번째 자리수
int thirdNum; // 정답의 세번째 자리수

bool same = false; // 모든 수가 다를 경우 true를 갖는 변수

int list[3]; // 정답의 각 자릿수를 담을 배열 list

// 3자리의 숫자가 모두 다른지 확인하는 함수 checkNumber
bool checkNumber(int num1, int num2, int num3) {

	same = false;

	// 만약 각 자릿수가 모두 서로 다르다면 same을 true로 변경한다.
	if ((num1 != num2) && (num1 != num3) && (num2 != num3)) {
		same = true;
	}

	// 중복되는 숫자가 있다면 false 반환, 중복되는 숫자가 없다면 true 반환
	return same;
}

int main() {

	while (1) {

		randomNum = rand() % 900 + 100; // 랜덤한 3자리수 생성

		// TODO 1: 3자리 숫자의 자릿수를 추출하고, 모든 수가 다른지 체크하는 코드블록 작성
		
		// 랜덤으로 생성된 숫자의 각 자릿수 추출
		firstNum = randomNum / 100;
		secondNum = randomNum % 100 / 10;
		thirdNum = randomNum % 10;

		// 랜덤으로 생성된 숫자의 각 자릿수를 매개변수로 checkNumber 함수를 실행하여 same 값을 반환받는다.
		checkNumber(firstNum, secondNum, thirdNum);

		// 함수를 통해 same 값이 true가 되었다면(3자리 숫자가 모두 다르다면) 랜덤 숫자 생성을 멈추고 반복문을 탈출한다.
		if (same == true) {
			break;
		}

	}
	// 사용자가 정답을 맞추기 위해 시도한 횟수
	int turn = 0;
	while (1) {
		cout << turn + 1 << "번째 시도입니다. " << endl;

		int userNumber; // 사용자가 입력한 세자리수 저장 변수
		int guessFirst; // 추측한 숫자의 첫번째 자리수
		int guessSecond; // 추측한 숫자의 두번째 자리수
		int guessThird; // 추측한 숫자의 세번째 자리수

		// 사용자에게 세자리 수를 입력받는 코드 블록
		while (1) {
			// 형식에 맞추어 사용자에게 숫자를 입력받는다.
			cout << "세자리 수를 입력해주세요: ";
			cin >> userNumber;

			// TODO 1: 3자리 숫자의 자릿수를 추출하고, 모든 수가 다른지 체크하는 코드블록 작성

			// 사용자에게 입력 받은 숫자의 각 자릿수를 추출한다.
			guessFirst = userNumber / 100;
			guessSecond = userNumber % 100 / 10;
			guessThird = userNumber % 10;

			// 사용자에게 입력 받은 숫자가 3자리가 아니라면 오류 메세지를 출력하고 입력을 다시 받는다.
			if (to_string(userNumber).length() != 3) {
				cout << "입력된 숫자가 3자리 수가 아닙니다. 다시 입력하세요." << endl;
				continue;
			}

			// 사용자에게 입력 받은 숫자의 각 자릿수를 매개변수로 checkNumber 함수를 실행하여 same 값을 반환받는다.
			checkNumber(guessFirst, guessSecond, guessThird);

			// 함수를 통해 same 값이 true가 되었다면(3자리 숫자가 모두 다르다면) 랜덤 숫자 생성을 멈추고 반복문을 탈출한다.
			if (same == true) {
				break;
			}
			// same 값이 true가 되지 않았다면 중복된 숫자가 있는 것이므로 오류 메세지를 출력하고 반복문으로 돌아간다.
			cout << "입력한 숫자에 중복된 숫자가 있습니다. 다시 입력하세요" << endl;
		}

		int strike = 0; // 스트라이크 갯수를 저장하는 변수
		int ball = 0; // 볼 갯수를 저장하는 변수

		// TODO 2: 정답과 추측한 숫자의 자릿수와 숫자를 비교하며 힌트를 주기 위한 코드블록 작성

		// 맞춰야하는 숫자의 자릿수를 list 배열에 하나씩 저장한다.
		list[0] = firstNum;
		list[1] = secondNum;
		list[2] = thirdNum;

		// 정답의 각 자릿수와 입력 받은 수의 각 자릿수가 일치한다면 스트라이크이므로 이 경우 strike 값을 증가시킨다.
		if (firstNum == guessFirst) strike++;
		if (secondNum == guessSecond) strike++;
		if (thirdNum == guessThird) strike++;

		// 입력 받은 수의 각 자릿수가 정답의 각 자릿수와 같은 수가 존재한다면, ball에 해당하므로 ball 값을 증가시킨다. (strike와 중복 포함 가능성 있음)
		for (auto elem : list) {
			if (elem == guessFirst || elem == guessSecond || elem == guessThird) {
				ball++;
			}
		}
		// strike로 중복 체크된 ball의 갯수만큼 볼을 빼준다.
		ball -= strike;

		// 결과를 형식에 맞추어 출력한다.
		cout << userNumber << "의 결과 : " << strike << " 스트라이크, " << ball << "볼 입니다." << endl;

		// 스트라이크가 3개가 된다면 정답을 맞춘 것이므로 반복을 탈출하여 프로그램을 종료시킨다.
		if (strike == 3) {
			cout << "정답을 맞췄습니다. 축하합니다.";
			break;
		}

		// 스트라이크가 3개가 되지 못했다면 아직 정답을 맞추지 못한 것이므로 정답을 맞추기 위한 시도를 계속하기 위해 turn을 증가시킨다.
		turn += 1;
	}

	return 0;
}
