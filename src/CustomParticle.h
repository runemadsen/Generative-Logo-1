#pragma once

#include "ofMain.h"
#include "ofxVectorMath.h"
#include "ofxBox2d.h"

class CustomParticle : public ofxBox2dCircle 
{
	
public:
	
	CustomParticle();
	bool checkReset();
	void draw();
	void setColor(int r, int g, int b);
	void setImage(ofImage*);
	
private:
	
	ofColor color;
	ofImage* _img;
};

