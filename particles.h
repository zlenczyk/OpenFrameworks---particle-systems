#pragma once

#include "ofMain.h"

class particles
{
public:
	std::unique_ptr<ofVec3f[]> pos;
	std::unique_ptr<ofVec4f[]> col;
	std::unique_ptr<ofVec3f[]> vel;
	std::unique_ptr<ofVec3f[]> acc;
	std::unique_ptr<ofVec4f[]> time;
	std::unique_ptr<bool[]>  alive;

	int count{ 0 };
	int countAlive{ 0 };

public:
	particles() { }
	explicit particles(int maxCount) { generate(maxCount); }
	~particles() { }

	particles(particles&) = delete;
	particles& operator=(particles&) = delete;

	void generate(int maxSize);
	void kill(int id, int eid);
	void wake(int id);
};
