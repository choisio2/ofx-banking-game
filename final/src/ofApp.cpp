#include "ofApp.h"
#include "string.h"

using namespace std; 

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255); 
	initial_screen_flag = true; 

	// coinGame �̹��� �ε�
	miningImage1.load("mining01.png");
	miningImage2.load("mining02.png");

	// spaceGame �̹��� �� ���� 
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
	// �� ó�� �α��� ȭ�� 
	if (initial_screen_flag) {
		// SJ Bank �ؽ�Ʈ�� ȭ�� �߾ӿ� ���
		myFont.load("Merriweather-Bold.ttf", 70);

		ofSetColor(0, 108, 206);
		string text = "SJ Bank";
		float textWidth = myFont.stringWidth(text); // �ؽ�Ʈ�� �ʺ� ���
		myFont.drawString(text, ofGetWidth() / 2 - textWidth / 2, ofGetHeight() / 2 - 70);

		// �ȳ����� ���
		ofSetColor(0);
		myFont.load("Merriweather-Bold.ttf", 20);
		text = "if you have ID, press '1' and login";
		textWidth = myFont.stringWidth(text); // �ؽ�Ʈ�� �ʺ� ���
		myFont.drawString(text, ofGetWidth() / 2 - textWidth / 2, ofGetHeight() / 2 - 33);

		text = "if you don't have ID, press '2' and make the new membership";
		textWidth = myFont.stringWidth(text); // �ؽ�Ʈ�� �ʺ� ���
		myFont.drawString(text, ofGetWidth() / 2 - textWidth / 2, ofGetHeight() / 2 - 5);
	}

	if (login_flag) { // �α��� ���� �� ��µǴ� ȭ�� 
		ofSetColor(0, 108, 206);
		// ���Ʒ� �׵θ� �׸���
		ofDrawRectangle(0, 0, ofGetWidth(), 100);
		ofDrawRectangle(0, ofGetHeight() - 100, ofGetWidth(), 100);

		ofSetColor(0); 
		myFont.load("Merriweather-Bold.ttf", 30);
		// �̸� ��� 
		string yourname = person.getName() + "'s balance is"; 
		myFont.drawString(yourname, 50, 250); 
		// �ܾ� ��� 
		myFont.load("Merriweather-Bold.ttf", 100);
		string yourbalance = to_string(person.getBalance());
		float balanceWidth = myFont.stringWidth(yourbalance);
		myFont.drawString(yourbalance, (ofGetWidth() / 2) - (balanceWidth / 2), 400);

		// �и��� �׸���
		ofSetColor(0, 108, 206);
		ofSetLineWidth(70); 
		ofDrawLine(0, 600, 900, 600); 

		/* ----- �� ���� �̴� ���� ----- */
		ofSetColor(0);
		myFont.load("Merriweather-Bold.ttf", 30);
		myFont.drawString("If you want to get money??", 50, 800);
		myFont.drawString("Coin Mining Game: Press '3' ", 50, 870);
		myFont.drawString("Spaceship Game: Press '4' ", 50, 940);
	}

	

	if (coin_flag) { // coin_flag�� true�� coinMiningGame ���� 
		coinMiningGame(); 
	}

	if (space_flag) { // space_flag�� true�� space �׸��� 
		drawSpace(); 
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == '1') { 
		person.loginExistingMember(); // ���� ȸ�� �α���
		login_flag = true; 
		initial_screen_flag = false; 
	}
	if (key == '2') {
		person.createNewMember(); // ���ο� ȸ�� ȸ������ 
	}
	if (key == '3') { // coin mining game ���� 
		login_flag = false; 
		initial_screen_flag = false; 
		space_flag = false; 
		coin_flag = true; 
	}
	if (key == '4') { // space game ���� 
		login_flag = false; 
		initial_screen_flag = false;
		coin_flag = false; 
		space_flag = true; 
		resetSpace(); 
	}
	if (key == 'q') { // ���� �������� �����ϰ� ���� 
		person.saveToFile();
		_Exit(0); 
	}


	// ---- Coin Mining Game -------
	if (coin_flag && key == ' ') {
		// �� �� ���� ������ 10���� ���� 
		person.setBalance(person.getBalance() + 10);  
		// �� �� space ���� ������ �̹����� �ٲٰ� �ϱ� ���ؼ�
		if (mining == 0) {
			mining = 1;
		}
		else if (mining == 1) {
			mining = 0;
		}
	}
	if (key == 'w' && coin_flag) { // bank ȭ������ ���ƿ��� 
		coin_flag = false;
		login_flag = true;
		person.saveToFile();
	}

	
	// ---- Space Game ----
	if (key == 'r' && isSpaceOver) { // space game reset 
		resetSpace();
	}
	if (key == 'w' && space_flag) { // bank ȭ������ ���ƿ��� 
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


/* ---- ���� ä�� ���� ---- */ 
void ofApp::coinMiningGame() {
	ofSetColor(255); // Ensure the background is white before drawing images
	if (mining == 0) {
		miningImage1.draw(0, 0, ofGetWidth(), ofGetHeight());
	}
	else {
		miningImage2.draw(0, 0, ofGetWidth(), ofGetHeight());
	}

	// �ܾ� ǥ�� 
	ofSetColor(0);
	myFont.load("Merriweather-Bold.ttf", 30);
	string current_balance = "Current Balance: " + to_string(person.getBalance());
	myFont.drawString(current_balance, 50, 100);

	// ���� ��� �Ұ� 
	myFont.load("Merriweather-Bold.ttf", 24);
	myFont.drawString("Press 'space' to earn 10 coins", 50, 200);
	myFont.drawString("Press 'w' to exit", 50, 250);
}



/* ----- Space Game ----- */
void ofApp::spaceGame() {
	if (!isSpaceOver) {
		ofBackground(20); 

		// spaceship�� �¿�θ� ������ �� ���� 
		if (ofGetKeyPressed(OF_KEY_LEFT)) {
			spaceshipX -= spaceshipHandle; 
		}
		if (ofGetKeyPressed(OF_KEY_RIGHT)) {
			spaceshipX += spaceshipHandle;
		}

		// spaceship ȭ�� ��� üũ 
		if (spaceshipX < 0) { // ���� ���� üũ 
			spaceshipX = 0;
		}
		if (spaceshipX > ofGetWidth() - spaceshipImage.getWidth()) { // ������ ���� üũ 
			spaceshipX = ofGetWidth() - spaceshipImage.getWidth();
		}

		// asteroid�� money ��ġ ������Ʈ 
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

	if (isSpaceOver) { // game over ���� �� ��� 
		myFont.load("Merriweather-Bold.ttf", 70);
		myFont.drawString("Game Over!", 150, 700);
		myFont.load("Merriweather-Bold.ttf", 35);
		myFont.drawString("Play Again: Press 'r'", 150, 800);
		myFont.drawString("Exit to Bank: Press 'w'", 150, 880);
		return; 
	}

	// spaceship �׸��� 
	spaceshipImage.draw(spaceshipX, spaceshipY);
	
	// item�� �׸��� 
	for (const auto& asteroid : Asteroid) {
		asteroidImage.draw(asteroid.x, asteroid.y);
	}

	for (const auto& money : Money) {
		moneyImage.draw(money.x, money.y);
	}

	// �ܾ� ��� 
	ofSetColor(255);
	myFont.load("Merriweather-Bold.ttf", 30);
	string current_balance = "Current Balance: " + to_string(person.getBalance());
	myFont.drawString(current_balance, 50, 100);

}

void ofApp::checkSpace() {
	// spaceshipRect�� �����ؼ� �̹����� ��ġ���� �� ��ġ���� Ȯ�� 
	ofRectangle spaceshipRect(spaceshipX, spaceshipY, spaceshipImage.getWidth(), spaceshipImage.getHeight());

	for (const auto& asteroid : Asteroid) {
		ofRectangle asteroidRect(asteroid.x, asteroid.y, asteroidImage.getWidth(), asteroidImage.getHeight());
		if (spaceshipRect.intersects(asteroidRect)) { // ���༺ �̹����� ��ġ�� -> game over 
			isSpaceOver = true;
			return;
		}
	}

	for (auto& money : Money) {
		ofRectangle moneyRect(money.x, money.y, moneyImage.getWidth(), moneyImage.getHeight());
		if (spaceshipRect.intersects(moneyRect)) {
			person.setBalance(person.getBalance() + 1000);  // ���� �̹����� ��ġ�� -> 1000�� ȹ��
			// ���� ȭ�� ������ ����� �ٽ� ����
			money.y = ofRandom(-1000, 0);
			money.x = ofRandom(0, ofGetWidth() - moneyImage.getWidth());
		}
	}
}

void ofApp::resetSpace() { // game reset 
	// �ʱ� ���ּ� ��ġ �ٽ� �ʱ�ȭ 
	spaceshipX = (ofGetWidth() - spaceshipWidth) / 2;
	spaceshipY = ofGetHeight() - 400;

	isSpaceOver = false; 
	Asteroid.clear();
	Money.clear();

	// �����ϰ� ��ġ�� �����ؼ� ���Ϳ� �ֱ� -> ���� for���� ���ؼ� ��� 
	for (int i = 0; i < 5; ++i) {
		Asteroid.push_back(ofVec2f(ofRandom(0, ofGetWidth() - asteroidImage.getWidth()), ofRandom(-1000, 0)));
		Money.push_back(ofVec2f(ofRandom(0, ofGetWidth() - moneyImage.getWidth()), ofRandom(-1000, 0)));
	}
}