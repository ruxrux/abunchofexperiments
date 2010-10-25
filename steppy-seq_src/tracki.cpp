/*
 *  tracki.cpp
 *  steppySeq
 *
 *  Created by rux on 8/8/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "tracki.h"

// --------------------------------------------------------
void tracki::setup(){

	stepSound.loadSound(stepSoundName, true);
	bPlayOnce = true;
	
	for(int i =0; i < 16; i++){
		stepButton temp;
		stepB.push_back(temp);
		stepB[i].setup();
		stepB[i].rect.y = tPos.y;
		stepB[i].rect.x = tPos.x +i*20;
	}
	

}


// --------------------------------------------------------
void tracki::update(int _step){
	for(int i =0; i< 16; i++){
		stepB[i].update();
		if(stepB[i].bActive == true && _step == i && bPlayOnce){
			if(bPlayOnce){
				stepSound.setSpeed(1.0f);
				stepSound.play();
				bPlayOnce = false;
			}
			
		}
	}
}


// --------------------------------------------------------
void tracki::draw(){
	for(int i =0; i< 16; i++){
		stepB[i].draw();
	}
}


// --------------------------------------------------------
void tracki::mouseDown(int x, int y){
	for(int i =0; i< 16; i++){
		stepB[i].mouseDown(x, y);
	}
}