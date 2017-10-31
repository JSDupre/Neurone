#include "Neurone.hpp"
#include <vector>

#ifndef NETWORK_H
#define NETWORK_H

class Network{
   private: 
      std::vector<Neurone*> neurones_;
      int clock_;
      std::vector<int> createConnectionForANeurone(unsigned int numberOfNeurones,double exitatoryProportion,
      	unsigned int indixAfterWichEachNeuroneIsInhibitory,double exitatoryConnectionProbability,
      	double inhibitoryConnectionProbability,unsigned int NeuroneIndix);
   public:
      Network(unsigned int numberOfNeurones,double exitatoryProportion,
      	double exitatoryConnectionProbability,double inhibitoryConnectionProbability,int clock);
  
      ~Network();
      void runSimulation(double Tstop);
      std::vector<Neurone*> getNeurones();
 };

#endif
