#include <iostream>
#include <vector>
#include "Constants.hpp"

#ifndef NEURONE_H
#define NEURONE_H

/**
 * class for a neuron
 */
class Neurone {
	private:
	
	int neurone_ID_;	//!< the neuron ID in the network
	double membranePotential_; //!< the neuron membrane potential (in mV)
	std::vector<int> SpikesTimeInNumberOfTimeIncrement_; //!< the neuron spikes' times (in number of since the beginning of the simulation)
	int localClock_;                                     //!< local clock for the neurone (can be incremented before the global simulation clock)
	std::vector<int> connections_;               //!< indices of the post-synaptic neurons the neuron is connected to 
	std::vector<double> spikeRingBuffer_;		     //!< ring buffer used to store the arriving spikes from pre-synaptic neurons in order to compute them after a certain delay
	double Iext_;					     //!< Intensity comming from the outside of the brain
	bool isExitatory_;				//!< type of the neuron : true if the neuron is excitatory and flase if the neuron is inhibitory

	public:
	/** \brief construct a neuron
	 * 
	 * @param clock local clock for the neuron
	 * @param Iext intensity comming from the outside of the brain
	 * @param isExitatory boolean true if the neuron is excitatory false if inhibitory
	 * @param neuroneID the neuron ID
	 */
	Neurone (int clock,double Iext,bool isExitatory, int neuroneID);
	bool update(unsigned int const& NumberOfTimeIncrement);
	double getMembranePotential() const;
	std::vector<int> getSpikesTimeInNumberOfTimeIncrement() const;
	std::vector<int> getConnections() const;
	void setConnections (std::vector<
	int> const& connections);
	void receive(int clockPlusDelay,double J);
	std::vector<double> getRingBuffer() const;
	double getJsentToPostSynapticNeurone() const;
	//int getNeuroneID() const;
};

#endif
