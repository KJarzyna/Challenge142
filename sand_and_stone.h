#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class sand_and_stone
{
public:
	void AskForInput();
	void RunGravity();
	void WriteToConsole();
	sand_and_stone();

private:
	vector<string> grid;
	string input_line;

	unsigned int grid_size;
	bool ErrorGrid, ErrorWrongInput;



};