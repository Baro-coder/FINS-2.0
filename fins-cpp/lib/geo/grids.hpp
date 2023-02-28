#ifndef GEOGRIDS_HNAME
#define GEOGRIDS_HNAME grids

class Grids
{
private:
    double lat; // lattitude
    double lon; // longitude

public:
    // ** Constructors **
    Grids();
    Grids(double lat, double lon);

    // ** Getters **
    double getLattitude();
    double getLongitude();

    // ** Setters **
    void setLattitude(double value);
    void setLongitude(double value);
};

#endif