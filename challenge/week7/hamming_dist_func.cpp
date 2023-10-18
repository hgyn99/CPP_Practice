#include <iostream>
#include <string>

using namespace std;

// �Է� ���� ���ڿ��� ��� �ҹ��ڷ� ��ȯ
string toLowerStr(string str) {
	for (char& c : str) {
		c = tolower(c);
	}
	return str;
}

// �Է� ���� ���ڿ��� ��� �빮�ڷ� ��ȯ
string toUpperStr(string str) {
	for (char& c : str) {
		c = toupper(c);
	}
	return str;
}

int calcHammingDist(string s1, string s2) {
	int count = 0; // �ع� �Ÿ��� ī������ ���� count ����
	// ���ڿ� s1�� s2�� ��� �ҹ��ڷ� �����Ͽ�, ��ҹ��� ���� ���� ����ϵ��� �Ѵ�.
	s1 = toLowerStr(s1);
	s2 = toLowerStr(s2);
	for (int i = 0; i < s1.length(); i++) {
		// ���� ���� ��ġ�� �� ���ڰ� �ٸ��ٸ� count�� 1 ������Ų��.
		if (s1[i] != s2[i])
			count += 1; 
	}
	return count; // ���� count ���� ��ȯ�Ѵ�.
}

int main() {
	string s1, s2; // DNA�� ������ ���ڿ� s1, s2�� ����
	
	// do-while ���� �̿��� ������ s1, s2 �Է��� �ް�, �Է��� ������ ������ �Է��� �ݺ��ϵ��� �Ѵ�.
	do {
		// ���Ŀ� ���߾� s1, s2 ���ڿ� �Է� �޴´�.
		cout << "s1: ";
		cin >> s1;
		cout << "s2: ";
		cin >> s2;
		// ���� �� ���ڿ��� ���̰� ���ٸ� while���� Ż���Ѵ�.
		if (s1.length() == s2.length()) break;
		// ���̰� �ٸ��ٸ� ���� �޼��� ��� �� while���� �ݺ��Ѵ�.
		cout << "����: ���̰� �ٸ�" << endl;
	} while (s1.length() != s2.length());

	// ��ҹ��� ���� ���� �Ÿ��� ���ϴ� �Լ��� �����Ͽ� count ���� �����Ѵ�.
	int count = calcHammingDist(s1, s2); 
	// ���� count ���� ����Ѵ�.
	cout << "�ع� �Ÿ��� " << count << endl; 

	return 0;
}