#include "Network.hpp"
#include <random>

//#define NDEBUG
#include <cassert>

using namespace std;
		
	Network::Network(unsigned int const& numberOfNeurones,double const& exitatoryProportion,
      	double const& exitatoryConnectionProbability,double const& inhibitoryConnectionProbability,int const& clock)
	:clock_(clock){
		//assert the probability are in the correct range
			assert(exitatoryProportion>=0.0 and exitatoryProportion<=1);
			assert(exitatoryConnectionProbability>=0.0 and exitatoryConnectionProbability<=1);
			assert(inhibitoryConnectionProbability>=0.0 and inhibitoryConnectionProbability<=1);
		
			//creating our neurones
			int numberOfExitatoryNeurones(numberOfNeurones*exitatoryProportion);
			if(exitatoryConnectionProbability==0.5){
			cerr<<"numberOfExitatoryNeurones "<<numberOfExitatoryNeurones<<endl;
		}
		for (unsigned int i(0);i<numberOfNeurones;++i){ //i start at 0 so < and not <=
			if(i<numberOfExitatoryNeurones){ //i start at 0 so < and not <=
				neurones_.push_back(new Neurone(clock,Iexterieur,true,i));
			}
			else{
				neurones_.push_back(new Neurone(clock,Iexterieur,false,i));
			}
		}
		if(exitatoryConnectionProbability==0.5){
			cerr<<"creation enurones ok"<<endl;
		}
			//creating the connection
		for (unsigned int i(0);i<numberOfNeurones;++i){
			neurones_[i]->setConnections(createConnectionForANeurone(numberOfNeurones,exitatoryProportion,
 				exitatoryConnectionProbability,inhibitoryConnectionProbability,i));
 				if(exitatoryConnectionProbability==0.5){
			cerr<<" conn pour neuonr "<<i<<" ok "<<endl;
		}
		}
	}

	vector<unsigned int> Network::createConnectionForANeurone(unsigned int const& numberOfNeurones,double const& exitatoryProportion,
      	double const& exitatoryConnectionProbability,double const& inhibitoryConnectionProbability,unsigned int const& NeuroneIndix){
			vector<unsigned int> connections;
			unsigned int indixAfterWichEachNeuroneIsInhibitory(numberOfNeurones*exitatoryProportion-1);
			//generation aléatoire
			static random_device rd;
			static mt19937 gen(rd());if(exitatoryConnectionProbability==0.5){
			cerr<<"generation connection : debut "<<endl;
		}

			//uniforme sur les excitatoires
			static std::uniform_int_distribution<int> distributionEx(0,indixAfterWichEachNeuroneIsInhibitory);
			int numberOfExitatoryNeuronesConnection (numberOfNeurones*exitatoryConnectionProbability);
			for(unsigned int i(0);i<numberOfExitatoryNeuronesConnection;++i){
				int indix = distributionEx(gen);
				connections.push_back(indix);
			}
			if(exitatoryConnectionProbability==0.5){
			cerr<<"exi ok "<<endl;
		}

			//uniforme sur les inhib
			static std::uniform_int_distribution<> distributionIn(indixAfterWichEachNeuroneIsInhibitory+1,numberOfNeurones-1);
			if(exitatoryConnectionProbability==0.5){
			cerr<<"debut neurons possible : "<<indixAfterWichEachNeuroneIsInhibitory+1<<endl;
		}
		if(exitatoryConnectionProbability==0.5){
			cerr<<"fin neurons possible : "<<numberOfNeurones-1<<endl;
		}
			//static std::uniform_int_distribution<> distributionIn(0,(numberOfNeurones-1)-(indixAfterWichEachNeuroneIsInhibitory+1));
			int numberOfInhibitoryNeuronesConnection (numberOfNeurones*inhibitoryConnectionProbability);
			if(exitatoryConnectionProbability==0.5){
			cerr<<"numberOfInhibitoryNeuronesConnection "<<numberOfInhibitoryNeuronesConnection<<endl;
		}
			for(unsigned int i(0);i<numberOfInhibitoryNeuronesConnection ;++i){
				if(exitatoryConnectionProbability==0.5){
			cerr<<"nueuron num "<<i<<endl;
		}
				int indix(distributionIn(gen));//+(indixAfterWichEachNeuroneIsInhibitory+1);
				if(exitatoryConnectionProbability==0.5){
			cerr<<"indix "<<indix<<endl;
		}
				connections.push_back(indix);
			}
			if(exitatoryConnectionProbability==0.5){
			cerr<<"exi ok "<<endl;
		}
			return connections;
	}

      Network::~Network(){
      	for(auto& ptr:neurones_){
      		ptr=nullptr;
      		delete ptr;
      	}
      }

     void Network::runSimulation(double const& Tstop){
     	int TotalNumberOfTimeIncrement(Tstop/TimeIncrement);
     	cout<<"simulation en cours : "<<endl;
     	int compteur(0);
     	while (clock_<TotalNumberOfTimeIncrement){
			for(auto& n:neurones_){ 
				bool spike(n->update(1));
				if(spike){
					for(auto& indixNeuroneConnected:n->getConnections()){
						neurones_[indixNeuroneConnected]->receive((clock_+D),n->getJsentToPostSynapticNeurone());
						//network.getNeurones()[connection.getPostIndix()]->receive((clock+D),connection.getJ());

					}
				}
			}
			clock_+=1;
		}
     }
     
     std::vector<int> Network::getSpikesVectorForNeuroneAtIndix(unsigned int const& indix)const{
		 assert(indix<neurones_.size());
		 return (neurones_[indix]->getSpikesTimeInNumberOfTimeIncrement());
	 }
	 
