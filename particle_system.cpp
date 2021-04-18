#include "particle_system.h"

particle_system::particle_system(int maxCount)
{

	count = maxCount;
	Particles.generate(maxCount);
	aliveParticles.generate(maxCount);

	for (int i = 0; i < maxCount; i++)
		Particles.alive[i] = false;
}

void particle_system::update(float dt)
{

	for (auto& emmiter : emitters)
	{
		emmiter->emit(dt, &Particles);
	}

	 for (int i = 0; i < count; i++)
	{
		Particles.acc[i] = ofVec3f(0.0f);
	}

	for (auto& updater : updaters)
	{
		updater->update(dt, &Particles);
	}
}

