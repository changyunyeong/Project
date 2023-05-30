#include "English.h"

English::English() {	
	word = "";			
	input = "";		
	cnt = 0;			
	line = "";
	totalWord = 0.0;
	progress = 0.0;
	wordCnt = 0;
	//accuracy = 0.0;
	totalTypos = 0;
	average = 0.0;
	totalKeystrokes = 0;
	averages = 0;
}

void English::wordE() {
	cin.ignore();			// ���� �ִ� ���� ����
	ifstream file("word.txt");
	auto startTime = chrono::steady_clock::now();			// ���� �ð� ����

	while (getline(file, line)) {
		totalWord++;
	}
	file.clear();			// ���� ���� �ʱ�ȭ
	file.seekg(0);			// ���� ���� �������� �̵�

	while (getline(file, word)) {
		cnt = 0;			// �ܾ� �ٲ� ������ �ʱ�ȭ
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << word << endl;			// �ܾ� ���
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		getline(cin, input);			// �ܾ� �Է�
		cout << endl;

		wordCnt++;			// ���Ͽ��� ���� ������ �� ����

		if (input.length() != word.length()) {
			cnt += abs(static_cast<int>(input.length()) - static_cast<int>(word.length()));	
			// �Էµ� �ܾ�� ���� �ܾ��� ���� ���̸� ��Ÿ�� ó��
		}

		for (int i = 0; i < word.length(); i++) {
			if (i < input.length() && input[i] != word[i]) {
				cnt++;		
				// �Էµ� �ܾ�� ���� �ܾ��� �� ���ڸ� ���ϸ� �ٸ� ��� ��Ÿ�� ó��
			}
		}

		totalTypos += cnt;		// ��Ÿ �� ����
		totalKeystrokes += input.length();

		accuracy = (static_cast<double>(word.length() - totalTypos) / static_cast<double>(word.length())) * 100.0;
		// �ܾ��� ���̿��� ��Ÿ���� �� ���� ��ü �ܾ��� ������ ������ 100�� ���� ��Ȯ���� ����
		if (wordCnt % 4 == 0) {			// 4�� ����� �Ǹ�
			cout << "Typos: " << totalTypos << endl;
			cout << "Accuracy: " << accuracy << "%" << endl;
			// ��Ÿ��, ��Ȯ�� ���

			progress = static_cast<double>(wordCnt) / static_cast<double>(totalWord) * 100.0;
			cout << "Progress: " << progress << "%" << endl;			// �����Ȳ ���

			auto endTime = chrono::steady_clock::now();			// ������ �ð� ����
			auto elaspedTime = chrono::duration_cast<chrono::seconds>(endTime - startTime).count();
			// ���� �ð����� ������ �ð��� �� �Է��ϴµ� �ɸ� �ð� ���
			cout << "Elasped Time: " << elaspedTime << endl;

			averages = ((static_cast<double>(totalKeystrokes)) * 60.0) / elaspedTime;
			cout<<"Avg Keystrokes: "<< averages << endl;

			char check = ' ';			// ����� ������ üũ�ϱ� ���� ����

			cout << "Continue? (Y/N): ";
			cin >> check;
			if (check == 'Y' || check == 'y') {			// ����ϰڴٰ� �Է��ϸ�
				cout << endl;			// �� �� ���� �ٽ� ����
				cin.ignore();			// ������ ����
				continue;
			}
			else if (check == 'N' || check == 'n') {			// �����ϰڴٰ� �Է��ϸ�
				return;			// �Լ� ��������
			}
			cnt = 0;
			cout << endl;
		}
	}
}

void English::shortE() {
	cin.ignore();			// ���� �ִ� ���� ����

	ifstream file("short.txt");
	auto startTime = chrono::steady_clock::now();			// ���� �ð� ����

	while (getline(file, line)) {
		totalWord++;
	}
	file.clear();			// ���� ���� �ʱ�ȭ
	file.seekg(0);			// ���� ���� �������� �̵�

	while (getline(file, word)) {
		cnt = 0;			// �ܾ� �ٲ� ������ �ʱ�ȭ
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << word << endl;			// �ܾ� ���
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		getline(cin, input);			// �ܾ� �Է�
		cout << endl;

		wordCnt++;			// ���Ͽ��� ���� ������ �� ����

		if (input.length() != word.length()) {
			cnt += abs(static_cast<int>(input.length()) - static_cast<int>(word.length()));
			// �Էµ� �ܾ�� ���� �ܾ��� ���� ���̸� ��Ÿ�� ó��
		}

		for (int i = 0; i < word.length(); i++) {
			if (i < input.length() && input[i] != word[i]) {
				cnt++;
				// �Էµ� �ܾ�� ���� �ܾ��� �� ���ڸ� ���ϸ� �ٸ� ��� ��Ÿ�� ó��
			}
		}

		totalTypos += cnt;		// ��Ÿ �� ����
		totalKeystrokes += input.length();

		accuracy = (static_cast<double>(word.length() - totalTypos) / static_cast<double>(word.length())) * 100.0;
		// �ܾ��� ���̿��� ��Ÿ���� �� ���� ��ü �ܾ��� ������ ������ 100�� ���� ��Ȯ���� ����
		if (wordCnt % 4 == 0) {			// 4�� ����� �Ǹ�
			cout << "Typos: " << totalTypos << endl;
			cout << "Accuracy: " << accuracy << "%" << endl;
			// ��Ÿ��, ��Ȯ�� ���

			progress = static_cast<double>(wordCnt) / static_cast<double>(totalWord) * 100.0;
			cout << "Progress: " << progress << "%" << endl;			// �����Ȳ ���

			auto endTime = chrono::steady_clock::now();			// ������ �ð� ����
			auto elaspedTime = chrono::duration_cast<chrono::seconds>(endTime - startTime).count();
			// ���� �ð����� ������ �ð��� �� �Է��ϴµ� �ɸ� �ð� ���
			cout << "Elasped Time: " << elaspedTime << endl;

			averages = ((static_cast<double>(totalKeystrokes)) * 60.0) / elaspedTime;
			cout << "Avg Keystrokes: " << averages << endl;

			char check = ' ';			// ����� ������ üũ�ϱ� ���� ����

			cout << "Continue? (Y/N): ";
			cin >> check;
			if (check == 'Y' || check == 'y') {			// ����ϰڴٰ� �Է��ϸ�
				cout << endl;			// �� �� ���� �ٽ� ����
				cin.ignore();			// ������ ����
				continue;
			}
			else if (check == 'N' || check == 'n') {			// �����ϰڴٰ� �Է��ϸ�
				return;			// �Լ� ��������
			}
			cnt = 0;
			cout << endl;
		}
	}
}

void English::longE() {
	cin.ignore();			// ���� �ִ� ���� ����
	int cmd = 0;			// � ������ �������� �Է¹��� ����
	string fileName = "";			// �ش� ��ȣ�� �´� ���� �̸�
	cout << "[1. The Elves and the Shoemaker 2.The Little Prince 3. The Selfish Giant 4. Rapunzel]" << endl;
	cout << "1, 2, 3, 4 In Order: ";
	cin >> cmd;
	
	switch (cmd) {
	case 1:			// 1�� �ԷµǸ�
		fileName = "The Elves and the Shoemaker.txt";			// �ش� ���� ����
		cin.ignore();			// ���� ����
		cout << endl;
		break;
	case 2:
		fileName = "The Little Prince.txt";
		cin.ignore();
		cout << endl;
		break;
	case 3:
		fileName = "The Selfish Giant.txt";
		cin.ignore();
		cout << endl;
		break;
	case 4:
		fileName = "Rapunzel.txt";
		cin.ignore();
		cout << endl;
		break;
	defaut:
		cout << "Enter Again: ";			// �ȳ� ������ ������
		cin >> cmd;			// ���ڸ� �ٽ� �Է¹޵��� ��
		break;
	}

	fstream file(fileName);
	auto startTime = chrono::steady_clock::now();			// ���� �ð� ����

	while (getline(file, line)) {
		totalWord++;
	}
	file.clear();			// ���� ���� �ʱ�ȭ
	file.seekg(0);			// ���� ���� �������� �̵�

	while (getline(file, word)) {
		cnt = 0;			// �ܾ� �ٲ� ������ �ʱ�ȭ
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << word << endl;			// �ܾ� ���
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		getline(cin, input);			// �ܾ� �Է�
		cout << endl;

		wordCnt++;			// ���Ͽ��� ���� ������ �� ����

		if (input.length() != word.length()) {
			cnt += abs(static_cast<int>(input.length()) - static_cast<int>(word.length()));
			// �Էµ� �ܾ�� ���� �ܾ��� ���� ���̸� ��Ÿ�� ó��
		}

		for (int i = 0; i < word.length(); i++) {
			if (i < input.length() && input[i] != word[i]) {
				cnt++;
				// �Էµ� �ܾ�� ���� �ܾ��� �� ���ڸ� ���ϸ� �ٸ� ��� ��Ÿ�� ó��
			}
		}

		totalTypos += cnt;		// ��Ÿ �� ����
		totalKeystrokes += input.length();

		accuracy = (static_cast<double>(word.length() - totalTypos) / static_cast<double>(word.length())) * 100.0;
		// �ܾ��� ���̿��� ��Ÿ���� �� ���� ��ü �ܾ��� ������ ������ 100�� ���� ��Ȯ���� ����
		if (wordCnt % 4 == 0) {			// 4�� ����� �Ǹ�
			cout << "Typos: " << totalTypos << endl;
			cout << "Accuracy: " << accuracy << "%" << endl;
			// ��Ÿ��, ��Ȯ�� ���

			progress = static_cast<double>(wordCnt) / static_cast<double>(totalWord) * 100.0;
			cout << "Progress: " << progress << "%" << endl;			// �����Ȳ ���

			auto endTime = chrono::steady_clock::now();			// ������ �ð� ����
			auto elaspedTime = chrono::duration_cast<chrono::seconds>(endTime - startTime).count();
			// ���� �ð����� ������ �ð��� �� �Է��ϴµ� �ɸ� �ð� ���
			cout << "Elasped Time: " << elaspedTime << endl;

			averages = ((static_cast<double>(totalKeystrokes)) * 60.0) / elaspedTime;
			cout << "Avg Keystrokes: " << averages << endl;

			char check = ' ';			// ����� ������ üũ�ϱ� ���� ����

			cout << "Continue? (Y/N): ";
			cin >> check;
			if (check == 'Y' || check == 'y') {			// ����ϰڴٰ� �Է��ϸ�
				cout << endl;			// �� �� ���� �ٽ� ����
				cin.ignore();			// ������ ����
				continue;
			}
			else if (check == 'N' || check == 'n') {			// �����ϰڴٰ� �Է��ϸ�
				return;			// �Լ� ��������
			}
			cnt = 0;
			cout << endl;
		}
	}
}