#pragma once
#include "particles.h"

class particles_updater
{
public:
	particles_updater() {}
	~particles_updater() {}

	virtual void update(float dt, particles* p) =0;
};

class EulerMethod : public particles_updater
{
public:
	virtual void update(float dt, particles* p) override;
};


class Time : public particles_updater
{
public:
	virtual void update(float dt, particles* p) override;
};
