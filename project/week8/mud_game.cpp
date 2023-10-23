#include <iostream>
#include <string>
using namespace std;

const int mapX = 5;
const int mapY = 5;

// �߰� ��� �䱸���� 1. ������ ü�� 20�� ������ ���� ����
int user_hp = 20;

// ����� ���� �Լ�
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(int map[][mapX], int user_x, int user_y);
bool checkGoal(int map[][mapX], int user_x, int user_y);
// �߰� ��� �䱸���� 5�� ���� �Լ� ����
void checkState(int map[][mapX], int user_x, int user_y);

// ����  �Լ�
int main() {
	// 0�� �� ����, 1�� ������, 2�� ��, 3�� ����, 4�� ������
	int map[mapY][mapX] = { {0, 1, 2, 0, 4},
					{1, 0, 0, 2, 0},
					{0, 0, 0, 0, 0},
					{0, 2, 3, 0, 0},
					{3, 0, 0, 0, 2} };


	// ������ ��ġ�� ������ ����
	int user_x = 0; // ���� ��ȣ
	int user_y = 0; // ���� ��ȣ

	// ���� ���� 
	while (1) { // ����ڿ��� ��� �Է¹ޱ� ���� ���� ����


		// ������� �Է��� ������ ����
		string user_input = "";

		cout << "��ɾ �Է��ϼ��� (��,��,��,��,����,����): ";
		cin >> user_input;

		if (user_input == "��") {
			// ���� �� ĭ �ö󰡱�
			user_y -= 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
				user_y += 1;
			}
			else {
				cout << "���� �� ĭ �ö󰩴ϴ�." << endl;
				displayMap(map, user_x, user_y);
				// �߰� ��� �䱸���� 5. ������, ��, ������ ���� �� ���
				checkState(map, user_x, user_y);
				// �߰� ��� �䱸���� 2, 3. �̵��� ������ ü�� 1�� ����, HP ���
				user_hp--;
				cout << "���� HP: " << user_hp << " ";
			}
		}
		else if (user_input == "��") {
			// �Ʒ��� �� ĭ ��������
			user_y += 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
				user_y -= 1;
			}
			else {
				cout << "�Ʒ��� �� ĭ �������ϴ�." << endl;
				displayMap(map, user_x, user_y);
				// �߰� ��� �䱸���� 5. ������, ��, ������ ���� �� ���
				checkState(map, user_x, user_y);
				// �߰� ��� �䱸���� 2, 3. �̵��� ������ ü�� 1�� ����, HP ���
				user_hp--;
				cout << "���� HP: " << user_hp << " ";
			}
		}
		else if (user_input == "��") {
			// �������� �̵��ϱ�
			user_x -= 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);

			if (inMap == false) {
				cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
				user_x += 1;
			}
			else {
				cout << "�������� �̵��մϴ�." << endl;
				displayMap(map, user_x, user_y);
				// �߰� ��� �䱸���� 5. ������, ��, ������ ���� �� ���
				checkState(map, user_x, user_y);
				// �߰� ��� �䱸���� 2, 3. �̵��� ������ ü�� 1�� ����, HP ���
				user_hp--;
				cout << "���� HP: " << user_hp << " ";
			}
		}
		else if (user_input == "��") {
			// ���������� �̵��ϱ�
			user_x += 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
				user_x -= 1;
			}
			else {
				cout << "���������� �̵��մϴ�." << endl;
				displayMap(map, user_x, user_y);
				// �߰� ��� �䱸���� 5. ������, ��, ������ ���� �� ���
				checkState(map, user_x, user_y);
				// �߰� ��� �䱸���� 1-2, 1-3. �̵��� ������ ü�� 1�� ����, HP ���
				user_hp--;
				cout << "���� HP: " << user_hp << " ";
			}
		}
		else if (user_input == "����") {
			// ���� �����ֱ� �Լ� ȣ��
			displayMap(map, user_x, user_y);
		}
		else if (user_input == "����") {
			cout << "�����մϴ�.";
			break;
		}
		else {
			cout << "�߸��� �Է��Դϴ�." << endl;
			continue;
		}

		// �߰� ��� �䱸���� 4. HP�� 0 ���ϰ� �Ǹ� "����"�� ����ϰ� ����
		if (user_hp <= 0) {
			cout << "HP�� 0 ���ϰ� �Ǿ����ϴ�. �����߽��ϴ�." << endl;
			cout << "������ �����մϴ�." << endl;
		}

		// �������� �����ߴ��� üũ
		bool finish = checkGoal(map, user_x, user_y);
		if (finish == true) {
			cout << "�������� �����߽��ϴ�! �����մϴ�!" << endl;
			cout << "������ �����մϴ�." << endl;
			break;
		}

	}
	return 0;
}


// ������ ����� ��ġ ����ϴ� �Լ�
void displayMap(int map[][mapX], int user_x, int user_y) {
	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			if (i == user_y && j == user_x) {
				cout << " USER |"; // �� �� 1ĭ ����
			}
			else {
				int posState = map[i][j];
				switch (posState) {
				case 0:
					cout << "      |"; // 6ĭ ����
					break;
				case 1:
					cout << "������|";
					break;
				case 2:
					cout << "  ��  |"; // �� �� 2ĭ ����
					break;
				case 3:
					cout << " ���� |"; // �� �� 1ĭ ����
					break;
				case 4:
					cout << "������|";
					break;
				}
			}
		}
		cout << endl;
		cout << " -------------------------------- " << endl;
	}
}

// �̵��Ϸ��� ���� ��ȿ�� ��ǥ���� üũ�ϴ� �Լ�
bool checkXY(int user_x, int mapX, int user_y, int mapY) {
	bool checkFlag = false;
	if (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY) {
		checkFlag = true;
	}
	return checkFlag;
}

// ������ ��ġ�� ���������� üũ�ϴ� �Լ�
bool checkGoal(int map[][mapX], int user_x, int user_y) {
	// ������ �����ϸ�
	if (map[user_y][user_x] == 4) {
		return true;
	}
	return false;
}

// �߰� ��� �䱸���� 5. ������, ��, ������ ���� �� ����ϴ� �Լ�
void checkState(int map[][mapX], int user_x, int user_y) {
	
	if (map[user_y][user_x] == 1) { // �������� ���� ��
		cout << "�������� �ֽ��ϴ�." << endl;
	}
	else if (map[user_y][user_x] == 2) { // ���� ���� ��
		cout << "���� �ֽ��ϴ�. HP�� 2 �پ��ϴ�." << endl;
		user_hp -= 2;
	}
	else if (map[user_y][user_x] == 3) { // ������ ���� ��
		cout << "�������� �ֽ��ϴ�. HP�� 2 �þ�ϴ�." << endl;
		user_hp += 2;
	}
}