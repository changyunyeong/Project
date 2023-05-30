#include "English.h"			// 한국어 연습 헤더파일
#include "Korean.h"			// 영어 연습 헤더파일
#include "gameE.h"			// 영어 게임 헤더파일
#include "gameK.h"			// 한국어 게임 헤더파일

void gameInstE() {
	int cmd = 0;
	gameE game;
	cout << endl;
	cout << "If you want to add an example of typing practice, press 1." << endl;
	cout << "If you want to play a typo - finding game, press 2." << endl;
	cout << "If you want to play a game of finding awkward words, press 3." << endl;
	cout << "If you want to play a whack - a - mole game, press 4." << endl;
	cin >> cmd;

	switch (cmd) {
	case 1:
		game.makeEx();			// 타자연습 예시 추가
		break;
	case 2:
		game.findEx();			// 오타 찾기
		break;
	case 3:
		game.deleteEx();			// 어색한 단어 찾기
		break;
	case 4:
		game.timeGame();			// 두더지게임
		break;
	default:
		cout << "Enter Again" << endl;
		cin >> cmd;
		break;
	}
	cout << endl;
}

void gameInstK() {
	int cmd = 0;
	gameK game;
	cout << endl;
	cout << "타자연습의 예시를 추가하고 싶으면 1번" << endl;
	cout << "오타를 찾는 게임을 하고 싶으면 2번" << endl;
	cout << "두더지게임을 하고 싶으면 3번을 입력하세요" << endl;
	cin >> cmd;

	switch (cmd) {
	case 1:
		game.makeEx();			// 타자연습 예시 추가
		break;
	case 2:
		game.findEx();			// 오타 찾기
		break;
	case 3:
		game.timeGame();			// 두더지게임
		break;
	default:
		cout << "다시 입력하세요" << endl;
		cin >> cmd;
		break;
	}
	cout << endl;

}

void Kor() {			// 한국어 안내문
	Korean testcase;
	cout << "낱말 연습을 하려면 1을, 짧은 글 연습을 하려면 2를, 긴 글 연습을 하려면 3을 입력하시오" << endl;
	cout << "만약 게임을 하고 싶다면 4번을 입력하세요: ";
	int cmd;
	cin >> cmd;
	switch (cmd) {
	case 1:
		testcase.wordK();			// 한글 단어 연습 함수 출력
		cin.ignore();
		break;
	case 2:
		testcase.shortK();			// 한글 짧은 글 연습 함수 출력
		cin.ignore();
		break;
	case 3:
		testcase.longK();			// 한글 긴 글 연습 함수 출력
		cin.ignore();
		break;
	case 4:
		gameInstK();			// 게임 함수 출력
		cin.ignore();
		break;
	default:			// 제시된 수자 외의 숫자가 입력되면
		cout << "다시 입력하시오: ";			// 다시 입력하라는 안내문이 나오고
		cin >> cmd;				// 다시 숫자를 입력 받음
		break;
	}
}

void Eng() {			// 영어 안내문
	English testcase;
	gameE playGame;
	cout << "Enter 1 for word practice, 2 for short text practice, or 3 for long text practice" << endl;
	cout << "Or if you want to play a game, enter 4: ";
	int cmd;
	cin >> cmd;
	switch (cmd) {
	case 1:
		testcase.wordE();			// 영어 단어 연습 함수 출력
		cin.ignore();
		break;
	case 2:
		testcase.shortE();			// 영어 짧은 글 연습 함수 출력
		cin.ignore();
		break;
	case 3:
		testcase.longE();			// 영어 긴 글 연습 함수 출력
		cin.ignore();
		break;
	case 4:
		gameInstE();			// 게임 함수 출력
		break;
	default:			// 제시된 숫자 외의 숫자가 입력되면
		cout << "Enter again: ";			// 다시 입력하라는 안내문이 나오고
		cin >> cmd;			// 다시 숫자를 입력 받음
		break;
	}
	cout << endl;
}

int main() {
	string cmd;

	cout << "한글을 연습하시겠습니까, 영어를 연습하시겠습니까?" << endl;
	cout << "한글을 연습하려면 '한글'을, 영어를 연습하려면 'English'를 입력하세요." << endl;
	cout << endl;
	cout << "Would you like to practice Korean or English ?" << endl;
	cout << "Enter '한글' to practice Korean, or 'English' to practice English." << endl;
	cout << endl;

	cin >> cmd;
	if (cmd == "한글") {
		Kor();			// 한국어 안내문 출력
	}
	else if (cmd == "English" || cmd == "english") {
		Eng();			// 영어 안내문 출력
	}
} 