#include <iostream>
#include "Neurone.hpp"
#include <cmath>
using namespace std;

	Neurone::Neurone (int clock,double Iext)
	:spikeRingBuffer_(DelayInTimeIncrement+1,1.0),membranePotential_(STANDART_POTENTIAL),localClock_(clock),Iext_(Iext){
			cerr<<"creation neurone taille ring buffer :"<<DelayInTimeIncrement+1<<endl;
		}
	
	bool Neurone::update(unsigned int const& NumberOfTimeIncrement){
		bool spike(false);
		for(unsigned int i(1);i<=NumberOfTimeIncrement;++i){
			size_t currentIndex(localClock_%spikeRingBuffer_.size());
			cerr<<"IND : "<<currentIndex<<endl;
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
					if(spikeRingBuffer_[currentIndex]!=0.0){cerr<<"ATTENTION POT :"<<spikeRingBuffer_[currentIndex]<<endl;}
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
	vector<Connection> Neurone::getConnections() const{
		return connections_;
	}
	void Neurone::setConnections (vector<Connection>& connections){
		connections_=connections;
	}
	void Neurone::receive(int clockPlusDelay,double J){
		for(auto& n:spikeRingBuffer_){
			n+=60;
		}
		size_t storageIndex(clockPlusDelay % spikeRingBuffer_.size());
		spikeRingBuffer_[storageIndex]+=J;
		cerr<<"differnces delais"<<clockPlusDelay-localClock_<<endl;
		
				cerr<<"local : "<<getLocalClock()<<endl; //ULTRA BIZARRE
		cerr<<"taille ring buffer"<<spikeRingBuffer_.size()<<endl;
		cerr<<"Recep :"<<J<<"dans "<<storageIndex<<endl;
		cerr<<"indice courant = "<<localClock_%spikeRingBuffer_.size()<<endl;
		cerr<<"valeur :"<<spikeRingBuffer_[storageIndex]<<endl;
	}
	vector<double> Neurone::getRingBuffer() const{
		return spikeRingBuffer_;
	}
	
	int Neurone::getLocalClock() const {
		return localClock_;
	}

