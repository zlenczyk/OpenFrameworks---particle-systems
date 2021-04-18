#include "particles.h"

void particles::generate(int maxSize)
{
	count = maxSize;
	countAlive = 0;

	pos.reset(new ofVec3f[maxSize]);
	col.reset(new ofVec4f[maxSize]);
	vel.reset(new ofVec3f[maxSize]);
	alive.reset(new bool[maxSize]);
	acc.reset(new ofVec3f[maxSize]);
	time.reset(new ofVec4f[maxSize]);
}

void particles::kill(int id, int eid)
{
	if (countAlive > 0)
	{
		alive[id] = false;
		col[id].w = 0;
		float reszta = (eid - 1) % 6;
		float krok = (eid - 1 - reszta) / 6;

		int k = 0;
		for (int j = 0; j < 6; j++) {
			for (int i = id; i < krok; i++)
			{
				col[id+k].w = 0;
			}
			k += krok;
		}
		countAlive--;
	}
}

void particles::wake(int id)
{
	if (countAlive < count)
	{
		alive[id] = true;
		countAlive++;
	}
}

