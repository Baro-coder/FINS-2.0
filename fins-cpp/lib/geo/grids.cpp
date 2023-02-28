#include "grids.hpp"

Grids::Grids() {
    this->lat = 0.0;
    this->lon = 0.0;
}

Grids::Grids(double lan, double lon) {
    this->lat = lan;
    this->lon = lon;
}


void Grids::setLattitude(double value)
{
    this->lat = value;
}

void Grids::setLongitude(double value)
{
    this->lon = value;
}


double Grids::getLattitude()
{
    return this->lat;
}

double Grids::getLongitude()
{
    return this->lon;
}
