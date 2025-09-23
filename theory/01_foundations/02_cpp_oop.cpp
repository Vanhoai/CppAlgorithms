//
// File        : 02_cpp_oop.cpp
// Author      : Hinsun
// Date        : 2025-09-20
// Copyright   : (c) 2025 Tran Van Hoai
// License     : MIT
//

// With Cpp OOP you can learn the principles and concepts of Object-Oriented Programming (OOP) in
// C++. This includes classes, objects, inheritance, polymorphism, encapsulation, and more.
// You can also learn about design patterns and how to apply them in C++ programming.
// This knowledge will help you to write modular and reusable code that is easy to maintain and
// extend. You can also learn about best practices and coding standards in OOP.
// This will help you to write clean and maintainable code that follows OOP principles.
// Overall, Cpp OOP is a great way to enhance your C++ programming skills and develop your
// understanding of OOP concepts. It is also a good foundation for learning more advanced topics in
// C++ programming. So, if you are interested in C++ programming and want to improve your skills,
// Cpp OOP is definitely worth exploring!
// Happy coding!
//
// With this part, please refer to design patterns folder for more details about OOP concepts and
// principles. And below is a sample class in C++.

#include <iostream>

class Food {
public:
    /**
     * Public access specifier will allow access to the members from outside the class.
     *
     * virtual keyword is used to declare a virtual function in C++. And the = 0 syntax is used to
     * declare a pure virtual function, which means that the function has no implementation in the
     * base class and must be overridden in any derived class. A class that contains at least one
     * pure virtual function is called an abstract class and cannot be instantiated directly.
     */
    virtual void eat() const = 0;
};

class BeefNoodleSoup : public Food {
private:
    float price;
    float beefWeight;

public:
    BeefNoodleSoup(const float p, const float bw) : price(p), beefWeight(bw) {}

    void eat() const override {
        std::cout << "Eating beef noodle soup!" << std::endl;
        std::cout << "Price: $" << price << std::endl;
        std::cout << "Beef Weight: " << beefWeight << " grams" << std::endl;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    const BeefNoodleSoup bns(5.99, 200.0);
    bns.eat();

    return 0;
}
