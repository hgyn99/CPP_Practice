#pragma once
#include <iostream>
#include <string>

using namespace std;

// User Ŭ����
class User
{
public:
	// ��� ����
	int hp;
	// ��� �Լ�
	void DecreaseHP(int dec_hp);
	int GetHP();
};