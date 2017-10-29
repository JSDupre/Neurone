google test 2 neurones

Neurone n1(clock,170);
		Neurone n2(clock,0.0);
		vector<Neurone> network;
		network.push_back(n1);
		network.push_back(n2);
		Connection c(1,200);//connection to n2
		vector<Connection> co;
		co.push_back(c);
		n1.setConnections(co);