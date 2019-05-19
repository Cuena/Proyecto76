
#include "BD.h"


sqlite3* abrirBD() {
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;

	rc = sqlite3_open("BD.db", &db);

	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return(0);
	}
	else {
		//fprintf(stderr, "Opened database successfully\n");
	}
	return db;
}

int crearBD() {
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;

	rc = sqlite3_open("BD.db", &db);

	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return(0);
	}
	else {
		fprintf(stderr, "Opened database successfully\n");
	}
	sqlite3_close(db);
	return 0;
}

 static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
	int i;
	for (i = 0; i < argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
		//aver = argv[i] ? argv[i] : "NULL";
	}
	printf("\n");
	return 0;
}

int select(std::string s) {
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	const char *sql;
	const char* data = "Callback function called";

	db = abrirBD();

	/* Create SQL statement */
	const char* result = "";
	const char*temp;
	std::string str;

	str = "SELECT * FROM PLAYER WHERE NAME = '";             
	str += s;      
	str += "';";
	result = str.c_str();
	printf(result);

	sql = result;
	
	

	/* Execute SQL statement */
	rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
	

	

	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Operation done successfully\n");
	}
	sqlite3_close(db);
	return 0;
}

int updateBD(std::string s) {
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	const char *sql;
	const char* data = "Callback function called";

	db = abrirBD();

	/* Create SQL statement */
	const char* result = "";
	const char*temp;
	std::string str;

	
	str = s;
	
	result = str.c_str();
	printf(result);

	sql = result;

	/* Execute SQL statement */
	rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);

	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Operation done successfully\n");
	}
	sqlite3_close(db);
	return 0;
}
int createTable() {
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	const char *sql;

	db = abrirBD();

	/* Create SQL statement */
	sql = "CREATE TABLE PLAYER("  \
		"NAME TEXT PRIMARY KEY     NOT NULL," \
		"PASSWORD VARCHAR(10)              NOT NULL," \
		"WINSPVP            INT," \
		"LOSESPVP            INT," \
		"WINSIA          INT," \
		"LOSESIA        INT," \
		"WINSONLINE        INT," \
		"LOSESONLINE         INT );";

	/* Execute SQL statement */
	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Table created successfully\n");
	}
	sqlite3_close(db);
	return 0;
}


int insert() {
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	const char *sql;

	db = abrirBD();

	/* Create SQL statement */
	sql = "INSERT INTO PLAYER "  \
		"VALUES ('KIKE', 'ZZZ', 0, 0, 0, 0, 0, 0);";
	
	/* Execute SQL statement */
	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Records created successfully\n");
	}
	sqlite3_close(db);
	return 0;
}

int insert(std::string s) {
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	const char *sql;

	db = abrirBD();

	/* Create SQL statement */
	std::string str;
	
	
	const char* result = "";
	//printf("bd: %s\n", s);
	str = "INSERT INTO PLAYER VALUES ('";
	str += s;
	str += "',";
	str += "'pass',0, 0, 0, 0, 0, 0); ";
	result = str.c_str();
	printf(result);

	sql = result;

	/* Execute SQL statement */
	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Records created successfully\n");
	}
	sqlite3_close(db);
	return 0;
}




