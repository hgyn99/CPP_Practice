#include <iostream>

using namespace std;

int main() {

	int number; // int Ÿ�� ���� number�� �����Ѵ�.

	cout << "���ڸ� �Է��Ͻÿ�: ";
	cin >> number;
	// ���� number�� �Է¹޴´�.
	
	if (number == 0) cout << "zero" << endl; // ���� number�� 0�̶��, zero�� ����Ѵ�.
	else if (number == 1) cout << "one" << endl; // ���� number�� 1�̶��, one�� ����Ѵ�.
	else cout << "many" << endl; // ��� �ش���� ������, many�� ����Ѵ�.

	return 0;
}