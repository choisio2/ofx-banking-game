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
	
		FILE* fp = fopen((id + ".txt").c_str(), "r"); // 아이디로 된 파일 열기

		// ID로 된 file이 존재할 경우 -> 비밀번호 match 
		if (fp != NULL) {
			char fileID[100], filePWD[100], filename[100];
			int filebalance = 0; 
			fgets(fileID, 100, fp);
			fgets(filePWD, 100, fp);
			fgets(filename, 100, fp); 
			fscanf(fp, "%d", &filebalance); 
			fclose(fp);

			// 개행 문자 제거
			fileID[strlen(fileID) - 1] = '\0';
			filePWD[strlen(filePWD) - 1] = '\0';
			filename[strlen(filename) - 1] = '\0'; 

			cout << "Enter password: ";
			cin >> password; 
			
			// 비밀번호가 맞을 시 성공 메시지 출력 & 멤버 변수들 update
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
		// 파일 찾기에 실패한 경우 
		else {
			cout << "ID not found. Please enter correct ID" << endl; 
		}
	}
}

void Person::createNewMember() {
	string id, password, again, name; 
	bool create_flag = false; 
	
	// 이름과 ID 입력받기 
	cout << "Enter your name: ";
	cin >> name;

	cout << "Enter a new ID: ";
	cin >> id;

	// 비밀번호가 2번 맞을 때까지 반복 
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
	// ID로 된 파일 이름을 가진 파일 생성하기
	FILE* fout = fopen((ID + ".txt").c_str(), "w"); // "w" 모드로 파일 열기
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