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
	void update(unsigned int const& NumberOfTimeIncrement,double ElectricInput,double InitialTime);
	double getMembranePotential() const;
	std::vector<double> getSpikesTime() const;
};

#endif
