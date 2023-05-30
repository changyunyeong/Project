#include "gameK.h"

gameK::gameK() {
	// 변수 초기화
	score = 0;
	error = 0;
	cnt = 0;
}

void gameK::makeEx() {
	cout << "원하는 단어나 문장을 입력하세요" << endl;
	cout << "다섯 개까지 입력할 수 있습니다" << endl;

	string* arr = new string[5];			// 사용자가 입력한 예시문
	string* arrEx = new string[5];			// 사용자가 입력한 예시문으로 진행할 타자연습
	cin.ignore();
	for (int i = 0; i < 5; i++) {
		cout << "입력: ";
		getline(cin, arr[i]);
	}

	cout << "--- 연습 시작 ---" << endl;

	for (int i = 0; i < 5; i++) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << arr[i] << endl;			// 사용자가 입력한 예시문 출력
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		getline(cin, arrEx[i]);			// 문장 입력 (타자연습)
	}

	for (int i = 0; i < 5; i++) {
		if (arr[i] != arrEx[i]) {			// 오타가 있으면
			error++;			// 변수 증가
		}
	}

	cout << endl;
	cout << "오타: " << error << endl;			// 오타수 출력
	cout << "잘했어요!" << endl;
}

void gameK::findEx() {
	cin.ignore();
	string* arr = new string[5];			// 오타가 있는 예시문
	string* rgArr = new string[5];			// 올바른 예시문
	string* inArr = new string[5];			// 사용자가 입력할 문장

	// 오타가 있는 문자열
	arr[0] = "내노라하다";			// 내로라하다	
	arr[1] = "어따 대고";			// 얻다 대고
	arr[2] = "물을 들이키다";			// 물을 들이켜다
	arr[3] = "몇일 후에 뵈요";			// 며칠 후에 봬요
	arr[4] = "단언컨데";			// 단언컨대

	// 올바른 문자열
	rgArr[0] = "내로라하다";
	rgArr[1] = "얻다 대고";
	rgArr[2] = "물을 들이켜다";
	rgArr[3] = "며칠 후에 봬요";
	rgArr[4] = "단언컨대";

	for (int i = 0; i < 5; i++) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << arr[i] << endl;			// 오타가 있는 문자열 출력
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		getline(cin, inArr[i]);			// 문자열 입력
		cout << endl;
		if (inArr[i] == rgArr[i]) {			// 입력한 문자열이 올바른 문자열과 동일하다면, 즉 오타를 수정하였으면
			cout << "정답입니다!" << endl;			// 안내문 출력
		}
		else {			// 그렇지 않으면
			cout << "다시 시도해 보세요" << endl;			// 안내문 출력하고
			cnt++;			// 변수 증가
		}
		cout << endl;
	}

	//오타수에 따라 결과문 다르게 출력
	// 만점 5점 기준으로 오타 수만큼 점수 차감
	switch (cnt) {
	case 0:
		cout << "점수: " << 5 - cnt << endl;
		cout << "완벽합니다" << endl;
		break;
	case 1:
		cout << "점수: " << 5 - cnt << endl;
		cout << "훌륭해요" << endl;
		break;
	case 2:
		cout << "점수: " << 5 - cnt << endl;
		cout << "잘했어요" << endl;
		break;
	case 3:
		cout << "점수: " << 5 - cnt << endl;
		cout << "좋아요" << endl;
		break;
	case 4:
		cout << "점수: " << 5 - cnt << endl;
		cout << "나쁘지 않아요" << endl;
		break;
	default:
		cout << "점수: " << 5 - cnt << endl;
		cout << "다시 시도해봐요!" << endl;
		break;
	}

	cout << endl;
	cout << "수정 전: " << endl;
	for (int i = 0; i < 5; i++) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << arr[i] << endl;			// 수정 전 배열 (arr 배열) 출력
	}
	cout << endl;
	cout << "수정 후: " << endl;
	for (int i = 0; i < 5; i++) {
		arr[i] = inArr[i];			// arr 배열(오타가 있던 제시문)을 사용자가 입력한 배열로 수정
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << arr[i] << endl;
	}
}

bool gameK::isInputTimedOut() {
	auto start = chrono::steady_clock::now();

	while (true) {
		if (cin.peek() != '\n') {
			// 아직 입력을 완료하지 않았을 경우
			return false;
		}

		auto end = chrono::steady_clock::now();
		chrono::duration<double> elapsed_seconds = end - start;
		// 시작 시간에서 끝나는 시간을 빼 경과된 시간 측정
		if (elapsed_seconds.count() >= 3.0) {
			// 3초가 지나면 함수 종료
			break;
		}
	}

	string remainingInput;
	getline(cin, remainingInput);

	return true;
}

void gameK::timeGame() {
	cin.ignore();
	ifstream file("단어게임.txt"); // 단어 목록이 있는 텍스트 파일
	string word;

	int score = 0;
	while (file >> word) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << word << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		if (isInputTimedOut()) {
			// 3초가 지나면
			cout << "시간 초과!" << endl;
			// 안내문 출력
			cout << endl;
		}
		else {
			string input;
			getline(cin, input);

			if (!input.empty() && input != word) {
				// 오타가 있으면
				cout << "오타!" << endl;
				// 안내문 출력
				cout << endl;
			}
			else {
				// 3초 안에 오타 없이 입력하면
				score++;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
				cout << "점수 +1" << endl;
				// 1점 추가
				cout << endl;
			}
		}

		this_thread::sleep_for(chrono::seconds(1)); // 1초 대기
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << "게임 끝!\n최종 점수: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	cout << score << endl;
}