#include "ofApp.h"

void ofApp::setup(){

	ofSetVerticalSync(true);

	bauble1.setRadius(160);
	bauble2.setRadius(120);
	bauble3.setRadius(100);
	bauble1.setPosition({ 0,160,400 });
	bauble2.setPosition({ -600,120,800 });
	bauble3.setPosition({ 500,100,1000 });
	bauble3.rotate(130, ofVec3f{ 0.0, 1.0, 0.0 });

	b1.set(50, 60);
	b2.set(40, 50);
	b3.set(30, 40);
	b1.rotate(30, 0.0, 0.0, 1.0);
	b2.rotate(320, 0.0, 0.0, 1.0);
	b3.rotate(340, 0.0, 0.0, 1.0);
	b1.setPosition({-100,300,400});
	b2.setPosition({ -520,210,800 });
	b3.setPosition({ 530,190,1000 });

	floor.set(4000, 3000);
	floor.rotate(270, ofVec3f{ 1.0, 0.0, 0.0 });
	floor.setPosition({0,0,0});
	snow.load("floor.jpg");

	s1.set(1000, 2500);
	s2.set(1000, 2500);
	s3.set(1000, 2500);
	s4.set(1000, 2500);
	s5.set(1000, 2500);

	s1.rotate(180, ofVec3f{ 1.0, 0.0, 0.0 });
	s1.rotate(180, ofVec3f{ 0.0, 0.0, 1.0 });
	s1.rotate(-50, ofVec3f{ 0.0, 1.0, 0.0 });
	s1.setPosition({ 1700,1000,-695 });
	back1.load("1.jpg");

	s2.rotate(180, ofVec3f{ 1.0, 0.0, 0.0 });
	s2.rotate(180, ofVec3f{ 0.0, 0.0, 1.0 });
	s2.rotate(-25, ofVec3f{ 0.0, 1.0, 0.0 });
	s2.setPosition({ 930,1000,-1289 });
	back2.load("2.jpg");

	s3.rotate(180, ofVec3f{ 1.0, 0.0, 0.0 });
	s3.rotate(180, ofVec3f{ 0.0, 0.0, 1.0 });
	s3.setPosition({ 0,1000,-1500 });
	back3.load("3.jpg");

	s5.rotate(180, ofVec3f{ 1.0, 0.0, 0.0 });
	s5.rotate(180, ofVec3f{ 0.0, 0.0, 1.0 });
	s5.rotate(50, ofVec3f{ 0.0, 1.0, 0.0 });
	s5.setPosition({ -1700,1000,-695 });
	back5.load("5.jpg");

	s4.rotate(180, ofVec3f{ 1.0, 0.0, 0.0 });
	s4.rotate(180, ofVec3f{ 0.0, 0.0, 1.0 });
	s4.rotate(25, ofVec3f{ 0.0, 1.0, 0.0 });
	s4.setPosition({ -930,1000,-1289 });
	back4.load("4.jpg");

	gold.load("gold.jpg");

	merry.load("merry.jpg");

	chris.load("chris.jpg");

	x = 0.0;
	z = y = x;

	cam.setPosition({0,600,2100});
	cam.lookAt({0,400,0});

	light.enable();
	light.setPosition({x+100,y+400,z+600});
	light.lookAt(origin);
 
	auto emmiter = make_shared<particle_emmiter>();

	emmiter->emitRate = (float)n * 110.0f;

	auto box = make_shared<Pos>();
	box->em = 6;
	emmiter->addGenerator(box);

	auto color = make_shared<Color>();
	color->em = 6;
	emmiter->addGenerator(color);

	auto velocity = make_shared<Velocity>();
	velocity->vel = 150.0;
	emmiter->addGenerator(velocity);

	 auto time = make_shared<TimeG>();
	time->minTime = 10.5;
	time->maxTime = 12.0;
	emmiter->addGenerator(time); 

	system->addEmitter(emmiter);

	auto timeUpdater = make_shared<Time>();
	system->addUpdater(timeUpdater);

	auto Euler = make_shared<EulerMethod>();
	system->addUpdater(Euler);

}

void ofApp::update(){
		system->update(dt);
}

void ofApp::draw(){

	cam.begin();
	ofEnableDepthTest();
	ofFill();
	ofSetColor(ofColor::white);
	snow.getTexture().bind();
	floor.mapTexCoordsFromTexture(snow.getTexture());
	ofPushMatrix();
	floor.draw();
	ofPopMatrix();
	snow.getTexture().unbind();

	ofFill();
	ofSetColor(ofColor::white);
	back3.getTexture().bind();
    s3.mapTexCoordsFromTexture(back3.getTexture());
	ofPushMatrix();
	s3.draw();
	ofPopMatrix();
	back3.getTexture().unbind();

	ofFill();
	ofSetColor(ofColor::white);
	back1.getTexture().bind();
	s1.mapTexCoordsFromTexture(back1.getTexture());
	ofPushMatrix();
	s1.draw();
	ofPopMatrix();
	back1.getTexture().unbind();

	ofFill();
	ofSetColor(ofColor::white);
	back2.getTexture().bind();
	s2.mapTexCoordsFromTexture(back2.getTexture());
	ofPushMatrix();
	s2.draw();
	ofPopMatrix();
	back2.getTexture().unbind();

	ofFill();
	ofSetColor(ofColor::white);
	back4.getTexture().bind();
	s4.mapTexCoordsFromTexture(back4.getTexture());
	ofPushMatrix();
	s4.draw();
	ofPopMatrix();
	back4.getTexture().unbind();

	ofFill();
	ofSetColor(ofColor::white);
	back3.getTexture().bind();
	s3.mapTexCoordsFromTexture(back3.getTexture());
	ofPushMatrix();
	s3.draw();
	ofPopMatrix();
	back3.getTexture().unbind();

	ofFill();
	ofSetColor(ofColor::white);
	back5.getTexture().bind();
	s5.mapTexCoordsFromTexture(back5.getTexture());
	ofPushMatrix();
	s5.draw();
	ofPopMatrix();
	back5.getTexture().unbind();

	ofFill();
	ofSetColor(ofColor::white);
	gold.getTexture().bind();
	bauble1.mapTexCoordsFromTexture(gold.getTexture());
	ofPushMatrix();
	bauble1.draw();
	ofPopMatrix();
	gold.getTexture().unbind();

	ofFill();
	ofSetColor(ofColor::white);
	merry.getTexture().bind();
	bauble2.mapTexCoordsFromTexture(merry.getTexture());
	ofPushMatrix();
	bauble2.draw();
	ofPopMatrix();
	merry.getTexture().unbind();

	ofFill();
	ofSetColor(ofColor::white);
	chris.getTexture().bind();
	bauble3.mapTexCoordsFromTexture(chris.getTexture());
	ofPushMatrix();
	bauble3.draw();
	ofPopMatrix();
	chris.getTexture().unbind();

	bauble3.draw();
	ofSetColor(ofColor(128,0,0));
	b1.draw();
	b2.draw();
	ofSetColor(ofColor(222,184,135));
	b3.draw();

		if (system->numAliveParticles() > 0) {
			for (int i = 0; i < system->numAliveParticles(); i++) {
				ofSetColor(system->Particles.col[i].x,
					system->Particles.col[i].y,
					system->Particles.col[i].z,
					system->Particles.col[i].w);
				ofDrawSphere(system->Particles.pos[i].x, system->Particles.pos[i].y, system->Particles.pos[i].z, 4);
			}
		}

	cam.end();

}


