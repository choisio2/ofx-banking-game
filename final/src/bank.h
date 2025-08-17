#pragma once

#include "ofMain.h"


class Person {
private:
	string ID; // ���̵�
	string PWD; // ��й�ȣ
	string Name; // �̸� 
	int Balance; // �ܾ�

public:
	Person() { // �⺻ �ʱ� ������
		ID = "";
		PWD = "";
		Name = "";
		Balance = 0; 
	}

	Person(string id, string password, string name, int balance); // ���ο� ����� ������ �����ϱ� ���� ������ 

	string getID(); // ID ��� �Լ� 
	string getName(); // Name ��� �Լ� 
	int getBalance(); // Balance ��� �Լ� 
	void loginExistingMember(); // ���� ȸ�� �α���
	void createNewMember(); // ���ο� ȸ�� ���� �����ϱ� 
	void saveToFile(); // ���ο� ȸ���� ������ ���ο� ���Ͽ� ����
	void setBalance(int money); // Balance ���� ������Ʈ �ϴ� �Լ� 

};

