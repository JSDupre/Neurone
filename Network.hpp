#include "Neurone.hpp"
#include <array>

class Network{
   private: 
      std::vector<Neurone> neurones_;
   public:
      Network();
      BuildNetwork(unsigned int number_of_neurones, double connection_probability);
      getNeurones();
 };
