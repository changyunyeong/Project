#include <iostream>
#include <string>
#include <windows.h>
#include <thread>
#include <fstream>
using namespace std;

class gameK {
public:
	gameK();
	void makeEx();			// ����ڰ� ���ù��� ����� Ÿ�ڿ���
	void findEx();			// �־��� ���忡�� ��Ÿ�� ã�� ����
	bool isInputTimedOut();			// �־��� �ð�(3��)�� �ʰ��ߴ��� �Ǵ�
	void timeGame();			// �δ�������
private:
	int score;
	int error;
	int cnt;
};