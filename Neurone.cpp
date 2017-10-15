#include <iostream>
#include "Neurone.hpp"
#include "Constants.hpp"
#include <cmath>
#include <vector>
#include <limits>
using namespace std;

	Neurone::Neurone ()
	:membranePotential_(STANDART_POTENTIAL),RefractoryClock_(numeric_limits<double>::lowest()){}
	/*
	void Neurone::update(unsigned int const& NumberOfTimeIncrement,double ElectricInput,double InitialTime){
			for(unsigned int i(0);i<NumberOfTimeIncrement;++i){
				if(RefractoryClock_>0.0){
					membranePotential_=RefractoryPotential;
				}
					else{
					double NewPotential;
					NewPotential=membranePotential_*exp(-TimeIncrement/Tau);
					NewPotential+=ElectricInput*NeuroneResistance*(1-exp(-TimeIncrement/Tau));
					membranePotential_=NewPotential;
					
					if(membranePotential_>SpikeThreshold){
						//1 we store the spike time
						SpikesTime_.push_back(InitialTime+(i+1)*TimeIncrement);
						//2 the potential fall down to 0
						membranePotential_=0.0;
						//the neurone goes refractory
						RefractoryClock_=RefractoryTime;
						}
					}
				RefractoryClock_-=TimeIncrement;
				}
			
		}*/
	
	void Neurone::update(double& time,double const& ElectricInput,double const& Tstop){
		while(time<Tstop){
			if(membranePotential_>SPIKE_THRESHOLD){
				SpikesTime_.push_back(time);
				setNeuroneRefractory(time);
			}
			if(isRefractory(time)){
				membranePotential_=0.0;
			}
			else{
				solveMembraneEquationAtTPlusH(ElectricInput);
				time=time+TIME_INCREMENT;
			}
			//return spike state?
		}
	}
	
	void Neurone::solveMembraneEquationAtTPlusH(double const& ElectricInput){
					double NewPotential;
					NewPotential=membranePotential_*exp(-TIME_INCREMENT/Tau);
					NewPotential+=ElectricInput*NeuroneResistance*(1-exp(-TIME_INCREMENT/Tau));
					membranePotential_=NewPotential;
				}
	
	void Neurone::setNeuroneRefractory (double time){
		RefractoryClock_=time+REFRACTORY_TIME;
	}
	bool Neurone::isRefractory (double time){
		return (time<=RefractoryClock_);
	}
	double Neurone::getMembranePotential() const{
		return membranePotential_;
	}
	vector<double> Neurone::getSpikesTime() const{
		return SpikesTime_;
	}

