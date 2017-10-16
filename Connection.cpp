#include "Connection.hpp"


    Connection::Connection(Neurone* post,double J,unsigned int D)
    :postsynapticNeurone_(post),J_(J){}
    
    Neurone* Connection::getPost(){
      return postsynapticNeurone_;
    }
    double Connection::getJ() const{
      return J_;
    }
