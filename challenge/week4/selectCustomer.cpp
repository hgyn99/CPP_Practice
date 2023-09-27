#include <iostream>
#include <string>

using namespace std;

int main() {

    const int maxPeople = 3;
    cout << "총 고객의 수를 입력하라: 3" << endl;
    string names[maxPeople];
    int ages[maxPeople];
    // 고객들의 이름을 저장할 names 배열과, 나이를 저장할 ages 배열을 선언한다.

    for (int i = 0; i < maxPeople; i++) {
        cout << "사람 " << i + 1 << "의 이름: ";
        cin >> names[i];
        cout << "사람 " << i + 1 << "의 나이: ";
        cin >> ages[i];
    }
    // 형식에 맞춰 이름과 나이를 입력할 것을 안내하는 문자열을 출력하여 사람들의 이름과 나이를 입력받는다.

    int ageThreshold;
    cout << "특정 나이 이상인 사람을 찾으려면 나이를 입력하세요:";
    cin >> ageThreshold;
    // 특정 나이를 저장할 ageThreshold 변수를 선언하여 특정 나이를 입력 받는다.
    
    cout << ageThreshold << "세 이상인 고객들:\n";
    // 특정 나이 이상인 고객들을 출력한다.

    int cnt = 0; // 특정 나이 이상인 고객들의 명수를 체크하기 위한 변수 cnt 선언

    for (int i = 0; i < maxPeople; i++) {
        if (ages[i] >= ageThreshold) {
            cout << names[i] << " (" << ages[i] << "세)" << endl;
            cnt++; // 특정 나이 이상인 고객이 있었다면 cnt를 증가시킨다.
        }
    }
    // i=0부터 i<3이 될 때까지 i를 1씩 증가하며 반복문을 반복하여,
    // i의 값을 활용해 배열의 특정 위치에 접근하며 특정 나이와 비교하고,
    // 특정 나이 이상인 고객의 이름과 나이를 출력한다.

    if (cnt == 0) {
        cout << ageThreshold << "이상의 나이를 가진 고객이 없습니다." << endl;
    }
    // 만약 특정 나이 이상의 나이를 가진 고객이 없다면, 고객이 없음을 알린다.

    return 0;
}