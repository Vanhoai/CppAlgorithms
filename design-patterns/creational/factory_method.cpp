#include <iostream>

//
// File        : factory_method.cpp
// Author      : Hinsun
// Date        : 2025-09-15
// Copyright   : (c) 2025 Tran Van Hoai
// License     : MIT
//

// Factory Method Design Pattern
// --------------------------------------------------------------------------
// Factory Method Design Pattern is a creational design pattern that provides
// an interface for creating objects in a superclass, but allows subclasses to
// alter the type of objects that will be created.
// --------------------------------------------------------------------------
// Problem: I have a logistics company, which can deliver products by truck and
// ship. I want to create a logistics management system, which can create
// different logistics objects based on the type of delivery method.
//
// Solution: We can use the Factory Method Design Pattern to create different
// logistics objects based on the type of delivery method. We can create a
// Logistics interface, which will have a method to create a transport object.
//
// We can create two classes RoadLogistics and SeaLogistics, which will
// implement the Logistics interface. The RoadLogistics class will create a
// Truck object, and the SeaLogistics class will create a Ship object. Both
// Truck and Ship classes will implement the Transport interface, which will
// have a method to deliver the product.

/**
 * Classes:
 * 1. Transport (interface)
 * 2. Truck (implements Transport)
 * 3. Ship (implements Transport)
 * 4. Logistics (interface)
 * 5. RoadLogistics (implements Logistics)
 * 6. SeaLogistics (implements Logistics)
 *
 * Pseudocode:
 * interface Transport is
 *     method calculateCost();
 *     method deliver();
 *
 * class Truck implements Transport is
 *     void deliver() is
 *         implementation of deliver method for Truck
 *
 *     method calculateCost() is
 *         implementation of calculateCost method for Truck
 *
 * class Ship implements Transport is
 *     void deliver() is
 *         implementation of deliver method for Ship
 *
 *     method calculateCost() is
 *         implementation of calculateCost method for Ship
 *
 * class Logistics is
 *     method planDelivery() is
 *         Transport t = createTransport();
 *         ...
 *
 *     abstract method createTransport();
 *
 * class RoadLogistics extend Logistics is
 *     override method createTransport() is
 *         return new Truck();
 *
 * class SeaLogistics extend Logistics is
 *     override method createTransport() is
 *         return new Ship();
 */

class Transport {
public:
    virtual void deliver() = 0;
    virtual double calculateCost() = 0;
    virtual ~Transport() = default;
};

class Truck : public Transport {
public:
    void deliver() override { std::cout << "Delivering by Truck" << std::endl; }
    double calculateCost() override { return 100.0; }
};

class Ship : public Transport {
public:
    void deliver() override { std::cout << "Delivering by Ship" << std::endl; }
    double calculateCost() override { return 200.0; }
};

class Logistics {
public:
    virtual Transport *createTransport() const = 0;

    void planDelivery() {
        Transport *transport = createTransport();
        transport->deliver();
        std::cout << "Cost: " << transport->calculateCost() << std::endl;
        delete transport;
    }

    virtual ~Logistics() = default;
};

class RoadLogistics : public Logistics {
public:
    Transport *createTransport() const override { return new Truck(); }
};

class SeaLogistics : public Logistics {
public:
    Transport *createTransport() const override { return new Ship(); }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    std::cout << "Factory Method Design Pattern with C++" << std::endl;
    Logistics *roadLogistics = new RoadLogistics();
    roadLogistics->planDelivery();
    delete roadLogistics;

    Logistics *seaLogistics = new SeaLogistics();
    seaLogistics->planDelivery();
    delete seaLogistics;

    return 0;
}
