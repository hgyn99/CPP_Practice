#include <iostream>
#define PI 3.14159265359 // ��ȣ ��� PI ���� 3.14159265359�� �����Ѵ�.

using namespace std;

int main() {

	int income = 1000; // int Ÿ�� ���� income�� �����ϰ� 1000�� �����Ѵ�.
	const double TAX_RATE = 0.25; // ��� ���� TAX_RATE�� �����ϰ� 0.25�� �����Ѵ�.
	income = income - TAX_RATE * income; // ������ ���� income ���� ��ȯ�ϰ� �� ���� income�� �ٽ� ������Ʈ�Ѵ�.

	double x = 100; // double Ÿ�� ���� x�� �����ϰ� 100�� �����Ѵ�.
	x = x * PI; // x�� ��ȣ ��� PI ���� ���Ͽ� x ���� ������Ʈ �Ѵ�.

	cout << x << endl; // x�� ����Ѵ�.

	return 0; // 0�� ��ȯ�Ͽ� ���α׷��� �����Ѵ�.
}