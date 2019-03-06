#include <iostream>
#include <fstream>
#include <string>
#include "Life.h"

using namespace std;

//This is game of Life.
//Making different methods that will allow the user interact with the game.


Life::Life(){ //runs each mode.

  string firstChoice = "";
  cout << "Do you want to provide a map [1] or choose a random grid [2]?" << '\n';

  while(true) //while loop to keep going until the user answears correc
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
  string boundryChoice  = ""; //temp for option
  cout << "What boundry mode would you want to run it on? (Classic, Donough, Mirror)" << '\n';

  while(true) //loop that chooses gamemode
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

Life::~Life() {

  //DESTRUCTUR
}
//method that prints the grid
void Life::printGrid() {

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
void Life::provideMap(){
  string fileName = "";
  std::cout << "What is the name of the file" << '\n';
  std::cin >> fileName;
  fstream inputMap(fileName);
  int gridRows = 0;
  int gridColumns = 0;
  if(inputMap.is_open())
  {
    string line = "";
    int counter = 0;
    while (getline(inputMap, line))
    {
      if(counter == 0)
      {
        gridRows = stoi(line);
      }
      else if(counter == 1)
      {
        gridColumns = stoi(line);
      }
      else
      {
        for(int i = 0; i < line.length() - 1; i++)
        {
          if(line[i] == 'X') //saves the x as true
          {
            a[counter - 2][i] == 'X'; //writes the map to the array
          }
          else
          {
            a[counter - 2][i] = '-';
          }
        }
      }
      counter++;
    }
  }
  inputMap.close();
}

void Life::randomConfig(){

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
  while (true) { //loop that asks for the density
    cin >> populationDensity;
    if (populationDensity <= 1.0 && populationDensity > 0.0)
    {

      break;
    }
    else{std::cout << "Invalid number try again." << '\n';}
  }//end of loop
  int cellCount = rows * columns * populationDensity;

  for ( int i = 0; i < cellCount; i++)
  {
    newHeight = rand() % rows;
    newWidth = rand() % columns;
    //cout << newHeight << " " << newWidth << endl;
    if ( a[newHeight][newWidth] == '\0')
    {
      a[newHeight][newWidth] = 'X';
      //cout << a[newHeight][newWidth] << endl;
    }
    else { i--;}
  }
}

void Life::copyGeneration() {
//copies A to B
  for(int i = 0; i < rows; i++ )
  {
    for(int j = 0; j < columns; j++)
    {
      a[i][j] = b[i][j];
    }
  }
}

void Life::controlPopulation(int row, int col) {

  std::cout << c[row][col] << '\n';
  if ( c[row][col] <= 1) {
    a[rows][columns] = '-';
      //thiss will empty the case
  }

  else if (c[row][col] == 3) {
    a[rows][columns] = 'X';
    //this will make one appear
  }

  else if (c[row][col] >= 4) {
    a[rows][columns] = '-';
    //this will make one appear
  }
}

int Life::NeighbordCheck(int row, int col) {

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

int Life::NeighbordCheckDoughnut() {
//Doughnut mode

}

int Life::NeighbordCheckMirror() {
//MirrorMode

}

bool Life::ifEmpty() { //checks if its empty
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
bool Life::isBalance() { //compares first grid to second
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

void Life::classicMode(int rows, int columns) {
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

void Life::mirrorMode() {
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
void Life::doughnutMode() { //doughnutMode
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
