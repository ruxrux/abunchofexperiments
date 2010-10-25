#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	w = ofGetScreenWidth();
	h = ofGetScreenHeight();
	rTimer		= 0;
	diffTime	= aTimer;
	bpm			= 120;
	step		= 0;
	
	nTracks = soundBank.listDir("SoundBank");
	cout << nTracks << endl;
	
	for(int i =0; i< nTracks; i++){
		tracki tempTrack;
		track.push_back(tempTrack);
		track[i].tPos.set(15, 20 + i*25);
		track[i].stepSoundName = soundBank.getPath(i);
		track[i].setup();
	}
}

//--------------------------------------------------------------
void testApp::update(){
	ofBackground(0,0,0);
	aTimer = ofGetElapsedTimeMillis();
	rTimer = aTimer - diffTime;
	
	float bpMillis;
	bpMillis = (bpm / 60.0f)*1000;
	float beatPulse;
	beatPulse = (60.0f / bpm/4) * 1000;
	

	if (rTimer > beatPulse){
		
		for(int i =0; i< nTracks; i++){
			track[i].bPlayOnce = true;
		}
		
		diffTime = aTimer;
		step ++;
		if(step == 16) step= 0;
	}
	
	for(int i =0; i< nTracks; i++){
		track[i].update(step);
	}
	
}

//--------------------------------------------------------------
void testApp::draw(){
	for(int i =0; i< nTracks; i++){
		track[i].draw();
	}
	
	ofFill();
	ofSetColor(130, 130, 130);
	ofRect(15 + step * 20, 10, 15, 5);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	for(int i =0; i< nTracks; i++){
		track[i].mouseDown(x, y);
	}
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

