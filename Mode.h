#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Mode
{
private:

public:

    Mode();
    ~Mode();

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


    void randomConfig();
    void provideMap();
    void compareGrids();
    void copyGeneration();
    void printGrid();
    void controlPopulation();
    int NeighbordCheck(int, int);
    int NeighbordCheckDoughnut();
    int NeighbordCheckMirror();
    void classicMode(int,int);
    void mirrorMode();
    void doughnutMode();
    void providegrid(); //provide grid from file




};
