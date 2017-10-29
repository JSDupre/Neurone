#include <iostream>
#include <vector>
#include "Constants.hpp"

#ifndef NEURONE_H
#define NEURONE_H

class Neurone {
	private:
	double membranePotential_; 
	std::vector<int> SpikesTimeInNumberOfTimeIncrement_; //store the spikes time (a certain number of time incrment)
	int localClock_;                                     //local clock for the neurone (can be incremented before the global simulation clock)
	std::vector<int> connections_;               //all the connection the neurone have (stored as indix)
	std::vector<double> spikeRingBuffer_;		     //used to sum the different J of every presynaptic neurones who has fired after a certain delay D
	double Iext_;					     //Intensity comming from the outside
	bool isExitatory_;

	public:
	Neurone (int clock,double Iext,bool isExitatory);
	bool update(unsigned int const& NumberOfTimeIncrement);
	double getMembranePotential() const;
	std::vector<int> getSpikesTimeInNumberOfTimeIncrement() const;
	std::vector<int> getConnections() const;
	void setConnections (std::vector<
	int> const& connections);
	void receive(int clockPlusDelay,double J);
	std::vector<double> getRingBuffer() const;
	double getJsentToPostSynapticNeurone() const;
};

#endif
