#include <iostream>
#include <vector>

#ifndef NEURONE_H
#define NEURONE_H

class Neurone {
	private:
	double membranePotential_;
	std::vector<double> SpikesTime_;
	double RefractoryClock_;//plutot comparer temps du dernier spike dans Spikes time ?
	std::vector<Neurone*> targets_;// a utiliser
	int localClock_;
	//std::array<double,??
	
	public:
	Neurone ();
	bool update(unsigned int const& NumberOfTimeIncrement,double const& ElectricInput,double const& InitialTime);
	double getMembranePotential() const;
	std::vector<double> getSpikesTime() const;
	vector<Neurone*> getTargets();// a def
};

#endif
