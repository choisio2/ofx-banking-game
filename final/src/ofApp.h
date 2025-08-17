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


		// ---- 새로 만든 ----
		ofTrueTypeFont myFont; // 글씨를 쓰는 폰트 
		Person person; // 현재 사용자 

		// flag -> 어떤 창을 띄울지 결정 
		bool initial_screen_flag = false; 
		bool login_flag = false; 
		bool coin_flag = false; 
		bool space_flag = false; 
		
		// 코인 채굴 게임 
		void coinMiningGame(); 
		ofImage miningImage1; // 광부 이미지1
		ofImage miningImage2; // 광부 이미지2
		int mining = 0; // 이미지를 번걸아서 띄우기 위한 변수 


		// 우주 게임
		void spaceGame(); // 게임을 반복하는 함수 -> update에서 호출 
		void drawSpace(); // 우주선과 item, gameover 안내 메세지 등을 띄우는 함수 -> draw에서 호출 
		void checkSpace(); // money를 먹었는지 
		void resetSpace(); // 우주게임 초기 세팅 

		ofImage spaceshipImage; // 우주선 이미지 
		int spaceshipWidth; // 우주선 이미지 너비
		int spaceshipHeight; // 우주선 이미지 높이 
		double spaceshipX; // 우주선의 x축 위치
		double spaceshipY; // 우주선의 y축 위치
		double spaceshipHandle = 40; // 우주선이 좌우로 움직이는 속도 
		bool isSpaceOver = false; // 게임이 끝났는지 확인하는 flag

		// item: 소행성, 돈
		ofImage asteroidImage; // 소행성 이미지 
		ofImage moneyImage; // 돈 이미지 띄우기 
		vector<ofVec2f> Asteroid; // 소행성의 위치를 저장하는 벡터
		vector<ofVec2f> Money; // 돈의 위치를 저장하는 벡터 
		double asteroidSpeed = 20; // 소행성이 아래로 움직이는 속도
		double moneySpeed = 20; // 돈이 아래로 움직이는 속도 


};
