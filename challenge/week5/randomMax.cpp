#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {

	const int numCell = 10; // 셀의 수 10을 상수로 선언
	int numList[numCell][numCell]; // 10 * 10 크기의 2차원 배열 numLIst를 선언한다.

	for (int i = 0; i < numCell; i++) {
		for (int j = 0; j < numCell; j++) {
			int x = rand() % 1000; // 난수를 1000으로 나누어, 0 ~ 999 범위의 숫자만 저장되도록 한다.
			numList[i][j] = x; // 난수를 하나씩 2차원 배열에 저장한다.
			cout << i << ", " << j << " : " << x << endl; // 난수를 형식에 맞춰 출력한다.
		}
	}
	// 반복문을 10 * 10번 반복하며, 같은 크기의 2차원 배열 numList에 난수 값을 하나씩 저장하는 것이다.
	cout << endl;

	int max = 0; // 큰 값 저장을 위한 변수
	int maxI; // 큰 값이 있는 i를 저장하기 위한 변수
	int maxJ; // 큰 값이 있는 j를 저장하기 위한 변수

	for (int i = 0; i < numCell; i++) {
		int j = 0; // 범위 기반 탐색을 위해 j 인덱스를 따로 선언
		for (auto elem : numList[i]) {
			int value = numList[i][j]; // 난수 값들을 우선 value에 저장
			if (value > max) { // 최대값 관련 정보를 저장하는 코드
				max = value;
				maxI = i;
				maxJ = j;
			}
			j++; // numList 배열의 한 줄을 모두 탐색한 후, j 인덱스를 증가시킴
		}
	}
	// 반복문에서 i 인덱스를 하나씩 증가시키며, numLIst 배열을 한 줄씩 탐색하도록 하는 코드이다.
	// 두번째 반복문에서 numList[i]에 해당하는 10개의 값들을 하나씩 꺼내어 value에 저장하고,
	// value 값이 커질 때마다 max에 value를 저장하고, maxI와 maxJ에 정보를 저장하도록 한다.
	
	cout << "가장 큰 값은 " << max << "이고, ";
	cout << "i와 j는 각각 " << maxI << ", " << maxJ << "입니다." << endl;
	cout << "검증 결과: " << numList[maxI][maxJ] << endl;
	// 형식에 맞추어 max 값에 대한 정보를 출력한다.

	return 0;
}