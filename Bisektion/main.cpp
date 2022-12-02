#include <iostream>

#include "math.h"

double polynom(double x)
{
    return (pow(x, 3) - 4*pow(x, 2) + x + 3);
}

std::string bisektion(double grenze_links, double grenze_rechts, double praezision, double (*funktion)(double))
{
    double intervall = grenze_rechts - grenze_links;

    while (intervall > praezision)
    {
        double grenze_mitte = grenze_links + intervall / 2.0;
        double wert_mitte = funktion(grenze_mitte);

        if (funktion(grenze_links) * wert_mitte < 0)
        {
            grenze_rechts = grenze_mitte;
        }
        else if (funktion(grenze_rechts) * wert_mitte < 0)
        {
            grenze_links = grenze_mitte;
        }
        else
        {
            return "Keine bzw. mehrere Nullstelle gefunden oder eine Nullstelle genau getroffen.";
        }

        intervall = grenze_rechts - grenze_links;
    }

    return std::to_string(grenze_links + intervall / 2.0);
}

int main()
{
    double grenze_links = -1;
    double grenze_rechts = 4;

    double praezision = 0.01;

    //Jede Funktion, die genau einen Parameter hat, der vom Typ double ist, und double returned.
    double (*funktion)(double) = polynom;

    std::cout << bisektion(grenze_links, grenze_rechts, praezision, funktion) << std::endl;

    system("PAUSE");

    return 0;
}