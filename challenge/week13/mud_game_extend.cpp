#include <iostream>
#include <string>

using namespace std;

// User Ŭ����
class User
{
private:
	// ��� ����
	int hp;
public:
	// ��� �Լ�
	void DecreaseHP(int dec_hp);
	void IncreaseHP(int inc_hp);
	int GetHP();
	virtual void doAttack() {
		cout << "�����մϴ�" << endl;
	}
	// ������
	User(int first_hp = 20) {
		hp = first_hp;
	}

};

class Magician : public User {
public:
	void doAttack() override {
		cout << "���� ���" << endl;
	}
};

class Warrior : public User {
public:
	void doAttack() override {
		cout << "���� ���" << endl;
	}
};

// Ŭ���� �ܺ� �Լ� ����
void User::DecreaseHP(int dec_hp) {
	hp -= dec_hp;
}
void User::IncreaseHP(int inc_hp) {
	hp += inc_hp;
}
int User::GetHP() {
	return hp;
}

const int mapX = 5; // ������ ������ ũ��
const int mapY = 5; // ������ ������ ũ��

// �߰� ��� �䱸���� 1. ������ ü�� 20�� ������ ���� ����
// int user_hp = 20; // �� �̻� �ʿ����� �ʾ� �ּ� ó��

// ����� ���� �Լ�
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(int map[][mapX], int magician_x, int magician_y, int warrior_x, int warrior_y);
bool checkGoal(int map[][mapX], int user_x, int user_y, User& user);
// �߰� ��� �䱸���� 4�� ���� �Լ� ����
bool CheckUser(User user);
// �߰� ��� �䱸���� 5�� ���� �Լ� ���� 
void checkState(int map[][mapX], int user_x, int user_y, User& user);
void handleUserInput(int map[][mapX], string user_input, int& user_x, int& user_y, User& my_user, string playerType);

// Magician�� Warrior ��ü ���� �� �ʱ� hp ����(20)
Magician magician_user;
Warrior warrior_user;

// �� �÷��̾��� ��ġ �ʱ�ȭ
int magician_x = 0, magician_y = 0;
int warrior_x = 0, warrior_y = 0;

// ���� ���� ��Ÿ���� ����
bool isMagicianTurn = true;

// ����  �Լ�
int main() {
	// 0�� �� ����, 1�� ������, 2�� ��, 3�� ����, 4�� ������
	int map[mapY][mapX] = { {0, 1, 2, 0, 4},
					{1, 0, 0, 2, 0},
					{0, 0, 0, 0, 0},
					{0, 2, 3, 0, 0},
					{3, 0, 0, 0, 2} };

	// ���� ���� 
	while (1) { // ����ڿ��� ��� �Է¹ޱ� ���� ���� ����

		// ������� ���� �˸�
		if (isMagicianTurn) {
			cout << "Magician�� ���Դϴ�." << endl;
		}
		else {
			cout << "Warrior�� ���Դϴ�." << endl;
		}


		// ������� �Է��� ������ ����
		string user_input = "";

		// ��ɾ �Է��� ���� �ȳ�
		cout << "��ɾ �Է��ϼ��� (��,��,��,��,����,����): ";
		cin >> user_input;
		// ����ڰ� �Է����� "����"�� �Է��ߴٸ�
		if (user_input == "����") {
			// ���� �޼��� ���
			cout << "�����մϴ�.";
			return 0;
		}
		// ����ڿ� ���� ��ɾ� ó��
		if (isMagicianTurn) {
			handleUserInput(map, user_input, magician_x, magician_y, magician_user, "Magician");
		}
		else {
			handleUserInput(map, user_input, warrior_x, warrior_y, warrior_user, "Warrior");
		}


		// �� �÷��̾��� ���� Ȯ�� �Լ�
		bool isAlive;
		if (isMagicianTurn) {
			isAlive = CheckUser(magician_user);
		}
		else {
			isAlive = CheckUser(warrior_user);
		}

		if (isAlive == false) {
			cout << "HP�� 0 ���ϰ� �Ǿ����ϴ�. �����߽��ϴ�." << endl;
			cout << "������ �����մϴ�." << endl;
			return 0;
		}

		// �������� �����ߴ��� üũ
		bool finish;

		if (isMagicianTurn) {
			finish = checkGoal(map, magician_x, magician_y, magician_user);
			if (finish == true) {
				cout << "Magician �÷��̾ �������� �����߽��ϴ�! �����մϴ�!" << endl;
				cout << "������ �����մϴ�." << endl;
				break;
			}
		}
		else {
			finish = checkGoal(map, warrior_x, warrior_y, warrior_user);
			if (finish == true) {
				cout << "Warrior �÷��̾ �������� �����߽��ϴ�! �����մϴ�!" << endl;
				cout << "������ �����մϴ�." << endl;
				break;
			}
		}


		// �� ����
		isMagicianTurn = !isMagicianTurn;
	}
	return 0;
}

void displayMap(int map[][mapX], int magician_x, int magician_y, int warrior_x, int warrior_y) {
	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			// Magician ��ġ Ȯ�� �� ���
			if (i == magician_y && j == magician_x) {
				cout << "  M   |";
			}
			// Warrior ��ġ Ȯ�� �� ���
			else if (i == warrior_y && j == warrior_x) {
				cout << "  W   |";
			}
			// �� �� ���� ��� ���
			else {
				int posState = map[i][j];
				switch (posState) {
				case 0:
					cout << "      |";
					break;
				case 1:
					cout << "������|";
					break;
				case 2:
					cout << "  ��  |";
					break;
				case 3:
					cout << " ���� |";
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
bool checkGoal(int map[][mapX], int user_x, int user_y, User& user) {
	// ������ �����ϸ�
	if (map[user_y][user_x] == 4) {
		return true;
	}
	return false;
}

// �߰� ��� �䱸���� 5. ������, ��, ������ ���� �� ����ϴ� �Լ�
void checkState(int map[][mapX], int user_x, int user_y, User& user) {

	if (map[user_y][user_x] == 1) { // �������� ���� ��
		cout << "�������� �ֽ��ϴ�." << endl;
	}
	else if (map[user_y][user_x] == 2) { // ���� ���� ��
		cout << "���� �ֽ��ϴ�. HP�� 2 �پ��ϴ�." << endl;
		// my_user�� HP 2��ŭ ����
		user.DecreaseHP(2);
		user.doAttack();
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

void handleUserInput(int map[][mapX], string user_input, int& user_x, int& user_y, User& my_user, string playerType) {
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
			// ���� �����ֱ�
			displayMap(map, magician_x, magician_y, warrior_x, warrior_y);
			// �߰� ��� �䱸���� 5. ������, ��, ������ ���� �� ���
			checkState(map, user_x, user_y, my_user);
			// �߰� ��� �䱸���� 2, 3. �̵��� ������ ü�� 1�� ����, HP ���
			// my_user�� HP 1��ŭ ����
			my_user.DecreaseHP(1);
			// ���� HP�� �޾ƿ� ���
			cout << "���� HP: " << my_user.GetHP() << endl << endl;
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
			// ���� �����ֱ�
			displayMap(map, magician_x, magician_y, warrior_x, warrior_y);
			// �߰� ��� �䱸���� 5. ������, ��, ������ ���� �� ���
			checkState(map, user_x, user_y, my_user);
			// �߰� ��� �䱸���� 2, 3. �̵��� ������ ü�� 1�� ����, HP ���
			// my_user�� HP 1��ŭ ����
			my_user.DecreaseHP(1);
			// ���� HP�� �޾ƿ� ���
			cout << "���� HP: " << my_user.GetHP() << endl << endl;
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
			// ���� �����ֱ�
			displayMap(map, magician_x, magician_y, warrior_x, warrior_y);
			// �߰� ��� �䱸���� 5. ������, ��, ������ ���� �� ���
			checkState(map, user_x, user_y, my_user);
			// �߰� ��� �䱸���� 2, 3. �̵��� ������ ü�� 1�� ����, HP ���
			// my_user�� HP 1��ŭ ����
			my_user.DecreaseHP(1);
			// ���� HP�� �޾ƿ� ���
			cout << "���� HP: " << my_user.GetHP() << endl << endl;
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
			// ���� �����ֱ�
			displayMap(map, magician_x, magician_y, warrior_x, warrior_y);
			// �߰� ��� �䱸���� 5. ������, ��, ������ ���� �� ���
			checkState(map, user_x, user_y, my_user);
			// �߰� ��� �䱸���� 1-2, 1-3. �̵��� ������ ü�� 1�� ����, HP ���
			// my_user�� HP 1��ŭ ����
			my_user.DecreaseHP(1);
			// ���� HP�� �޾ƿ� ���
			cout << "���� HP: " << my_user.GetHP() << endl << endl;
		}
	}
	// ����ڰ� �Է����� "����"�� �Է��ߴٸ�
	else if (user_input == "����") {
		// ���� �����ֱ� �Լ� ȣ��
		displayMap(map, magician_x, magician_y, warrior_x, warrior_y);
		// �ڵ� �� ������ �����ϱ� ���� �� ������ �ѹ� �� ��
		isMagicianTurn = !isMagicianTurn;
	}
	// ����ڰ� �������� �ʴ� ����� �Է��ߴٸ�
	else {
		// ���� �޼��� ��� �� ���Է� �޵��� �Ѵ�.
		cout << "�߸��� �Է��Դϴ�." << endl;
		// �ڵ� �� ������ �����ϱ� ���� �� ������ �ѹ� �� ��
		isMagicianTurn = !isMagicianTurn;
		return;
	}
}