#pragma once
#include<stdlib.h>
#include"Nostalgia.h"
class Swarm;
class Vector;

class Particle
{
private:

	double maxSpeed;
	Vector velocity;
	Vector location;
	double c1, c2;
	Nostalgia nostalgia;
	Swarm *s;


public:
	void setSwarmRef(Swarm *s);
	void update();
	void setLocation(Vector location);
	Vector getLocation();
	Nostalgia getNostalgia();
	double getMaxSpeed();
	void setVelocity(Vector v);
	Vector getVelocity();

	
	Particle(Swarm *s = NULL);
	~Particle();
};

