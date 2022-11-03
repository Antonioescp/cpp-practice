#include <iostream>

using namespace std;

class Dog
{
public:
    void Bark() { cout << "Bark!" << endl; }
    void Eat() { cout << "The dog is eating" << endl; }
    void Walk() { cout << "Dog walk" << endl; }
};

class Bird
{
public:
    void Chirp() { cout << "Chirp!" << endl; }
    void Eat() { cout << "The bird is eating" << endl; }
};

class Human
{
public:
    void Walk() { cout << "Human walk" << endl; }
};

class DogBirdHuman : public Dog, public Bird, public Human
{
public:
    using Human::Walk;
};

int main()
{
    DogBirdHuman db;
    dynamic_cast<Dog&>( db ).Eat();
    db.Bird::Eat();

    db.Walk();
}