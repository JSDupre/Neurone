#include <iostream>
#include <vector>

#ifndef NEURONE_H
#define NEURONE_H

class Neurone {
	private:
	double membranePotential_;
	std::vector<double> SpikesTime_;
	public:
	Neurone ();
	void update(unsigned int const& NumberOfTimeIncrement,double const& ElectricInput,double const& InitialTime);
	double getMembranePotential const();
	vector<double> getSpikesTime const();
};

#endif
