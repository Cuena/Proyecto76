#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h" 

sqlite3* abrirBD();
int crearBD();
int createTable();
int insert();
int select();

class BD
{
public:
	BD();
	virtual ~BD();
};
