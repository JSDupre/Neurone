//google test 2 neurones
#include "gtest/gtest.h"
#include "Network.hpp"
#include <vector>
using namespace std;

int main(int argc; char* argv[]){
	::testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}

TEST(test1Neurone,correctPotWithIext){
	Neurone n(0,1,true);
	cerr<<"neurone with Iext=1"<<endl;
	bool test1=n.update(1);
	EXPECT_EQ(n.getMembranePotential(),1*R1);
	bool spike=n.update(10000);
	EXPECT_FALSE(spike);
}

TEST(test1Neurone,SpikeAtACorrectTime){
	Neurone n(0,1.01,true);
	cerr<<"neurone with Iext=1.01"<<endl;;
	bool spike=n.udpate(3000);
	EXPECT_TRUE(spike);
	EXPECT_TRUE(n.getSpikesTimeInNumberOfTimeIncrement()[0]==924);
	EXPECT_TRUE(n.getSpikesTimeInNumberOfTimeIncrement()[1]==1859);
	EXPECT_TRUE(n.getSpikesTimeInNumberOfTimeIncrement()[2]==2794);
}

TEST(test2Neurons,correctConnection){
	Neurone n1(0,1,true,1);
	Neurone n2(0,1,true,2);
	std::vector<int> co(1,2);
	n1.setConnection(co);
	EXPECT_TRUE(n1.getConnections()[0]==2);
}

TEST(testNetwork,correctConnection){
	Network network (2,1,1,0,0);
	cerr<<"2 exitatory neurons with each other connected"<<endl;
	EXPECT_TRUE(network.getNeuroneAtIndix(0)->getConnections()[0]==1);
	EXPECT_TRUE(network.getNeuroneAtIndix(1)->getConnections()[0]==0);
}
	//for further test we will see if the graph are correct 
/*
TEST(testNetwork,exitatoryNetwork){
	EXPECT_TRUE(Iexterieur==0.0)<<"now Iext=0.0 but there is exitatory spike
	 comming from the rest of the brain"<<endl;
	Network network (2,1,0,1,0)<<"network with 2 inhibitory neurons"<<endl;
	network.run(1)<<"we run the network for 1s"<<endl;
	EXPECT_TRUE
}*/
