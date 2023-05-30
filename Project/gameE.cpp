#include "gameE.h"

gameE::gameE() {
	// ���� �ʱ�ȭ
	score = 0;
	error = 0;
	cnt = 0;
}

void gameE::makeEx() {
	cout << "Please enter the desired word or sentence" << endl;
	cout << "The criteria are five" << endl;

	string* arr = new string[5];			// ����ڰ� �Է��� ���ù�
	string* arrEx = new string[5];			// ����ڰ� �Է��� ���ù����� ������ Ÿ�ڿ���
	cin.ignore();
	for (int i = 0; i < 5; i++) {
		cout << "Enter: ";
		getline(cin, arr[i]);
	}

	cout << "--- Start Practice ---" << endl;

	for (int i = 0; i < 5; i++) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << arr[i] << endl;			// ����ڰ� �Է��� ���ù� ���
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		getline(cin, arrEx[i]);			// ���� �Է� (Ÿ�ڿ���)
	}

	for (int i = 0; i < 5; i++) {
		if (arr[i] != arrEx[i]) {			// ��Ÿ�� ������
			error++;			// ���� ����
		}
	}

	cout << endl;
	cout << "Typos: " << error << endl;			// ��Ÿ�� ���
	cout << "Good!" << endl;
}

void gameE::findEx() {
	cin.ignore();
	string* arr = new string[5];			// ��Ÿ�� �ִ� ���ù�
	string* rgArr = new string[5];			// �ùٸ� ���ù�
	string* inArr = new string[5];			// ����ڰ� �Է��� ����

	// ��Ÿ�� �ִ� ���ڿ�
	arr[0] = "baeutiful";			// beautiful
	arr[1] = "I lvoe you";			// I love you
	arr[2] = "knowlege";			// knowledge
	arr[3] = "She is taller then her brother";			// She is taller than her brother
	arr[4] = "congratulatoin";			// congratulation

	// �ùٸ� ���ڿ�
	rgArr[0] = "beautiful";
	rgArr[1] = "I love you";
	rgArr[2] = "knowledge";
	rgArr[3] = "She is taller than her brother";
	rgArr[4] = "congratulation";

	for (int i = 0; i < 5; i++) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << arr[i] << endl;			// ��Ÿ�� �ִ� ���ڿ� ���
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		getline(cin, inArr[i]);			// ���ڿ� �Է�
		cout << endl;
		if (inArr[i] == rgArr[i]) {			// �Է��� ���ڿ��� �ùٸ� ���ڿ��� �����ϴٸ�, �� ��Ÿ�� �����Ͽ�����
			cout << "Right!" << endl;			// �ȳ��� ���
		}
		else {			// �׷��� ������
			cout << "Try again" << endl;			// �ȳ��� ����ϰ�
			cnt++;			// ���� ����
		}
		cout << endl;
	}

	// ��Ÿ���� ���� ����� �ٸ��� ���
	// ���� 5�� �������� ��Ÿ ����ŭ ���� ����
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
		cout << arr[i] << endl;			// ���� �� �迭 (arr �迭) ���
	}
	cout << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << "After Edit: " << endl;
	for (int i = 0; i < 5; i++) {
		arr[i] = inArr[i];			// arr �迭(��Ÿ�� �ִ� ���ù�)�� ����ڰ� �Է��� �迭�� ����
		cout << arr[i] << endl;
	}
}

void gameE::deleteEx() {
	cin.ignore();
	string* arr = new string[5];			// ����� �ܾ �ִ� ���ù� �迭
	string* inArr = new string[5];			// ����ڰ� �Է��� �ܾ� �迭

	arr[0] = "Banana, Mango, Apple, Pen, Pineapple";			// ������ �ƴ� �� ����
	arr[1] = "Train, Airplane, Crosswalk, Taxi, Bus";			// ��������� �ƴ� �� ����
	arr[2] = "CPU, RUM, RAM, ROM, Memory";			// ��ǻ�� ��ǰ�� ������ ���� �� ����
	arr[3] = "Seoul, Busan, Korea, Incheon, Jeju";			// �� �̸��� �ƴ� �� ����
	arr[4] = "Pine, Rose, Tulip, Sunflower, Lily";				// ���� �ƴ� �� ����

	cout << "Input the word to be deleted from the given example words" << endl;
	cout << endl;
	for (int i = 0; i < 5; i++) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << arr[i] << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		getline(cin, inArr[i]);
		cout << endl;
		if (i == 0 && (inArr[i] == "Pen" || inArr[i] == "pen")) {
			// �ش� �ε����� ��︮�� �ʴ� �ܾ �°� �ۼ��Ͽ��ٸ�
			cout << "Right!" << endl;			// �ȳ����� ��� ��
			score++;			// ���� ����
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
	// ������ ���� ����� �ٸ��� ���
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
	// ����� �ܾ ������ �迭 (������ �迭)
	delArr[0] = "Banana, Mango, Apple, Pineapple";
	delArr[1] = "Train, Airplane, Crosswalk, Taxi, Bus";
	delArr[2] = "CPU, RAM, ROM, Memory";
	delArr[3] = "Seoul, Busan, Incheon, Jeju";
	delArr[4] = "Rose, Tulip, Sunflower, Lily";

	cout << "Right Answer: " << endl;
	for (int i = 0; i < 5; i++) {
		cout << delArr[i] << endl;
		// ���� �迭 ���
	}
}

bool gameE::isInputTimedOut() {
	auto start = std::chrono::steady_clock::now();

	while (true) {
		if (cin.peek() != '\n') {
			// ���� �Է��� �Ϸ����� �ʾ��� ���
			return false;
		}

		auto end = chrono::steady_clock::now();
		chrono::duration<double> elapsed_seconds = end - start;
		// ���� �ð����� ������ �ð��� �� ����� �ð� ����
		if (elapsed_seconds.count() >= 3.0) {
			// 3�ʰ� ������ �Լ� ����
			break;
		}
	}

	string remainingInput;
	getline(cin, remainingInput);

	return true;
}

void gameE::timeGame() {
	cin.ignore();
	ifstream file("wordGame.txt");			// �ܾ� ����� �ִ� �ؽ�Ʈ ����
	string word;

	while (file >> word) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << word << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		if (isInputTimedOut()) {
			// 3�ʰ� ������
			cout << "Time Over!" << endl;
			// �ȳ��� ���
			cout << endl;
		}
		else {
			string input;
			getline(cin, input);

			if (!input.empty() && input != word) {
				// ��Ÿ�� ������
				cout << "Typos!" << endl;
				// �ȳ��� ���
				cout << endl;
			}
			else {
				// 3�� �ȿ� ��Ÿ ���� �Է��ϸ�
				score++;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
				cout << "Score +1" << endl;
				// 1�� �߰�
				cout << endl;
			}
		}

		this_thread::sleep_for(chrono::seconds(1));			// 1�� ���
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << "Game End!\nFinal Score: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	cout << score << endl;
}