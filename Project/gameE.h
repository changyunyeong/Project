#include <iostream>
#include <string>
#include <windows.h>
#include <thread>
#include <fstream>
using namespace std;

class gameE {
public:
	gameE();
	void makeEx();			// ����ڰ� ���ù��� ����� Ÿ�ڿ���
	void findEx();			// �־��� ���忡�� ��Ÿ�� ã�� ����
	void deleteEx();			// �־��� ���忡�� ����� �ܾ ������ ������ ����
	bool isInputTimedOut();			// �־��� �ð�(3��)�� �ʰ��ߴ��� �Ǵ�
	void timeGame();			// �δ�������
private:
	int score;			// ���� ����
	int error;			// ��Ÿ�� ����
	int cnt;			// ���� ����
};