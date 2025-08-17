#include "bank.h" 

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std; 

Person::Person(string id, string password, string name, int balance) {
	ID = id;
	PWD = password;
	Name = name;
	Balance = balance; 
}

string Person::getID() {
	return ID; 
}

string Person::getName() {
	return Name; 
}

int Person::getBalance() {
	return Balance; 
}

void Person::loginExistingMember() {
	string id, password; 
	bool login_flag = false; 

	while (!login_flag) {
		cout << "Enter ID: "; 
		cin >> id; 
	
		FILE* fp = fopen((id + ".txt").c_str(), "r"); // ���̵�� �� ���� ����

		// ID�� �� file�� ������ ��� -> ��й�ȣ match 
		if (fp != NULL) {
			char fileID[100], filePWD[100], filename[100];
			int filebalance = 0; 
			fgets(fileID, 100, fp);
			fgets(filePWD, 100, fp);
			fgets(filename, 100, fp); 
			fscanf(fp, "%d", &filebalance); 
			fclose(fp);

			// ���� ���� ����
			fileID[strlen(fileID) - 1] = '\0';
			filePWD[strlen(filePWD) - 1] = '\0';
			filename[strlen(filename) - 1] = '\0'; 

			cout << "Enter password: ";
			cin >> password; 
			
			// ��й�ȣ�� ���� �� ���� �޽��� ��� & ��� ������ update
			if (password == filePWD) {
				cout << "Login succssful!" << endl; 
				cout << "Welcom back to SJ bank, " << filename << "!!" << endl; 
				ID = fileID;
				PWD = filePWD; 
				Name = filename; 
				Balance = filebalance;
				login_flag = true; 
			}
			else {
				cout << "Incorrect password. Please try again" << endl; 
			}
		}
		// ���� ã�⿡ ������ ��� 
		else {
			cout << "ID not found. Please enter correct ID" << endl; 
		}
	}
}

void Person::createNewMember() {
	string id, password, again, name; 
	bool create_flag = false; 
	
	// �̸��� ID �Է¹ޱ� 
	cout << "Enter your name: ";
	cin >> name;

	cout << "Enter a new ID: ";
	cin >> id;

	// ��й�ȣ�� 2�� ���� ������ �ݺ� 
	while (!create_flag) {
		cout << "Enter a password: ";
		cin >> password;

		cout << "Enter a password again: ";
		cin >> again;

		if (password == again) {
			create_flag = true; 
			Person newMember(id, password, name, 0); 
			newMember.saveToFile(); 
		}
		else {
			cout << "Incorrect password. Try again." << endl; 
		}
	}
	cout << "Create New Membership successful. Welcome to SJ Bank!" << endl;
}

void Person::saveToFile() {
	// ID�� �� ���� �̸��� ���� ���� �����ϱ�
	FILE* fout = fopen((ID + ".txt").c_str(), "w"); // "w" ���� ���� ����
	if (fout != NULL) {
		fprintf(fout, "%s\n", ID.c_str());
		fprintf(fout, "%s\n", PWD.c_str());
		fprintf(fout, "%s\n", Name.c_str());
		fprintf(fout, "%d\n", Balance); 
		fclose(fout);
	}
	else {
		cout << "Error: Unable to create file" << endl;
	}
}

void Person::setBalance(int money) {
	Balance = money; 
}