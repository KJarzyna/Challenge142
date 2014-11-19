#include "sand_and_stone.h"

//constructor
sand_and_stone::sand_and_stone()
{
	ErrorGrid=0;
	ErrorWrongInput=0;

	AskForInput();
	if(!ErrorGrid && !ErrorWrongInput){
		RunGravity();
		WriteToConsole();}
}

void sand_and_stone::AskForInput()
{
//Ask for grid size
	cout << "Please set grid size (NxN): " << endl;
	cin >> grid_size;
	if(cin.fail()){
			cout << "Wrong input! Integer only!" << endl;
			ErrorWrongInput = true;}
	cin.ignore (1, '\n');
	cin.clear();
	
//Ask for grid to solve.
	if(!ErrorWrongInput){
		cout << "Please set positions of stones and sand: " << endl;

		for(int n=0;n<grid_size;n++){
			getline(cin,input_line);
	
			if(input_line.size()==grid_size){
				grid.push_back(input_line);}
			else if(input_line.size()<grid_size){
				cout << "Too few characters in row! Start over!" << endl;
				ErrorGrid = true;
				break;}
			else if(input_line.size()>grid_size){
				cout << "Too many characters in row! Start over!" << endl;
				ErrorGrid = true;
				break;}

		cin.clear();
		input_line.clear();}}
}

void sand_and_stone::RunGravity()
{
	for (int j=0;j<grid_size;j++) { //Run simulation for every column
		for (int k=0;k<grid_size-1;k++) {
			while(grid[k][j]=='.' && grid[k+1][j]!='#' && grid[k+1][j]!='.' ) { //Check if all sand particles in column have something under them (stone or other sand). 
				for(int i=grid_size-2;i>-1;i--)	{//Run simulation for every row in column except the last one
					if(grid[i][j]=='.' && grid[i+1][j] == ' '){
						grid[i].replace(j,1," ");
						grid[i+1].replace(j,1,".");}	
					else if(grid[i][j]=='.' && grid[i+1][j]=='#') break;
					WriteToConsole();
//					sleep(1);
					system("cls");}}}}
}

void sand_and_stone::WriteToConsole()
{
	for(int n=0;n<grid.size();n++) cout << grid[n] << endl;
}