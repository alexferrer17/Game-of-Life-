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
      for ( int j = 0; j < columns; j++)
      {
        if( a[i][j] == 'X')
        {
          cout << "X";
        }
        else
        {
          cout <<"-";
        }
      }
      cout << endl;
    }
}
void Mode::provideMap(){

}
void Mode::randomConfig(){

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
    cin >> columns; //this should attribute the value of the array
    if( columns > 0)
    {break;}
    else {std::cout << "Try a valid number" << '\n';}
  }

  cout << "Whats the population density?: (0/1)" << '\n';
  while (true) {
    cin >> populationDensity;
    if (populationDensity <= 1.0 && populationDensity > 0.0)
    {
      std::cout << populationDensity << endl;
      break;
    }
    else{std::cout << "Invalid number try again." << '\n';}
  }//end of while
  int cellCount = rows * columns * populationDensity;
  cout << cellCount << endl;
  for ( int i = 0; i < cellCount; i++)
  {
    newHeight = rand() % rows;
    newWidth = rand() % columns;
    cout << newHeight << " " << newWidth << endl;
    if ( a[newHeight][newWidth] == '\0')
    {
      a[newHeight][newWidth] = 'X';
      cout << a[newHeight][newWidth] << endl;
    }
    else { i--;}
  }
}

void Mode::inputFile() {


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

void Mode::controlPopulation(int row, int col) {

  if ( c[row][col] <= 1) {
    a[rows][columns] = '-';
      //thiss will empty the case
  }

  else if (c[row][col] == 3) {
    a[rows][columns] = 'X';
    //this will make one appear
  }
  //pretend this works
  else if (c[row][col] >= 4) {
    a[rows][columns] = '-';
    //this will make one appear
  }
}

int Mode::NeighbordCheck(int row, int col) {

  cout << "Made it to NeighbordCheck" << '\n';
  cout << "This is the grid before:" << '\n';
  cout << a[rows][columns] << '\n';
  int population = 0;

  if(row == 0)//If the the cell is in the top side of the the grid
  {
    if(col == 0)//Checks if the cell is in the top left corner
    {
      if(a[row + 1][col] == 'X')//cell below
      {
        population++;
      }
      if(a[row + 1][col + 1] == 'X')//cell to the bottom right
      {
        population++;
      }
      if(a[row][col + 1] == 'X')//cell to the right
      {
        population++;
      }
    }
    else if(col == maxColumn - 1)//check if the cell is at the top right corner
    {
      if(a[row][col - 1] == 'X') //cell to the left
      {
        population++;
      }
      if(a[row + 1][col - 1] == 'X')//cell to the bottom left
      {
        population++;
      }
      if(a[row + 1][col] == 'X')//cell below
      {
        population++;
      }
    }
    else //cell is not in a corner
    {
      if(a[row][col - 1] == 'X') //cell to the left
      {
        population++;
      }
      if(a[row + 1][col - 1] == 'X')//cell to the bottom left
      {
        population++;
      }
      if(a[row + 1][col] == 'X')//cell to the bottom
      {
        population++;
      }
      if(a[row + 1][col + 1] == 'X')//cell to the bottom right
      {
        population++;
      }
      if(a[row][col + 1] == 'X')//cell to the right
      {
        population++;
      }
    }
  }
  else if(row == maxRow - 1) //Cell is in the bottom of the grid
  {
    if(col == 0)//check if the cell is at the bottom left corner
    {
      if(a[row][col + 1] == 'X')//cell to the right
      {
        population++;
      }
      if(a[row - 1][col + 1] == 'X')//cell to the top right
      {
        population++;
      }
      if(a[row - 1][col] == 'X')//cell to the top
      {
        population++;
      }
    }
    else if(col == maxColumn - 1)//bottom right corner
    {
      if(a[row][col - 1] == 'X')//cell to the left
      {
        population++;
      }
      if(a[row - 1][col] == 'X')//cell to the top
      {
        population++;
      }
      if(a[row - 1][col - 1] == 'X')//cell to the top left
      {
        population++;
      }
    }
    else//cell is not in a corner
    {
      if(a[row][col - 1] == 'X')//cell to the left
      {
        population++;
      }
      if(a[row][col + 1] == 'X')//cell to the right
      {
        population++;
      }
      if(a[row - 1][col + 1] == 'X')//cell to the top right
      {
        population++;
      }
      if(a[row - 1][col] == 'X')//cell to the top
      {
        population++;
      }
      if(a[row - 1][col - 1] == 'X')//cell to the top left
      {
        population++;
      }
    }

  }

  else if(col == maxColumn - 1)//cell is in the right side of the grid
  {
    if(a[row][col - 1] == 'X')//cell to the left
    {
      population++;
    }
    if(a[row + 1][col - 1] == 'X')//cell to the bottom left
    {
      population++;
    }
    if(a[row + 1][col] == 'X')//cell to the bottom
    {
      population++;
    }
    if(a[row - 1][col] == 'X')//cell to the top
    {
      population++;
    }
    if(a[row - 1][col - 1] == 'X')//cell to the top left
    {
      population++;
    }
  }

  else if(col == 0)//left side of the grid
  {
    if(a[row + 1][col] == 'X')//cell to the bottom
    {
      population++;
    }
    if(a[row + 1][col + 1] == 'X')//cell to the bottom right
    {
      population++;
    }
    if(a[row][col + 1] == 'X')//cell to the right
    {
      population++;
    }
    if(a[row - 1][col + 1] == 'X')//cell to the top right
    {
      population++;
    }
    if(a[row - 1][col] == 'X')//cell to the top
    {
      population++;
    }
  }

  else //cell is not along any of the edges of the grid
  {
    if(a[row][col - 1] == 'X')//cell to the left
    {
      population++;
    }
    if(a[row + 1][col - 1] == 'X')//cell to the bottom left
    {
      population++;
    }
    if(a[row + 1][col] == 'X')//cell to the bottom
    {
      population++;
    }
    if(a[row + 1][col + 1] == 'X')//cell to the bottom right
    {
      population++;
    }
    if(a[row][col + 1] == 'X')//cell to the right
    {
      population++;
    }
    if(a[row - 1][col + 1] == 'X')//cell to the top right
    {
      population++;
    }
    if(a[row - 1][col] == 'X')//cell to the top
    {
      population++;
    }
    if(a[row - 1][col - 1] == 'X')//cell to the top left
    {
      population++;
    }
  }
  return population;
}
  //for each of the spaces that is not in any side of the grid nor any corner (col != 0, maxColumn, row =
























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

bool Mode::ifEmpty() {
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
    {
      if( a[i][j] == 'X' )
      {
        return false;
      }
    }
  }
  return true;
}
bool Mode::isBalance() {
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
    {
      if( a[i][j] != b[i][j] )
      {
        return false;
      }
    }
  }
  return true;
}

void Mode::classicMode(int rows, int columns) {
  cout << "Made it to Classic mode" << '\n';
  cout << "rows: " << rows << '\n';
  cout << "columns: " << columns << '\n';
  while(!isBalance() && !ifEmpty())
  {
  printGrid();
  copyGeneration();//
  for(int row = 0; row < rows; row++ )
  {
    for(int col = 0; col < columns; col++)
    {
      NeighbordCheck(row,col);
      //a[i][j] = NeighbordCheck(i, j);
      //checks each spot
      controlPopulation(row,col);
      cout << a[row][col] << '\n';
    }
  }
  '\n';
  printGrid();
}

}

void Mode::mirrorMode() {
  for(int i = 0; i < rows; i++ )
  {
    for(int j = 0; j < columns; j++)
    {
      NeighbordCheckMirror(); //checks each spot
      controlPopulation(i,j); //increments the population
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
      controlPopulation(i,j); //increments the population
      copyGeneration();
      printGrid();
    }
  }
}

//second version of then generation, incorporates the results from the first one hence have to run simulation

//void currentGeneration2( )
