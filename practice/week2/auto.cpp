#include <iostream>

using namespace std;

auto add(int x, int y) {
	return x + y; 
}
// �Ű����� x, y�� �޾ƿ� x + y�� ��ȯ�ϴ� auto Ÿ�� �Լ� add�� �����Ѵ�.

int main() {

	auto sum = add(5, 6); // auto Ÿ�� ���� sum�� �����ϰ� �Ű����� x�� 5, y�� 6�� �Ѱ��ָ� add �Լ��� �����Ͽ� ���� ��ȯ ���� sum�� �����Ѵ�.
	cout << sum; // sum�� ����Ѵ�.

	return 0; // 0�� ��ȯ�Ͽ� ���α׷��� �����Ѵ�.
}