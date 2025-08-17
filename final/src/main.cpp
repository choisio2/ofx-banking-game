#include "ofMain.h"
#include "ofApp.h"
#include "bank.h""
#include <stdio.h>


//========================================================================
int main( ){
	/*
	//Use ofGLFWWindowSettings for more options like multi-monitor fullscreen
	ofGLWindowSettings settings;
	settings.setSize(900, 1400);
	settings.windowMode = OF_WINDOW; //can also be OF_FULLSCREEN

	auto window = ofCreateWindow(settings);

	ofRunApp(window, make_shared<ofApp>());
	ofRunMainLoop();
	*/
	// 프로그램 초기화
	ofSetupOpenGL(900, 1400, OF_WINDOW); // 창 크기 설정 (너비 900, 높이 1400, 윈도우 모드)

	// 애플리케이션 인스턴스 생성 및 실행
	ofRunApp(new ofApp());

	// 프로그램 종료
	return 0;
}
