#include <iostream>

using namespace std;

int main() {

	int a, b, c, smallest; // int Ÿ�� ���� a, b, c, smallest�� �����Ѵ�.

	cout << "3���� ������ �Է��Ͻÿ�: ";
	cin >> a >> b >> c;
	// 3���� ������ �Է��϶�� �޼����� ����� �� a, b, c 3���� ������ �Է¹޴´�.

	if (a < b && a < c) // ���� a�� b���� �۰� a�� c���� �۴ٸ�
		smallest = a; // ���� ���� ������ smallest�� a�� �ȴ�.
	else if (b < a && b < c) // ���� b�� a���� �۰� b�� c���� �۴ٸ�
		smallest = b; // smallest�� b�� �ȴ�.
	else // �� ���ǽ��� ��� �ƴ϶��
		smallest = c; // smallest�� c�� �ȴ�.

	cout << "���� ���� ������ " << smallest << endl; // ���� ���� ������ smallest�� ����Ѵ�.

	return 0; // 0�� ��ȯ�Ͽ� ���α׷��� �����Ѵ�.
}