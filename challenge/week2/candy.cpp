#include <iostream>

using namespace std;

int main() {

	int money, price; // int Ÿ�� ���� money, price�� �����Ѵ�.
	cout << "���� ������ �ִ� ��: ";
	cin >> money;
	// ���� ������ �ִ� �� money�� �Է¹޴´�.
	cout << "ĵ���� ����: ";
	cin >> price;
	// ĵ���� ���� price�� �Է¹޴´�.
	cout << "�ִ�� �� �� �ִ� ĵ�� = " << money / price << endl;
	// �ִ�� �� �� �ִ� ĵ��(��)�� ����Ѵ�.
	cout << "ĵ�� ���� �� ���� �� = " << money % price << endl;
	// ĵ�� ���� �� ���� ��(������)�� ����Ѵ�.
	return 0; // 0�� ��ȯ�ϸ� ���α׷��� �����Ѵ�.
}