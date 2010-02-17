/*
 *  CustomParticle.cpp
 *  runeParticles
 *
 *  Created by Rune Madsen on 2/16/10.
 *  Copyright 2010 New York University. All rights reserved.
 *
 */

#include "CustomParticle.h"

CustomParticle::CustomParticle()
{
	color.r = 100;
	color.g = 100;
	color.b = 100;
	
	bodyDef.allowSleep = true;
}

bool CustomParticle::checkReset()
{
	if(getPosition().y > ofGetHeight())
	{
		setup(world, ofRandom(0, ofGetWidth()), 0, getRadius());
		
		return true;
	}
	
	return false;
}

void CustomParticle::draw()
{
	glPushMatrix();
	glTranslatef(getPosition().x, getPosition().y, 0);
	
	//ofSetColor(50, 50, 50);
	//ofFill();
	//ofCircle(0, 0, getRadius());
	
	ofEnableAlphaBlending();
	ofSetColor(255, 255, 255);
	_img->draw(-(_img->width / 2), -(_img->height / 2));
	ofDisableAlphaBlending();
	
	glPopMatrix();
	
}

void CustomParticle::setColor(int rCol, int gCol, int bCol)
{
	color.r = rCol;
	color.g = gCol;
	color.b = bCol;
}

void CustomParticle::setImage(ofImage* img)
{
	_img = img;
}


