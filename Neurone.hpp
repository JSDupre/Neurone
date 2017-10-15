#include <iostream>
#include <vector>

#ifndef NEURONE_H
#define NEURONE_H

class Neurone {
	private:
	double membranePotential_;
	std::vector<double> SpikesTime_;
	double RefractoryClock_;
	bool isRefractory (double time);
	void setNeuroneRefractory (double time);
	void solveMembraneEquationAtTPlusH(double const& ElectricInput);
	
	public:
	Neurone ();
	void update(double& time, double const& ElectricInput,double const& Tstop);
	double getMembranePotential() const;
	std::vector<double> getSpikesTime() const;
};

#endif
