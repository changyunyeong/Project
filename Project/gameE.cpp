#include "gameE.h"

gameE::gameE() {
	// 변수 초기화
	score = 0;
	error = 0;
	cnt = 0;
}

void gameE::makeEx() {
	cout << "Please enter the desired word or sentence" << endl;
	cout << "The criteria are five" << endl;

	string* arr = new string[5];			// 사용자가 입력한 예시문
	string* arrEx = new string[5];			// 사용자가 입력한 예시문으로 진행할 타자연습
	cin.ignore();
	for (int i = 0; i < 5; i++) {
		cout << "Enter: ";
		getline(cin, arr[i]);
	}

	cout << "--- Start Practice ---" << endl;

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
	cout << "Typos: " << error << endl;			// 오타수 출력
	cout << "Good!" << endl;
}

void gameE::findEx() {
	cin.ignore();
	string* arr = new string[5];			// 오타가 있는 예시문
	string* rgArr = new string[5];			// 올바른 예시문
	string* inArr = new string[5];			// 사용자가 입력할 문장

	// 오타가 있는 문자열
	arr[0] = "baeutiful";			// beautiful
	arr[1] = "I lvoe you";			// I love you
	arr[2] = "knowlege";			// knowledge
	arr[3] = "She is taller then her brother";			// She is taller than her brother
	arr[4] = "congratulatoin";			// congratulation

	// 올바른 문자열
	rgArr[0] = "beautiful";
	rgArr[1] = "I love you";
	rgArr[2] = "knowledge";
	rgArr[3] = "She is taller than her brother";
	rgArr[4] = "congratulation";

	for (int i = 0; i < 5; i++) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << arr[i] << endl;			// 오타가 있는 문자열 출력
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		getline(cin, inArr[i]);			// 문자열 입력
		cout << endl;
		if (inArr[i] == rgArr[i]) {			// 입력한 문자열이 올바른 문자열과 동일하다면, 즉 오타를 수정하였으면
			cout << "Right!" << endl;			// 안내문 출력
		}
		else {			// 그렇지 않으면
			cout << "Try again" << endl;			// 안내문 출력하고
			cnt++;			// 변수 증가
		}
		cout << endl;
	}

	// 오타수에 따라 결과문 다르게 출력
	// 만점 5점 기준으로 오타 수만큼 점수 차감
	switch (cnt) {
	case 0:
		cout << "Score: " << 5 - cnt << endl;
		cout << "Perfect" << endl;
		break;
	case 1:
		cout << "Score: " << 5 - cnt << endl;
		cout << "Excellent" << endl;
		break;
	case 2:
		cout << "Score: " << 5 - cnt << endl;
		cout << "Great" << endl;	
		break;
	case 3:
		cout << "Score: " << 5 - cnt << endl;
		cout << "Good" << endl;
		break;
	case 4:
		cout << "Score: " << 5 - cnt << endl;
		cout << "Well done" << endl;
		break;
	default:
		cout << "Score: " << 5 - cnt << endl;
		cout << "Try again!" << endl;
		break;
	}

	cout << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "Before Edit: " << endl;
	for (int i = 0; i < 5; i++) {
		cout << arr[i] << endl;			// 수정 전 배열 (arr 배열) 출력
	}
	cout << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << "After Edit: " << endl;
	for (int i = 0; i < 5; i++) {
		arr[i] = inArr[i];			// arr 배열(오타가 있던 제시문)을 사용자가 입력한 배열로 수정
		cout << arr[i] << endl;
	}
}

void gameE::deleteEx() {
	cin.ignore();
	string* arr = new string[5];			// 어색한 단어가 있는 예시문 배열
	string* inArr = new string[5];			// 사용자가 입력할 단어 배열

	arr[0] = "Banana, Mango, Apple, Pen, Pineapple";			// 음식이 아닌 것 삭제
	arr[1] = "Train, Airplane, Crosswalk, Taxi, Bus";			// 교통수단이 아닌 것 삭제
	arr[2] = "CPU, RUM, RAM, ROM, Memory";			// 컴퓨터 부품과 관련이 없는 것 삭제
	arr[3] = "Seoul, Busan, Korea, Incheon, Jeju";			// 시 이름이 아닌 것 삭제
	arr[4] = "Pine, Rose, Tulip, Sunflower, Lily";				// 꽃이 아닌 것 삭제

	cout << "Input the word to be deleted from the given example words" << endl;
	cout << endl;
	for (int i = 0; i < 5; i++) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << arr[i] << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		getline(cin, inArr[i]);
		cout << endl;
		if (i == 0 && (inArr[i] == "Pen" || inArr[i] == "pen")) {
			// 해당 인덱스에 어울리지 않는 단어를 맞게 작성하였다면
			cout << "Right!" << endl;			// 안내문구 출력 후
			score++;			// 점수 증가
			cout << endl;
		}
		else if (i == 1 && (inArr[i] == "Crosswalk" || inArr[i] == "crosswalk")) {
			cout << "Right!" << endl;
			score++;
			cout << endl;
		}
		else if (i == 2 && inArr[i] == "RUM") {
			cout << "Right!" << endl;
			score++;
			cout << endl;
		}
		else if (i == 3 && (inArr[i] == "Korea" || inArr[i] == "korea")) {
			cout << "Right!" << endl;
			score++;
			cout << endl;
		}
		else if (i == 4 && (inArr[i] == "Pine" || inArr[i] == "pine")) {
			cout << "Right!" << endl;
			score++;
			cout << endl;
		}
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	// 점수에 따라 결과문 다르게 출력
	switch (score) {			
	case 5:
		cout << "Score: " << score << endl;
		cout << "Perfect" << endl;
		break;
	case 4:
		cout << "Score: " << score << endl;
		cout << "Excellent" << endl;
		break;
	case 3:
		cout << "Score: " << score << endl;
		cout << "Great" << endl;
		break;
	case 2:
		cout << "Score: " << score << endl;
		cout << "Good" << endl;
		break;
	case 1:
		cout << "Score: " << score << endl;
		cout << "Well done" << endl;
		break;
	default:
		cout << "Score: " << 5 - score << endl;
		cout << "Try again!" << endl;
		break;
	}
	cout << endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	string* delArr = new string[5];			
	// 어색한 단어가 삭제된 배열 (정답인 배열)
	delArr[0] = "Banana, Mango, Apple, Pineapple";
	delArr[1] = "Train, Airplane, Crosswalk, Taxi, Bus";
	delArr[2] = "CPU, RAM, ROM, Memory";
	delArr[3] = "Seoul, Busan, Incheon, Jeju";
	delArr[4] = "Rose, Tulip, Sunflower, Lily";

	cout << "Right Answer: " << endl;
	for (int i = 0; i < 5; i++) {
		cout << delArr[i] << endl;
		// 정답 배열 출력
	}
}

bool gameE::isInputTimedOut() {
	auto start = std::chrono::steady_clock::now();

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

void gameE::timeGame() {
	cin.ignore();
	ifstream file("wordGame.txt");			// 단어 목록이 있는 텍스트 파일
	string word;

	while (file >> word) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << word << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		if (isInputTimedOut()) {
			// 3초가 지나면
			cout << "Time Over!" << endl;
			// 안내문 출력
			cout << endl;
		}
		else {
			string input;
			getline(cin, input);

			if (!input.empty() && input != word) {
				// 오타가 있으면
				cout << "Typos!" << endl;
				// 안내문 출력
				cout << endl;
			}
			else {
				// 3초 안에 오타 없이 입력하면
				score++;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
				cout << "Score +1" << endl;
				// 1점 추가
				cout << endl;
			}
		}

		this_thread::sleep_for(chrono::seconds(1));			// 1초 대기
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << "Game End!\nFinal Score: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	cout << score << endl;
}