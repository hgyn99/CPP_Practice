#include <iostream>
#include <time.h>

using namespace std;

int main() {

	int ans; // ���� ����
	int ans_count = 0;

	cout << "��� ������ �ڵ����� �����մϴ�." << endl;
	// ���� ���� �ȳ� �޼����� ����Ѵ�.

	while (true) {

		int firstNum = rand() % 100;
		int secondNum = rand() % 100;
		// ù ��° ���ڿ� �� ��° ���ڸ� �����ϰ�, �� ������ �����Ѵ�.

		cout << firstNum << "+" << secondNum << "=";
		// ������ ����Ѵ�.
		cin >> ans;
		// ���� �Է� �޴´�.

		if (ans == (firstNum + secondNum)) {
			cout << "�¾ҽ��ϴ�." << endl;
			ans_count++;
			if (ans_count == 5) break;
		}
		// ���� ���� ���� �´ٸ� �¾Ҵٴ� �޼����� ����ϰ�, ���� Ƚ���� ������Ű�� �ݺ����� Ż���Ѵ�.
		// ���� Ƚ���� 5���� �Ǹ�, �ݺ����� Ż���ϸ� ���α׷��� �����Ѵ�.
		else {
			cout << "Ʋ�Ƚ��ϴ�." << endl;
		}
		// ���� ���� ���� Ʋ�ȴٸ� Ʋ�ȴٴ� �޼����� ����ϰ� �ݺ����� �ݺ��Ѵ�.

	}

	return 0;
}