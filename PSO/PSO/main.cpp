#include<iostream>
#include<conio.h>
#include<math.h>
#include<time.h>
#include<fstream>
using namespace std;
#include "Vector.h"
#include "Swarm.h"
#include"Particle.h"
#include<time.h>
#define PI 3.14159265

int main()
{
	double S;//world scaling
	srand(time(NULL));
	cout << "Enter the value of S to spawn particles between minLoc(-S, -S), maxLoc(S, S), greater value of S spreads particles over a wider area: " << endl;
	cin >> S;
	cout << "Enter number of particles to spawn: ";
	int num;
	cin >> num;

	fstream file;
	file.open("PSO_result.txt", ios::in | ios::out | ios::ate);
	if (!file.is_open())
	{
		cout << "creating new file: PSO_result.txt" << endl;
		file.open("PSO_result.txt", ios::in | ios::out);
		if (!file.is_open())cout << "file couldn't be created" << endl;
	}

	int maxIterations = 1000;
	Swarm s(num);
	Vector minLoc(-S, -S), maxLoc(S, S);
	s.randomizeParticleLocation(minLoc, maxLoc);
	s.randomizeParticleVelocity();//random velocity
	for (int i = 1; i <= maxIterations; i++)
	{
		s.update();
		s.print(i);
		if (i % 20 == 0 && s.isConverged())
		{
			cout << "Swarm converged after: " << i << " iterations." << endl;
			break;
		}
	}
	cout << "best soulution is: (" << s.getNorm().location.x << ", " << s.getNorm().location.y << ")" << endl;
	cout << "objective value: " << s.getNorm().value << endl;	
	
	file << time(NULL) << ": " << endl;
	file << "best soulution is: (" << s.getNorm().location.x << ", " << s.getNorm().location.y << ")" << endl;
	file << "objective value: " << s.getNorm().value << endl;
	file.close();
	main();
}