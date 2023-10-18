#include <iostream>
#include <string>

using namespace std;

int main() {
	string s1, s2; // DNA�� ������ ���ڿ� s1, s2�� ����
	int count = 0; // �ع� �Ÿ��� ī������ ���� count ����

	// ���Ŀ� ���߾� DNA1, DNA2 ���ڿ� �Է� ����
	cout << "DNA1: ";
	cin >> s1;
	cout << "DNA2: ";
	cin >> s2;

	// ���� �Է� ���� �� ���ڿ��� ���̰� ���� �ٸ��ٸ�
	if (s1.length() != s2.length())
		cout << "����: ���̰� �ٸ�" << endl; // ���̰� �ٸ��ٴ� ���� �޼��� ���
	else { // ���̰� ���ٸ� (�������� �Է��̶��)
		// �ݺ����� ���ڿ��� ���̸�ŭ �ݺ��Ͽ� ���� �ϳ��� ������ �� ���ڿ��� ���Ѵ�.
		for (int i = 0; i < s1.length(); i++) {
			if (s1[i] != s2[i])
				count += 1; // ���� ���� ��ġ�� �� ���ڰ� �ٸ��ٸ� count�� 1 ������Ų��.
		}
		cout << "�ع� �Ÿ��� " << count << endl; // ���� count ���� ����Ѵ�.
	}
	return 0;
}