#include <iostream>
#include "Neurone.hpp"
#include <fstream>
#include <iomanip>
#include "Constants.hpp"
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

void AskUserAnIntervalle(double borneInf, double borneSup,double min,double max)
{
	/*
	do{
		cout<<"entrez borne inf (entre 0 et Tstop)"<<endl;
	borneInf=AskUserADouble();
	} while (borneInf<min or borneInf>max);
	
	do{
		cout<<"entrez borne sup (entre borne sup et Tstop)"<<endl;
	borneSup=AskUserADouble();
	} while (borneSup<min or borneSup>max or borneSup<borneInf);*/
}


int main() {
		Neurone n; //un neurone
		
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
		
		//loop for two or more neurone
		
		return 0;
	}
