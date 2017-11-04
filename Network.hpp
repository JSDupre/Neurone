#include "Neurone.hpp"
#include <vector>
#include <fstream>

#ifndef NETWORK_H
#define NETWORK_H
/**
 * class for a network of neurons.
 * create all the neurons that it contain and is able to run a simulation according to the constants in "Constants.hpp"
 */
class Network{
   private: 
      std::vector<Neurone*> neurones_; //!<neurons of the network
      int clock_;//!<clock of the simulation
      /**
       * \brief create random connections for a neurons with other neurons of the network depending of certain parameters
       * 
       * @param numberOfNeurones the number of neurons in the network
       * @param exitatoryProportion the proportion of excitatory neurons in the network
       * @param indixAfterWichEachNeuroneIsInhibitory the indix after wich each neuron of the network is inhibitory
       * @param exitatoryConnectionProbability the probabity of connection with excitatory neurons
       * @param inhibitoryConnectionProbability the probabity of connection with inhibitory neurons
       * @param NeuroneIndix the indix of the neuron we are creating the connections for
       */
      std::vector<int> createConnectionForANeurone(unsigned int numberOfNeurones,double exitatoryProportion,
      	unsigned int indixAfterWichEachNeuroneIsInhibitory,double exitatoryConnectionProbability,
      	double inhibitoryConnectionProbability,unsigned int NeuroneIndix);
      	
   public:
	   /** \brief constructor for Network
       * 
       * @param numberOfNeurones the number of neurons in the network
       * @param exitatoryProportion the proportion of excitatory neurons in the network
       * @param exitatoryConnectionProbability the probabity of connection with excitatory neurons
       * @param inhibitoryConnectionProbability the probabity of connection with inhibitory neurons
       * @param clock the initial clock of the network
       */
      Network(unsigned int numberOfNeurones,double exitatoryProportion,
      	double exitatoryConnectionProbability,double inhibitoryConnectionProbability,int clock);
      /** \brief destructor for Network
       * 
       * handle the correct memory desallocation and destruction of the neurons of the network
       */
      ~Network();
      /** \brief run the simulation of the network during Tstop seconds according to the constants in "Constants.hpp"
       * 
       * @param Tstop the ending time of the simulation in seconds
       */
      void runSimulation(double Tstop);
      /** \brief return the spike's times of a certain neuron of the network in a vector
       * 
       * @param indix the indix of the neuron
       */
      std::vector<int> getSpikesVectorForNeuroneAtIndix(unsigned int indix);
 };

#endif
