#include "Network.hpp"
#include <random>

//#define NDEBUG
#include <cassert>

using namespace std;
		
	Network::Network(unsigned int numberOfNeurones,double exitatoryProportion,
      	double exitatoryConnectionProbability,double inhibitoryConnectionProbability,int clock)
	:clock_(clock){
		//assert the probability are in the correct range
			assert(exitatoryProportion>=0.0 and exitatoryProportion<=1);
			assert(exitatoryConnectionProbability>=0.0 and exitatoryConnectionProbability<=1);
			assert(inhibitoryConnectionProbability>=0.0 and inhibitoryConnectionProbability<=1);

			//creating our neurones
			int numberOfExitatoryNeurones(numberOfNeurones*exitatoryProportion);
		for (unsigned int i(0);i<=numberOfNeurones;++i){
			if(i<numberOfExitatoryNeurones){ //i start at 0 so < and not <=
				neurones_.push_back(new Neurone(clock,Iexterieur,true,i));
			}
			else{
				neurones_.push_back(new Neurone(clock,Iexterieur,false,i));
			}
		}
			//creating the connection
		for (unsigned int i(0);i<=numberOfNeurones;++i){
			neurones_[i]->setConnections(createConnectionForANeurone(numberOfNeurones,exitatoryProportion,numberOfExitatoryNeurones-1,
 				exitatoryConnectionProbability,inhibitoryConnectionProbability,i));
		}
	}

	vector<int> Network::createConnectionForANeurone(unsigned int numberOfNeurones,double exitatoryProportion,
      	unsigned int indixAfterWichEachNeuroneIsInhibitory,double exitatoryConnectionProbability,double inhibitoryConnectionProbability,unsigned int NeuroneIndix){
			vector<int> connections;
			//generation aléatoire
			static random_device rd;
			static mt19937 gen(rd());

			//uniforme sur les excitatoires
			static std::uniform_int_distribution<int> distributionEx(0,indixAfterWichEachNeuroneIsInhibitory);
			int numberOfExitatoryNeuronesConnection (numberOfNeurones*exitatoryConnectionProbability);
			for(unsigned int i(0);i<numberOfExitatoryNeuronesConnection;++i){
				int indix = distributionEx(gen);
				connections.push_back(indix);
			}

			//uniforme sur les inhib
			static std::uniform_int_distribution<int> distributionIn(indixAfterWichEachNeuroneIsInhibitory+1,numberOfNeurones-1);
			int numberOfInhibitoryNeuronesConnection (numberOfNeurones*inhibitoryConnectionProbability);
			for(unsigned int i(0);i<numberOfInhibitoryNeuronesConnection ;++i){
				int indix = distributionIn(gen);
				connections.push_back(indix);
			}
			return connections;
	}

      Network::~Network(){
      	for(auto& ptr:neurones_){
      		ptr=nullptr;
      		delete ptr;
      	}
      }

     void Network::runSimulation(double Tstop){
     	int TotalNumberOfTimeIncrement(Tstop/TimeIncrement);
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
     
     vector<Neurone*> Network::getNeurones(){
		 return neurones_;
	 }
