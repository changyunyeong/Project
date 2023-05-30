#include <iostream>
#include <string>
#include <windows.h>
#include <thread>
#include <fstream>
using namespace std;

class gameE {
public:
	gameE();
	void makeEx();			// 사용자가 예시문을 만드는 타자연습
	void findEx();			// 주어진 문장에서 오타를 찾아 수정
	void deleteEx();			// 주어진 문장에서 어색한 단어나 문장이 있으면 삭제
	bool isInputTimedOut();			// 주어진 시간(3초)를 초과했는지 판단
	void timeGame();			// 두더지게임
private:
	int score;			// 점수 저장
	int error;			// 오타수 저장
	int cnt;			// 점수 저장
};