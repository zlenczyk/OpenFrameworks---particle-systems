#pragma once
#include "particles.h"
#include "particles_generator.h"

class particle_emmiter
{
protected:
	vector<shared_ptr<particles_generator>> generators;
public:
	float emitRate{ 0.0 };

	particle_emmiter() {}
	virtual ~particle_emmiter() {}

	virtual void emit(float dt, particles* p);
	void addGenerator(shared_ptr<particles_generator> gen) { generators.push_back(gen); };
};
