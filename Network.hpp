#include "Neurone.hpp"
#include <array>

class Network{
   private: 
      array<Neurone>;
   public:
      Network();
      BuildNetwork(unsigned int number_of_neurones, double connection_probability);
 };
