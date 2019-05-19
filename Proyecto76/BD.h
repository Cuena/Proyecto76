

#include "sqlite3.h" 
#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h" 
#include <string>
#include <stdlib.h>
#include <stdio.h>

#pragma once



sqlite3* abrirBD();
int crearBD();
int createTable();
int insert();
int select(std::string s);
int updateBD(std::string s);
int insert(std::string s);
static int callback(void *NotUsed, int argc, char **argv, char **azColName);

//std::string aver;
class BD
{
public:

	BD();
	virtual ~BD();
	std::string averlo;

	


	
};
