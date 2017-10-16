

class Neurone;//predeclaration pour eviter dependance circulaire

class Connection {
  private: 
    Neurone* postsynapticNeurone_;
    double J; //connection strenght
    unsigned int D; //delay in the transmission of the spikes
    
   public:
    Connection(Neurone* pre,Neurone* post,double J,unsigned int D)
    Connection(Connection const& c)=delete;
    ~Connection();
    getPost(); //const?
    getJ() const;
    getD() const;
};
    
   
