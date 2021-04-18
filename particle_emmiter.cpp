#include "particle_emmiter.h"

void particle_emmiter::emit(float dt, particles* p)
{
	int new_particles_MAX = static_cast<int>(emitRate);
	int ID_first = p->countAlive;
	int ID_last = std::min(ID_first + new_particles_MAX, p->count - 1);

	for (auto& gen : generators)
		gen->generate(dt, p, ID_first, ID_last);

	 for (int i = ID_first; i < ID_last; i++)
	{
		p->wake(i);
	}
}