#include "Swarm.h"
#include "Vector.h"
#include "Particle.h"
#include<iostream>
#include<iomanip>
using namespace std;


bool Swarm::isConverged()
{
	long double sum = 0;
	for (int i = 0; i < populationSize - 1; i++)
		sum += (p[i].getLocation() - p[i + 1].getLocation()).squaredLength();
	return (sum < 1);
}

void Swarm::print(int iteration)
{
	const int s = 15;
	cout << setw(s)<<"(location.x," << setw(s) << "location.y)" << 
		setw(s) << "(velocity.x," << setw(s) << "velocity.y)" << 
		setw(s) << "(nostalgia.x," << setw(s) << "nostalgia.y)" << 
		setw(s) << "nostalgia value" << endl;
	for (int i = 0; i < populationSize; i++)
	{
		cout <<i+1<< " ("<<setw(s)<<p[i].getLocation().x << "," << setw(s) << p[i].getLocation().y << ")"<<
			setw(s) << "("<<p[i].getVelocity().x << "," << setw(s) << p[i].getVelocity().y << ")" <<
			setw(s) << "(" << p[i].getNostalgia().location.x << "," << setw(s) << p[i].getNostalgia().location.y << ")" <<
			setw(s) << p[i].getNostalgia().value << endl;
	}
	if (iteration != 0)cout << iteration << ") ";
	cout << "Norm: " << "(" << setw(s) << norm.location.x << "," << setw(s) << norm.location.y << ")" << setw(s) << "norm value: " << norm.value << endl;

	

}

Nostalgia Swarm::getNorm()
{
	return norm;
}

void Swarm::setObjFunc(void * f)
{
	objFunc = f;
}

void Swarm::randomizeParticleLocation(Vector minLoc, Vector maxLoc)
{
	Vector location;
	Nostalgia best;
	for (int i = 0; i < populationSize; i++)
	{
		location.x = minLoc.x + (double)rand() / (double)RAND_MAX * (maxLoc.x - minLoc.x + 1);
		location.y = minLoc.y + (double)rand() / (double)RAND_MAX * (maxLoc.y - minLoc.y + 1);
		p[i].setLocation(location);
		if (p[i].getNostalgia().value < best.value)
			best = p[i].getNostalgia();
	}
	norm = best;
	norm.isValid = true;
}

void Swarm::randomizeParticleVelocity()
{
	for (int i = 0; i < populationSize; i++)
	{
		Vector v = Vector(rand() - RAND_MAX / 2, rand() - RAND_MAX / 2).unitVector();
		cout << setw(10) << v.x << "," << setw(10) << v.y << endl; 
		p[i].setVelocity(v * ((double)rand() / (double)RAND_MAX * p[i].getMaxSpeed()));	
	}
}

void Swarm::update()
{
	for (int i = 0; i < populationSize; i++)
	{
		p[i].update();
		if (p[i].getNostalgia().value < norm.value)
			norm = p[i].getNostalgia();
	}
}

Swarm::Swarm(int n)
{
	populationSize = n;
	p = new Particle[n];
	norm.isValid = false;
	for (int i = 0; i < n; i++)
		p[i].setSwarmRef(this);
}


Swarm::~Swarm()
{
}
