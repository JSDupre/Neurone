#include <iostream>
#include "Neurone.hpp"
#include "Constants.hpp"
#include <cmath>
#include <vector>
using namespace std;

	Neurone::Neurone (int clock)
	:membranePotential_(STANDART_POTENTIAL),localClock_(clock),spikeRingBuffer_(D+1,0.0){}
	
	bool Neurone::update(double const& ElectricInput){
				bool spike(false);
				if(membranePotential_>=SpikeThreshold)
				{
					//1 we store the spike time
					SpikesTime_.push_back(localClock_);
					//2 the neurone goes refractory: the potential fall down to 0
					membranePotential_=RefractoryPotential;
					spike=true;
				}
						
				else if((localClock_-SpikesTime.back())<=RefractoryTimeInTimeIncrement) //on regarde le temps ecoulé depuis le dernier spike
				{
					membranePotential_=RefractoryPotential;
				}
				else
				{
					double NewPotential;
					NewPotential=membranePotential_*exp(-TimeIncrement/Tau)+ElectricInput*NeuroneResistance*(1-exp(-TimeIncrement/Tau));
					size_t currentIndex(localClock_%(D+1));
					NewPotential+=spikeRingBuffer_[currentIndex]; //on a network
					membranePotential_=NewPotential;
				}
				++localClock_;
				return spike;
				}
			
		}
	
	double Neurone::getMembranePotential() const{
		return membranePotential_;
	}

	std::vector<int> Neurone::getSpikesTimeInNumberOfTimeIncrement() const{
		return SpikesTimeInNumberOfTimeIncrement_;
	}
	vector<Connection> Neurone::getConnections() const{
		return connections_;
	}
	void Neurone::setConnections (vector<Connection>& connections){
		connections_=connections;
	}
	void Neurone::receive(int clockPlusDelay,double J){
		size_t storageIndex(clockPlusDelay % (D+1));
		spikeRingBuffer_[storageIndex]+=J;
	}

