#include <cstdlib>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

const int SCORE = 5;

int main(int argc, char *argv[])
{
	ifstream ouf(argv[1]); //Takmicar
	ifstream sof(argv[2]); //Komisija
	ifstream inf(argv[3]); //Input

	string sol, sol2, out;
	string nosolution = "nemoguce";
	sof >> sol;
	ouf >> out;

	sol2 = sol;
	reverse(sol2.begin(), sol2.end());

	if ((sol.compare(out) == 0) || (sol.compare(nosolution) != 0 && sol2.compare(out) == 0))
	{
		return SCORE;
	}
	else
	{
		return -1;
	}
}
