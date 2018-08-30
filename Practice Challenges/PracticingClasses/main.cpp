#include <iostream>
#include <cassert>
#include <stdexcept>
#include <vector>
#include <cmath>

using namespace std;
class HelloWorld
{
private:
	char *m_data;

public:
	HelloWorld(){
    m_data = new char[14]{"Hello, World!"};
    }

	~HelloWorld()
	{
	    delete[] m_data;
	}
	void print()
	{
		cout << m_data;
	}
};
int main()
{
	HelloWorld hello;
	hello.print();

    return 0;
}

/*
class Point2d
{
private:
    double m_x;
    double m_y;
public:
    Point2d(double x = 0.0, double y = 0.0) : m_x(x), m_y(y)  //member initializer list
    {}

    void print()
    {
        cout << "Point2d(" << m_x << " , " << m_y << ")\n";
    }
    double distanceTo(Point2d other)
    {
        return sqrt((m_x - other.m_x)*(m_x - other.m_x) + (m_y - other.m_y)*(m_y - other.m_y));
    }
};
int main()
{
    Point2d first;
    Point2d second(3.0, 4.0);
    first.print();
    second.print();
    cout << "Distance between two points: " << first.distanceTo(second) << '\n';
}
Element a[i] is true if integer i is in the set. Element a[j] is false if integer j is not in the set.
Each element can hold hold integers in the range 0 through 100. For example, for the set {3, 5, 7, 10},
 a[3] is 1, a[5] is 1, a[7] is 1, and a[10] is 1; all other elements of a are 0.
static int SIZE = 100;
class IntegerSet
{
    private:
    int a[];

    public:
    IntegerSet() //default constructor: "empty set", where all values contain false
    {
        a[100] = {0};
    }
    void insertElement(int k) { //function that places a new integer k into a set by setting a[k] to true
        if ( 0 <= k && k <= SIZE)
            a[k] = 1;
    }

    void deleteElement(int m) { //function that deletes integer m by setting a[m] to false
        if ( 0 <= m && m <= SIZE)
            a[m] = 0;
    }

    bool isEqual(IntegerSet s) { //function that determines whether two sets are equal
        for (int i = 0; i <= SIZE; i++)
            if ( a[i] != s.a[i] )
                return false;
        return true;
    }

};

int main()
{
    IntegerSet();
    return 0;
}
Create a class Rectangle with attributes length and width, each of which
defaults to 1. Provide member functions that calculate the perimeter and the area of the rectangle.
Also, provide set and get functions for the length and width attributes. The set functions should verify that
length and width are each floating-point numbers larger than 0.0 and less than 20.0.

class Rectangle
{
    private:
    float m_length;
    float m_width;
    public:
        //default constructor
        Rectangle()
        {
            m_length = 1;
            m_width = 1;
        }
        //functions that calculate perimeter and area
        int getPerimeter(){
        cout << "The perimeter of your rectangle is: " << 2*m_length + 2*m_width << endl;
        return 0;
        }
        int getArea(){
        cout << "The area of your rectangle is: " << m_length*m_width << endl;
        return 0;
        }
    //set and get functions
    void setLength(int length) { m_length = length; }
    void setWidth(int width) { m_width = width; }
    int getLength() { return m_length; }
    int getWidth() { return m_width; }
    //tells you if your rectangle is a square
    bool square()
    {
        cout << "You have a rectangle!" << endl;
        if (m_length == m_width)
            cout << "Your rectangle is also a square!" << endl;
    }

};

int main()
{
    Rectangle rectangle; //Since no arguments, calls Rectangle() default constructor
    rectangle.setLength(5);
    rectangle.setWidth(5);
    rectangle.getPerimeter();
    rectangle.getArea();
    rectangle.square();
    return 0;
}


Write a class named Ball. Ball should have two private member variables with default values:
m_color (“Black”) and m_radius (10.0). Ball should provide constructors to set only m_color, set only m_radius,
set both, or set neither value. For this quiz question, do not use default parameters for your constructors.
Also write a function to print out the color and radius of the ball.

class Ball
{
private:
    string m_color;
    double m_radius;
public:
 // Constructor with only radius parameter (color will use default value)
	Ball(double radius)
	{
		m_color = "black";
		m_radius = radius;
	}
        // Constructor with both color and radius parameters
        // handles no parameter, color only, and color + radius cases.
	Ball(const std::string &color="black", double radius=10.0)
	{
		m_color = color;
		m_radius = radius;
	}

	void print()
	{
		cout << "color: " << m_color << ", radius: " << m_radius << '\n';
	}
};

int main()
{
    Ball def;
    def.print();

	Ball blue("blue");
	blue.print();

	Ball twenty(20.0);
	twenty.print();

	Ball blueTwenty("blue", 20.0);
	blueTwenty.print();

    return 0;
}


class Fraction
{
private:
    int m_numerator;
    int m_denominator;
public:
    Fraction(int numerator = 0, int denominator = 1)
    {
        assert(denominator != 0);
        m_numerator = numerator;
        m_denominator = denominator;
    }
    int getNumerator() { return m_numerator; }
    int getDenominator() { return m_denominator; }
    double getValue() { return static_cast<double>(m_numerator / m_denominator); }
};

int main()
{
    Fraction frac;
    cout << frac.getNumerator() << "/" << frac.getDenominator() << '\n';
    Fraction fiveThirds(5, 3);
    cout << fiveThirds.getNumerator() << "/" << fiveThirds.getDenominator() << '\n';
    Fraction six(6);
    cout << six.getNumerator() << "/" << six.getDenominator() << '\n';
    return 0;
}

class CharacterClass
{
    string m_name;
    int m_health;
    int m_mana;
    int m_attackPower;
    int m_magicPower;

public:
    void setStats(string name, int health, int mana, int attackPower, int magicPower)
    {
        m_name = name;
        m_health = health;
        m_mana = mana;
        m_attackPower = attackPower;
        m_magicPower = magicPower;
    }

    void print() const
    {
        cout << "Name: " << m_name << " Health: " << m_health << " Mana: " << m_mana << " Attack Power: " << m_attackPower << " Magic Power: " <<
        m_magicPower << endl;
    }

    void increaseHealth()
    {
        m_health += 10;
    }

    void increaseMana()
    {
        m_mana += 10;
    }

    void increaseAttackPower()
    {
        m_attackPower += 10;
    }

    void increaseMagicPower()
    {
        m_magicPower += 10;
    }
};

int main()
{
    CharacterClass Alex;
    Alex.setStats("Alex", 100, 100, 10, 10);
    Alex.print();

    CharacterClass Valerie;
    Valerie.setStats("Valerie", 100, 100, 15, 5);
    Valerie.print();

    CharacterClass Angelo;
    Angelo.setStats("Angelo", 1000, 1000, 100, 100);
    Angelo.print();

    bool val = true;
    while (val) {
    cout << "\nWelcome to the Stat Trainer! Please select an option (1-5): " << endl << "1: Increase Health" << endl <<
    "2: Increase Mana" << endl << "3: Increase Attack Power" << endl << "4: Increase Magic Power" << endl
    << "5: Exit Stat Trainer" << endl << "Your choice: ";
    int input;
    cin >> input;

        switch(input){
        case 1:
        Alex.increaseHealth();
        cout << "Your updated stats are: ";
        Alex.print();
        break;
        case 2:
        Alex.increaseMana();
        cout << "Your updated stats are: ";
        Alex.print();
        break;
        case 3:
        Alex.increaseAttackPower();
        cout << "Your updated stats are: ";
        Alex.print();
        break;
        case 4:
        Alex.increaseMagicPower();
        cout << "Your updated stats are: ";
        Alex.print();
        break;
        case 5:
            cout << "Thank you for using the Stat Trainer!";
        val = false;
        }
    }
    cout << endl;
    return 0;
}

class Point3d
{
    double m_x, m_y, m_z;

public:
    void setValues(double x, double y, double z)
    {
        m_x = x;
        m_y = y;
        m_z = z;
    }
    void print() const
    {
        cout << "<" << m_x << ", " << m_y << ", " << m_z << ">";
    }
    bool isEqual(const Point3d &p)
	{
		return (m_x == p.m_x && m_y == p.m_y && m_z == p.m_z);
	}
};

int main()
{
    Point3d point1;
	point1.setValues(1.0, 2.0, 3.0);

	Point3d point2;
	point2.setValues(1.0, 2.0, 3.0);

	if (point1.isEqual(point2))
		cout << "point1 and point2 are equal\n";
	else
		cout << "point1 and point2 are not equal\n";

	Point3d point3;
	point3.setValues(3.0, 4.0, 5.0);

	if (point1.isEqual(point3))
		cout << "point1 and point3 are equal\n";
	else
		cout << "point1 and point3 are not equal\n";

	return 0;
}
*/
