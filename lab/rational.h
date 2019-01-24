#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>


class Rational {
public:
    Rational();

    Rational(int numerator, int denominator);

    int numerator() const;

    int denominator() const;

    Rational operator+(const Rational rhs) const;
    Rational operator-(const Rational rhs) const;
    Rational operator*(const Rational rhs) const;
    Rational operator/(const Rational rhs) const;
    friend std::ostream& operator<<(std::ostream &os, const Rational rhs);
    friend std::istream& operator>>(std::istream &is, Rational &rhs);
    bool operator==(const Rational rhs) const;


private:
    int p;
    int q;
};


#endif // RATIONAL_H
