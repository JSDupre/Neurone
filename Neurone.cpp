#include <iostream>
#include "Neurone.hpp"
#include "Constants.hpp"
#include <cmath>
#include <vector>
using namespace std;

	Neurone::Neurone ()
	:membranePotential_(STANDART_POTENTIAL),RefractoryClock_(0.0){}
	
	bool Neurone::update(unsigned int const& NumberOfTimeIncrement,double const& ElectricInput,double const& InitialTime){
			for(unsigned int i(0);i<NumberOfTimeIncrement;++i){
				if(membranePotential_>=SpikeThreshold){
						//1 we store the spike time
						SpikesTime_.push_back(InitialTime+(i+1)*TimeIncrement);
						//2 the potential fall down to 0
						membranePotential_=RefractoryPotential;
						//the neurone goes refractory
						RefractoryClock_=RefractoryTime;
						return true;
						}
						
				else if(RefractoryClock_>0.0){
					membranePotential_=RefractoryPotential;
					RefractoryClock_-=TimeIncrement;
				}
				else{
					double NewPotential;
					NewPotential=membranePotential_*exp(-TimeIncrement/Tau);
					NewPotential+=ElectricInput*NeuroneResistance*(1-exp(-TimeIncrement/Tau));
					membranePotential_=NewPotential;
					}
				return false;
				}
			
		}
	
	double Neurone::getMembranePotential() const{
		return membranePotential_;
	}
	vector<double> Neurone::getSpikesTime() const{
		return SpikesTime_;
	}

