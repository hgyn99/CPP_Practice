#include <iostream>
#include <string>

using namespace std;

int main() {

	string s1 = "Good"; // string Ÿ�� ���� s1�� �����ϰ�, ���ڿ� "Good"�� �����Ѵ�.
	string s2 = "Morning"; // string Ÿ�� ���� s2�� �����ϰ�, ���ڿ� "Morning"�� �����Ѵ�.
	string s3 = s1 + " " + s2 + "!"; // s1�� s2�� ����� ���ڿ��� ���Ͽ� ���ο� ���ڿ��� �簡���Ѵ�.

	cout << s3 << endl; // ���� ������� ���ڿ� s3�� ����Ѵ�.

	return 0; // 0�� ��ȯ�ϸ� ���α׷��� �����Ѵ�.
}