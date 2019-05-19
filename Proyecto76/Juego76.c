

#include "Juego76.h"


void crearMapa() {



	for (int i = 1; i < 8; ++i)
	{
		for (int j = 0; j < 7; j++)
		{
			mapa[i][j] = '0';
		}
	}

	

}



void pintar2() {


	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			printf(" ");
			printf("%c ", mapa[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}



char pintar3(char xd[7][7]) {


	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			
			xd[i][j] = mapa[i][j];

		}
		
	}
	return xd;
}






int winCheckMapa(int i) {


	int HEIGHT = 7;
	int WIDTH = 7;
	int EMPTY_SLOT = '0';
	for (int r = 1; r < HEIGHT; r++) {
		for (int c = 0; c < WIDTH; c++) {
			int player = mapa[r][c];
			if (player == EMPTY_SLOT) {

				continue; // no se miran los espacios libres

			}

			if (c + 3 < WIDTH &&
				player == mapa[r][c + 1] && // horizontal
				player == mapa[r][c + 2] &&
				player == mapa[r][c + 3]) {
				//win = i;
				return i;
			
			}


			if (r + 3 < HEIGHT) {
				if (player == mapa[r + 1][c] && // vertical
					player == mapa[r + 2][c] &&
					player == mapa[r + 3][c]) {
					//win = i;
					return i;
					
				}



				if (c + 3 < WIDTH &&
					player == mapa[r + 1][c + 1] && // diagonal derecha
					player == mapa[r + 2][c + 2] &&
					player == mapa[r + 3][c + 3]) {
					//win = i;
					return i;
					
				}



				if (c - 3 >= 0 &&
					player == mapa[r + 1][c - 1] && // diagonal izquierda
					player == mapa[r + 2][c - 2] &&
					player == mapa[r + 3][c - 3]) {
					//win = i;
					return i;
					
				}


			}
		}
	}

	return 0;

}

void crearFich(char * nombre, char mapaG[][7])
{
	FILE *f = fopen(nombre, "w");
	if (f == NULL)
	{
		printf("Error\n");
		exit(1);
	}
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			fprintf(f, "%c,", mapaG[i][j]);
		}
	}
	fclose(f);
}

void leerFich(char * nombre)
{
	FILE *f;
	f = fopen(nombre, "r");
	if (f == NULL) {
		printf("Error al abrir\n");
		exit(0);
	}



	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			fscanf(f, "%c,", &mapa[i][j]);
		}
	}
	fclose(f);
}


int llena(int a) {

	int cont = 0;

	for (int i = 1; i < 7; i++)
	{
		
		if (mapa[i][a - 1] != '0')
			cont++;
	}

	

	if (cont == 6) {
		return 1;
	}
	else {
		return 0;
	};


}


void buscarLibre2(char a) {
	j = 6;
	while (mapa[j][move1 - 1] == player1char || mapa[j][move1 - 1] == player2char)
	{
		j--;
	}

	mapa[j][move1 - 1] = a;
	
	ult[0] = j;
	ult[1] = move1 - 1;

}




void meterFicha2(char *player, char a, int col, int l) {
	if (l == 1) {

		

		move1 = col;


	
	}
	else { move1 = col; };

	int v = llena(move1);

	while (v == 1)
	{

		
		v = llena(move1);


	}
	buscarLibre2(a);
}

bool movres() {

	for (int i = 0; i < 7; i++) {

		if (mapa[1][i] == '0')
			return true;
	}

	return false;

}

int AIManager() //Metodo que ejecuta la primera vuelta del algoritmo NegaMax
{
	int chance[2] = { 9999999 , 0 };

	int ult2[] = { 0,0 };
	for (int column = 1; column <= 7; column++)
	{
		PlayOut = 0;
		EVA = 0;
		

		if (llena(column) == 0 && movres()) {

		
			meterFicha2("Player 2: ", player2char, column, 0);
			ult2[0] = ult[0];
			ult2[1] = ult[1];

			if (winCheckMapa(2) == 2)
			{
			
				mapa[ult2[0]][ult2[1]] = '0';

				return column;
			}
			float temp = -(100 * NegaMax(1));

			if (PlayOut != 0)
				temp -= ((100 * EVA) / PlayOut); 
		
			if (chance[0] > temp)
			{
				chance[0] = temp;
				chance[1] = column;
			}

			mapa[ult2[0]][ult2[1]] = '0';


		}
	}

	return chance[1];
}

int NegaMax(int Depth)  //Algoritmo NegaMax programado para el 4 en raya  
						//Hemos editado el algoritmo inicial para adaptarlo a nuestro programa
						//Existe un bug que no hemos sido capaces de solucionar
{
	char XO;
	int p;

	int ult2[] = { 0,0 };
	int chance = 0;
	if (Depth % 2 != 0) {
		XO = player1char;
		p = 1;
	}
	else {
		XO = player2char;
		p = 2;
	}

	for (int column = 1; column <= 7; column++)
	{
		if (llena(column) == 0 && movres()) {

			meterFicha2("", XO, column, 0);
			ult2[0] = ult[0];
			ult2[1] = ult[1];
			if (winCheckMapa(p) != 0)
			{
				PlayOut++;
				if (XO == player2char)
					EVA++;
				else
					EVA--;


				mapa[ult2[0]][ult2[1]] = '0';
				return -1;
			}

			mapa[ult2[0]][ult2[1]] = '0';
		}
	}
	if (Depth <= 6)
	{

		for (int column = 1; column <= 7; column++)
		{
			int temp = 0;


			if (llena(column) == 0 && movres()) {
				meterFicha2("", XO, column, 0);
				ult2[0] = ult[0];
				ult2[1] = ult[1];
				if (winCheckMapa(p) != 0)
				{
					PlayOut++;
					if (XO == '2')
						EVA++;
					else
						EVA--;

					mapa[ult2[0]][ult2[1]] = '0';
					return -1;
				}
				temp = NegaMax(Depth + 1);
				if (column == 1)
					chance = temp;
				if (chance < temp)
					chance = temp;

				mapa[ult2[0]][ult2[1]] = '0';
			}
		}
	}
	return -chance;

}

void borrarFila(int f) {

	
		for (int j = 0; j < 7; j++)
		{
			mapa[f][j] = '0';
		}
	
}

void borrarColumna(int c) {


	for (int i = 1; i < 8; ++i)
	{
		
			mapa[i][c] = '0';
		
	}

}

