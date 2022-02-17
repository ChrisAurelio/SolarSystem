#ifndef UNIVERSE_H
#define UNIVERSE_H

#include "CelestialBody.h"
#include <vector>
#include <memory>
#include <new>

class Universe {

    public:

        Universe();
        const std::shared_ptr<CelestialBody>& bodyNum(int index) const;
        void push(std::shared_ptr<CelestialBody> &CelBody);
        void step(double seconds);

    private:

        vector<std::shared_ptr<CelestialBody>> CelBodies;
        double Ax;
        double Ay;
        double deltaX;
        double deltaY;
        double newXPos;
        double newYPos;
        double newXVel;
        double newYVel;
        double radius;
        double F;
        double Fx;
        double Fy;
        double netX;
        double netY;
};

#endif
