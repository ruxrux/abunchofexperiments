/*
 *  tracki.h
 *  steppySeq
 *
 *  Created by rux on 8/8/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef TRACKI
#define TRACKI

#include "ofMain.h"
#include "stepButton.h"

class tracki {
	public:
		void setup();
		void update(int _step);
		void draw();
		void mouseDown(int x, int y);
	
		vector < stepButton >	stepB;
		ofSoundPlayer			stepSound;
		bool					bPlayOnce;
		string					stepSoundName;
	
		ofPoint					tPos;
	
};
#endif