/*
 *  stepButton.cpp
 *  steppySeq
 *
 *  Created by rux on 8/6/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "stepButton.h"

// -------------------------------------------
void stepButton::setup() {
	
	rect.x = 0;
	rect.y = 0;
	rect.width = 10;
	rect.height = 20;
	color.x = 90;
	color.y = 90;
	color.z = 90;
	nClicks = 0;
	bActive	= false;
	bClick	= false;
	
	
	
}

// -------------------------------------------
void stepButton::update() {
	if(bActive){
		color.x = 250;
		color.y = 250;
		color.z = 0;
	} else {
		
		color.x = 90;
		color.y = 90;
		color.z = 90;
	}
}


// -------------------------------------------
void stepButton::draw() {
	if(bActive){
		ofFill();
	}else{
		ofNoFill();
	}
	ofSetColor(color.x, color.y, color.z);
	ofRect(rect.x, rect.y, rect.width, rect.height);
}

// -------------------------------------------
void stepButton::mouseDown(int x, int y) {
	if((x >rect.x && x <rect.x+rect.width)&&(y >rect.y && y<rect.y+rect.height)){
		bClick = true;
		
		if(nClicks % 2 ==0){
			bActive = true;
		} else {
			bActive = false;
		}
		
		nClicks++;
		
	}
}

