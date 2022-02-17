#include "CelestialBody.h"
#include "Universe.h"

int main(int argc, char* argv[]) {

	if(argc != 3) {
    	std::cerr << "There must be two command line arguments." << endl;
    	return -1;
    }

    string firstInput = argv[1];
    string secondInput = argv[2];
	string::size_type sz;

	double timeLimit = std::stod(firstInput, &sz);
	double rate = std::stod(secondInput, &sz);
	double elapsedTime = 0;

	sf::Font font;
	if(!font.loadFromFile("axis.ttf"))
		return -1;

	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::White);
	text.move(15.f, 10.f);
	
	sf::Music music;
	if (!music.openFromFile("RobotRock.ogg"))
		return -1;

	music.play();
	music.setLoop(true);

    sf::Image background;
    if (!background.loadFromFile("background.png"))
	    return -1;

    sf::Texture backTexture;
    backTexture.loadFromImage(background);

    sf::Sprite backSprite;
    backSprite.setTexture(backTexture);

    sf::Vector2u size = background.getSize();
	sf::RenderWindow window(sf::VideoMode(size.x, size.y), "N-Body Simulation");
	window.setFramerateLimit(60);

	Universe universe;

	int numOfPlanets;
	double radius;

	cin >> numOfPlanets;
	cin >> radius;

	for(int i = 0; i < numOfPlanets; i++) {

		CelestialBody CelBody;
		cin >> CelBody;
		std::shared_ptr<CelestialBody> CelBody_ptr(new CelestialBody(CelBody.getXPos(), CelBody.getYPos(), 
		CelBody.getXVel(), CelBody.getYVel(), CelBody.getMass(), CelBody.getFilename(), size.x, size.y, radius));
		universe.push(CelBody_ptr);
	}

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(backSprite);
		
		text.setString("Elapsed Time: " + std::to_string(static_cast<int>(elapsedTime)));
		window.draw(text);

		universe.step(rate);

		for(int i = 0; i < numOfPlanets; i++) {

			window.draw(*universe.bodyNum(i));
		}

		elapsedTime += rate;

		window.display();

		if(elapsedTime > timeLimit)
			window.close();

	}

	cout << numOfPlanets << endl;
	cout << std::scientific << std::setprecision(2) << radius << endl;

	for(int i = 0; i < numOfPlanets; i++) {

		cout << std::scientific << std::setprecision(4) << *universe.bodyNum(i);
	}

    return 0;
}
