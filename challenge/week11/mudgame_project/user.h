#pragma once
#include <iostream>
#include <string>

using namespace std;

// User Ŭ����
class User
{
private:
	// ��� ����
	int hp;
public:
	// ��� �Լ�
	void DecreaseHP(int dec_hp);
	void IncreaseHP(int inc_hp);
	int GetHP();
	// ������
	User(int first_hp = 20) {
		hp = first_hp;
	}

};