#define _USE_MATH_DEFINES

#include <iostream>

#include "math.h"


double polynom(double x)
{
    return (-pow(x, 2) + 2*x + 3);
}


double links(double (*funktion)(double), double stelle, double intervall)
{
    return funktion(stelle);
}

double mitte(double (*funktion)(double), double stelle, double intervall)
{
    return funktion(stelle + 0.5 * intervall);
}

double rechts(double (*funktion)(double), double stelle, double intervall)
{
    return funktion(stelle + intervall);
}


double untersumme(double (*funktion)(double), double stelle, double intervall)
{
    double links = funktion(stelle);
    double rechts = funktion(stelle + intervall);

    if (links < rechts)
    {
        return links;
    }

    return rechts;
}

double obersumme(double (*funktion)(double), double stelle, double intervall)
{
    double links = funktion(stelle);
    double rechts = funktion(stelle + intervall);

    if (links > rechts)
    {
        return links;
    }

    return rechts;
}


void riemann(double grenze_links, double grenze_rechts, unsigned int schritte,
             double (*funktion)(double), double (*art)(double (*)(double), double, double))
{
    double intervall = (grenze_rechts - grenze_links) / schritte;

    std::cout << "Intervall: " << intervall << std::endl;

    double integral = 0.0;

    for (unsigned int i = 0; i < schritte; i++)
    {
        integral += art(funktion, grenze_links + intervall * i, intervall);
    }

    std::cout << "Integral: " << integral * intervall << std::endl;
}


int main()
{
    const double grenze_links = -M_PI;
    const double grenze_rechts = M_PI;

    const unsigned int schritte = 100;

    //Jede Funktion, die genau einen Parameter hat, der vom Typ double ist, und double returned.
    double (*funktion)(double) = sin;

    //Punkt, an dem der Wert des Intervalls ermittelt wird.
    //Möglich: links, mitte oder rechts sowie ober- oder untersumme.
    double (*art)(double (*)(double), double, double) = mitte;

    riemann(grenze_links, grenze_rechts, schritte, funktion, art);

    system("PAUSE");

    return 0;
}