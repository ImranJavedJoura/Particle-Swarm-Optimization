#include "Particle.h"
#include "Vector.h"
#include "Swarm.h"
#define PI 3.1415926535897932384626433832795028841971693993751058209 

double ackleyFunc(Vector v)
{
	const double a = 20, b = .2, c = PI * 2;
	return -a * exp(-b * sqrt(0.5*(v.x*v.x + v.y*v.y))) -
		exp(0.5*(cos(c*v.x) + cos(c*v.y))) + a + exp(1);
}

void Particle::setSwarmRef(Swarm * s)
{
	this->s = s;
}

void Particle::update()
{
	//update location
	velocity = velocity * .5 +
		(nostalgia.location - location) * (2 * rand() / (double)RAND_MAX) +
		(s->getNorm().location - location) * (2 * rand() / (double)RAND_MAX);

	setLocation(location + velocity);
}

void Particle::setLocation(Vector location)
{
	nostalgia.isValid = true;
	this->location = location;
	double value = ackleyFunc(location);
	if (value < nostalgia.value)
	{
		nostalgia.location = location;
		nostalgia.value = value;
	}
}

Vector Particle::getLocation()
{
	return location;
}

Nostalgia Particle::getNostalgia()
{
	return nostalgia;
}

double Particle::getMaxSpeed()
{
	return maxSpeed;
}

void Particle::setVelocity(Vector v)
{
	if (v.squaredLength() > maxSpeed*maxSpeed)
		velocity = v.unitVector() * maxSpeed;
	else velocity = v;
}

Vector Particle::getVelocity()
{
	return velocity;
}

Particle::Particle(Swarm *s)
{
	maxSpeed = 10;
//	velocity = Vector(0, 0);
//	location = Vector(0, 0);
	nostalgia.isValid = false;
	c1 = c2 = 2;
	this->s = s;
}


Particle::~Particle()
{
}
