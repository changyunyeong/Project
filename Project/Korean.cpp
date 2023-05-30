#include "Korean.h"

Korean::Korean() {
	word = "";			
	input = "";			
	cnt = 0;			
	line = "";
	totalWord = 0.0;
	progress = 0.0;
	wordCnt = 0;
	accuracy = 0.0;
	totalTypos = 0;
	average = 0.0;
	totalKeystrokes = 0;
	averages = 0;
}

void Korean::wordK() {
	cin.ignore();			// 남아 있던 공백 제거
	ifstream file("낱말연습.txt");
	auto startTime = chrono::steady_clock::now();			// 시작 시간 측정

	while (getline(file, line)) {
		totalWord++;
	}
	file.clear();			// 파일 상태 초기화
	file.seekg(0);			// 파일 시작 지점으로 이동

	while (getline(file, word)) {
		cnt = 0;			// 단어 바뀔 때마다 초기화
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << word << endl;			// 단어 출력
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		getline(cin, input);			// 단어 입력
		cout << endl;

		wordCnt++;			// 파일에서 읽을 때마다 값 증가

		if (input.length() != word.length()) {
			cnt += abs(static_cast<int>(input.length()) - static_cast<int>(word.length()));
			// 입력된 단어와 정답 단어의 길이 차이를 오타로 처리
		}

		for (int i = 0; i < word.length(); i++) {
			if (i < input.length() && input[i] != word[i]) {
				cnt++;
				// 입력된 단어와 정답 단어의 각 문자를 비교하며 다른 경우 오타로 처리
			}
		}

		totalTypos += cnt;		// 오타 수 누적
		totalKeystrokes += input.length();			// 단어 수 누적

		accuracy = (static_cast<double>(word.length() - totalTypos) / static_cast<double>(word.length())) * 100.0;
		// 단어의 길이에서 오타수를 뺀 것을 전체 단어의 개수로 나누고 100을 곱해 정확도를 구함
		if (wordCnt % 4 == 0) {			// 4의 배수가 되면
			cout << "오타: " << totalTypos << endl;
			cout << "정확도: " << accuracy << "%" << endl;
			// 오타수, 정확도 출력

			progress = static_cast<double>(wordCnt) / static_cast<double>(totalWord) * 100.0;
			cout << "진행상황: " << progress << "%" << endl;			// 진행상황 출력

			auto endTime = chrono::steady_clock::now();			// 끝나는 시간 측정
			auto elaspedTime = chrono::duration_cast<chrono::seconds>(endTime - startTime).count();
			// 시작 시간에서 끝나는 시간을 빼 입력하는데 걸린 시간 계산
			cout << "경과 시간: " << elaspedTime << endl;

			averages = ((static_cast<double>(totalKeystrokes)) * 60.0) / elaspedTime;
			cout << "평균 타수: " << averages << endl;

			string check = "";			// 계속할 것인지 체크하기 위한 변수

			cout << "계속하시겠습니까? (예/아니오): ";
			cin >> check;
			if (check == "예") {			// 계속하겠다고 입력하면
				cout << endl;			// 한 줄 띄우고 다시 시작
				cin.ignore();			// 공백을 지움
				continue;
			}
			else if (check == "아니오") {			// 종료하겠다고 입력하면
				return;			// 함수 빠져나옴
			}
			cnt = 0;
			cout << endl;
		}
	}
}

void Korean::shortK() {
	cin.ignore();			// 남아 있던 공백 제거
	ifstream file("짧은글연습.txt");
	auto startTime = chrono::steady_clock::now();			// 시작 시간 측정

	while (getline(file, line)) {
		totalWord++;
	}
	file.clear();			// 파일 상태 초기화
	file.seekg(0);			// 파일 시작 지점으로 이동

	while (getline(file, word)) {
		cnt = 0;			// 단어 바뀔 때마다 초기화
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << word << endl;			// 단어 출력
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		getline(cin, input);			// 단어 입력
		cout << endl;

		wordCnt++;			// 파일에서 읽을 때마다 값 증가

		if (input.length() != word.length()) {
			cnt += abs(static_cast<int>(input.length()) - static_cast<int>(word.length()));
			// 입력된 단어와 정답 단어의 길이 차이를 오타로 처리
		}

		for (int i = 0; i < word.length(); i++) {
			if (i < input.length() && input[i] != word[i]) {
				cnt++;
				// 입력된 단어와 정답 단어의 각 문자를 비교하며 다른 경우 오타로 처리
			}
		}

		totalTypos += cnt;		// 오타 수 누적
		totalKeystrokes += input.length();

		accuracy = (static_cast<double>(word.length() - totalTypos) / static_cast<double>(word.length())) * 100.0;
		// 단어의 길이에서 오타수를 뺀 것을 전체 단어의 개수로 나누고 100을 곱해 정확도를 구함
		if (wordCnt % 4 == 0) {			// 4의 배수가 되면
			cout << "오타: " << totalTypos << endl;
			cout << "정확도: " << accuracy << "%" << endl;
			// 오타수, 정확도 출력

			progress = static_cast<double>(wordCnt) / static_cast<double>(totalWord) * 100.0;
			cout << "진행상황: " << progress << "%" << endl;			// 진행상황 출력

			auto endTime = chrono::steady_clock::now();			// 끝나는 시간 측정
			auto elaspedTime = chrono::duration_cast<chrono::seconds>(endTime - startTime).count();
			// 시작 시간에서 끝나는 시간을 빼 입력하는데 걸린 시간 계산
			cout << "경과 시간: " << elaspedTime << endl;

			averages = ((static_cast<double>(totalKeystrokes)) * 60.0) / elaspedTime;
			cout << "평균 타수: " << averages << endl;

			string check = "";			// 계속할 것인지 체크하기 위한 변수

			cout << "계속하시겠습니까? (예/아니오): ";
			cin >> check;
			if (check == "예") {			// 계속하겠다고 입력하면
				cout << endl;			// 한 줄 띄우고 다시 시작
				cin.ignore();			// 공백을 지움
				continue;
			}
			else if (check == "아니오") {			// 종료하겠다고 입력하면
				return;			// 함수 빠져나옴
			}
			cnt = 0;
			cout << endl;
		}
	}
}

void Korean::longK() {
	cin.ignore();			// 남아 있던 공백 제거
	int cmd = 0;			// 어떤 문장을 선택할지 입력받을 변수
	string fileName = "";			// 해당 번호에 맞는 파일 이름
	cout << "[1.나의 사랑 한글날 2. 동백꽃 3. 마지막 잎새 4. 메밀꽃 필 무렵]" << endl;
	cout << "1, 2, 3, 4 In Order: ";
	cin >> cmd;

	switch (cmd) {
	case 1:			// 1이 입력되면
		fileName = "나의사랑한글날.txt";			// 해당 파일 열기
		cin.ignore();			// 공백 제거
		cout << endl;
		break;
	case 2:
		fileName = "동백꽃.txt";
		cin.ignore();
		cout << endl;
		break;
	case 3:
		fileName = "마지막잎새.txt";
		cin.ignore();
		cout << endl;
		break;
	case 4:
		fileName = "메밀꽃필무렵.txt";
		cin.ignore();
		cout << endl;
		break;
	defaut:
		cout << "다시 입력하세요: ";			// 안내 문구가 나오고
		cin >> cmd;			// 숫자를 다시 입력받도록 함
		break;
	}

	fstream file(fileName);
	auto startTime = chrono::steady_clock::now();			// 시작 시간 측정

	while (getline(file, line)) {
		totalWord++;
	}
	file.clear();			// 파일 상태 초기화
	file.seekg(0);			// 파일 시작 지점으로 이동

	while (getline(file, word)) {
		cnt = 0;			// 단어 바뀔 때마다 초기화
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << word << endl;			// 단어 출력
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		getline(cin, input);			// 단어 입력
		cout << endl;

		wordCnt++;			// 파일에서 읽을 때마다 값 증가

		if (input.length() != word.length()) {
			cnt += abs(static_cast<int>(input.length()) - static_cast<int>(word.length()));
			// 입력된 단어와 정답 단어의 길이 차이를 오타로 처리
		}

		for (int i = 0; i < word.length(); i++) {
			if (i < input.length() && input[i] != word[i]) {
				cnt++;
				// 입력된 단어와 정답 단어의 각 문자를 비교하며 다른 경우 오타로 처리
			}
		}

		totalTypos += cnt;		// 오타 수 누적
		totalKeystrokes += input.length();

		accuracy = (static_cast<double>(word.length() - totalTypos) / static_cast<double>(word.length())) * 100.0;
		// 단어의 길이에서 오타수를 뺀 것을 전체 단어의 개수로 나누고 100을 곱해 정확도를 구함
		if (wordCnt % 4 == 0) {			// 4의 배수가 되면
			cout << "오타: " << totalTypos << endl;
			cout << "정확도: " << accuracy << "%" << endl;
			// 오타수, 정확도 출력

			progress = static_cast<double>(wordCnt) / static_cast<double>(totalWord) * 100.0;
			cout << "진행상황: " << progress << "%" << endl;			// 진행상황 출력

			auto endTime = chrono::steady_clock::now();			// 끝나는 시간 측정
			auto elaspedTime = chrono::duration_cast<chrono::seconds>(endTime - startTime).count();
			// 시작 시간에서 끝나는 시간을 빼 입력하는데 걸린 시간 계산
			cout << "경과 시간: " << elaspedTime << endl;

			averages = ((static_cast<double>(totalKeystrokes)) * 60.0) / elaspedTime;
			cout << "평균 타수: " << averages << endl;

			string check = "";			// 계속할 것인지 체크하기 위한 변수

			cout << "계속하시겠습니까? (예/아니오): ";
			cin >> check;
			if (check == "예") {			// 계속하겠다고 입력하면
				cout << endl;			// 한 줄 띄우고 다시 시작
				cin.ignore();			// 공백을 지움
				continue;
			}
			else if (check == "아니오") {			// 종료하겠다고 입력하면
				return;			// 함수 빠져나옴
			}
			cnt = 0;
			cout << endl;
		}
	}
}