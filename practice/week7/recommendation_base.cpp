#include <iostream>

using namespace std;

int main() {

	const int NUM_USERS = 3; // ������ ���� ����� ����
	const int NUM_ITEMS = 3; // �׸��� ���� ����� ����
	int userPreferences[NUM_USERS][NUM_ITEMS]; // ������ ��ȣ���� ������ 2���� �迭 ����

	// ����ڿ� �׸� ���� ��ȣ���� �Է� �޾� 2���� �迭 �ʱ�ȭ
	for (int i = 0; i < NUM_USERS; ++i) { // �ݺ����� ���� ����ŭ �ݺ��Ѵ�.
		// ������ ���߾� ����ڿ��� �Է��� �ȳ��Ѵ�.
		cout << "����� " << (i + 1) << "�� ��ȣ���� �Է��ϼ��� (";
		cout << NUM_ITEMS << "���� �׸� ����): ";

		// �� �׸� ���� ������ ��ȣ���� �ϳ��� �Է� �޴´�.
		for (int j = 0; j < NUM_ITEMS; ++j) {
			cin >> userPreferences[i][j];
		}
	}

	// �� ����ڿ� ���� ��õ �׸� ã��
	for (int i = 0; i < NUM_USERS; ++i) { // �ݺ����� ���� ����ŭ �ݺ��Ѵ�.
		int maxPreferenceIndex = 0; // ������ �ִ� ��ȣ���� ���� �ε����� ������ ���� ����
		for (int j = 1; j < NUM_ITEMS; ++j) { // �ݺ����� �׸��� �� ��ŭ �ݺ��Ѵ�.
			// ���� �ε��� i�� ���� ������ �ִ� ��ȣ���� ������ ��� �ִ� ��ȣ������ ũ�ٸ�
			// ������ �ִ� ��ȣ���� j ������ ������Ʈ�Ѵ�.
			if (userPreferences[i][j] > userPreferences[i][maxPreferenceIndex]) {
				maxPreferenceIndex = j;
			}
		}

		// ����ڿ��� ��õ�ϴ� �׸� ���
		cout << "����� " << (i + 1) << "���� ��õ�ϴ� �׸�: ";
		cout << (maxPreferenceIndex + 1) << endl;
	}

	return 0;
}