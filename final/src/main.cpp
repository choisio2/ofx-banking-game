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
	// ���α׷� �ʱ�ȭ
	ofSetupOpenGL(900, 1400, OF_WINDOW); // â ũ�� ���� (�ʺ� 900, ���� 1400, ������ ���)

	// ���ø����̼� �ν��Ͻ� ���� �� ����
	ofRunApp(new ofApp());

	// ���α׷� ����
	return 0;
}
