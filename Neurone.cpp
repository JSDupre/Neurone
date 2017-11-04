#include <iostream>
#include "Neurone.hpp"
#include <cmath>
#include <random>
using namespace std;

	Neurone::Neurone (int clock,double Iext,bool isExitatory,int neuroneID)
	:spikeRingBuffer_(DelayInTimeIncrement+1,0.0),membranePotential_(STANDART_POTENTIAL)
	,localClock_(clock),Iext_(Iext),isExitatory_(isExitatory),neurone_ID_(neuroneID){}
	
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
					static random_device rd;
					static mt19937 gen(rd());
					static poisson_distribution<> distribution (NuExtTimeH);
					int numberOfExternalSpike(distribution(gen));
					double externalRandomPart(Je*numberOfExternalSpike);
					
					double decayingPart(membranePotential_*R1);
					double externalCurrentPart(Iext_*R2);
					membranePotential_=decayingPart+externalCurrentPart+spikeRingBuffer_[currentIndex]+externalRandomPart;
				}
				localClock_+=1;
				//reset ring buffer slot
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
		if(isExitatory_){return Je;}
		else{return-Ji;}
	}
