#include <iostream> // ������� iostream ����

using namespace std; // �̸� ���� ����

int main() { // main �Լ��� �����Ѵ�.

	int two = 2; // int�� ���� two�� �����ϰ� ���� 2�� �����Ѵ�.
	int eight = 8; // int�� ���� eight�� �����ϰ� ���� 8�� �����Ѵ�.
	int sum1 = 2; // int�� ���� sum1�� �����ϰ� ���� 2�� �����Ѵ�.
	int sum2 = 8; // int�� ���� sum2�� �����ϰ� ���� 8�� �����Ѵ�.

	sum1 += two; // sum1�� two�� ���� ���� sum1�� �����Ѵ�.
	sum2 /= eight; // sum2�� 8�� ���� ���� sum2�� �����Ѵ�.

	cout << "sum1 = " << sum1 << endl; // ������ ���߾� sum1 ���� ����Ѵ�.
	cout << "sum2 = " << sum2 << endl; // ������ ���߾� sum2 ���� ����Ѵ�.

	return 0; // 0�� ��ȯ�Ͽ� ���α׷��� �����Ѵ�.
}