#pragma once

#include "sqlite3.h" 
#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h" 
#include <string>
#include <stdlib.h>
#include <stdio.h>


//std::string aver;
class BD
{
public:
	BD();
	virtual ~BD();

	sqlite3* abrirBD();
	int crearBD();
	int createTable();
	int insert();
	int select();

	
};
