#include <iostream>
using namespace std;

int main(){
    enum class Color {white, black, blue, red};
    Color my_color = Color::red;
    if (my_color==Color::red)
    {
        cout<< "The color of my car is red"<<endl;
    }
    else{
        cout<< "The color of my car is not red"<<endl;
    }

    enum class Direction {Up, Down, Left, Right};
    Direction a = Direction::Down;
    switch (a)
    {
    case Direction::Up : 
        cout<<"The direction is Up"<<endl;
        break;
    case Direction::Down :
        cout<<"The direction is Down"<<endl;
        break;
    case Direction::Left:
        cout<<"The direction is Left"<<endl;
        break;
    case Direction::Right:
        cout<<"The direction is Right"<<endl;
        break;
    }
}