#pragma once
#include"particle.hpp"

class Swarm{
    public:
        Swarm();
        Swarm(int swarmSize, double c1, double c2, double maxVelocity, vector<vector<int>> bounds); /* establish the swarm */
        void optimize(); 
        double getBestValue() { return bestValue_; }; 
        vector<double> getBestPos() { return bestPos_; };
        ~Swarm(); 
    private:
        const double c1_; /* cognitive velocity constant */
        const double c2_; /* social velocity constant */
        double constructionFactor_ = 1; /* how much to weigh the previous velocity */
        double bestValue_;
        int swarmSize_;
        Particle* swarmArray_;
        vector<double> bestPos_;  
};