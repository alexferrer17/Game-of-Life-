#include <iostream>
#include <fstream>
#include <string>
#include "Mode.h"

using namespace std;
//first version of grid

//variables that keep track if there is an X


//function that stores grid of size (does not change throughout the procces)
//funtion that goes throught the grid size
//implement simulation here or in the different gamemodes class?

//funtion that goes trought the same grid but after simulation

Mode::Mode(){ //runs each mode.

  string firstChoice = "";
  cout << "Do you want to provide a map [1] or choose a random grid [2]?" << '\n';

  while(true)
  {
    cin >> firstChoice;
    if (firstChoice == "1")
    {
    provideMap();
    break;
    }
    else if (firstChoice == "2")
    {
    randomConfig();
    break;
    }
    else {cout << "Try Again" << '\n';}
  }
  string boundryChoice  = "";
  cout << "What boundry mode would you want to run it on? (Classic, Donough, Mirror)" << '\n';

  while(true)
  {
    cin >> boundryChoice;
    if(boundryChoice == "Classic")
    {
      classicMode(rows, columns);
      break;
    }
    else if (boundryChoice == "Doughnut")
    {
      doughnutMode();
      break;
    }
    else if (boundryChoice == "Mirror")
    {
      mirrorMode();
      break;
    }
    else {cout << "Try Again" << '\n';}
  }//end of while loop

  }

Mode::~Mode() {

  //DESTRUCTUR
}
//TODO: this might beN WRONG because it shold not be a void type or the argument is wrong in the currentGeneration() method
void Mode::printGrid() {

    for ( int i = 0; i < rows; i++)
    {
      '\n';
      for ( int j = 0; j < columns; j++)
      {
        cout << a[i][j];
      }
    }
}
void Mode::provideMap(){

}
void Mode::randomConfig(){
  int rows;
  int columns;
  float populationDensity;
  int newHeight;
  int newWidth;


  //method for a random population density
  cout << "Whats the height of your grid?:" << '\n';
  while (true)
  {
  cin >> rows;
  if (rows > 0)
  {
    break;
  }
  else
  {
    std::cout << "Try a valid number" << '\n';
  }
  }
  cout << "Whats the width of your gird?:" << '\n';
  while (true)
  {
    cin >> columns; //this should attribute the value
    if( columns > 0)
    {break;}
    else {std::cout << "Try a valid number" << '\n';}
  }

  cout << "Whats the population density?: (0/1)" << '\n';
  while (true) {
    cin >> populationDensity;
    if (populationDensity <= 1){break;}
    else{std::cout << "Invalid number try again." << '\n';}
  }//end of while.

  int cellCount = rows * columns * populationDensity;
  for ( int i = 0; i < cellCount; i++)
  {
    newHeight = rand() % rows;
    newWidth = rand() % columns;

    /*if ( a[newHeight][newWidth] == '-')
    {
      a[newHeight][newWidth] = 'X';
    }
    else { i--};*/
  }


{

}


}

void Mode::copyGeneration() {

  for(int i = 0; i < rows; i++ )
  {
    for(int j = 0; j < columns; j++)
    {
      a[i][j] = b[i][j];
    }
  }
}

void Mode::controlPopulation() {

  int population;
  if ( population <= 1) {
    a[rows][columns] = '-';
      //thiss will empty the case
  }

  else if (population == 3) {
    a[rows][columns] = 'X';
    //this will make one appear
  }
  //pretend this works
  else if (population >= 4) {
    a[rows][columns] = 'X';
    //this will make one appear
  }
}

int Mode::NeighbordCheck(int rows, int columns) {

  if (columns != 0 || columns != maxColumn && rows != 0 || rows != maxRow) { //TODO: Add conditions where rows and columns are not corners
    //keeps track of the population
  //each different value has to be evaluated in this scope
    if ( a[rows-1][columns-1] == 'X')
    {
      population++;
    }
    else if ( a[rows-1][columns] == 'X')
    {
      population++;
    }
    else if ( a[rows-1][columns+1] == 'X')
    {
      population++;
    }
    else if ( a[rows][columns-1] == 'X')
    {
      population++;
    }
    else if ( a[rows][columns+1] == 'X')
    {
      population++;
    }
    else if ( a[rows+1][columns-1] == 'X')
    {
      population++;
    }
    else if ( a[rows+1][columns] == 'X')
    {
      population++;
    }
    else if ( a[rows+1][columns+1] == 'X')
    {
      population++;
    }

  }//for each of the spaces that is not in any side of the grid nor any corner (columns != 0, maxColumn, rows =

  else if(columns == 0) {

    if ( a[rows-1][columns] == 'X')
    {
      population++;
    }
    else if ( a[rows-1][columns+1] == 'X')
    {
      population++;
    }
    else if ( a[rows][columns+1] == 'X')
    {
      population++;
    }
    else if ( a[rows+1][columns] == 'X')
    {
      population++;
    }
    else if ( a[rows+1][columns+1] == 'X')
    {
      population++;
    }

  } //end for right left side of the grid ( columns = 0)

  else if( rows == 0) {

    if ( a[rows][columns-1] == 'X')
    {
      population++;
    }
    else if ( a[rows][columns+1] == 'X')
    {
      population++;
    }
    else if ( a[rows+1][columns-1] == 'X')
    {
      population++;
    }
    else if ( a[rows+1][columns] == 'X')
    {
      population++;
    }
    else if ( a[rows+1][columns+1] == 'X')
    {
      population++;
    }

  } //end of if for the first row ( rows = 0 )

  else if(rows == maxRow) { //if for the corners in the right side of the grid

    if ( a[rows][columns-1] == 'X')
    {
      population++;
    }
    else if ( a[rows][columns+1] == 'X')
    {
      population++;
    }
    else if ( a[rows-1][columns-1] == 'X')
    {
      population++;
    }
    else if ( a[rows-1][columns] == 'X')
    {
      population++;
    }
    else if ( a[rows-1][columns+1] == 'X')
    {
      population++;
    }

  } //end of if for whole botton side of the grid (rows = maxRow)

  else if(columns == maxColumn) {

    if ( a[rows-1][columns] == 'X')
    {
      population++;
    }
    else if ( a[rows-1][columns-1] == 'X')
    {
      population++;
    }
    else if ( a[rows][columns-1] == 'X')
    {
      population++;
    }
    else if ( a[rows+1][columns] == 'X')
    {
      population++;
    }
    else if ( a[rows+1][columns-1] == 'X')
    {
      population++;
    }

  } //end of if for the whole right side of the grid (columns == maxColumn)

  else if (rows == maxRow && columns == maxColumn) {

    if ( a[rows-1][columns-1] == 'X')
    {
      population++;
    }
    else if ( a[rows-1][columns] == 'X')
    {
      population++;
    }
    else if ( a[rows][columns-1] == 'X')
    {
      population++;
    }

  }//end of if when its the bottom right corner of the grid

  else if (rows == 0 && columns==0 ) {

    if ( a[rows+1][columns+1] == 'X')
    {
      population++;
    }
    else if ( a[rows+1][columns] == 'X')
    {
      population++;
    }
    else if ( a[rows][columns+1] == 'X')
    {
      population++;
    }

  } //end of if when its the left top corner

  else if (rows == maxRow && columns == 0){

    if ( a[rows-1][columns] == 'X')
    {
      population++;
    }
    else if ( a[rows-1][columns+1] == 'X')
    {
      population++;
    }
    else if ( a[rows][columns+1] == 'X')
    {
      population++;
    }

  }

  else if (rows == 0 && columns == maxColumn) {

    if ( a[rows+1][columns] == 'X')
    {
      population++;
    }
    else if ( a[rows+1][columns-1] == 'X')
    {
      population++;
    }
    else if ( a[rows][columns-1] == 'X')
    {
      population++;
    }
  } //end of if for right top corner of grid

}

/*void compareGrids ( bool a[rows+1][columns+1]) {

  for( int a = 0; a < rows; a++)
  {
    for ( int b =0; b < columns; b++)
    {
      a[a][b] = b[a][b];
    }
  }
}*/

/*void Mode::determineState(bool a[rows+1][columns+1]) {

  bool b[rows+1][columns+1] = {};
  compareGrids(a,b);

  for ( int i = 1; a )

}*/
/*------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------
*/

int Mode::NeighbordCheckDoughnut() {


}

int Mode::NeighbordCheckMirror() {


}

void Mode::classicMode(int rows, int columns) {
  cout << "Made it to Classic mode" << '\n';
  cout << a[rows][columns] << '\n';
  cout << "rows: " << rows << " columns: " << columns << '\n';
  for(int i = 0; i < rows; i++ )
  {
    for(int j = 0; j < columns; j++)
    {
      NeighbordCheck(i, j); //checks each spot
      controlPopulation(); //increments the population
      copyGeneration();
      printGrid(); //maybe should have a return type?
    }
  }

}
void Mode::mirrorMode() {
  for(int i = 0; i < rows; i++ )
  {
    for(int j = 0; j < columns; j++)
    {
      NeighbordCheckMirror(); //checks each spot
      controlPopulation(); //increments the population
      copyGeneration();
      printGrid();
    }
  }
}
void Mode::doughnutMode() {
  for(int i = 0; i < rows; i++ )
  {
    for(int j = 0; j < columns; j++)
    {
      NeighbordCheckMirror(); //checks each spot
      controlPopulation(); //increments the population
      copyGeneration();
      printGrid();
    }
  }
}

//second version of then generation, incorporates the results from the first one hence have to run simulation

//void currentGeneration2( )
