#include "user.h"

const int mapX = 5; // ������ ������ ũ��
const int mapY = 5; // ������ ������ ũ��

// �߰� ��� �䱸���� 1. ������ ü�� 20�� ������ ���� ����
// int user_hp = 20; // �� �̻� �ʿ����� �ʾ� �ּ� ó��

// ����� ���� �Լ�
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(int map[][mapX], int user_x, int user_y);
bool checkGoal(int map[][mapX], int user_x, int user_y);
// �߰� ��� �䱸���� 4�� ���� �Լ� ����
bool CheckUser(User user);
// �߰� ��� �䱸���� 5�� ���� �Լ� ���� 
void checkState(int map[][mapX], int user_x, int user_y, User& user);

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

	// ���� ���� �� �ʱ� hp ����(20)
	User my_user;



	// ���� ���� 
	while (1) { // ����ڿ��� ��� �Է¹ޱ� ���� ���� ����


		// ������� �Է��� ������ ����
		string user_input = "";

		// ��ɾ �Է��� ���� �ȳ�
		cout << "��ɾ �Է��ϼ��� (��,��,��,��,����,����): ";
		cin >> user_input;

		if (user_input == "��") { // ����ڰ� �Է����� "��"�� �Է��ߴٸ�
			// ���� �� ĭ �ö󰡱�
			user_y -= 1; // ������� y ��ǥ�� -1��ŭ �����Ͽ� ��ġ�� ���� �ø�
			bool inMap = checkXY(user_x, mapX, user_y, mapY); // ������� ��ġ�� ���� ��ȿ���� bool ������ ������
			// ������ ����� �� ���� �޼��� ��� �� ��ġ ����
			if (inMap == false) {
				cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
				user_y += 1;
			}
			// �������� �Է��̶�� ��ġ �̵�
			else {
				cout << "���� �� ĭ �ö󰩴ϴ�." << endl;
				displayMap(map, user_x, user_y);
				// �߰� ��� �䱸���� 5. ������, ��, ������ ���� �� ���
				checkState(map, user_x, user_y, my_user);
				// �߰� ��� �䱸���� 2, 3. �̵��� ������ ü�� 1�� ����, HP ���
				// my_user�� HP 1��ŭ ����
				my_user.DecreaseHP(1);
				// ���� HP�� �޾ƿ� ���
				cout << "���� HP: " << my_user.GetHP() << " ";
			}
		}
		else if (user_input == "��") { // ����ڰ� �Է����� "��"�� �Է��ߴٸ�
			// �Ʒ��� �� ĭ ��������
			user_y += 1; // ������� y ��ǥ�� +1��ŭ �����Ͽ� ��ġ�� �Ʒ��� �ø�
			bool inMap = checkXY(user_x, mapX, user_y, mapY); // ������� ��ġ�� ���� ��ȿ���� bool ������ ������
			// ������ ����� �� ���� �޼��� ��� �� ��ġ ����
			if (inMap == false) {
				cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
				user_y -= 1;
			}
			// �������� �Է��̶�� ��ġ �̵�
			else {
				cout << "�Ʒ��� �� ĭ �������ϴ�." << endl;
				displayMap(map, user_x, user_y);
				// �߰� ��� �䱸���� 5. ������, ��, ������ ���� �� ���
				checkState(map, user_x, user_y, my_user);
				// �߰� ��� �䱸���� 2, 3. �̵��� ������ ü�� 1�� ����, HP ���
				// my_user�� HP 1��ŭ ����
				my_user.DecreaseHP(1);
				// ���� HP�� �޾ƿ� ���
				cout << "���� HP: " << my_user.GetHP() << " ";
			}
		}
		else if (user_input == "��") { // ����ڰ� �Է����� "��"�� �Է��ߴٸ�
			// �������� �̵��ϱ�
			user_x -= 1; // ������� x ��ǥ�� -1��ŭ �����Ͽ� ��ġ�� �������� �̵���
			bool inMap = checkXY(user_x, mapX, user_y, mapY); // ������� ��ġ�� ���� ��ȿ���� bool ������ ������
			// ������ ����� �� ���� �޼��� ��� �� ��ġ ����
			if (inMap == false) {
				cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
				user_x += 1;
			}
			// �������� �Է��̶�� ��ġ �̵�
			else {
				cout << "�������� �̵��մϴ�." << endl;
				displayMap(map, user_x, user_y);
				// �߰� ��� �䱸���� 5. ������, ��, ������ ���� �� ���
				checkState(map, user_x, user_y, my_user);
				// �߰� ��� �䱸���� 2, 3. �̵��� ������ ü�� 1�� ����, HP ���
				// my_user�� HP 1��ŭ ����
				my_user.DecreaseHP(1);
				// ���� HP�� �޾ƿ� ���
				cout << "���� HP: " << my_user.GetHP() << " ";
			}
		}
		else if (user_input == "��") { // ����ڰ� �Է����� "��"�� �Է��ߴٸ�
			// ���������� �̵��ϱ�
			user_x += 1; // ������� x ��ǥ�� +1��ŭ �����Ͽ� ��ġ�� ���������� �̵���
			bool inMap = checkXY(user_x, mapX, user_y, mapY); // ������� ��ġ�� ���� ��ȿ���� bool ������ ������
			// ������ ����� �� ���� �޼��� ��� �� ��ġ ����
			if (inMap == false) {
				cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
				user_x -= 1;
			}
			// �������� �Է��̶�� ��ġ �̵�
			else {
				cout << "���������� �̵��մϴ�." << endl;
				displayMap(map, user_x, user_y);
				// �߰� ��� �䱸���� 5. ������, ��, ������ ���� �� ���
				checkState(map, user_x, user_y, my_user);
				// �߰� ��� �䱸���� 1-2, 1-3. �̵��� ������ ü�� 1�� ����, HP ���
				// my_user�� HP 1��ŭ ����
				my_user.DecreaseHP(1);
				// ���� HP�� �޾ƿ� ���
				cout << "���� HP: " << my_user.GetHP() << " ";
			}
		}
		// ����ڰ� �Է����� "����"�� �Է��ߴٸ�
		else if (user_input == "����") {
			// ���� �����ֱ� �Լ� ȣ��
			displayMap(map, user_x, user_y);
		}
		// ����ڰ� �Է����� "����"�� �Է��ߴٸ�
		else if (user_input == "����") {
			// ���� �޼��� ���
			cout << "�����մϴ�.";
			break;
		}
		// ����ڰ� �������� �ʴ� ����� �Է��ߴٸ�
		else {
			// ���� �޼��� ��� �� ���Է� �޵��� continue
			cout << "�߸��� �Է��Դϴ�." << endl;
			continue;
		}

		// �߰� ��� �䱸���� 4. HP�� 0 ���ϰ� �Ǹ� "����"�� ����ϰ� ���� - �Լ� ��ȯ
		bool isAlive = CheckUser(my_user);

		if (isAlive == false) {
			cout << "HP�� 0 ���ϰ� �Ǿ����ϴ�. �����߽��ϴ�." << endl;
			cout << "������ �����մϴ�." << endl;
			return 0;
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
void checkState(int map[][mapX], int user_x, int user_y, User & user) {

	if (map[user_y][user_x] == 1) { // �������� ���� ��
		cout << "�������� �ֽ��ϴ�." << endl;
	}
	else if (map[user_y][user_x] == 2) { // ���� ���� ��
		cout << "���� �ֽ��ϴ�. HP�� 2 �پ��ϴ�." << endl;
		// my_user�� HP 2��ŭ ����
		user.DecreaseHP(2);
	}
	else if (map[user_y][user_x] == 3) { // ������ ���� ��
		cout << "������ �ֽ��ϴ�. HP�� 2 �þ�ϴ�." << endl;
		// my_user�� HP�� 2��ŭ ����
		user.IncreaseHP(2);
	}
}

// ������ HP ���¸� üũ�ϴ� �Լ�
bool CheckUser(User user) {

	if (user.GetHP() <= 0) return false;

	return true;
}
