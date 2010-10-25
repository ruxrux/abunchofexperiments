/*
 *  stepButton.h
 *  steppySeq
 *
 *  Created by rux on 8/6/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef STEP_BUTTON
#define STEP_BUTTON
#include "ofMain.h"

class stepButton {
	public:
		void setup();
		void draw();
		void update();
		void mouseDown(int x, int y);
		ofRectangle rect;
		ofPoint		color;
		bool		bClick, bActive;
		int			nClicks;
		

		
};
#endif

