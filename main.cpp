#include <iostream>
#include <vector>
#include <Windows.h>
#include <capstone/capstone.h>

#pragma comment (lib,"Dbghelp")
#pragma comment(lib,"capstone32.lib")

using namespace std;

int main(int argc, char* argv[])
{
  if (strcmp(argv[1], "--path") == 0)
  {
  	CreateDebug(argv[2]);
  	DebugRun();
  }
  return 0;
}
