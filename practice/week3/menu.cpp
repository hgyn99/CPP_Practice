#include <iostream>

using namespace std;

int main() {

	int choice; // int Ÿ�� ���� choice�� �����Ѵ�.

	cout << "1. ���� ����" << endl;
	cout << "2. ���� ���� �ݱ�" << endl;
	cout << "3. ����" << endl;
	// �Է� ���ڿ� ���� ��� �ȳ�
	cin >> choice; // ���� ��ȣ�� choice�� �Է� �޴´�.

	switch (choice) {
		case 1: // 1�� �Է����� ���
			cout << "���� ������ �����߽��ϴ�." << endl;
			break;
			// ���� ������ �����ߴٴ� �޼����� ����ϰ� switch ���� �������´�.
		case 2: // 2�� �Է����� ���
			cout << "���� �ݱ⸦ �����߽��ϴ�." << endl;
			break;
			// ���� �ݱ⸦ �����ߴٴ� �޼����� ����ϰ� switch ���� �������´�.
		case 3: // 3�� �Է����� ���
			cout << "���α׷��� �����մϴ�." << endl;
			break;
			// ���α׷��� �����Ѵٴ� �޼����� ����ϰ� switch ���� �������´�.
		default: // �� ���� ���
			cout << "�߸��� �����Դϴ�." << endl;
			break;
			// �߸��� �����̶�� �޼����� ����ϰ� switch ���� �������´�.
	}

	return 0;
}