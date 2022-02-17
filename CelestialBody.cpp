#include "CelestialBody.h"

CelestialBody::CelestialBody() {}

CelestialBody::CelestialBody(double xPos, double yPos, double xVel, double yVel, double mass, string filename, unsigned int xSize, unsigned int ySize, double radius) {

    this->xPos = xPos;
    this->yPos = yPos;
    this->xVel = xVel;
    this->yVel = yVel;
    this->mass = mass;
    this->radius = radius;
    this->filename = filename;
    this->xSize = xSize;
    this->ySize = ySize;

    image.loadFromFile(filename);
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    sprite.setPosition(((xPos/radius) * (xSize/2) + (xSize/2)), (yPos/radius) * (ySize/2) + (ySize/2));
}

double CelestialBody::getXPos() {

    return xPos;
}

double CelestialBody::getYPos() {

    return yPos;
}

double CelestialBody::getXVel() {

    return xVel;
}

double CelestialBody::getYVel() {

    return yVel;
}

double CelestialBody::getMass() {

    return mass;
}

string CelestialBody::getFilename() {

    return filename;
}

void CelestialBody::setXVel(double xV) {

    xVel = xV;
}

void CelestialBody::setYVel(double yV) {

    yVel = yV;
}

void CelestialBody::setXPos(double xP) {

    xPos = xP;
}

void CelestialBody::setYPos(double yP) {

    yPos = yP;
}

void CelestialBody::setPosition() {

    sprite.setPosition(((xPos/radius) * (xSize/2) + (xSize/2)), (yPos/radius) * (ySize/2) + (ySize/2));
}

void CelestialBody::draw(sf::RenderTarget& target, sf::RenderStates states) const {

    target.draw(sprite, states);
}

istream& operator>>(istream& in, CelestialBody &CelBody) {

    in >> CelBody.xPos;
    in >> CelBody.yPos;
    in >> CelBody.xVel;
    in >> CelBody.yVel;
    in >> CelBody.mass;
    in >> CelBody.filename;
    
    CelBody.image.loadFromFile(CelBody.filename);
    CelBody.texture.loadFromImage(CelBody.image);
    CelBody.sprite.setTexture(CelBody.texture);

    return in;
}

ostream& operator<<(ostream& out, CelestialBody &CelBody) {

    out << CelBody.xPos << " ";
    out << CelBody.yPos << " ";
    out << CelBody.xVel << " ";
    out << CelBody.yVel << " ";
    out << CelBody.mass << " ";
    out << CelBody.filename << endl;

    return out;
}