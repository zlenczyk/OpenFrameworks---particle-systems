#include "particles_generator.h"

void particles_generator::generate(float dt, particles* p, int startId, int endId)
{
}

void Color::generate(float dt, particles* p, int startId, int endId)
{
	float reszta = (endId - 1) % em;
	float krok = (endId - 1 - reszta) / em;

	int k = 0;
	for (int j = 0; j < em; j++) {
		float r, g, b, a;
		r = ofRandom(1, 255);
		g = ofRandom(1, 255);
		b = ofRandom(1, 255);
		a = 255;
		for (int i = startId; i < krok; i++)
		{
			p->col[i+k] = { r,g,b,a };
		}
		k += krok;
	}
}

void Velocity::generate(float dt, particles* p, int startId, int endId)
{
	ofVec3f unit;
	float phi, theta, v, x, y, z;
	for (int i = startId; i < endId; ++i)
	{
		theta = ofRandom(1,360) * PI / 180.0;
		phi = ofRandom(1, 360) * PI / 180.0;
		v = vel;
		x = sin(theta) * cos(phi);
		y = sin(theta) * sin(phi);
		z = cos(theta);
		unit.set(x, y, z);
		unit = unit.getNormalized();

		p->vel[i] = v * unit;
	}
}

void Pos::generate(float dt, particles* p, int startId, int endId)
{
	float reszta = (endId-1) % em;
	float krok = (endId-1 - reszta) / em;

	int k = 0;
	for (int j = 0; j < em; j++) {
		int xx = ofRandom(-1500, 1500);
		int yy = ofRandom(600,1200);
		int zz = ofRandom(-200, -1400);
		for (int i = startId; i < krok; i++)
		{
			p->pos[i+k].x = xx;
			p->pos[i + k].y = yy;
			p->pos[i+k].z = zz;
		}
		k += krok;
		cout << startId;
	}

}

void TimeG::generate(float dt, particles* p, int startId, int endId)
{
	for (int i = startId; i < endId; ++i)
	{
		p->time[i].x = p->time[i].y = glm::linearRand(minTime, maxTime);
		p->time[i].z = (float)0.0;
		p->time[i].w = (float)1.0 / p->time[i].x;
	}
}
