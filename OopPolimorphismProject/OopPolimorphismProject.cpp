#include <iostream>
#include <vector>

class Animal
{
protected:
    std::string name;
public:
    Animal() { name = ""; }
    Animal(std::string name) : name{ name } {}

    std::string& Name() { return name; };

    virtual std::string Voice() = 0;
};

class Dog : public Animal
{
public:
    Dog() : Animal("Dog") { };
    Dog(std::string name) : Animal(name) {}

    std::string Voice() override
    {
        return "Gaff-Gaff";
    }
};

class Cat : public Animal
{
public:
    Cat() : Animal("Cat") { };
    Cat(std::string name) : Animal(name) {}

    /*std::string Voice() override
    {
        return "Myau-Myau";
    }*/
};

class Tigr : public Cat
{
public:
    Tigr() : Cat("Tigr") { };
    Tigr(std::string name) : Cat(name) {}

    std::string Voice() final override
    {
        return "Rrrrrr";
    }

};

class BengalTigr : public Tigr
{
public:
    BengalTigr() : Tigr("Bengal Tigr") { };
    BengalTigr(std::string name) : Tigr(name) {}

    /*std::string Voice() override
    {
        return "Rrrrrr";
    }*/

};

class MyString
{
    std::string str;
public:
    //int Length() { return str.length(); }
    std::string& Str() { return str; }
    int CharCount(char ch)
    {
        int count{};
        for (int i{}; i < str.length(); i++)
            if (str[i] == ch) count++;
        return count;
    }
};


int main()
{
    srand(time(nullptr));

    std::vector<Animal*> zoo;
    for (int i{}; i < 10; i++)
        if (rand() % 100 >= 50)
            zoo.push_back(new Dog());
        else
            zoo.push_back(new Tigr());

    /*for (int i{}; i < zoo.size(); i++)
        std::cout << zoo[i]->Name() << ": " 
                  << zoo[i]->Voice() << "\n";
    std::cout << "\n";*/

    for (Animal* animal : zoo)
        animal->Name() = "*******";

    for (Animal* animal : zoo)
        std::cout << animal->Name() << ": "
                  << animal->Voice() << "\n";


}
