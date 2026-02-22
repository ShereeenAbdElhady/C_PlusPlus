/*
Builder Design Pattern:-
The builder pattern is defined as a creational design pattern that separates the construction of a complex object
from its representation, allowing us to create different representations of an object using the same construction process. 
It's beneficial when an object has many optional properties or configurations.

Key components of the Builder Pattern in C++
	• Director: The Director is the main component of the builder pattern it basically responsible
     for the construction process of the program. It works with a Builder to build an object. 
     The Director knows the actual steps required to build an object, but it does not know the details
     of how each step is implemented.
	• Builder: The Builder is the main interface or an abstract class that defines the construction 
      steps required to create an object.
	• Concrete Builder: Basically, these are the classes that implement the Builder interface. 
      Each Concrete Builder is responsible for constructing a particular variant of the object.
	• Product: The Product is the complex object that we want to create. 
      The Product class may have methods to access or manipulate these components. It often has multiple parts or components that are built by the Builder.


Factory Design Pattern:-
The Factory Method Pattern is a creational design pattern that lets a class delegate the responsibility 
of creating objects to its subclasses.
Instead of creating objects directly using new, you define a method (called a factory method) to create objects. 
This gives you flexibility and reduces tight coupling between code that uses the object and the code that creates it.

Core Components
Component	Role
Product	Abstract base class or interface for the objects
Concrete Product	Actual class created by the factory
Creator	Abstract class declaring the factory method
Concrete Creator	Subclass that overrides the factory method to create specific products

Observer Design Pattern:-
The Observer Pattern is a behavioral design pattern where:
1.One object (Subject) holds the main data.
2.Many other objects (Observers) want to be notified whenever that data changes.
This is called a "one-to-many" relationship.

visitor Design Pattern:-
A visitor design patterns or visitor method is basically defined as a behavioral design pattern that allows 
us to define a new operation without changing the classes of the elements on which it operates
It is particularly useful when we have a set of related classes, and we want to perform different
operations on each class without modifying their code.

• Visitor Interface/Abstract Class: Defines the interface or abstract class with a set of visit methods, 
each corresponding to a specific type of element in the object structure. These methods typically take the element as a parameter.
• Concrete Visitor: Implements the Visitor interface or extends the abstract class. 
It provides concrete implementations for each of the visit methods, specifying what actions should be taken when visiting each type of element.
• Element Interface/Abstract Class: Declares the accept method, which accepts a visitor as an argument. 
This method is implemented by concrete elements and is used to invoke the appropriate visit method on the visitor.
• Concrete Element: Implements the Element interface or extends the abstract class. It defines the accept 
method by calling the corresponding visit method on the visitor, effectively allowing the visitor to perform operations on the element.
• Object Structure: Represents a collection or structure of elements that can be traversed by the visitor. 
It provides an interface to traverse its elements, often through an iterator or similar mechanism.
The Visitor Pattern is particularly useful when the object structure is complex, and the algorithm to be applied 
to its elements is likely to change or be extended. It allows for adding new operations without modifying 
the existing code for the elements or the object structure.

*/
                          /******************* Builder design pattern ********************/ 
#include <iostream>
#include <string>

// Product class
class Pizza {
public:
    void setDough(const std::string& dough)
    {
        this->dough = dough;
    }

    void setSauce(const std::string& sauce)
    {
        this->sauce = sauce;
    }

    void setTopping(const std::string& topping)
    {
        this->topping = topping;
    }

    void displayPizza() const
    {
        std::cout << "Pizza with Dough: " << dough
                  << ", Sauce: " << sauce
                  << ", Topping: " << topping << std::endl;
    }

private:
    std::string dough;
    std::string sauce;
    std::string topping;
};

// Abstract builder class
class PizzaBuilder {
public:
    virtual void buildDough() = 0;
    virtual void buildSauce() = 0;
    virtual void buildTopping() = 0;
    virtual Pizza getPizza() const = 0;
};

// Concrete builder for a specific type of pizza

/*
In this example:

"Pizza" is the product class that we want to build.
"PizzaBuilder" is an abstract builder class that defines the steps to build a pizza and provides a method to get the final pizza.
"HawaiianPizzaBuilder" and "SpicyPizzaBuilder" are concrete builder classes that implement the "PizzaBuilder" 
 interface to construct specific types of pizzas.
"Cook" is the director class that orchestrates the construction process, 
taking a builder and calling the necessary build methods to create a pizza.
In the "main" function, we create instances of different builders and use the Cook class to build pizzas
 with specific characteristics.I
 */
class HawaiianPizzaBuilder : public PizzaBuilder {
public:
    void buildDough() override
    {
        pizza.setDough("Pan Dough");
    }

    void buildSauce() override
    {
        pizza.setSauce("Hawaiian Sauce");
    }

    void buildTopping() override
    {
        pizza.setTopping("Ham and Pineapple");
    }

    Pizza getPizza() const override { return pizza; }

private:
    Pizza pizza;
};

// Concrete builder for another type of pizza
class SpicyPizzaBuilder : public PizzaBuilder {
public:
    void buildDough() override
    {
        pizza.setDough("Thin Dough");
    }

    void buildSauce() override
    {
        pizza.setSauce("Spicy Tomato Sauce");
    }

    void buildTopping() override
    {
        pizza.setTopping("Pepperoni and Jalapenos");
    }

    Pizza getPizza() const override { return pizza; }

private:
    Pizza pizza;
};

// Director class that orchestrates the construction
class Cook {
public:
    void makePizza(PizzaBuilder& builder)
    {
        builder.buildDough();
        builder.buildSauce();
        builder.buildTopping();
    }
};

int main()
{
    Cook cook;

    HawaiianPizzaBuilder hawaiianBuilder;
    cook.makePizza(hawaiianBuilder);
    Pizza hawaiianPizza = hawaiianBuilder.getPizza();
    hawaiianPizza.displayPizza();

    SpicyPizzaBuilder spicyBuilder;
    cook.makePizza(spicyBuilder);
    Pizza spicyPizza = spicyBuilder.getPizza();
    spicyPizza.displayPizza();

    return 0;
}
/* 
output
Pizza with Dough: Pan Dough, Sauce: Hawaiian Sauce, Topping: Ham and Pineapple
Pizza with Dough: Thin Dough, Sauce: Spicy Tomato Sauce, Topping: Pepperoni and Jalapenos
*/

                         /******************* Factory design pattern ********************/ 

/*Example: Shape Factory in C++
Let’s build a simple shape factory that creates Circle and Square. */

//Step 1: Abstract Product – Shape
class Shape {
public:
    virtual void draw() = 0; // Pure virtual function
    virtual ~Shape() {}
};
/*This is a base class called Shape with a draw() function.
It says that every shape must have its own version of the draw() function. */


//Step 2: Concrete Products – Circle and Square
class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing Circle\n";
    }
};

class Square : public Shape {
public:
    void draw() override {
        std::cout << "Drawing Square\n";
    }
};
/*Circle and Square are classes that inherit from Shape.
They each have their own way of drawing themselves. */

//Step 3: Abstract Creator – ShapeFactory
class ShapeFactory {
public:
    virtual Shape* createShape() = 0; // Factory method
    virtual ~ShapeFactory() {}
};
/*This is a base factory class that declares a method createShape().
It doesn't create shapes itself, but tells subclasses to do it. */

//Step 4: Concrete Creators – CircleFactory and SquareFactory
class CircleFactory : public ShapeFactory {
public:
    Shape* createShape() override {
        return new Circle();
    }
};

class SquareFactory : public ShapeFactory {
public:
    Shape* createShape() override {
        return new Square();
    }
};

/*These classes override the factory method to create specific shapes.
CircleFactory returns a Circle, and SquareFactory returns a Square. */

//Step 5: Client Code
int main() {
    ShapeFactory* factory;

    factory = new CircleFactory();
    Shape* shape1 = factory->createShape();
    shape1->draw(); // Output: Drawing Circle
    delete shape1;
    delete factory;

    factory = new SquareFactory();
    Shape* shape2 = factory->createShape();
    shape2->draw(); // Output: Drawing Square
    delete shape2;
    delete factory;

    return 0;
}
/*
The main function creates factories and uses them to get shapes.
It calls draw() on the shapes, showing how the Factory Method works. 
*/

                         /******************* Observer design pattern ********************/
/* 
Example: Weather Station & Displays
Let’s say we have a Weather Station that collects temperature, humidity, and pressure.
We also have Displays that need to show this information whenever it changes. */

//Step 1: Define the Observer interface
class Observer {
public:
    virtual void update(float temperature, float humidity, float pressure) = 0;
    virtual ~Observer() {}
};
//This is an abstract class (or interface) with an update function. All observers must implement this function to receive updates.

//Step 2: Define the Subject interface
#include <vector>
class Subject {
public:
    virtual void registerObserver(Observer* observer) = 0;
    virtual void removeObserver(Observer* observer) = 0;
    virtual void notifyObservers() = 0;
    virtual ~Subject() {}
};
// This interface defines how observers register, remove, or get notified.The subject will use this to manage the observer list.

//Step 3: Create the Concrete Subject (WeatherStation)
#include <iostream>
#include <algorithm>
class WeatherStation : public Subject {
private:
    std::vector<Observer*> observers;
    float temperature, humidity, pressure;
public:
    void registerObserver(Observer* observer) override {
        observers.push_back(observer);
    }
    void removeObserver(Observer* observer) override {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }
    void notifyObservers() override {
        for (Observer* observer : observers) {
            observer->update(temperature, humidity, pressure);
        }
    }
    void setMeasurements(float temp, float hum, float pres) {
        temperature = temp;
        humidity = hum;
        pressure = pres;
        notifyObservers(); // Notify all observers of the new data
    }
};
/*  WeatherStation stores a list of observers.
When new data is set, it notifies all observers using the update() function.*/

//Step 4: Create the Concrete Observer (Display)
class Display : public Observer {
public:
    void update(float temperature, float humidity, float pressure) override {
        std::cout << "Display: Temperature = " << temperature
                  << "°C, Humidity = " << humidity
                  << "%, Pressure = " << pressure << " hPa\n";
    }
};
/*Display is a class that implements Observer.
When update() is called, it prints the latest weather data.*/

//Step 5: Client Code (main function)
int main() {
    WeatherStation station;

    Display display1;
    Display display2;

    station.registerObserver(&display1);
    station.registerObserver(&display2);

    // First update
    station.setMeasurements(25.5, 60.0, 1013.2);

    // Second update
    station.setMeasurements(24.8, 58.0, 1014.5);

    return 0;
}
/* We create a WeatherStation and two Display objects.
They are registered as observers, and they get updated automatically when the data changes. */

/* Output of the code
Display: Temperature = 25.5°C, Humidity = 60%, Pressure = 1013.2 hPa
Display: Temperature = 25.5°C, Humidity = 60%, Pressure = 1013.2 hPa
Display: Temperature = 24.8°C, Humidity = 58%, Pressure = 1014.5 hPa
Display: Temperature = 24.8°C, Humidity = 58%, Pressure = 1014.5 hPa */


                         /******************* Visitor design pattern ********************/
/* 
example of the Visitor Pattern in C++ involving a set of geometric shapes (elements) and a set of operations (visitors)
 that can be performed on these shapes.
 */

//Visitor Interface, Declares a visit method for each concrete element type.
class Visitor {
public:
    virtual void visit(ElementA& element) = 0;
    virtual void visit(ElementB& element) = 0;
    // ... other visit methods for different elements
};

//Concrete Visitor, Implements the visit methods declared in the Visitor interface.
class ConcreteVisitor : public Visitor {
public:
    void visit(ElementA& element) override {
        // Perform operation on ElementA
    }

    void visit(ElementB& element) override {
        // Perform operation on ElementB
    }
    // ... implementations for other visit methods
};

//Element Interface, Declares an accept method that takes a visitor as an argument.
class Element {
public:
    virtual void accept(Visitor& visitor) = 0;
};

//Concrete Element, Implements the accept method, calling the appropriate visit method on the visitor.
class ElementA : public Element {
public:
    void accept(Visitor& visitor) override {
        visitor.visit(*this);
    }
};

class ElementB : public Element {
public:
    void accept(Visitor& visitor) override {
        visitor.visit(*this);
    }
};

//Object Structure, Represents a collection or structure of elements.

//overall
//shapes
#include <iostream>
#include <vector>

// Forward declarations
class Circle;
class Square;

// Visitor interface
class ShapeVisitor {
public:
    virtual void visit(Circle& circle) = 0;
    virtual void visit(Square& square) = 0;
};

// Element interface
class Shape {
public:
    virtual void accept(ShapeVisitor& visitor) = 0;
};

// Concrete Element: Circle
class Circle : public Shape {
public:
    void accept(ShapeVisitor& visitor) override {
        visitor.visit(*this);
    }

    void draw() {
        std::cout << "Drawing Circle\n";
    }
};

// Concrete Element: Square
class Square : public Shape {
public:
    void accept(ShapeVisitor& visitor) override {
        visitor.visit(*this);
    }

    void draw() {
        std::cout << "Drawing Square\n";
    }
};

// Concrete Visitor: DrawingVisitor
class DrawingVisitor : public ShapeVisitor {
public:
    void visit(Circle& circle) override {
        std::cout << "Drawing a Circle\n";
        circle.draw();
    }

    void visit(Square& square) override {
        std::cout << "Drawing a Square\n";
        square.draw();
    }
};

// Concrete Visitor: AreaVisitor
class AreaVisitor : public ShapeVisitor {
public:
    void visit(Circle& circle) override {
        std::cout << "Calculating area of Circle\n";
        // Calculate and print area logic for Circle
    }

    void visit(Square& square) override {
        std::cout << "Calculating area of Square\n";
        // Calculate and print area logic for Square
    }
};

// Object Structure
class ShapeContainer {
public:
    void addShape(Shape* shape) {
        shapes.push_back(shape);
    }

    void performOperations(ShapeVisitor& visitor) {
        for (Shape* shape : shapes) {
            shape->accept(visitor);
        }
    }

private:
    std::vector<Shape*> shapes;
};

int main() {
    // Create instances of shapes
    Circle circle;
    Square square;

    // Create a container and add shapes to it
    ShapeContainer container;
    container.addShape(&circle);
    container.addShape(&square);

    // Create visitors
    DrawingVisitor drawingVisitor;
    AreaVisitor areaVisitor;

    // Perform drawing operations
    container.performOperations(drawingVisitor);

    // Perform area calculation operations
    container.performOperations(areaVisitor);

    return 0;
}

/* 
Output
Drawing a Circle
Drawing Circle
Drawing a Square
Drawing Square
Calculating area of Circle
Calculating area of Square
*/