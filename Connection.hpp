
#ifndef CONNECTION_H
#define CONNECTION_H

class Connection {
  private: 
    size_t postsynapticNeuroneIndix_;
    double J_; //connection strenght
    
   public:
    Connection(unsigned int postIndix,double J);
    unsigned int getPostIndix() const;
    double getJ() const;
};
    
#endif
