#include <SFML/Graphics.hpp>
#include<stdio.h> 
#include<math.h> 
#include <random>
#include <iostream>
#include <iomanip>
#include "windows.h"

#define lim_dot 1e7 //Максимальное количество точек
#define r 500 //Начальный радиус
using namespace sf;
using namespace std;
double circle(double, double);

double circle(double x, double radius)
{
    double y = radius * radius - x * x;
    return y;
}

int main()
{
    //экран
    sf::RenderWindow window(sf::VideoMode(2*r+50, 2*r+50), "Choto IZI!");
    //Прямоугольник
    sf::RectangleShape rectangle(sf::Vector2f(2*r, 2*r));
    rectangle.setFillColor(sf::Color::Black);
    rectangle.setOutlineThickness(10.f);
    rectangle.setOutlineColor(sf::Color(250, 150, 100));
    rectangle.setPosition(10, 10);
    //Круг
    sf::CircleShape shape(r);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(10, 10);
    int circle_dot = 0, square_dot = 0;
    window.clear();
    sf::VertexArray array_point(Points, lim_dot);
    //window.draw(rectangle);
    //window.draw(shape);
    window.setFramerateLimit(60);
    for (int i = 0; i < lim_dot; i++) {
        double x = rand() % (r * 2), y = rand() % (r * 2);
        array_point[i].position = Vector2f(x, y);
        array_point[i].color = (sf::Color::Red);
        if (pow((x-r), 2) + pow((y-r), 2) <= pow(r, 2)){
            array_point[i].color = (sf::Color::White);
            circle_dot++;
        }
        square_dot++;
        if (i % 10000 == 0) {
             double a = (double(circle_dot) / double(square_dot)) * 4;
             std::cout << std::setprecision(10) << std::fixed;
             std::cout << i << ' ' << a << '\n';  
             window.draw(array_point);
             window.display();
        }
    }
    window.display();
    return 0;
}