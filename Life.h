#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Life
{
private:

public:

    Life();
    ~Life();

    string mode;
    int numOfGenerations = 0;
    int population = 0;
    int columns;
    int rows;
    int maxColumn;
    int maxRow;
    char a[1000][1000]; //first grid
    char b[1000][1000]; //second grid
    char c[1000][1000];

    //look into what variables to declare

    bool ifEmpty();
    bool isBalance();
    void randomConfig();
    void inputFile();
    void provideMap();
    void compareGrids();
    void copyGeneration();
    void printGrid();
    void controlPopulation(int, int);
    int NeighbordCheck(int, int);
    int NeighbordCheckDoughnut();
    int NeighbordCheckMirror();
    void classicMode(int,int);
    void mirrorMode();
    void doughnutMode();
    void providegrid(); //provide grid from file




};
