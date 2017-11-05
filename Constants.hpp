#include <cmath>

		//Constants obtained from the Brunel Paper
	const double SpikeThreshold(20);//mV
	const double Tau(20);//ms
	const double TimeIncrement(0.1);//ms
	const double C(1.0);//ms/ohm
	const double STANDART_POTENTIAL(0.0);//mV
	const double RefractoryTime(2);//ms 
	const double RefractoryPotential(10.0);//mV
	const int NumberOfExitatoryNeurone(10000);
	const int NumberOfInhibitoryNeurone(2500);
	const double ProbabilityOfConnection(0.1);
	const double g(3);//  Ji/Je ,see paper
	const double D(1.5); //delay (ms)
	const double Je(0.1); //connection strenght, the same for each exitatory connection for simplification
	const double Eta(2); //Nuext/NuThr
	
	//for graph procuction
	const int numberOfNeuronsToRecord(100);

		//Precomputation of constants depending the previous ones to avoid useless operation
	const double NeuroneResistance(Tau/C);
	const int RefractoryTimeInTimeIncrement(RefractoryTime/TimeIncrement);
	const int DelayInTimeIncrement(D/TimeIncrement);
	const double Ji(g*Je); //see Model
	const double Iexterieur(0.8); // test 
	const double NuExt((Eta*SpikeThreshold)/(Je*Tau)); //spikes*ms^-1, see Brunel paper
	const double NuExtTimeH (NuExt*TimeIncrement);
	const double R1(exp(-TimeIncrement/Tau));
	const double R2(NeuroneResistance*(1-exp(-TimeIncrement/Tau)));
	const int Ce(NumberOfExitatoryNeurone*ProbabilityOfConnection);
	const int Ci(NumberOfInhibitoryNeurone*ProbabilityOfConnection);
	const int TOTAL_NUMBER_OF_NEURONES(NumberOfExitatoryNeurone+NumberOfInhibitoryNeurone);
	const double NumberOfExitatoryNeuroneInDouble(NumberOfExitatoryNeurone);
	const double NumberOfInhibitoryNeuroneInDouble(NumberOfInhibitoryNeurone);
	const double EXITATORY_PROPORTION(NumberOfExitatoryNeuroneInDouble/(NumberOfExitatoryNeuroneInDouble+NumberOfInhibitoryNeuroneInDouble));

	
	
	
	

