#include <iostream>

using namespace std;

int main() {

	int userInput; // ������� �Է°� userInput�� �����Ѵ�.

	cout << "������ 10�� �Է��ϼ��� (0�� �Է��ϸ� ����):";
	// ������ �Է��� ���� �ȳ��ϴ� �޼����� ����Ѵ�.

	for (int i = 0; i < 10; i++) { // �ݺ����� 10�� �ݺ��Ѵ�.
		cin >> userInput; // userInput�� �Է¹޴´�.
		if (userInput == 0) break; // ���� �Է� ���� 0�̶�� �ݺ����� Ż���Ѵ�.
		cout << "�Է°�: " << userInput << " Ƚ�� :" << i << endl;
		// ������� �Է� ���� �Է� Ƚ���� ����Ѵ�.
	}

	cout << "���� �Ǿ����ϴ�"; // ���α׷� ���� �ȳ� �޼����� ����Ѵ�.


	return 0;
}