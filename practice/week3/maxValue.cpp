#include <iostream>

using namespace std;

int main() {

	int a, b, c, largest; // int Ÿ�� ���� a, b, c, largest�� �����Ѵ�.

	cout << "3���� ������ �Է��Ͻÿ�: "; 
	cin >> a >> b >> c;
	// 3���� ������ �Է��϶�� �޼����� ����� �� a, b, c 3���� ������ �Է¹޴´�.

	if (a > b && a > c) // ���� a�� b���� ũ�� a�� c���� ũ�ٸ�
		largest = a; // ���� ū ������ largest�� a�� �ȴ�.
	else if (b > a && b > c) // ���� b�� a���� ũ�� b�� c���� ũ�ٸ�
		largest = b; // largest�� b�� �ȴ�.
	else // �� ���ǽ��� ��� �ƴ϶��
		largest = c; // largest�� c�� �ȴ�.

	cout << "���� ū ������ " << largest << endl; // ���� ū ������ largest�� ����Ѵ�.

	return 0;
}