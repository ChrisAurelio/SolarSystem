#ifndef CELESTIALBODY_H
#define CELESTIALBODY_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Export.hpp>
#include <SFML/Graphics/RenderStates.hpp>

using std::cin;
using std::cout;
using std::endl;
using std::move;
using std::vector;
using std::istream;
using std::ostream;
using std::string;

class CelestialBody : public sf::Drawable {

    public:

        CelestialBody();
        CelestialBody(double xPos, double yPos, double xVel, double yVel, double mass, string filename, unsigned int xSize, unsigned int ySize, double radius);
        double getXPos();
        double getYPos();
        double getXVel();
        double getYVel();
        double getMass();
        string getFilename();
        void setXVel(double xV);
        void setYVel(double yV);
        void setXPos(double xP);
        void setYPos(double yP);
        void setPosition();
        friend istream& operator>>(istream& in, CelestialBody &CelBody);
        friend ostream& operator<<(ostream& out, CelestialBody &CelBody);

    private:

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        unsigned int xSize;
        unsigned int ySize;
        double radius;
        double xPos;
        double yPos;
        double xVel;
        double yVel;
        double mass;
        string filename;
        sf::Image image;
        sf::Texture texture;
        sf::Sprite sprite;
};

#endif