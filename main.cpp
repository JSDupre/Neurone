#include <iostream>
#include "Neurone.hpp"
#include <fstream>
#include <iomanip>
#include "Constants.hpp"
#include <vector>
using namespace std;

bool isInIntervalle(double ToTest,double Inf,double Sup){
	bool x(ToTest>=Inf and ToTest<Sup);
	return x;
}
void recordValue(Neurone const& n,double time,ofstream& out)
{
	out<<setprecision(3)<<time<<" "<<n.getMembranePotential()<<endl;
}

double AskUserADouble() {
	//on pourrait checker que l'entrée soit correcte
	double result;
		cin>>result;
	return result;
	}

int main() {
		Network network;
		network.BuildNetwork(2,1);//pour l'instant 2 neurones connectés
		
		cout<<"temps de simulation? (ms)"<<endl;
		double Tstop(AskUserADouble());
		int TotalNumberOfIncrement = Tstop/TimeIncrement;//calcul du nombre de pas de simulation (pourrait prendre une valeur max)
		
		cout<<"entrez borne inf (entre 0 et Tstop)"<<endl;
		double BorneInfIntervalle(AskUserADouble());
		
		cout<<"entrez borne sup (entre borne sup et Tstop)"<<endl;
		double BorneSupIntervalle(AskUserADouble());
		
		cout<<"Input value?"<<endl;
		double Iext(AskUserADouble());
		
		ofstream f("values.txt",ios::trunc);//declaration du stream d'ecriture
		/*
		//simulation loop for a single neurone
		for(unsigned int i(0);i<TotalNumberOfIncrement;++i){
			recordValue(n,i*TimeIncrement,f);
			if(isInIntervalle(i*TimeIncrement,BorneInfIntervalle,BorneSupIntervalle)){
				n.update(1,Iext,0.0);
			}
			else {
				n.update(1,0.0,0.0);
			}
		}
		*/
		double clock(0);
		//loop for two or more neurone
		while (clock<TotalNumberOfTimeIncrement){
			for(auto& n:network.getNeurones()){
				bool spike=n.update(1,clock); //arguments pour neurone::update ??
				if(spike){
					for(auto& connection:n.getConnections()){
						(connection.getPost()).receive(clock+connection.getD(),connection.getJ());
					}
				}
			}
			clock+=1;
		}
			
		
		return 0;
	}
