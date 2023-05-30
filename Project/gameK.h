#include <iostream>
#include <string>
#include <windows.h>
#include <thread>
#include <fstream>
using namespace std;

class gameK {
public:
	gameK();
	void makeEx();			// 사용자가 예시문을 만드는 타자연습
	void findEx();			// 주어진 문장에서 오타를 찾아 수정
	bool isInputTimedOut();			// 주어진 시간(3초)를 초과했는지 판단
	void timeGame();			// 두더지게임
private:
	int score;
	int error;
	int cnt;
};