#include "testApp.h"
#include "stdio.h"

/* Setup methods
_______________________________________________________________________ */

void testApp::setup() 
{
	ofSetVerticalSync(true);
	ofBackground(0, 0, 0);
	ofSetLogLevel(OF_LOG_NOTICE);
	
	test.loadImage("logo.png");
	particleL.loadImage("images/particle.png");
	particleM.resize(particleM.width * 0.9, particleM.height * 0.9);
	particleM.clone(particleL);
	particleM.resize(particleM.width * 0.7, particleM.height * 0.7);
	particleS.clone(particleL);
	particleS.resize(particleM.width * 0.5, particleM.height * 0.5);
		
	setupWorld();
	
	setupLineStrip();
	
	screenCounter = 0;
	resetCount = 0;
}

void testApp::setupWorld()
{
	box2d.init();
	box2d.setGravity(0, 1);
	//box2d.createFloor();
	//box2d.createBounds();
	box2d.checkBounds(true);
	box2d.setFPS(30.0);
}

void testApp::setupLineStrip()
{
	// draw R
	rLet.setWorld(box2d.getWorld());
	rLet.clear();
	rLet.addPoint(107, 294);
	rLet.addPoint(107, 474);
	rLet.addPoint(167, 474);
	rLet.addPoint(167, 324);
	rLet.addPoint(227, 324);
	rLet.addPoint(227, 384);
	rLet.addPoint(287, 384);
	rLet.addPoint(287, 294);
	rLet.createShape();
	
	// draw U
	uLet.setWorld(box2d.getWorld());
	uLet.clear();
	uLet.addPoint(317, 294);
	uLet.addPoint(317, 474);
	uLet.addPoint(497, 474);
	uLet.addPoint(497, 294);
	uLet.createShape();
	
	// draw U reversed
	uLetRev.setWorld(box2d.getWorld());
	uLetRev.clear();
	uLetRev.addPoint(377, 444);
	uLetRev.addPoint(377, 274);
	uLetRev.addPoint(400, 250);
	uLetRev.addPoint(437, 274);
	uLetRev.addPoint(437, 444);
	uLetRev.createShape();
	
	// draw N
	nLet.setWorld(box2d.getWorld());
	nLet.clear();
	nLet.addPoint(527, 294);
	nLet.addPoint(527, 474);
	nLet.addPoint(587, 474);
	nLet.addPoint(587, 324);
	nLet.addPoint(647, 324);
	nLet.addPoint(647, 474);
	nLet.addPoint(707, 474);
	nLet.addPoint(707, 294);
	nLet.createShape();
	
	// draw E
	eLet.setWorld(box2d.getWorld());
	eLet.clear();
	eLet.addPoint(737, 294);
	eLet.addPoint(737, 474);
	eLet.addPoint(917, 474);
	eLet.addPoint(917, 444);
	eLet.addPoint(797, 444);
	eLet.addPoint(797, 414);
	eLet.addPoint(917, 414);
	eLet.addPoint(917, 294);
	eLet.createShape();
	
	// draw E reversed
	eLetRev.setWorld(box2d.getWorld());
	eLetRev.clear();
	eLetRev.addPoint(797, 324);
	eLetRev.addPoint(857, 324);
	eLetRev.addPoint(857, 384);
	eLetRev.addPoint(797, 384);
	eLetRev.addPoint(797, 324);
	eLetRev.createShape();
	
}

/* Update
_______________________________________________________________________ */

void testApp::update() 
{
	box2d.update();
	
	if(particleCount < MAX_PARTICLES)
	{
		createParticles();
	}
}

void testApp::createParticles()
{
	for(int i=0; i<FOR_PARTICLES; i++) 
	{
		// skip if we resetted a particle
		if(resetCount > 0)
		{
			resetCount--;
			
			//printf("Skipped one \n");
		}
		else 
		{
			float radius = ofRandom(1, 4);
			CustomParticle p;
			//p.setPhysics(2, 0.200, 0.9);
			p.setPhysics(0.4, 0.900, 0.2);
			p.setup(box2d.getWorld(), ofRandom(0, ofGetWidth()), 0, radius);
			p.setColor(242, 138, 81);
			
			if(radius < 2)		p.setImage(&particleS);
			else if(radius < 3) p.setImage(&particleM);
			else				p.setImage(&particleL);
			
			customParticles.push_back(p);
			
			particleCount++;
		}
	}
	
	printf("ParticleCount: %d \n", particleCount);
}

/* Draw
_______________________________________________________________________ */

void testApp::draw() 
{	
	bool del;
	
	//printf("Size: %d \n", customParticles.size());
	
	for(int i = 0; i < customParticles.size(); i++) 
	{
		if(particleCount < MAX_PARTICLES)
		{
			if(customParticles[i].checkReset())
			{
				resetCount++;
			}
		}
		
		customParticles[i].draw();
	}
	
	// leave these out on real test
	/*
	rLet.draw();
	uLet.draw();
	uLetRev.draw();
	nLet.draw();
	eLet.draw();
	eLetRev.draw();
	box2d.draw();*/
	
	theScreen.grabScreen(0,0,ofGetWidth(),ofGetHeight());
	theScreen.saveImage("screengrab/screen"+ofToString(screenCounter)+".png");
	screenCounter++;
}

/* Keyboard events
_______________________________________________________________________ */

void testApp::keyPressed(int key) 
{
	
}

void testApp::keyReleased(int key) 
{
	
}

/* Mouse Events
_______________________________________________________________________ */

void testApp::mouseMoved(int x, int y ) 
{
	
}

void testApp::mouseDragged(int x, int y, int button) 
{	
	
}

void testApp::mousePressed(int x, int y, int button) 
{	

}

void testApp::mouseReleased(int x, int y, int button)
{

}

/* Resize Event
_______________________________________________________________________ */

void testApp::resized(int w, int h)
{
	
}

