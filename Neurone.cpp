#include <iostream>
#include "Neurone.hpp"
#include "Constants.hpp"
#include <cmath>
#include <vector>
using namespace std;

	Neurone::Neurone (int clock)
	:membranePotential_(STANDART_POTENTIAL),localClock_(clock){}
	
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
					NewPotential=membranePotential_*exp(-TimeIncrement/Tau);
					NewPotential+=ElectricInput*NeuroneResistance*(1-exp(-TimeIncrement/Tau));
					membranePotential_=NewPotential;
				}
				return spike;
				}
			
		}
	
	double Neurone::getMembranePotential() const{
		return membranePotential_;
	}
	vector<double> Neurone::getSpikesTime() const{
		return SpikesTime_;
	}

