#pragma once
#include "mathUtils.hpp"

class Particle{
    public:
        Particle();
        Particle(double maxVelocity, vector<vector<int>> bounds); 
        double checkBestValue(); /* checks value of function that we want to optimize */
        void updatePosition(); /* updates the particle position based on new velocity updates */
        void updateVelocity(double c1, double c2, double constructionFactor, vector<double> bestPos); /* updates velocity based on social and cognitive velocity */
        vector<double> getBestPos() { return bestPos_; };
    private:
        vector<vector<int>> bounds_; 

        vector<double> pos_;
        vector<double> velocity_;
        vector<double> bestPos_; 
    
        double bestValue_;
        double maxVelocity_;
        int dimension_;
};