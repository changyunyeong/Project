#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <windows.h>
#include <vector>
using namespace std;

class English {
public:
	English();
	void wordE();
	void shortE();
	void longE();

private:
	string word;			// ���Ͽ��� �о�� �ܾ�
	string input;			// ����ڰ� �Է��� �ܾ�, ����
	string line;			// ���Ͽ� ����� ��ü �ܾ�/����
	double totalWord;			// ���Ͽ� ����� ��ü �ܾ�
	double progress;			// ���� ��Ȳ
	int wordCnt;			// 4������ �ȳ��� ����ϱ� ���� ����
	unsigned long long accuracy;			// ��Ȯ��
	int totalTypos;			// ��ü ��Ÿ ����
	double average;			// ���
	int totalKeystrokes;			// ������ �ܾ� ��
	int averages;			// ���Ÿ��
	int cnt;			// ��Ÿ��
};
