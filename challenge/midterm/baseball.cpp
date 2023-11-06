#include <iostream>
#include <string>
using namespace std;

int randomNum; // ����� �ϴ� 3�ڸ����� ���� ���� ����
int firstNum; // ������ ù��° �ڸ���
int secondNum; // ������ �ι�° �ڸ���
int thirdNum; // ������ ����° �ڸ���

bool same = false; // ��� ���� �ٸ� ��� true�� ���� ����

int list[3]; // ������ �� �ڸ����� ���� �迭 list

// 3�ڸ��� ���ڰ� ��� �ٸ��� Ȯ���ϴ� �Լ� checkNumber
bool checkNumber(int num1, int num2, int num3) {

	same = false;

	// ���� �� �ڸ����� ��� ���� �ٸ��ٸ� same�� true�� �����Ѵ�.
	if ((num1 != num2) && (num1 != num3) && (num2 != num3)) {
		same = true;
	}

	// �ߺ��Ǵ� ���ڰ� �ִٸ� false ��ȯ, �ߺ��Ǵ� ���ڰ� ���ٸ� true ��ȯ
	return same;
}

int main() {

	while (1) {

		randomNum = rand() % 900 + 100; // ������ 3�ڸ��� ����

		// TODO 1: 3�ڸ� ������ �ڸ����� �����ϰ�, ��� ���� �ٸ��� üũ�ϴ� �ڵ��� �ۼ�
		
		// �������� ������ ������ �� �ڸ��� ����
		firstNum = randomNum / 100;
		secondNum = randomNum % 100 / 10;
		thirdNum = randomNum % 10;

		// �������� ������ ������ �� �ڸ����� �Ű������� checkNumber �Լ��� �����Ͽ� same ���� ��ȯ�޴´�.
		checkNumber(firstNum, secondNum, thirdNum);

		// �Լ��� ���� same ���� true�� �Ǿ��ٸ�(3�ڸ� ���ڰ� ��� �ٸ��ٸ�) ���� ���� ������ ���߰� �ݺ����� Ż���Ѵ�.
		if (same == true) {
			break;
		}

	}
	// ����ڰ� ������ ���߱� ���� �õ��� Ƚ��
	int turn = 0;
	while (1) {
		cout << turn + 1 << "��° �õ��Դϴ�. " << endl;

		int userNumber; // ����ڰ� �Է��� ���ڸ��� ���� ����
		int guessFirst; // ������ ������ ù��° �ڸ���
		int guessSecond; // ������ ������ �ι�° �ڸ���
		int guessThird; // ������ ������ ����° �ڸ���

		// ����ڿ��� ���ڸ� ���� �Է¹޴� �ڵ� ���
		while (1) {
			// ���Ŀ� ���߾� ����ڿ��� ���ڸ� �Է¹޴´�.
			cout << "���ڸ� ���� �Է����ּ���: ";
			cin >> userNumber;

			// TODO 1: 3�ڸ� ������ �ڸ����� �����ϰ�, ��� ���� �ٸ��� üũ�ϴ� �ڵ��� �ۼ�

			// ����ڿ��� �Է� ���� ������ �� �ڸ����� �����Ѵ�.
			guessFirst = userNumber / 100;
			guessSecond = userNumber % 100 / 10;
			guessThird = userNumber % 10;

			// ����ڿ��� �Է� ���� ���ڰ� 3�ڸ��� �ƴ϶�� ���� �޼����� ����ϰ� �Է��� �ٽ� �޴´�.
			if (to_string(userNumber).length() != 3) {
				cout << "�Էµ� ���ڰ� 3�ڸ� ���� �ƴմϴ�. �ٽ� �Է��ϼ���." << endl;
				continue;
			}

			// ����ڿ��� �Է� ���� ������ �� �ڸ����� �Ű������� checkNumber �Լ��� �����Ͽ� same ���� ��ȯ�޴´�.
			checkNumber(guessFirst, guessSecond, guessThird);

			// �Լ��� ���� same ���� true�� �Ǿ��ٸ�(3�ڸ� ���ڰ� ��� �ٸ��ٸ�) ���� ���� ������ ���߰� �ݺ����� Ż���Ѵ�.
			if (same == true) {
				break;
			}
			// same ���� true�� ���� �ʾҴٸ� �ߺ��� ���ڰ� �ִ� ���̹Ƿ� ���� �޼����� ����ϰ� �ݺ������� ���ư���.
			cout << "�Է��� ���ڿ� �ߺ��� ���ڰ� �ֽ��ϴ�. �ٽ� �Է��ϼ���" << endl;
		}

		int strike = 0; // ��Ʈ����ũ ������ �����ϴ� ����
		int ball = 0; // �� ������ �����ϴ� ����

		// TODO 2: ����� ������ ������ �ڸ����� ���ڸ� ���ϸ� ��Ʈ�� �ֱ� ���� �ڵ��� �ۼ�

		// ������ϴ� ������ �ڸ����� list �迭�� �ϳ��� �����Ѵ�.
		list[0] = firstNum;
		list[1] = secondNum;
		list[2] = thirdNum;

		// ������ �� �ڸ����� �Է� ���� ���� �� �ڸ����� ��ġ�Ѵٸ� ��Ʈ����ũ�̹Ƿ� �� ��� strike ���� ������Ų��.
		if (firstNum == guessFirst) strike++;
		if (secondNum == guessSecond) strike++;
		if (thirdNum == guessThird) strike++;

		// �Է� ���� ���� �� �ڸ����� ������ �� �ڸ����� ���� ���� �����Ѵٸ�, ball�� �ش��ϹǷ� ball ���� ������Ų��. (strike�� �ߺ� ���� ���ɼ� ����)
		for (auto elem : list) {
			if (elem == guessFirst || elem == guessSecond || elem == guessThird) {
				ball++;
			}
		}
		// strike�� �ߺ� üũ�� ball�� ������ŭ ���� ���ش�.
		ball -= strike;

		// ����� ���Ŀ� ���߾� ����Ѵ�.
		cout << userNumber << "�� ��� : " << strike << " ��Ʈ����ũ, " << ball << "�� �Դϴ�." << endl;

		// ��Ʈ����ũ�� 3���� �ȴٸ� ������ ���� ���̹Ƿ� �ݺ��� Ż���Ͽ� ���α׷��� �����Ų��.
		if (strike == 3) {
			cout << "������ ������ϴ�. �����մϴ�.";
			break;
		}

		// ��Ʈ����ũ�� 3���� ���� ���ߴٸ� ���� ������ ������ ���� ���̹Ƿ� ������ ���߱� ���� �õ��� ����ϱ� ���� turn�� ������Ų��.
		turn += 1;
	}

	return 0;
}
