#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>
#include <math.h>
#include <cmath>

sf::Vector2f center;

double GetY(double x) {
    double power = 1.0 / 3.0;
    return (double)(pow(pow(x + 2, 2), power)) - (pow(pow(x - 2, 2), power));
}

sf::Vertex GetPoint(double x)
{
    sf::Vertex vertex;

    double y = GetY(x);
    vertex.color = sf::Color::White;
    sf::Vector2f pos = sf::Vector2f(x * 10, y * 10) + center;
    vertex.position = pos;

    return vertex;
}


sf::Vector2f GetCenter(sf::RenderWindow& window)
{
    sf::Vector2f center = sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2);
    return center;
}

sf::CircleShape CreateCircle() {
    sf::CircleShape circle(2);
    circle.setPosition(center);
    circle.setFillColor(sf::Color::Red);
    return circle;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "");
    center = GetCenter(window);

    sf::CircleShape centerCircle = CreateCircle();

    std::cout << "Enter a min number: ";
    int min = 0;
    std::cin >> min;

    std::cout << "Enter a max number: ";
    int max = 0;
    std::cin >> max;

    sf::VertexArray vertexes;


    for (double i = min; i <= max; i += 0.1) {
        vertexes.append(GetPoint(i));
    }


    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();

                break;
            }
        }
        window.draw(vertexes);
        window.draw(centerCircle);

        window.display();
    }
}