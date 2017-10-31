#include <fstream>
#include "Network.hpp"

//#define NDEBUG
#include  <cassert>
using namespace std;

void writeSpikesDataFile(Network & network,ofstream& out,unsigned int numberOfNeuronesToRecord);
double AskUserADouble();


int main() {
			//simulation
		cout<<"temps de simulation? (ms)"<<endl;
		double Tstop(AskUserADouble());
		int clock(0);
		Network network (TOTAL_NUMBER_OF_NEURONES,EXITATORY_PROPORTION,ProbabilityOfConnection,ProbabilityOfConnection,clock);
		network.runSimulation(Tstop);
		
			//writing simulation result for latter analisys
		ofstream spikeWriting("spikes.txt",ios::trunc);//declaration du stream d'ecriture
		writeSpikesDataFile(network,spikeWriting,30);
		
		return 0;
	}

void writeSpikesDataFile(Network & network,ofstream& out,unsigned int numberOfNeuronesToRecord)
{
	assert(numberOfNeuronesToRecord<=(network.getNeurones()).size());
	for(unsigned int i(0);i<=numberOfNeuronesToRecord-1;++i){
		for(unsigned int j(0);j<=((network.getNeurones())[i]->getSpikesTimeInNumberOfTimeIncrement()).size()-1;++j)
		out<<i<<"/"<<((network.getNeurones())[i]->getSpikesTimeInNumberOfTimeIncrement()[j])
		*TimeIncrement<<"/n";
	}
}

double AskUserADouble() {
	//on pourrait checker que l'entrée soit correcte
	double result;
		cin>>result;
	return result;
	}
