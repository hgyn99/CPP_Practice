#include <iostream> // ������� iostream ����

using namespace std; // �̸� ���� ����

int main() { // main �Լ��� �����Ѵ�.

	int one = 1; // int�� ���� one�� �����ϰ� ���� 1�� �����Ѵ�.
	int two = 2; // int�� ���� two�� �����ϰ� ���� 2�� �����Ѵ�.
	int three = 3; // int�� ���� three�� �����ϰ� ���� 3�� �����Ѵ�.
	int four = 4; // int�� ���� four�� �����ϰ� ���� 4�� �����Ѵ�.

	cout << "1 + 3 = " << one + three << endl; // ���Ŀ� ���߾� ��� ���� ����Ѵ�.
	cout << "4 - 2 = " << four - two << endl; // ���Ŀ� ���߾� ��� ���� ����Ѵ�.
	cout << "2 * 3 = " << two * three << endl; // ���Ŀ� ���߾� ��� ���� ����Ѵ�.
	cout << "4 / 2 = " << four / two << endl; // ���Ŀ� ���߾� ��� ���� ����Ѵ�.

	cout << "2 + 3 * 4 = " << two + three * four << endl; // ���Ŀ� ���߾� ��� ���� ����Ѵ�.
	cout << "2 + 3 * 4 = " << two + three * four << endl; // ���Ŀ� ���߾� ��� ���� ����Ѵ�.
	cout << "1 + 4 / 2 = " << one + four / two << endl; // ���Ŀ� ���߾� ��� ���� ����Ѵ�.

	return 0; // 0�� ��ȯ�Ͽ� ���α׷��� �����Ѵ�.
}