#include <iostream>
using namespace std;

// ������ �����ϴ� �� �ʿ��� ���� ���� -> �Լ������� ����� ���� ��� ���� ����ȭ

const int numCell = 3; // �������� ���� ���� ����
int k = 0; // ���� �������� üũ�ϱ� ���� ����
char currentUser = 'X'; // ���� ������ ���� �����ϱ� ���� ����
char board[numCell][numCell]{}; // �������� ��Ÿ���� 2���� �迭
int x, y = 0; // ����ڿ��� xy��ǥ���� �Է¹ޱ� ���� ����
bool isWin = false; // �¸� ���θ� Ȯ���ϴ� ���� isWin

// �Է��� ��ǥ�� ��ȿ���� ��ȿ���� üũ�ϴ� �Լ�
bool isValid(int x, int y) {
	if (x >= numCell || y >= numCell) { // ��ǥ ������ �����
		cout << x << "," << y << ": x�� y���� �ϳ��� ĭ�� ����ϴ�. " << endl;
		return false;
	}
	if (board[x][y] != ' ') { // ��ǥ������ �Է°��� �ߺ��ɶ�
		cout << x << "," << y << ": �̹� ���� ���ֽ��ϴ�. " << endl;
		return false;
	}
	return true;
}

// �Ű������� ���� user�� �¸� ������ �����ߴ��� Ȯ���ϴ� �Լ�
bool checkWin(char user) {

	// ���� �� �¸�����: countHor�� ���� �������� ũ���� numCell�� �������� �ش� user�� ���� ���� ��� ���� ���̹Ƿ� �¸� �޼��� ��� �� isWin�� true�� ��ȯ�Ѵ�.
	for (int i = 0; i < numCell; i++) {
		int countHor = 0;
		for (int j = 0; j < numCell; j++) {
			if (board[i][j] == user) { // �ش� ������ ���� ���� ������ Ȯ���ϴ� ����
				countHor++;
			}
		}
		if (countHor == numCell) {
			isWin = true;
			cout << "���ο� ��� ���� �������ϴ�!!" << endl;
			return isWin;
		}
	}

	// ���� �� �¸�����: countVer�� ���� �������� ũ���� numCell�� �������� �ش� user�� ���� ���� ��� ���� ���̹Ƿ� �¸� �޼��� ��� �� isWin�� true�� ��ȯ�Ѵ�.
	for (int i = 0; i < numCell; i++) {
		int countVer = 0;
		for (int j = 0; j < numCell; j++) {
			if (board[j][i] == user) { // �ش� ������ ���� ���� ������ Ȯ���ϴ� ����
				countVer++;
			}
		}
		if (countVer == numCell) {
			isWin = true;
			cout << "���ο� ��� ���� �������ϴ�!!" << endl;
			return isWin;
		}
	}

	// �밢�� �� �¸�����1 (���� ������ ������ �Ʒ���): countDiag1�� ���� �������� ũ���� numCell�� �������� �ش� user�� �밢�� ���� ��� ���� ���̹Ƿ� �¸� �޼��� ��� �� isWin�� true�� ��ȯ�Ѵ�.
	int countDiag1 = 0;
	for (int i = 0; i < numCell; i++) {
		if (board[i][i] == user) { // �ش� ������ �밢��(���� ������ ������ �Ʒ���) ���� ������ Ȯ���ϴ� ����
			countDiag1++;
		}
	}
	if (countDiag1 == numCell) {
		isWin = true;
		cout << "���� ������ ������ �Ʒ� �밢������ ��� ���� �������ϴ�!" << endl;
		return isWin;
	}

	// �밢�� �� �¸�����2 (������ ������ ���� �Ʒ���): countDiag2�� ���� �������� ũ���� numCell�� �������� �ش� user�� �밢�� ���� ��� ���� ���̹Ƿ� �¸� �޼��� ��� �� isWin�� true�� ��ȯ�Ѵ�.
	int countDiag2 = 0;
	for (int i = 0; i < numCell; i++) {
		if (board[i][numCell - 1 - i] == user) { // �ش� ������ �밢��(������ ������ ���� �Ʒ���) ���� ������ Ȯ���ϴ� ����
			countDiag2++;
		}
	}
	if (countDiag2 == numCell) {
		isWin = true;
		cout << "������ ������ ���� �Ʒ� �밢������ ��� ���� �������ϴ�!" << endl;
		return isWin;
	}

	return isWin;
}


int main() {

	// ������ �ʱ�ȭ
	for (int i = 0; i < numCell; i++) {
		for (int j = 0; j < numCell; j++) {
			board[i][j] = ' ';
		}
	}

	// ������ ���� �ݺ�
	while (true) {
		// 1. ���� �������� ���
		// TODO 1.1: 3�ο� �������� ���� - �Ϸ�
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
		cout << k % 3 + 1 << "�� ����(" << currentUser << ")�� �����Դϴ�. -> ";

		// 2. ��ǥ �Է� �ޱ�
		cout << "(x, y) ��ǥ�� �Է��ϼ���: ";
		int x, y;
		cin >> x >> y;

		// 3. �Է¹��� ��ǥ�� ��ȿ�� üũ
		// TODO FUNC 1: isValid �Լ� ���� �� ȣ�� - �Ϸ�

		// x, y ��ǥ�� ���� isValid �Լ��� ������ ��ȯ ���� validResult�� �����Ѵ�.
		bool validResult = isValid(x, y);
		// ���� isValid �Լ��� ��ȯ ���� false���(��ȿ�� ��ǥ�� �ƴ϶��)
		if (validResult == false) {
			continue; // �ٽ� �Է��� �޵��� �ݺ������� ���ư���.
		}


		// 4. �Է¹��� ��ǥ�� ���� ������ �� ����
		board[x][y] = currentUser;

		// 5. ���� ���� �� ���
		// TODO 1.2: numCell ���ڿ� ���� ������ ��� - �Ϸ�

		// numCell�� ���ڿ� �°Բ� ���Ŀ� ���߾� �������� ���
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

		// TODO FUNC2: 6.1���� 6.2���� checkWin �Լ� ���� �� ȣ�� - �Ϸ�
		// 6.1. ����/���� �� üũ�ϱ�

		// ���� ������ ����, ����, �밢��1, �밢��2 �¸� ������ �����ϴ��� Ȯ���ϴ� �Լ� checkWin�� �����Ѵ�.
		checkWin(currentUser);

		// 6.2. �밢���� üũ�ϱ�
		// TODO 1.3: numCell�� ���� �밢�� ���� üũ �ڵ�� Ȯ�� - �Ϸ�
		// HINT: for ��

		// �� �Լ����� �밢�� ���Ǳ��� �˻��Ͽ���.

		// �¸��ڰ� �����Ǿ����� �ش� �÷��̾ ����ϰ� ������ �����Ѵ�.
		if (isWin == true) {
			cout << k % 3 + 1 << "�� ����(" << currentUser << ")�� �¸��Դϴ�!" << endl;
			break;
		}

		// 7. ��� ĭ �� á���� üũ�ϱ�
		int checked = 0;
		for (int i = 0; i < numCell; i++) {
			for (int j = 0; j < numCell; j++) {
				if (board[i][j] == ' ') {
					checked++;
				}
			}
		}

		// ��� ĭ�� �� á�ٸ� �ݺ����� Ż���Ͽ� ���α׷��� �����Ѵ�.
		if (checked == 0) {
			cout << "��� ĭ�� �� á���ϴ�.  �����մϴ�. " << endl;
			break;
		}

		k++;
	}

	return 0;
}