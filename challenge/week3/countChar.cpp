#include <iostream>

using namespace std;

int main() {

	int vowel = 0;
	int consonant = 0;
	// ������ ������ ������ vowel, ������ ������ ������ consonant�� �����ϰ� 0���� �ʱ�ȭ�Ѵ�.

	cout << "�����ڸ� �Է��ϰ� ctrl+z�� ġ����" << endl;
	// �Է� �ȳ��޼��� ���

	char ch; // ����� �Է��� �����ϱ� ���� ����
	while (cin >> ch) {
		switch (ch) {
		case 'a': case 'e': case 'i': case 'o': case 'u':
			vowel++;
			break;
		// ���� �Է� ���� a, e, i, o ,u �� �ϳ���� ������ ������ ������Ű��, �ݺ����� Ż���Ѵ�.
		default:
			consonant++;
		// ���� �Է� ���� ������ �ƴ� �����̶�� ������ ������ ������Ų��.
		}
	}
	cout << "����: " << vowel << endl;
	cout << "����: " << consonant << endl;
	// ������ ������ ������ ������ ����ϰ� ���α׷��� �����Ѵ�.

	return 0;
}