#include <iostream>
#include <vector>
#include "Connection.hpp"

#ifndef NEURONE_H
#define NEURONE_H

class Neurone {
	private:
	double membranePotential_; 
	std::vector<int> SpikesTimeInNumberOfTimeIncrement_; //store the spikes time (a certain number of time incrment)
	int localClock_;                                     //local clock for the neurone (can be incremented before the global simulation clock)
	std::vector<Connection> connections_;                //all the connection the neurone have (s
	//buffer ??
	
	public:
	Neurone ();
	bool update(unsigned int const& NumberOfTimeIncrement,double const& ElectricInput,double const& InitialTime);
	double getMembranePotential() const;
	std::vector<double> getSpikesTime() const;
	vector<Connection> getConnections();
	void setConnections (vector<Connection>& connections);//const& ?
	void receive(int clockPlusDelay,double J);
};

#endif
