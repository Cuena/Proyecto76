

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
	pintar2();
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
				//printf("GANA EL JUGADOR %d, (HORIZONTAL)\n",i);
			}


			if (r + 3 < HEIGHT) {
				if (player == mapa[r + 1][c] && // vertical
					player == mapa[r + 2][c] &&
					player == mapa[r + 3][c]) {
					//win = i;
					return i;
					//printf("GANA EL JUGADOR %d, (VERTICAL)\n",i);
				}



				if (c + 3 < WIDTH &&
					player == mapa[r + 1][c + 1] && // diagonal derecha
					player == mapa[r + 2][c + 2] &&
					player == mapa[r + 3][c + 3]) {
					//win = i;
					return i;
					//printf("GANA EL JUGADOR %d, (DIAGONAL)\n",i);
				}



				if (c - 3 >= 0 &&
					player == mapa[r + 1][c - 1] && // diagonal izquierda
					player == mapa[r + 2][c - 2] &&
					player == mapa[r + 3][c - 3]) {
					//win = i;
					return i;
					//printf("GANA EL JUGADOR %d, (DIAGONAL)\n",i);
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
		//printf("ficha en %i %i: %c\n", i, a, mapa[i][a-1]);
		if (mapa[i][a - 1] != '0')
			cont++;
	}

	//printf("numero de fichas: %i\n", cont);

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
	//printf("Move: %i %i \n", j, move1 - 1);
	ult[0] = j;
	ult[1] = move1 - 1;
	//printf("Ult Move: %i %i \n", j, move1 - 1);
}




void meterFicha2(char *player, char a, int col, int l) {
	if (l == 1) {

		

		move1 = col;


		//printf("\n\n");
	}
	else { move1 = col; };
	//printf("El move es: %i \n",move1);
	int v = llena(move1);
	//printf("llena: %d \n", llena);
	//printf("move1: %d \n", move1);
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

int AIManager() // AI Algorithm
{
	int chance[2] = { 9999999 , 0 };

	int ult2[] = { 0,0 };
	for (int column = 1; column <= 7; column++)
	{
		PlayOut = 0;
		EVA = 0;
		//int PlayNumber = GetValue(column);

		if (llena(column) == 0 && movres()) {

			//input[PlayNumber] = 'O';
			meterFicha2("Player 2: ", player2char, column, 0);
			ult2[0] = ult[0];
			ult2[1] = ult[1];

			if (winCheckMapa(2) == 2)
			{
				//input[PlayNumber] = ' ';
				mapa[ult2[0]][ult2[1]] = '0';

				return column;
			}
			float temp = -(100 * NegaMax(1));

			if (PlayOut != 0)
				temp -= ((100 * EVA) / PlayOut); //bug
			//if (-temp >= 100)
				//provocation = true;
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

int NegaMax(int Depth) // MiniMax algorithm in NegaMax form
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
					if (XO == 'O')
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


//
//bool movres() {
//
//	for (int i = 0; i < 7; i++) {
//
//		if (mapa[6][i] == '0')
//			return true;
//
//
//	}
//
//	return false;
//}

//int mixmax(int nivel, bool player) {
//
//	int score;
//	if (player) {
//		score = winCheckMapa(2);
//	}else{ score = winCheckMapa(1); }
//
//	if (score == 1) //devolver si gana
//		return -10;
//	if (score == 2) //devolver si gana
//		return 10;
//	if (!movres)
//		return -1; //devolver si no quedan espacios libres
//	if (nivel == 0) {
//	
//		if (player) { return 10; }
//		return -10;
//	
//	}
//
//	if (player) {
//	
//		int best = -1000;
//		
//		
//			for (int j = 0; j < 7; j++)
//			{
//				
//				if (llena(j) == 0)
//				{
//					
//					//mapa[i][j] = '2';
//					int az = 6;
//					while (mapa[az][j] == player1char || mapa[az][j] == player2char)
//					{
//						az--;
//					}
//
//					mapa[az][j] = '2';
//
//					
//					int curr=3;
//					
//					   curr = mixmax(nivel - 1, !player);
//
//					if (best < curr)
//						best = curr;
//					printf("Curr: %i Best: %i", curr,best);
//					mapa[az][j] = '0';
//				}
//			}
//		
//
//		//printf("Best1: %i", best);
//		return best;
//	
//	} else {
//
//		int best = 1000;
//		
//		
//			for (int j = 0; j < 7; j++)
//			{
//				// Check if cell is empty 
//				if (llena(j) == 0)
//				{
//					// Make the move 
//					//mapa[i][j] = '1';
//
//					int az = 6;
//					while (mapa[az][j] == player1char || mapa[az][j] == player2char)
//					{
//						az--;
//					}
//
//					mapa[az][j] = '2';
//
//					// Call minimax recursively and choose 
//					// the maximum value 
//					int curr=3;
//					
//					    curr = mixmax(nivel - 1, !player);
//
//					if (best > curr)
//						best = curr;
//
//					printf("Curr: %i Best: %i", curr, best);
//					// Undo the move 
//					mapa[az][j] = '0';
//				}
//			}
//		
//		//printf("Best2: %i", best);
//		return best;
//
//	}
//
//
//
//}
//
//int findBestMove()
//{
//	int bestVal = -1000;
//	int bestMove;
//	bestMove = 8;
//
//	// Traverse all cells, evaluate minimax function for 
//	// all empty cells. And return the cell with optimal 
//	// value. 
//	
//		for (int j = 0; j < 7; j++)
//		{
//			// Check if cell is empty 
//			if (llena(j) == 0)
//			{
//				// Make the move 
//				//mapa[i][j] = '2';
//				int az = 6;
//				while (mapa[az][j] == player1char || mapa[az][j] == player2char)
//				{
//					az--;
//				}
//
//				mapa[az][j] = '2';
//				// compute evaluation function for this 
//				// move. 
//				
//				int moveVal = mixmax(5,false);
//
//				printf("Hola: %i\n",moveVal);
//				// Undo the move 
//				mapa[az][j] = '0';
//
//				// If the value of the current move is 
//				// more than the best value, then update 
//				// best/ 
//				if (moveVal > bestVal)
//				{
//					bestMove = j;
//					bestVal = moveVal;
//				}
//			}
//		}
//	
//
//	printf("Best Move is : %d\n\n",
//		bestMove);
//
//	return bestMove;
//}


//int AIManager() // AI Algorithm
//{
//	int chance[2] = { 9999999 , 0 };
//
//	int ult2[] = { 0,0 };
//	for (int column = 1; column <= 7; column++)
//	{
//		PlayOut = 0;
//		EVA = 0;
//		//int PlayNumber = GetValue(column);
//
//		if (llena(column) == 0 && movres()) {
//
//			//input[PlayNumber] = 'O';
//			meterFicha2("Player 2: ", player2char, column, 0);
//			ult2[0] = ult[0];
//			ult2[1] = ult[1];
//
//			if (winCheckMapa(2) == 2)
//			{
//				//input[PlayNumber] = ' ';
//				mapa[ult2[0]][ult2[1]] = '0';
//
//				return column;
//			}
//			float temp = -(100 * NegaMax(1));
//
//			if (PlayOut != 0)
//				temp -= ((100 * EVA) / PlayOut); //bug
//			//if (-temp >= 100)
//				//provocation = true;
//			if (chance[0] > temp)
//			{
//				chance[0] = temp;
//				chance[1] = column;
//			}
//
//			mapa[ult2[0]][ult2[1]] = '0';
//
//
//		}
//	}
//
//	return chance[1];
//}
//
//int NegaMax(int Depth) // MiniMax algorithm in NegaMax form
//{
//	char XO;
//	int p;
//
//	int ult2[] = { 0,0 };
//	int chance = 0;
//	if (Depth % 2 != 0) {
//		XO = player1char;
//		p = 1;
//	}
//	else {
//		XO = player2char;
//		p = 2;
//	}
//
//	for (int column = 1; column <= 7; column++)
//	{
//		if (llena(column) == 0 && movres()) {
//
//			meterFicha2("", XO, column, 0);
//			ult2[0] = ult[0];
//			ult2[1] = ult[1];
//			if (winCheckMapa(p) != 0)
//			{
//				PlayOut++;
//				if (XO == player2char)
//					EVA++;
//				else
//					EVA--;
//
//
//				mapa[ult2[0]][ult2[1]] = '0';
//				return -1;
//			}
//
//			mapa[ult2[0]][ult2[1]] = '0';
//		}
//	}
//	if (Depth <= 6)
//	{
//
//		for (int column = 1; column <= 7; column++)
//		{
//			int temp = 0;
//
//
//			if (llena(column) == 0 && movres()) {
//				meterFicha2("", XO, column, 0);
//				ult2[0] = ult[0];
//				ult2[1] = ult[1];
//				if (winCheckMapa(p) != 0)
//				{
//					PlayOut++;
//					if (XO == 'O')
//						EVA++;
//					else
//						EVA--;
//
//					mapa[ult2[0]][ult2[1]] = '0';
//					return -1;
//				}
//				temp = NegaMax(Depth + 1);
//				if (column == 1)
//					chance = temp;
//				if (chance < temp)
//					chance = temp;
//
//				mapa[ult2[0]][ult2[1]] = '0';
//			}
//		}
//	}
//	return -chance;
//
//}
//
//
//


//main() con una demo para ver la funcionalidad del juego en la cmd, nada mas empezar el juego se inicia una pantalla con el tablero en blanco
//los jugadores deberan ir introduciendo fichas escribiendo en consola el numero de la columna por la que quieren introducir la ficha (1,2,3,4,5,6 o 7)

//int main()
//{
//
//
//
//
//
//	while (again == 'Y' || again == 'y')
//	{
//
//		crearMapa();
//		pintar2();
//
//
//		while (win == 0)
//		{
//
//
//
//
//
//
//			if (win == 0)
//			{
//
//				//meterFicha2("Player 2: ", player2char);
//				int prueba = AIManager();
//				//printf("La prueba ha decidido que se meta en: %i", prueba);
//				meterFicha2("", player2char, prueba, 0);
//				pintar2();
//
//				if (winCheckMapa(2) == 2) {
//					printf("No eres un reto \n");
//					win = 1;
//				}
//			}
//
//			if (win == 0)
//			{
//
//				meterFicha2("Player 1: ", player1char, 0, 1);
//
//				pintar2();
//
//				if (winCheckMapa(1) == 1) {
//					printf("Has tenido suerte \n");
//					win == 1;
//				}
//
//			}
//
//		}
//
//
//		printf("Player 1  (%d)   -   (%d)  Player 2\n", onescore, twoscore);
//		printf("\n\n");
//		printf("Quieres jugar otra vez? (Y para jugar otra vez): \n");
//		fflush(stdout);
//
//		fgets(c, 200, stdin);
//		again = c[0];
//
//
//
//
//
//
//
//		printf("\n\n\n\n\n\n");
//
//		win = 0;
//
//
//	}
//
//	printf("Gracias por jugar! \n\n");
//
//	return 0;
//}

