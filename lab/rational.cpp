
#include <iostream>
#include <string>
#include "assert.h"
#include "rational.h"

Rational::Rational():
    p(0), q(1)
{
}


Rational::Rational(int numerator, int denominator)
{


//  проверка деления на ноль
    assert(denominator != 0);

//  Если числитель дроби равен нулю, то знаменатель должен быть равен 1
    if(numerator == 0) {
    p = 0;
    q = 1;
    return;
    }

//  Сокращение дроби p/q
    int minValue;

    if(abs(numerator) < abs(denominator)) {
        minValue = abs(numerator);
    }
    else {
        minValue = abs(denominator);
    }

    for(int i = minValue; i > 0; i--) {
        if(((numerator % i) == 0) && ((denominator % i) == 0)) {
            p = numerator / i;
            q = denominator / i;

            break;
        }
    }

//  Если один из операндов отрицательный, то числитель будет отрицательным, а знаменатель положительным
    if(((p < 0) && (q > 0)) || ((p > 0) && (q < 0))){
        p = abs(p);
        p = -p;
        q = abs(q);
    }
//  Если оба операнда положительные либо отрицательные, то числитель и знаменатель также будут положительными
    else {
        p = abs(p);
        q = abs(q);
    }
}


int Rational::numerator() const
{
    return p;
}


int Rational::denominator() const
{
    return q;
}


bool Rational::operator==(const Rational rhs) const
{
    if((this->p == rhs.p) && (this->q == rhs.q)) {
        return true;
    }
    else {
        return false;
    }
}


Rational Rational::operator+(const Rational rhs) const
{
    Rational a;

    //  приведение к общему знаменателю и сложение
    a.p = (this->p * rhs.q) + (rhs.p * this->q);
    a.q = this->q * rhs.q;

    //  сокращение дроби
    //  Сокращение дроби p/q
    int minValue;

    if(abs(a.p) < abs(a.q)) {
        minValue = abs(a.p);
    }
    else {
        minValue = abs(a.q);
    }

    for(int i = minValue; i > 0; i--) {
        if(((a.p % i) == 0) && ((a.q % i) == 0)) {
            a.p /= i;
            a.q /= i;

            break;
        }
    }

    return a;
}


Rational Rational::operator-(const Rational rhs) const
{
    Rational a;

    //  приведение к общему знаменателю и вычитание
    a.p = (this->p * rhs.q) - (rhs.p * this->q);
    a.q = this->q * rhs.q;

    //  сокращение дроби
    //  Сокращение дроби p/q
    int minValue;

    if(abs(a.p) < abs(a.q)) {
        minValue = abs(a.p);
    }
    else {
        minValue = abs(a.q);
    }

    for(int i = minValue; i > 0; i--) {
        if(((a.p % i) == 0) && ((a.q % i) == 0)) {
            a.p /= i;
            a.q /= i;

            break;
        }
    }

    return a;
}


Rational Rational::operator*(const Rational rhs) const
{
    Rational a;

    //  умножение
    a.p = this->p * rhs.p;
    a.q = this->q * rhs.q;

    //  сокращение дроби
    //  Сокращение дроби p/q
    int minValue;

    if(abs(a.p) < abs(a.q)) {
        minValue = abs(a.p);
    }
    else {
        minValue = abs(a.q);
    }

    for(int i = minValue; i > 0; i--) {
        if(((a.p % i) == 0) && ((a.q % i) == 0)) {
            a.p /= i;
            a.q /= i;

            break;
        }
    }

    return a;
}


Rational Rational::operator/(const Rational rhs) const
{
    assert(rhs.p > 0);

    Rational a;

    //  деление
    a.p = this->p * rhs.q;
    a.q = this->q * rhs.p;

    //  сокращение дроби
    //  Сокращение дроби p/q
    int minValue;

    if(abs(a.p) < abs(a.q)) {
        minValue = abs(a.p);
    }
    else {
        minValue = abs(a.q);
    }

    for(int i = minValue; i > 0; i--) {
        if(((a.p % i) == 0) && ((a.q % i) == 0)) {
            a.p /= i;
            a.q /= i;

            break;
        }
    }

    return a;
}


std::ostream& operator<<(std::ostream &os, const Rational rhs)
{
    os << rhs.p << "/" << rhs.q;

    return os;
}


std::istream& operator>>(std::istream &is, Rational &rhs)
{
    std::string str, substr;
    std::size_t slash;

    //  получение строки
    is >> str;

    //  проверка на пустую строку
    if(str.empty()) {
        return is;
    }

    //  определение числителя
    rhs.p = std::stoi(str);

    //  определение положения символа делителя
    slash = str.find_first_of('/');

    //  формирование строки содержащей символ делителя и знаменатель
    substr = str.substr(slash);

    //  удаление из строки символа делителя
    substr.erase(0, 1);

    //  определение знаменателя
    rhs.q = std::stoi(substr);

    //  сокращение дроби
    //  Сокращение дроби p/q
    int minValue;

    if(abs(rhs.p) < abs(rhs.q)) {
        minValue = abs(rhs.p);
    }
    else {
        minValue = abs(rhs.q);
    }

    for(int i = minValue; i > 0; i--) {
        if(((rhs.p % i) == 0) && ((rhs.q % i) == 0)) {
            rhs.p /= i;
            rhs.q /= i;

            break;
        }
    }

    return is;
}


