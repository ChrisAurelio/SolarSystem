#include "Universe.h"

Universe::Universe() {}

CelestialBody CBody;

const std::shared_ptr<CelestialBody>& Universe::bodyNum(int index) const {

    return CelBodies[index];
}

void Universe::push(std::shared_ptr<CelestialBody> &CelBody) {

    CelBodies.push_back(CelBody);
}

void Universe::step(double seconds) {

    for(auto CelBody : CelBodies) {

        for(auto i = CelBodies.begin(); i != CelBodies.end(); i++) {

            if(CelBody == *i)
                continue;

            deltaX = (*i)->getXPos() - CelBody->getXPos();
            deltaY = (*i)->getYPos() - CelBody->getYPos();
            radius = std::sqrt((deltaX * deltaX) + (deltaY * deltaY));
            F = (6.67e-11 * CelBody->getMass() * (*i)->getMass()) / (radius * radius);
            Fx = F * deltaX / radius;
            Fy = F * deltaY / radius;

            netX += Fx;
            netY += Fy;
        }

        Ax = netX / CelBody->getMass();
        Ay = netY / CelBody->getMass();

        CelBody->setXVel(CelBody->getXVel() + (Ax * seconds));
        CelBody->setYVel(CelBody->getYVel() - (Ay * seconds));

        netX = 0.0;
        netY = 0.0;
    }

    for (auto CelBody : CelBodies) {

        CelBody->setXPos(CelBody->getXPos() + (seconds * CelBody->getXVel()));
        CelBody->setYPos(CelBody->getYPos() - (seconds * CelBody->getYVel()));

        CelBody->setPosition();
    }
}