#pragma once
#include "particles.h"

class particles_generator
{
public:
	particles_generator() { }
	virtual ~particles_generator() { }

	virtual void generate(float dt, particles* p, int ID_first, int ID_last) = 0;
};

class Color : public particles_generator
{
public:
	int em;
public:
	Color() { }

	virtual void generate(float dt, particles* p, int ID_first, int ID_last) override;
};


class Velocity : public particles_generator
{
public:
	float vel{ 0.0f };
public:
	Velocity() { }

	void generate(float dt, particles* p, int ID_first, int ID_last) override;
};

class BoxPosGen : public particles_generator
{
public:
	ofVec3f pos{ 0.0 };
	ofVec3f maxStartPosOffset{ 0.0 };
public:
	BoxPosGen() { }

	void generate(float dt, particles* p, int ID_first, int ID_last) override;
};

class Pos : public particles_generator
{
public:
	int em;
public:
	Pos() { }

	void generate(float dt, particles* p, int ID_first, int ID_last) override;
};

class TimeG : public particles_generator
{
public:
	float minTime{ 0.0 };
	float maxTime{ 0.0 };
public:
	TimeG() { }

	virtual void generate(float dt, particles* p, int ID_first, int ID_last) override;
};
