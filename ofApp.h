#pragma once

#include "ofMain.h"
#include "particle_system.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		float x, y, z;
		ofVec3f origin = { x,y,z };

		particle_system* system = new particle_system(5000);


		int n = 1000;
		float dt = 0.1;

		ofPlanePrimitive floor;
		ofPlanePrimitive s1;
		ofPlanePrimitive s2;
		ofPlanePrimitive s3;
		ofPlanePrimitive s4;
		ofPlanePrimitive s5;


		ofEasyCam cam;
		ofLight light;
		ofSpherePrimitive bauble1;
		ofSpherePrimitive bauble2;
		ofSpherePrimitive bauble3;
		ofCylinderPrimitive b1;
		ofCylinderPrimitive b2;
		ofCylinderPrimitive b3;

		ofImage snow;
		ofImage gold;
		ofImage merry;
		ofImage chris;
		ofImage back1;
		ofImage back2;
		ofImage back3;
		ofImage back4;
		ofImage back5;
		
};
