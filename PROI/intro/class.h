#ifndef CLASS_H_INCLUDED
#define CLASS_H_INCLUDED
#include <iostream>
//#include <string>

class Wall{
    int width, height, position;
    std::string color;
public:
    Wall();
    void setWidth(int w);
    void setHeight(int h);
    void moveWall(int x);
    void paintWall(std::string _color);
    std::string getColor();
    int getWidth();
    int getHeight();
};


#endif // CLASS_H_INCLUDED
