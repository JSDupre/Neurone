#include <iostream>
#include "Neurone.hpp"
#include "Constants.cpp"
#include <cmath>

	Neurone::Neurone ()
	:membranePotential_(STANDART_POTENTIAL){}
	void Neurone::update(unsigned int const& NumberOfTimeIncrement,double const& ElectricInput,double const& InitialTime){
			for(unsigned int i(0);i<NumberOfTimeIncrement;++i){
					double NewPotential;
					NewPotential=MembranePotential*exp(-TimeIncrement/Tau);
					NewPotential+=ElectricInput*NeuroneResistance*(1-exp(-TimeIncrement/Tau));
					membranePotential_=NewPotential;
					if(membranePotential_>SpikeThreshold){
						//1 we store the spike time
						SpikesTime_.push_back(InitialTime+(i+1)*TimeIncrement)
						//2 the potential fall down to 0
						membranePotential_=0.0;
						};
				}
			
		};
	
	double Neurone::getMembranePotential (){
		return membranePotential_;
	}
	vector<double> Neurone::getSpikesTime (){
		return SpikesTime_;
	}

