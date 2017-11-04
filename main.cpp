#include <fstream>
#include "Network.hpp"

//#define NDEBUG
#include  <cassert>
using namespace std;

double AskUserADouble();
void writeSpikesDataFile(Network & network,unsigned int numberOfNeuronesToRecord);

int main() {
			//simulation
		cout<<"temps de simulation? (ms)"<<endl;
		double Tstop(AskUserADouble());
		int clock(0);
		Network network (TOTAL_NUMBER_OF_NEURONES,EXITATORY_PROPORTION,ProbabilityOfConnection,ProbabilityOfConnection,clock);
		cerr<<"build network fini"<<endl;
		network.runSimulation(Tstop);
		cerr<<"simulation finished"<<endl;
			//writing simulation result for latter analisys
		writeSpikesDataFile(network,100);
		cerr<<"ecriture ok"<<endl;
		
		return 0;
	}
void writeSpikesDataFile(Network & network,unsigned int numberOfNeuronesToRecord)
{
	ofstream out("spikes.txt",ios::trunc); //declaration stream d'ecriture
	for(unsigned int i(0);i<numberOfNeuronesToRecord;++i){
		for(unsigned int j(0);j<(network.getSpikesVectorForNeuroneAtIndix(i)).size();++j){
		out<<network.getSpikesVectorForNeuroneAtIndix(i)[j]*0.001<<"\t"<<i<<"\n"; //the 0.01 is to adjust the graph to the settings of the web application wich draw
																				// the graph
		}
	}
}


double AskUserADouble() {
	//on pourrait checker que l'entrée soit correcte
	double result;
		cin>>result;
	return result;
	}
