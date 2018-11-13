#include "swarm.hpp"

Swarm::Swarm(int swarmSize, double c1, double c2, double maxVelocity, vector<vector<int>> bounds):
    c1_(c1), c2_(c2),swarmSize_(swarmSize){
    
    swarmArray_ = new Particle[swarmSize];
    for (int i = 0; i < swarmSize; i++) 
        swarmArray_[i] = Particle(maxVelocity, bounds);

    for (int i = 0; i < bounds.size(); i++)  
        bestPos_.push_back(0);
     
    if (c1_ + c2_ > 4)
        constructionFactor_ = 2 / (2 + sqrt((c1_ + c2_)*(c1_ + c2_) - 4 * (c1_ + c2_)));

    bestValue_ = 100000;
}

void Swarm::optimize(){
    for (int i = 0; i < swarmSize_; i++) { /* evaluate fitness of particle */
        double tmp = swarmArray_[i].checkBestValue(); 
        if (tmp < bestValue_){
            bestValue_ = tmp;
            bestPos_ = swarmArray_[i].getBestPos();
        }
    }

    for (int i = 0; i < swarmSize_; i++){
        swarmArray_[i].updateVelocity(c1_, c2_, constructionFactor_, bestPos_);
        swarmArray_[i].updatePosition();
    }
}

Swarm::~Swarm(){
    delete [] swarmArray_;
}