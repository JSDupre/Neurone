#include <iostream>
#include "Neurone.hpp"
#include <fstream>
#include <iomanip>
#include "Constants.hpp"
using namespace std;

/*void recordValue(Neurone const& n,double time,ofstream& f);
void AskUserAnIntervalle(double borneInf, double borneSup,double min,double max);
double AskUserADouble();*/


void recordValue(Neurone const& n,double time,ofstream& out)
{
	out<<setprecision(3)<<time<<" "<<n.getMembranePotential()<<endl;
}

double AskUserADouble() {
	double result;
		cin>>result;
	return result;
	}

void AskUserAnIntervalle(double borneInf, double borneSup,double min,double max)
{
	do{
		cout<<"entrez borne inf (entre 0 et Tstop)"<<endl;
	borneInf=AskUserADouble();
	} while (borneInf<min or borneInf>max);
	
	do{
		cout<<"entrez borne sup (entre 0 et Tstop)"<<endl;
	borneSup=AskUserADouble();
	} while (borneSup<min or borneSup>max or borneSup<borneInf);
}


int main() {
		Neurone n; //un neurone
		
		cout<<"temps de simulation? (s)"<<endl;
		double Tstop(AskUserADouble());
		int TotalNumberOfIncrement = Tstop/TimeIncrement;//calcul du nombre de pas de simulation (pourrait prendre une valeur max)
		
		double BorneInfIntervalle;
		double BorneSupIntervalle;
		AskUserAnIntervalle(BorneInfIntervalle,BorneSupIntervalle,0.0,Tstop);
		
		cout<<"Input value? (mA)"<<endl;
		double Iext(AskUserADouble());
		
		ofstream f("values.txt",ios::trunc);//declaration du stream d'ecriture
		
		//simulation loop
		for(unsigned int i(0);i<TotalNumberOfIncrement;++i){
			recordValue(n,i*TimeIncrement,f);
			if(i*TimeIncrement>=BorneInfIntervalle and i*TimeIncrement<BorneSupIntervalle){
				n.update(1,Iext,0.0);
			}
			else {
				n.update(1,0.0,0.0);
			}
		}
	}
