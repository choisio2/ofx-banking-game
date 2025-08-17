#pragma once

#include "ofMain.h"
#include "bank.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);


		// ---- ���� ���� ----
		ofTrueTypeFont myFont; // �۾��� ���� ��Ʈ 
		Person person; // ���� ����� 

		// flag -> � â�� ����� ���� 
		bool initial_screen_flag = false; 
		bool login_flag = false; 
		bool coin_flag = false; 
		bool space_flag = false; 
		
		// ���� ä�� ���� 
		void coinMiningGame(); 
		ofImage miningImage1; // ���� �̹���1
		ofImage miningImage2; // ���� �̹���2
		int mining = 0; // �̹����� ���ɾƼ� ���� ���� ���� 


		// ���� ����
		void spaceGame(); // ������ �ݺ��ϴ� �Լ� -> update���� ȣ�� 
		void drawSpace(); // ���ּ��� item, gameover �ȳ� �޼��� ���� ���� �Լ� -> draw���� ȣ�� 
		void checkSpace(); // money�� �Ծ����� 
		void resetSpace(); // ���ְ��� �ʱ� ���� 

		ofImage spaceshipImage; // ���ּ� �̹��� 
		int spaceshipWidth; // ���ּ� �̹��� �ʺ�
		int spaceshipHeight; // ���ּ� �̹��� ���� 
		double spaceshipX; // ���ּ��� x�� ��ġ
		double spaceshipY; // ���ּ��� y�� ��ġ
		double spaceshipHandle = 40; // ���ּ��� �¿�� �����̴� �ӵ� 
		bool isSpaceOver = false; // ������ �������� Ȯ���ϴ� flag

		// item: ���༺, ��
		ofImage asteroidImage; // ���༺ �̹��� 
		ofImage moneyImage; // �� �̹��� ���� 
		vector<ofVec2f> Asteroid; // ���༺�� ��ġ�� �����ϴ� ����
		vector<ofVec2f> Money; // ���� ��ġ�� �����ϴ� ���� 
		double asteroidSpeed = 20; // ���༺�� �Ʒ��� �����̴� �ӵ�
		double moneySpeed = 20; // ���� �Ʒ��� �����̴� �ӵ� 


};
