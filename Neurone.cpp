#include <iostream>
#include "Neurone.hpp"
#include <cmath>
using namespace std;

	Neurone::Neurone (int clock,double Iext,bool isExitatory)
	:spikeRingBuffer_(DelayInTimeIncrement+1,0.0),membranePotential_(STANDART_POTENTIAL)
	,localClock_(clock),Iext_(Iext),isExitatory_(isExitatory){}
	
	bool Neurone::update(unsigned int const& NumberOfTimeIncrement){
		bool spike(false);
		for(unsigned int i(1);i<=NumberOfTimeIncrement;++i){
			size_t currentIndex(localClock_%spikeRingBuffer_.size());
				if(membranePotential_>=SpikeThreshold)
				{
					//1 we store the spike time
					SpikesTimeInNumberOfTimeIncrement_.push_back(localClock_);
					//2 the neurone goes refractory: the potential fall down to 0
					membranePotential_=RefractoryPotential;
					spike=true;
				} 
				
				else if(not SpikesTimeInNumberOfTimeIncrement_.empty() and (localClock_-SpikesTimeInNumberOfTimeIncrement_.back())<=RefractoryTimeInTimeIncrement) //on regarde le temps ecoulé depuis le dernier spike
				{
					membranePotential_=RefractoryPotential;
				} 
				else
				{
					double NewPotential;
					NewPotential=membranePotential_*exp(-TimeIncrement/Tau)+Iext_*NeuroneResistance*(1-exp(-TimeIncrement/Tau));
					NewPotential+=spikeRingBuffer_[currentIndex]; 
					if(spikeRingBuffer_[currentIndex]!=0.0){cerr<<"Ring buff value : "<<spikeRingBuffer_[currentIndex]<<endl;}
					membranePotential_=NewPotential;
				}
				localClock_+=1;
				//reset ring buffer
				spikeRingBuffer_[currentIndex]=0.0;
				}
			
			return spike;
		}
	
	double Neurone::getMembranePotential() const{
		return membranePotential_;
	}

	std::vector<int> Neurone::getSpikesTimeInNumberOfTimeIncrement() const{
		return SpikesTimeInNumberOfTimeIncrement_;
	}
	vector<int> Neurone::getConnections() const{
		return connections_;
	}
	void Neurone::setConnections (vector<int> const& connections){
		connections_=connections;
	}
	void Neurone::receive(int clockPlusDelay,double J){
		size_t storageIndex(clockPlusDelay % spikeRingBuffer_.size());
		spikeRingBuffer_[storageIndex]+=J;
	}
	vector<double> Neurone::getRingBuffer() const{
		return spikeRingBuffer_;
	}

	double Neurone::getJsentToPostSynapticNeurone() const{
		if(isExitatory_){return J;}
		else{return-J;}
	}
