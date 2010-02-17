#ifndef _TEST_APP
#define _TEST_APP
#include "ofMain.h"
#include "ofxVectorMath.h"
#include "ofxBox2d.h"
#include "CustomParticle.h"

#define MAX_PARTICLES 5000
//#define MAX_PARTICLES 200
#define FOR_PARTICLES 2

class testApp : public ofBaseApp 
{
	
public:
	
	void setup();
	void update();
	void draw();
	
	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void resized(int w, int h);
	
	float px, py;
	bool							bDrawLines;
	bool							bMouseForce;
	
	ofxBox2d box2d;		
	ofxBox2dLine rLet;
	ofxBox2dLine uLet;
	ofxBox2dLine uLetRev;
	ofxBox2dLine nLet;
	ofxBox2dLine eLet;
	ofxBox2dLine eLetRev;
	vector <CustomParticle>	customParticles; 
			
	
private:
	
	void setupWorld();
	void setupLineStrip();
	void createParticles();
	
	ofImage test;
	ofImage particleS;
	ofImage particleM;
	ofImage particleL;
	ofImage theScreen;
	
	int screenCounter;
	
	int resetCount;

	
	int particleCount;
	
};

#endif
