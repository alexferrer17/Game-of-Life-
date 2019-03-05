#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class runModes
{
private:

public:

    runModes();
    ~runModes();

    string mode;
    int numOfGenerations = 0;
    int population = 0;
    int columns;
    int rows;
    int maxColumn;
    int maxRow;
    char a[1000][1000]; //first grid
    char b[1000][1000]; //second grid

    //look into what variables to declare

    void compareGrids();
    void randomConfig();
    void printGrid();
    void copyGeneration();
    void controlPopulation();
    int NeighbordCheck(int, int);
    int NeighbordCheckDonought(int, int);
    int NeighbordCheckMirror(int, int);
    void providegrid(); //provide grid from file




};
