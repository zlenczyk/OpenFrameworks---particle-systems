#pragma once

#include "particles.h"
#include "particle_emmiter.h"
#include "particles_updater.h"

class particle_system
{
public:
	particles Particles;
	particles aliveParticles;

	int count;

	vector<shared_ptr<particles_updater>> updaters;
	vector<shared_ptr<particle_emmiter>> emitters;

public:
	particle_system(int maxCount);
	~particle_system() { }

	particle_system(particle_system&) = delete;
	particle_system& operator=(particle_system&) = delete;

	virtual void update(float dt);

	void addEmitter(shared_ptr<particle_emmiter> emmiter) { emitters.push_back(emmiter); }
	void addUpdater(shared_ptr<particles_updater> updater) { updaters.push_back(updater); }

	virtual int numAllParticles() { return Particles.count; }
    virtual int numAliveParticles() { return Particles.countAlive; }
};