#include "gameK.h"

gameK::gameK() {
	// ���� �ʱ�ȭ
	score = 0;
	error = 0;
	cnt = 0;
}

void gameK::makeEx() {
	cout << "���ϴ� �ܾ ������ �Է��ϼ���" << endl;
	cout << "�ټ� ������ �Է��� �� �ֽ��ϴ�" << endl;

	string* arr = new string[5];			// ����ڰ� �Է��� ���ù�
	string* arrEx = new string[5];			// ����ڰ� �Է��� ���ù����� ������ Ÿ�ڿ���
	cin.ignore();
	for (int i = 0; i < 5; i++) {
		cout << "�Է�: ";
		getline(cin, arr[i]);
	}

	cout << "--- ���� ���� ---" << endl;

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
	cout << "��Ÿ: " << error << endl;			// ��Ÿ�� ���
	cout << "���߾��!" << endl;
}

void gameK::findEx() {
	cin.ignore();
	string* arr = new string[5];			// ��Ÿ�� �ִ� ���ù�
	string* rgArr = new string[5];			// �ùٸ� ���ù�
	string* inArr = new string[5];			// ����ڰ� �Է��� ����

	// ��Ÿ�� �ִ� ���ڿ�
	arr[0] = "������ϴ�";			// ���ζ��ϴ�	
	arr[1] = "��� ���";			// ��� ���
	arr[2] = "���� ����Ű��";			// ���� �����Ѵ�
	arr[3] = "���� �Ŀ� �ƿ�";			// ��ĥ �Ŀ� �Ŀ�
	arr[4] = "�ܾ�����";			// �ܾ�����

	// �ùٸ� ���ڿ�
	rgArr[0] = "���ζ��ϴ�";
	rgArr[1] = "��� ���";
	rgArr[2] = "���� �����Ѵ�";
	rgArr[3] = "��ĥ �Ŀ� �Ŀ�";
	rgArr[4] = "�ܾ�����";

	for (int i = 0; i < 5; i++) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << arr[i] << endl;			// ��Ÿ�� �ִ� ���ڿ� ���
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		getline(cin, inArr[i]);			// ���ڿ� �Է�
		cout << endl;
		if (inArr[i] == rgArr[i]) {			// �Է��� ���ڿ��� �ùٸ� ���ڿ��� �����ϴٸ�, �� ��Ÿ�� �����Ͽ�����
			cout << "�����Դϴ�!" << endl;			// �ȳ��� ���
		}
		else {			// �׷��� ������
			cout << "�ٽ� �õ��� ������" << endl;			// �ȳ��� ����ϰ�
			cnt++;			// ���� ����
		}
		cout << endl;
	}

	//��Ÿ���� ���� ����� �ٸ��� ���
	// ���� 5�� �������� ��Ÿ ����ŭ ���� ����
	switch (cnt) {
	case 0:
		cout << "����: " << 5 - cnt << endl;
		cout << "�Ϻ��մϴ�" << endl;
		break;
	case 1:
		cout << "����: " << 5 - cnt << endl;
		cout << "�Ǹ��ؿ�" << endl;
		break;
	case 2:
		cout << "����: " << 5 - cnt << endl;
		cout << "���߾��" << endl;
		break;
	case 3:
		cout << "����: " << 5 - cnt << endl;
		cout << "���ƿ�" << endl;
		break;
	case 4:
		cout << "����: " << 5 - cnt << endl;
		cout << "������ �ʾƿ�" << endl;
		break;
	default:
		cout << "����: " << 5 - cnt << endl;
		cout << "�ٽ� �õ��غ���!" << endl;
		break;
	}

	cout << endl;
	cout << "���� ��: " << endl;
	for (int i = 0; i < 5; i++) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << arr[i] << endl;			// ���� �� �迭 (arr �迭) ���
	}
	cout << endl;
	cout << "���� ��: " << endl;
	for (int i = 0; i < 5; i++) {
		arr[i] = inArr[i];			// arr �迭(��Ÿ�� �ִ� ���ù�)�� ����ڰ� �Է��� �迭�� ����
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << arr[i] << endl;
	}
}

bool gameK::isInputTimedOut() {
	auto start = chrono::steady_clock::now();

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

void gameK::timeGame() {
	cin.ignore();
	ifstream file("�ܾ����.txt"); // �ܾ� ����� �ִ� �ؽ�Ʈ ����
	string word;

	int score = 0;
	while (file >> word) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << word << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		if (isInputTimedOut()) {
			// 3�ʰ� ������
			cout << "�ð� �ʰ�!" << endl;
			// �ȳ��� ���
			cout << endl;
		}
		else {
			string input;
			getline(cin, input);

			if (!input.empty() && input != word) {
				// ��Ÿ�� ������
				cout << "��Ÿ!" << endl;
				// �ȳ��� ���
				cout << endl;
			}
			else {
				// 3�� �ȿ� ��Ÿ ���� �Է��ϸ�
				score++;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
				cout << "���� +1" << endl;
				// 1�� �߰�
				cout << endl;
			}
		}

		this_thread::sleep_for(chrono::seconds(1)); // 1�� ���
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << "���� ��!\n���� ����: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	cout << score << endl;
}