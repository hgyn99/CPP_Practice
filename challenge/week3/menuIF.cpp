#include <iostream>

using namespace std;

int main() {

	int choice; // int Ÿ�� ���� choice�� �����Ѵ�.

	cout << "1. ���� ����" << endl;
	cout << "2. ���� ���� �ݱ�" << endl;
	cout << "3. ����" << endl;
	// �Է� ���ڿ� ���� ��� �ȳ�
	cin >> choice; // ���� ��ȣ�� choice�� �Է� �޴´�.

	if (choice == 1) cout << "���� ������ �����߽��ϴ�." << endl;
	// ���� choice�� 1�̶��, ���� ������ �����ߴٴ� �޼����� ����Ѵ�.
	else if (choice == 2) cout << "���� �ݱ⸦ �����߽��ϴ�." << endl; 
	// ���� choice�� 2���, ���� �ݱ⸦ �����ߴٴ� �޼����� ����Ѵ�.
	else if (choice == 3) cout << "���α׷��� �����մϴ�." << endl; 
	// ���� choice�� 3�̶��, ���α׷��� �����Ѵٴ� �޽����� ����Ѵ�.
	else cout << "�߸��� �����Դϴ�." << endl; 
	// ��� �ƴ϶��, �߸��� �����̶�� �޽����� ����Ѵ�.

	return 0;
}