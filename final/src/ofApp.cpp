#include "ofApp.h"
#include "string.h"

using namespace std; 

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255); 
	initial_screen_flag = true; 

	// coinGame 이미지 로드
	miningImage1.load("mining01.png");
	miningImage2.load("mining02.png");

	// spaceGame 이미지 및 세팅 
	spaceshipImage.load("spaceship.png");
	spaceshipWidth = 200;
	spaceshipHeight = 200;
	spaceshipImage.resize(spaceshipWidth, spaceshipHeight);

	spaceshipX = (ofGetWidth() - spaceshipWidth) / 2;
	spaceshipY = ofGetHeight() - 400;

	asteroidImage.load("asteroid.png");
	moneyImage.load("money.png");
	asteroidImage.resize(100, 100);
	moneyImage.resize(100, 100); 

}

//--------------------------------------------------------------
void ofApp::update(){
	if (space_flag) {
		spaceGame(); 
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	// 맨 처음 로그인 화면 
	if (initial_screen_flag) {
		// SJ Bank 텍스트를 화면 중앙에 출력
		myFont.load("Merriweather-Bold.ttf", 70);

		ofSetColor(0, 108, 206);
		string text = "SJ Bank";
		float textWidth = myFont.stringWidth(text); // 텍스트의 너비 계산
		myFont.drawString(text, ofGetWidth() / 2 - textWidth / 2, ofGetHeight() / 2 - 70);

		// 안내사항 출력
		ofSetColor(0);
		myFont.load("Merriweather-Bold.ttf", 20);
		text = "if you have ID, press '1' and login";
		textWidth = myFont.stringWidth(text); // 텍스트의 너비 계산
		myFont.drawString(text, ofGetWidth() / 2 - textWidth / 2, ofGetHeight() / 2 - 33);

		text = "if you don't have ID, press '2' and make the new membership";
		textWidth = myFont.stringWidth(text); // 텍스트의 너비 계산
		myFont.drawString(text, ofGetWidth() / 2 - textWidth / 2, ofGetHeight() / 2 - 5);
	}

	if (login_flag) { // 로그인 성공 시 출력되는 화면 
		ofSetColor(0, 108, 206);
		// 위아래 테두리 그리기
		ofDrawRectangle(0, 0, ofGetWidth(), 100);
		ofDrawRectangle(0, ofGetHeight() - 100, ofGetWidth(), 100);

		ofSetColor(0); 
		myFont.load("Merriweather-Bold.ttf", 30);
		// 이름 출력 
		string yourname = person.getName() + "'s balance is"; 
		myFont.drawString(yourname, 50, 250); 
		// 잔액 출력 
		myFont.load("Merriweather-Bold.ttf", 100);
		string yourbalance = to_string(person.getBalance());
		float balanceWidth = myFont.stringWidth(yourbalance);
		myFont.drawString(yourbalance, (ofGetWidth() / 2) - (balanceWidth / 2), 400);

		// 분리선 그리기
		ofSetColor(0, 108, 206);
		ofSetLineWidth(70); 
		ofDrawLine(0, 600, 900, 600); 

		/* ----- 돈 벌기 미니 게임 ----- */
		ofSetColor(0);
		myFont.load("Merriweather-Bold.ttf", 30);
		myFont.drawString("If you want to get money??", 50, 800);
		myFont.drawString("Coin Mining Game: Press '3' ", 50, 870);
		myFont.drawString("Spaceship Game: Press '4' ", 50, 940);
	}

	

	if (coin_flag) { // coin_flag가 true면 coinMiningGame 실행 
		coinMiningGame(); 
	}

	if (space_flag) { // space_flag가 true면 space 그리기 
		drawSpace(); 
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == '1') { 
		person.loginExistingMember(); // 기존 회원 로그인
		login_flag = true; 
		initial_screen_flag = false; 
	}
	if (key == '2') {
		person.createNewMember(); // 새로운 회원 회원가입 
	}
	if (key == '3') { // coin mining game 실행 
		login_flag = false; 
		initial_screen_flag = false; 
		space_flag = false; 
		coin_flag = true; 
	}
	if (key == '4') { // space game 실행 
		login_flag = false; 
		initial_screen_flag = false;
		coin_flag = false; 
		space_flag = true; 
		resetSpace(); 
	}
	if (key == 'q') { // 현재 정보들을 저장하고 종료 
		person.saveToFile();
		_Exit(0); 
	}


	// ---- Coin Mining Game -------
	if (coin_flag && key == ' ') {
		// 한 번 누를 때마다 10원씩 얻음 
		person.setBalance(person.getBalance() + 10);  
		// 한 번 space 누를 때마다 이미지를 바꾸게 하기 위해서
		if (mining == 0) {
			mining = 1;
		}
		else if (mining == 1) {
			mining = 0;
		}
	}
	if (key == 'w' && coin_flag) { // bank 화면으로 돌아오기 
		coin_flag = false;
		login_flag = true;
		person.saveToFile();
	}

	
	// ---- Space Game ----
	if (key == 'r' && isSpaceOver) { // space game reset 
		resetSpace();
	}
	if (key == 'w' && space_flag) { // bank 화면으로 돌아오기 
		space_flag = false;
		login_flag = true;
		person.saveToFile();
		ofBackground(255);
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}


/* ---- 코인 채굴 게임 ---- */ 
void ofApp::coinMiningGame() {
	ofSetColor(255); // Ensure the background is white before drawing images
	if (mining == 0) {
		miningImage1.draw(0, 0, ofGetWidth(), ofGetHeight());
	}
	else {
		miningImage2.draw(0, 0, ofGetWidth(), ofGetHeight());
	}

	// 잔액 표시 
	ofSetColor(0);
	myFont.load("Merriweather-Bold.ttf", 30);
	string current_balance = "Current Balance: " + to_string(person.getBalance());
	myFont.drawString(current_balance, 50, 100);

	// 게임 방법 소개 
	myFont.load("Merriweather-Bold.ttf", 24);
	myFont.drawString("Press 'space' to earn 10 coins", 50, 200);
	myFont.drawString("Press 'w' to exit", 50, 250);
}



/* ----- Space Game ----- */
void ofApp::spaceGame() {
	if (!isSpaceOver) {
		ofBackground(20); 

		// spaceship은 좌우로만 움직일 수 있음 
		if (ofGetKeyPressed(OF_KEY_LEFT)) {
			spaceshipX -= spaceshipHandle; 
		}
		if (ofGetKeyPressed(OF_KEY_RIGHT)) {
			spaceshipX += spaceshipHandle;
		}

		// spaceship 화면 경계 체크 
		if (spaceshipX < 0) { // 왼쪽 방향 체크 
			spaceshipX = 0;
		}
		if (spaceshipX > ofGetWidth() - spaceshipImage.getWidth()) { // 오른쪽 방향 체크 
			spaceshipX = ofGetWidth() - spaceshipImage.getWidth();
		}

		// asteroid와 money 위치 업데이트 
		for (auto& asteroid : Asteroid) {
			asteroid.y += asteroidSpeed; 
			if (asteroid.y > ofGetHeight()) {
				asteroid.y = ofRandom(-1000, 0);
				asteroid.x = ofRandom(0, ofGetHeight() - asteroidImage.getWidth());
			}
		}
		for (auto& money : Money) {
			money.y += moneySpeed;
			if (money.y > ofGetHeight()) {
				money.y = ofRandom(-1000, 0);
				money.x = ofRandom(0, ofGetWidth() - moneyImage.getWidth());
			}
		}

		checkSpace();
	}
}

void ofApp::drawSpace() {
	ofSetColor(255);

	if (isSpaceOver) { // game over 됐을 때 출력 
		myFont.load("Merriweather-Bold.ttf", 70);
		myFont.drawString("Game Over!", 150, 700);
		myFont.load("Merriweather-Bold.ttf", 35);
		myFont.drawString("Play Again: Press 'r'", 150, 800);
		myFont.drawString("Exit to Bank: Press 'w'", 150, 880);
		return; 
	}

	// spaceship 그리기 
	spaceshipImage.draw(spaceshipX, spaceshipY);
	
	// item들 그리기 
	for (const auto& asteroid : Asteroid) {
		asteroidImage.draw(asteroid.x, asteroid.y);
	}

	for (const auto& money : Money) {
		moneyImage.draw(money.x, money.y);
	}

	// 잔액 출력 
	ofSetColor(255);
	myFont.load("Merriweather-Bold.ttf", 30);
	string current_balance = "Current Balance: " + to_string(person.getBalance());
	myFont.drawString(current_balance, 50, 100);

}

void ofApp::checkSpace() {
	// spaceshipRect을 생성해서 이미지가 겹치는지 안 겹치는지 확인 
	ofRectangle spaceshipRect(spaceshipX, spaceshipY, spaceshipImage.getWidth(), spaceshipImage.getHeight());

	for (const auto& asteroid : Asteroid) {
		ofRectangle asteroidRect(asteroid.x, asteroid.y, asteroidImage.getWidth(), asteroidImage.getHeight());
		if (spaceshipRect.intersects(asteroidRect)) { // 소행성 이미지와 겹치면 -> game over 
			isSpaceOver = true;
			return;
		}
	}

	for (auto& money : Money) {
		ofRectangle moneyRect(money.x, money.y, moneyImage.getWidth(), moneyImage.getHeight());
		if (spaceshipRect.intersects(moneyRect)) {
			person.setBalance(person.getBalance() + 1000);  // 코인 이미지와 겹치면 -> 1000원 획득
			// 돈이 화면 밖으로 벗어나면 다시 생성
			money.y = ofRandom(-1000, 0);
			money.x = ofRandom(0, ofGetWidth() - moneyImage.getWidth());
		}
	}
}

void ofApp::resetSpace() { // game reset 
	// 초기 우주선 위치 다시 초기화 
	spaceshipX = (ofGetWidth() - spaceshipWidth) / 2;
	spaceshipY = ofGetHeight() - 400;

	isSpaceOver = false; 
	Asteroid.clear();
	Money.clear();

	// 랜덤하게 위치를 설정해서 벡터에 넣기 -> 추후 for문을 통해서 사용 
	for (int i = 0; i < 5; ++i) {
		Asteroid.push_back(ofVec2f(ofRandom(0, ofGetWidth() - asteroidImage.getWidth()), ofRandom(-1000, 0)));
		Money.push_back(ofVec2f(ofRandom(0, ofGetWidth() - moneyImage.getWidth()), ofRandom(-1000, 0)));
	}
}