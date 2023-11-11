#pragma once
#include <iostream>
#include <string>

using namespace std;

// User 클래스
class User
{
public:
	// 멤버 변수
	int hp;
	// 멤버 함수
	void DecreaseHP(int dec_hp);
	int GetHP();
};