#include "Connection.hpp"


    Connection::Connection((unsigned int postIndix,double J)
    :postsynapticNeuroneIndix_(postIndix),J_(J){}
    
    unsigned int Connection::getPostIndix() const{
      return postsynapticNeuroneIndix_;
    }
    double Connection::getJ() const{
      return J_;
    }
	
