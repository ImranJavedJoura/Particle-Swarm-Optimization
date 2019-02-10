#pragma once
#include<stdlib.h>
#include<iostream>
#include"Nostalgia.h"
class Vector;
class Particle; 
class Swarm
{
	int populationSize;
	Nostalgia norm;
	Particle * p;
	void *objFunc;

public:
	
	bool isConverged();
	void print(int iteration = 0);
	Nostalgia getNorm();
	void setObjFunc(void *f);
	void randomizeParticleLocation(Vector minLoc, Vector maxLoc);
	void randomizeParticleVelocity();
	void update();
	Swarm(int populationSize);
	~Swarm();
};

