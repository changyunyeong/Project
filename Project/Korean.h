#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <cmath>
#include <windows.h>
#include <vector>
using namespace std;

class Korean {
public:
	Korean();
	void wordK();			// 한국어 낱말 연습
	void shortK();			// 한국어 짧은 글 연습
	void longK();			// 한국어 긴 글 연습

private:
	string word;			// 파일에서 읽어올 단어
	string input;			// 사용자가 입력할 단어, 문장
	string line;			// 파일에 저장된 전체 단어/문장
	double totalWord;			// 파일에 저장된 전체 단어
	double progress;			// 진행 상황
	int wordCnt;			// 4번마다 안내문 출력하기 위한 변수
	unsigned long long accuracy;			// 정확도
	int totalTypos;			// 전체 오타 변수
	double average;			// 평균
	int totalKeystrokes;			// 누적된 단어 수
	int averages;			// 평균타수
	int cnt;			// 오타수
};