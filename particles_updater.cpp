#include "particles_updater.h"


void EulerMethod::update(float dt, particles* p)
{
	float delta_t = (float)dt;

	int ID_last = p->countAlive;

	for (int i = 0; i < ID_last; i++)
		p->acc[i] += p->vel[i]*(-3.0)*dt;

	for (int j = 0; j < ID_last; j++)
		p->vel[j] += delta_t * p->acc[j];

	for (int k = 0; k < ID_last; k++)
		p->pos[k] += delta_t * p->vel[k];
}

void Time::update(float dt, particles* p)
{
	unsigned int endId = p->countAlive;
	const float localDT = (float)dt;

	if (endId == 0) return; 

	 for (int i = 0; i < endId; i++)
	{
		p->time[i].x -= localDT;
		p->time[i].z = (float)1.0 - (p->time[i].x * p->time[i].w);	


		if (p->time[i].x < (float)0.0)
		{
			p->kill(i,endId);
			endId = p->countAlive < p->count ? p->countAlive : p->count;
		}
	}
}

