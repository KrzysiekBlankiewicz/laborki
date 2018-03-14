#include <iostream>
#include "class.h"

using namespace std;


Wall:: Wall(){
    width = 1; height = 1; position = 1; color = "white";
}
void Wall::setWidth(int _width){
    width = _width;
}
void Wall::setHeight(int _height){
    height = _height;
}
void Wall::moveWall(int _position){
    position = _position;
}
void Wall::paintWall(string _color){
    color = _color;
}
string Wall::getColor(){
    return color;
}
int Wall::getWidth(){
    return width;
}
int Wall::getHeight(){
    return height;
}
