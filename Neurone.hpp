#include <iostream>
#include <vector>

#ifndef NEURONE_H
#define NEURONE_H

class Neurone {
	private:
	double membranePotential_;
	std::vector<double> SpikesTime_;
	double RefractoryClock_;
	vector<Neurone*> targets_;// a utiliser
	double J; //propre à chaque neurone ?
	
	public:
	Neurone ();
	bool update(unsigned int const& NumberOfTimeIncrement,double const& ElectricInput,double const& InitialTime);
	double getMembranePotential() const;
	std::vector<double> getSpikesTime() const;
	vector<Neurone*> getTargets();// a def
};

#endif
