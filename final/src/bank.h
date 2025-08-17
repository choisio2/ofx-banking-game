#pragma once

#include "ofMain.h"


class Person {
private:
	string ID; // 아이디
	string PWD; // 비밀번호
	string Name; // 이름 
	int Balance; // 잔액

public:
	Person() { // 기본 초기 생성자
		ID = "";
		PWD = "";
		Name = "";
		Balance = 0; 
	}

	Person(string id, string password, string name, int balance); // 새로운 멤버의 정보를 저장하기 위한 생성자 

	string getID(); // ID 얻는 함수 
	string getName(); // Name 얻는 함수 
	int getBalance(); // Balance 얻는 함수 
	void loginExistingMember(); // 기존 회원 로그인
	void createNewMember(); // 새로운 회원 정보 생성하기 
	void saveToFile(); // 새로운 회원의 정보를 새로운 파일에 저장
	void setBalance(int money); // Balance 새로 업데이트 하는 함수 

};

