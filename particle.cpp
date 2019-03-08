#include "particle.hpp"

Particle::Particle(){}

Particle::Particle(double maxVelocity, vector<vector<int>> bounds){
    bounds_ = bounds;
    dimension_ = bounds_.size();

    for (int i = 0; i < dimension_; i++) 
        pos_.push_back(randomDouble(bounds_[i][0], bounds_[i][1]));
    
    for (int i = 0; i < dimension_; i++) 
        velocity_.push_back(randomDouble(maxVelocity * (-1), maxVelocity));
 
    bestPos_ = pos_;
    bestValue_ = 100000;
    maxVelocity_ = maxVelocity;
}

double Particle::checkBestValue(){
    double tmp = func(pos_[0], pos_[1]);
    if (tmp < bestValue_) {
        bestValue_ = tmp;
        bestPos_ = pos_;
    }
    return tmp;
}

void Particle::updatePosition(){
    for (int i = 0; i < dimension_; i++) {
        pos_[i] += velocity_[i];
        
        /* if out of bounds */
        if (pos_[i] < bounds_[i][0])
            pos_[i] = bounds_[i][0];
            
        else if (pos_[i] > bounds_[i][1])
            pos_[i] = bounds_[i][1];
    }
}

void Particle::updateVelocity(double c1, double c2, double constructionFactor, vector<double> bestPos){
    for (int i = 0; i < dimension_; i++){
        double velCognitive = randomDouble(0,c1) * (bestPos_[i] - pos_[i]);
        double velSocial = randomDouble(0,c2) * (bestPos[i] - pos_[i]);
        double velocity = constructionFactor * velocity_[i] + velCognitive + velSocial;
        
        velocity_[i] = 
            abs(velocity) > abs(maxVelocity_) ? maxVelocity_ * (velocity < 0 ? -1 : 1) : velocity;
    }
}
