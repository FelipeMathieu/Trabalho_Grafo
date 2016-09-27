#pragma once

#include "dirent-1.21\include\dirent.h"
#include <iostream>
#include <string>
#include <sys/types.h>
#include "wFile.h"
#include "Grafo.h"
#include <xutility>

using namespace std;

class Search_Data
{
public:
	Search_Data();
	~Search_Data();

	static int openDir_My(char *dirname, char *currentDirName, Grafo *G);
};

