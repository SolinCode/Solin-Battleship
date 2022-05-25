#include <iostream>
#include "windows.h"

#define _BIND_TO_CURRENT_CRT_VERSION 1
#define _BIND_TO_CURRENT_ATL_VERSION 1
#define _BIND_TO_CURRENT_MFC_VERSION 1
#define _BIND_TO_CURRENT_OPENMP_VERSION 1

using namespace std;
const int mapSize = 10;

void mapRender(int mapGrid[mapSize][mapSize]);

int main() {
	srand(time(NULL));

	// Player
	int mapGridPlayer[mapSize][mapSize]{ 0 }; // Карта игрока
	int tempShipPlayer{};
	int continueStepPlayer{};
	int shipsLostPlayer{ 8 }; // Показывает сколько осталось кораблей у игрока
	int endGameWinPlayer{};

	bool shipsPlaceAutomatic{}; // Переменная для выбора режима расстановки кораблей ( автоматическая/ручная )

	// Computer
	int mapGridComputer[mapSize][mapSize]{ 0 }; // Карта компьютера
	int mapGridComputerHide[mapSize][mapSize]{ 0 }; // Карта компьютера скрытая
	int tempShipComputerHide{};
	int continueStepComputer{};
	int shipsLostComputer{ 8 }; // Показывает сколько осталось кораблей у компьютера
	int endGameWinComputer{};

	// Others
	int shipsCounter{}; // Счетчик кораблей при построении карты

	int tempShipX{};
	int tempShipY{};

	int tempCounter1{};
	int tempCounter2{};

	int tempRotation{};

	while (true)
	{
		char what{};
		system("cls");

		cout << "Welcome to \"Solin-Battleship\" game!\n";
		cout << "1. Start the game\n2. Rules\n3. About\n4. Exit\nSelect >> ";
		cin >> what;

		if (what == '1') {
			system("cls");
			cout << "Select game mode\n1. 8 - 1*1\n2. 3 - 1*5\nSelect mode >> ";
			cin >> what;

			if (what == '1') {
				cout << "\n1. Player - Computer\n2. Computer - Computer\nSelect mode >> ";
				cin >> what;
				if (what == '1') {
				system("cls");

				// Заполнение поля игрока сеткой
				for (int i = 0; i < mapSize; i++) {
					mapGridPlayer[i][0] = i;
					mapGridPlayer[0][i] = i;
					mapGridPlayer[0][0] = 10;
				}

				// Заполнение поля компьютера сеткой
				for (int i = 0; i < mapSize; i++) {
					mapGridComputer[i][0] = i;
					mapGridComputer[0][i] = i;
					mapGridComputer[0][0] = 10;

					mapGridComputerHide[i][0] = i;
					mapGridComputerHide[0][i] = i;
					mapGridComputerHide[0][0] = 10;
				}

				cout << "1. Automatic placement of ships\n2. Manual ship placement\nSelect >> ";
				cin >> what;

				if (what == '1') {
					// Автоматическая расстановка кораблей
					system("cls");
					shipsPlaceAutomatic = true;
				}
				else if (what == '2') {
					// Ручная расстановка кораблей
					system("cls");
					shipsPlaceAutomatic = false;
				}

				while (shipsCounter != 8) {
					if (shipsPlaceAutomatic == true) {
						tempShipX = rand() % 9 + 1;
						tempShipY = rand() % 9 + 1;

						if (mapGridPlayer[tempShipX][tempShipY] != 12 &&
							mapGridPlayer[tempShipX - 1][tempShipY] != 12 &&
							mapGridPlayer[tempShipX + 1][tempShipY] != 12 &&
							mapGridPlayer[tempShipX - 1][tempShipY + 1] != 12 &&
							mapGridPlayer[tempShipX + 1][tempShipY + 1] != 12 &&
							mapGridPlayer[tempShipX][tempShipY + 1] != 12 &&
							mapGridPlayer[tempShipX - 1][tempShipY - 1] != 12 &&
							mapGridPlayer[tempShipX + 1][tempShipY - 1] != 12 &&
							mapGridPlayer[tempShipX][tempShipY - 1] != 12)
						{
							mapGridPlayer[tempShipX][tempShipY] = 12;
							shipsCounter++;
						}
						else {
							tempShipX = 0;
							tempShipY = 0;
						}
						system("cls");
					}
					else if (shipsPlaceAutomatic == false) {
						cout << "----Player--Map----\n";
						mapRender(mapGridPlayer);
						cout << "Enter position (X - Y)\n";
						cin >> tempShipX >> tempShipY;

						if (mapGridPlayer[tempShipX][tempShipY] != 12 &&
							mapGridPlayer[tempShipX - 1][tempShipY] != 12 &&
							mapGridPlayer[tempShipX + 1][tempShipY] != 12 &&
							mapGridPlayer[tempShipX - 1][tempShipY + 1] != 12 &&
							mapGridPlayer[tempShipX + 1][tempShipY + 1] != 12 &&
							mapGridPlayer[tempShipX][tempShipY + 1] != 12 &&
							mapGridPlayer[tempShipX - 1][tempShipY - 1] != 12 &&
							mapGridPlayer[tempShipX + 1][tempShipY - 1] != 12 &&
							mapGridPlayer[tempShipX][tempShipY - 1] != 12)
						{
							mapGridPlayer[tempShipX][tempShipY] = 12;
							shipsCounter++;
						}
						else {
							tempShipX = 0;
							tempShipY = 0;
						}
						system("cls");
					}
				}

				shipsCounter = 0;

				while (shipsCounter != 8) {
					tempShipX = rand() % 9 + 1;
					tempShipY = rand() % 9 + 1;

					if (mapGridComputerHide[tempShipX][tempShipY] != 12 &&
						mapGridComputerHide[tempShipX - 1][tempShipY] != 12 &&
						mapGridComputerHide[tempShipX + 1][tempShipY] != 12 &&
						mapGridComputerHide[tempShipX - 1][tempShipY + 1] != 12 &&
						mapGridComputerHide[tempShipX + 1][tempShipY + 1] != 12 &&
						mapGridComputerHide[tempShipX][tempShipY + 1] != 12 &&
						mapGridComputerHide[tempShipX - 1][tempShipY - 1] != 12 &&
						mapGridComputerHide[tempShipX + 1][tempShipY - 1] != 12 &&
						mapGridComputerHide[tempShipX][tempShipY - 1] != 12)
					{
						mapGridComputerHide[tempShipX][tempShipY] = 12;
						shipsCounter++;
					}
					else {
						tempShipX = 0;
						tempShipY = 0;
					}
					system("cls");
				}

				endGameWinPlayer = 0;
				endGameWinComputer = 0;

				while (true)
				{
					if (endGameWinComputer == 1) {
						cout << "Player Won!";
						Sleep(1000);
						break;
					}
					else if (endGameWinPlayer == 1) {
						cout << "Computer Won!";
						Sleep(1000);
						break;
					}

					// Игра
					continueStepPlayer = 0;

					while (true)
					{
						cout << "---Computer--Map---\n";
						// Игрок вывод поля игрока
						mapRender(mapGridComputer);

						//cout << "\n----Debug---Map----\n";
						//// Игрок вывод поля игрока скрытое
						//mapRender(mapGridComputerHide);

						cout << endl;

						cout << "\n----Player--Map----\n";
						mapRender(mapGridPlayer);

						if (continueStepPlayer == 1) {
							break;
						}
						else {
							cout << endl << " Computer ships: " << shipsLostComputer << " Player ships: " << shipsLostPlayer << " > Player, Enter position >> ";
							cin >> tempShipX >> tempShipY;

							if (tempShipX == 0 || tempShipY == 0 || tempShipX > 9 || tempShipY > 9) {
								continueStepPlayer = 0;
								//cout << "range";
								//Sleep(100);
							}
							else if (mapGridComputerHide[tempShipX][tempShipY] == 11) {
								continueStepPlayer = 0;
								//cout << "sdecb uze udarili";
								//Sleep(100);
							}
							else if (mapGridComputerHide[tempShipX][tempShipY] == 12) {
								mapGridComputerHide[tempShipX][tempShipY] = 13;
								mapGridComputer[tempShipX][tempShipY] = 13;
								continueStepPlayer = 0;
								//cout << "popal";
								//Sleep(100);
							}
							else if (mapGridComputerHide[tempShipX][tempShipY] == 13) {
								continueStepPlayer = 0;
								//cout << "uze popal po korablu boat";
								//Sleep(100);
							}
							else if (mapGridComputerHide[tempShipX][tempShipY] == 0) {
								mapGridComputerHide[tempShipX][tempShipY] = 11;
								mapGridComputer[tempShipX][tempShipY] = 11;
								continueStepPlayer = 1;
								//cout << "normal +1";
								//Sleep(100);
							}
						}
						system("cls");
					}

					continueStepComputer = 0;

					while (true)
					{
						if (continueStepComputer == 1) {
							break;
						}
						else {
							tempShipX = rand() % 9 + 1;
							tempShipY = rand() % 9 + 1;

							if (tempShipX == 0 || tempShipY == 0 || tempShipX > 9 || tempShipY > 9) {
								continueStepComputer = 0;
								//cout << "range";
								//Sleep(100);
							}
							else if (mapGridPlayer[tempShipX][tempShipY] == 11) {
								continueStepComputer = 0;
								//cout << "sdecb uze udarili";
								//Sleep(100);
							}
							else if (mapGridPlayer[tempShipX][tempShipY] == 12) {
								mapGridPlayer[tempShipX][tempShipY] = 13;
								continueStepComputer = 1;
								//cout << "popal";
								//Sleep(100);
							}
							else if (mapGridPlayer[tempShipX][tempShipY] == 13) {
								continueStepComputer = 0;
								//cout << "uze popal po korablu boat";
								//Sleep(100);
							}
							else if (mapGridPlayer[tempShipX][tempShipY] == 0) {
								mapGridPlayer[tempShipX][tempShipY] = 11;
								continueStepComputer = 1;
								//cout << "normal";
								//Sleep(100);
							}
						}
					}

					shipsLostPlayer = 0;
					shipsLostComputer = 0;

					tempCounter1 = 0;
					tempCounter2 = 0;

					system("cls");
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 10; j++) {
							if (mapGridComputerHide[i][j] == 13) {
								tempCounter1 += 1;
							}
							if (mapGridPlayer[i][j] == 13) {
								tempCounter2 += 1;
							}

							if (tempCounter2 == 8) {
								endGameWinPlayer = 1;
							}
							if (tempCounter1 == 8) {
								endGameWinComputer = 1;
							}

							if (mapGridComputerHide[i][j] == 12) {
								shipsLostComputer += 1;
							}
							if (mapGridPlayer[i][j] == 12) {
								shipsLostPlayer += 1;
							}
						}
					}
				}
			}
				else if (what == '2') {
				system("cls");

				// Player
				int mapGridPlayer[mapSize][mapSize]{ 0 }; // Карта игрока
				int tempShipPlayer{};
				int continueStepPlayer{};
				int shipsLostPlayer{ 8 }; // Показывает сколько осталось кораблей у игрока
				int endGameWinPlayer{};

				bool shipsPlaceAutomatic{}; // Переменная для выбора режима расстановки кораблей ( автоматическая/ручная )

				// Computer
				int mapGridComputer[mapSize][mapSize]{ 0 }; // Карта компьютера
				int mapGridComputerHide[mapSize][mapSize]{ 0 }; // Карта компьютера скрытая
				int tempShipComputerHide{};
				int continueStepComputer{};
				int shipsLostComputer{ 8 }; // Показывает сколько осталось кораблей у компьютера
				int endGameWinComputer{};

				// Others
				int shipsCounter{}; // Счетчик кораблей при построении карты

				int tempShipX{};
				int tempShipY{};

				int tempCounter1{};
				int tempCounter2{};

				// Заполнение поля игрока сеткой
				for (int i = 0; i < mapSize; i++) {
					mapGridPlayer[i][0] = i;
					mapGridPlayer[0][i] = i;
					mapGridPlayer[0][0] = 10;
				}

				// Заполнение поля компьютера сеткой
				for (int i = 0; i < mapSize; i++) {
					mapGridComputer[i][0] = i;
					mapGridComputer[0][i] = i;
					mapGridComputer[0][0] = 10;

					mapGridComputerHide[i][0] = i;
					mapGridComputerHide[0][i] = i;
					mapGridComputerHide[0][0] = 10;
				}

				while (shipsCounter != 8) {
					tempShipX = rand() % 9 + 1;
					tempShipY = rand() % 9 + 1;

					if (mapGridPlayer[tempShipX][tempShipY] != 12 &&
						mapGridPlayer[tempShipX - 1][tempShipY] != 12 &&
						mapGridPlayer[tempShipX + 1][tempShipY] != 12 &&
						mapGridPlayer[tempShipX - 1][tempShipY + 1] != 12 &&
						mapGridPlayer[tempShipX + 1][tempShipY + 1] != 12 &&
						mapGridPlayer[tempShipX][tempShipY + 1] != 12 &&
						mapGridPlayer[tempShipX - 1][tempShipY - 1] != 12 &&
						mapGridPlayer[tempShipX + 1][tempShipY - 1] != 12 &&
						mapGridPlayer[tempShipX][tempShipY - 1] != 12)
					{
						mapGridPlayer[tempShipX][tempShipY] = 12;
						shipsCounter++;
					}
					else {
						tempShipX = 0;
						tempShipY = 0;
					}
					system("cls");
				}

				shipsCounter = 0;

				while (shipsCounter != 8) {
					tempShipX = rand() % 9 + 1;
					tempShipY = rand() % 9 + 1;

					if (mapGridComputerHide[tempShipX][tempShipY] != 12 &&
						mapGridComputerHide[tempShipX - 1][tempShipY] != 12 &&
						mapGridComputerHide[tempShipX + 1][tempShipY] != 12 &&
						mapGridComputerHide[tempShipX - 1][tempShipY + 1] != 12 &&
						mapGridComputerHide[tempShipX + 1][tempShipY + 1] != 12 &&
						mapGridComputerHide[tempShipX][tempShipY + 1] != 12 &&
						mapGridComputerHide[tempShipX - 1][tempShipY - 1] != 12 &&
						mapGridComputerHide[tempShipX + 1][tempShipY - 1] != 12 &&
						mapGridComputerHide[tempShipX][tempShipY - 1] != 12)
					{
						mapGridComputerHide[tempShipX][tempShipY] = 12;
						shipsCounter++;
					}
					else {
						tempShipX = 0;
						tempShipY = 0;
					}
					system("cls");
				}

				endGameWinPlayer = 0;
				endGameWinComputer = 0;

				while (true)
				{
					if (endGameWinComputer == 1) {
						cout << "Computer-1 Won!";
						Sleep(1000);
						break;
					}
					else if (endGameWinPlayer == 1) {
						cout << "Computer-2 Win!";
						Sleep(1000);
						break;
					}

					// Игра
					continueStepPlayer = 0;

					while (true)
					{
						cout << "--Computer-1--Map--\n";
						// Игрок вывод поля игрока
						mapRender(mapGridComputer);

						cout << endl;

						cout << "\n--Computer-2--Map--\n";
						mapRender(mapGridPlayer);

						if (continueStepPlayer == 1) {
							break;
						}
						else {
							tempShipX = rand() % 9 + 1;
							tempShipY = rand() % 9 + 1;

							Sleep(800);

							if (tempShipX == 0 || tempShipY == 0 || tempShipX > 9 || tempShipY > 9) {
								continueStepPlayer = 0;
								//cout << "range";
								//Sleep(100);
							}
							else if (mapGridComputerHide[tempShipX][tempShipY] == 11) {
								continueStepPlayer = 0;
								//cout << "sdecb uze udarili";
								//Sleep(100);
							}
							else if (mapGridComputerHide[tempShipX][tempShipY] == 12) {
								mapGridComputerHide[tempShipX][tempShipY] = 13;
								mapGridComputer[tempShipX][tempShipY] = 13;
								continueStepPlayer = 1;
								//cout << "popal";
								//Sleep(100);
							}
							else if (mapGridComputerHide[tempShipX][tempShipY] == 13) {
								continueStepPlayer = 0;
								//cout << "uze popal po korablu boat";
								//Sleep(100);
							}
							else if (mapGridComputerHide[tempShipX][tempShipY] == 0) {
								mapGridComputerHide[tempShipX][tempShipY] = 11;
								mapGridComputer[tempShipX][tempShipY] = 11;
								continueStepPlayer = 1;
								//cout << "normal +1";
								//Sleep(100);
							}
						}
						system("cls");
					}

					continueStepComputer = 0;

					while (true)
					{
						if (continueStepComputer == 1) {
							break;
						}
						else {
							tempShipX = rand() % 9 + 1;
							tempShipY = rand() % 9 + 1;

							if (tempShipX == 0 || tempShipY == 0 || tempShipX > 9 || tempShipY > 9) {
								continueStepComputer = 0;
								//cout << "range";
								//Sleep(100);
							}
							else if (mapGridPlayer[tempShipX][tempShipY] == 11) {
								continueStepComputer = 0;
								//cout << "sdecb uze udarili";
								//Sleep(100);
							}
							else if (mapGridPlayer[tempShipX][tempShipY] == 12) {
								mapGridPlayer[tempShipX][tempShipY] = 13;
								continueStepComputer = 1;
								//cout << "popal";
								//Sleep(100);
							}
							else if (mapGridPlayer[tempShipX][tempShipY] == 13) {
								continueStepComputer = 0;
								//cout << "uze popal po korablu boat";
								//Sleep(100);
							}
							else if (mapGridPlayer[tempShipX][tempShipY] == 0) {
								mapGridPlayer[tempShipX][tempShipY] = 11;
								continueStepComputer = 1;
								//cout << "normal";
								//Sleep(100);
							}
						}
					}

					shipsLostPlayer = 0;
					shipsLostComputer = 0;

					tempCounter1 = 0;
					tempCounter2 = 0;

					system("cls");
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 10; j++) {
							if (mapGridComputerHide[i][j] == 13) {
								tempCounter1 += 1;
							}
							if (mapGridPlayer[i][j] == 13) {
								tempCounter2 += 1;
							}

							if (tempCounter2 == 8) {
								endGameWinPlayer = 1;
							}
							if (tempCounter1 == 8) {
								endGameWinComputer = 1;
							}

							if (mapGridComputerHide[i][j] == 12) {
								shipsLostComputer += 1;
							}
							if (mapGridPlayer[i][j] == 12) {
								shipsLostPlayer += 1;
							}
						}
					}
				}
			}
			}
			else if (what == '2') {
				system("cls");

				// Заполнение поля игрока сеткой
				for (int i = 0; i < mapSize; i++) {
					mapGridPlayer[i][0] = i;
					mapGridPlayer[0][i] = i;
					mapGridPlayer[0][0] = 10;
				}

				// Заполнение поля компьютера сеткой
				for (int i = 0; i < mapSize; i++) {
					mapGridComputer[i][0] = i;
					mapGridComputer[0][i] = i;
					mapGridComputer[0][0] = 10;

					mapGridComputerHide[i][0] = i;
					mapGridComputerHide[0][i] = i;
					mapGridComputerHide[0][0] = 10;
				}

				cout << "1. Automatic placement of ships\n2. Manual ship placement\nSelect >> ";
				cin >> what;

				if (what == '1') {
					// Автоматическая расстановка кораблей
					system("cls");
					shipsPlaceAutomatic = true;
				}
				else if (what == '2') {
					// Ручная расстановка кораблей
					system("cls");
					shipsPlaceAutomatic = false;
				}

				while (shipsCounter != 3) {
					if (shipsPlaceAutomatic == true) {
						tempShipX = rand() % 9 + 1;
						tempShipY = rand() % 9 + 1;

						tempRotation = rand() % 2 + 1;

						if (tempRotation == 1) {
							if (mapGridPlayer[tempShipX][tempShipY] != 12 &&
								mapGridPlayer[tempShipX - 1][tempShipY] != 12 &&
								mapGridPlayer[tempShipX + 1][tempShipY] != 12 &&
								mapGridPlayer[tempShipX - 1][tempShipY + 1] != 12 &&
								mapGridPlayer[tempShipX + 1][tempShipY + 1] != 12 &&
								mapGridPlayer[tempShipX][tempShipY + 1] != 12 &&
								mapGridPlayer[tempShipX - 1][tempShipY - 1] != 12 &&
								mapGridPlayer[tempShipX + 1][tempShipY - 1] != 12 &&
								mapGridPlayer[tempShipX][tempShipY - 1] != 12 &&
								mapGridPlayer[tempShipX][tempShipY] != 12 &&
								mapGridPlayer[tempShipX][tempShipY + 1] != 12 &&
								mapGridPlayer[tempShipX][tempShipY + 2] != 12 &&
								mapGridPlayer[tempShipX][tempShipY + 3] != 12 &&
								mapGridPlayer[tempShipX][tempShipY + 4] != 12 &&

								mapGridPlayer[tempShipX][tempShipY + 1] != 12 &&
								mapGridPlayer[tempShipX][tempShipY + 2] != 12 &&
								mapGridPlayer[tempShipX][tempShipY + 3] != 12 &&
								mapGridPlayer[tempShipX][tempShipY + 4] != 12 &&
								mapGridPlayer[tempShipX][tempShipY + 5] != 12 &&

								mapGridPlayer[tempShipX][tempShipY - 1] != 12 &&
								mapGridPlayer[tempShipX - 1][tempShipY] != 12 &&
								mapGridPlayer[tempShipX - 1][tempShipY - 1] != 12 &&
								mapGridPlayer[tempShipX + 1][tempShipY - 1] != 12 &&
								mapGridPlayer[tempShipX + 1][tempShipY + 1] != 12 &&
								mapGridPlayer[tempShipX + 1][tempShipY] != 12 &&
								mapGridPlayer[tempShipX - 1][tempShipY + 1] != 12 &&
								mapGridPlayer[tempShipX + 1][tempShipY + 2] != 12 &&
								mapGridPlayer[tempShipX + 1][tempShipY + 3] != 12 &&
								mapGridPlayer[tempShipX + 1][tempShipY + 4] != 12 &&
								mapGridPlayer[tempShipX + 1][tempShipY + 5] != 12 &&
								mapGridPlayer[tempShipX - 1][tempShipY + 2] != 12 &&
								mapGridPlayer[tempShipX - 1][tempShipY + 3] != 12 &&
								mapGridPlayer[tempShipX - 1][tempShipY + 4] != 12 &&
								mapGridPlayer[tempShipX - 1][tempShipY + 5] != 12 &&
								mapGridPlayer[tempShipX][tempShipY + 5] != 12 &&

								mapGridPlayer[tempShipX][tempShipY + 1] == 00 &&
								mapGridPlayer[tempShipX][tempShipY + 2] == 00 &&
								mapGridPlayer[tempShipX][tempShipY + 3] == 00 &&
								mapGridPlayer[tempShipX][tempShipY + 4] == 00 &&
								mapGridPlayer[tempShipX][tempShipY + 5] == 00)
							{
								mapGridPlayer[tempShipX][tempShipY] = 12;
								mapGridPlayer[tempShipX][tempShipY + 1] = 12;
								mapGridPlayer[tempShipX][tempShipY + 2] = 12;
								mapGridPlayer[tempShipX][tempShipY + 3] = 12;
								mapGridPlayer[tempShipX][tempShipY + 4] = 12;

								shipsCounter++;
							}
							else {
								tempShipX = 0;
								tempShipY = 0;
							}
						}

						if (tempRotation == 2) {
							if (mapGridPlayer[tempShipX][tempShipY] != 12 &&
								mapGridPlayer[tempShipX][tempShipY] != 12 &&
								mapGridPlayer[tempShipX + 1][tempShipY] != 12 &&
								mapGridPlayer[tempShipX + 2][tempShipY] != 12 &&
								mapGridPlayer[tempShipX + 3][tempShipY] != 12 &&
								mapGridPlayer[tempShipX + 4][tempShipY] != 12 &&

								mapGridPlayer[tempShipX][tempShipY+1] != 12 &&
								mapGridPlayer[tempShipX-1][tempShipY+1] != 12 &&
								mapGridPlayer[tempShipX][tempShipY-1] != 12 &&
								mapGridPlayer[tempShipX-1][tempShipY-1] != 12 &&
								mapGridPlayer[tempShipX-1][tempShipY] != 12 &&

								mapGridPlayer[tempShipX][tempShipY] == 00 &&
								mapGridPlayer[tempShipX + 1][tempShipY] == 0 &&
								mapGridPlayer[tempShipX + 2][tempShipY] == 0 &&
								mapGridPlayer[tempShipX + 3][tempShipY] == 0 &&
								mapGridPlayer[tempShipX + 4][tempShipY] == 0 &&

								mapGridPlayer[tempShipX + 1][tempShipY + 1] != 12 &&
								mapGridPlayer[tempShipX + 2][tempShipY + 1] != 12 &&
								mapGridPlayer[tempShipX + 3][tempShipY + 1] != 12 &&
								mapGridPlayer[tempShipX + 4][tempShipY + 1] != 12 &&
								mapGridPlayer[tempShipX + 5][tempShipY + 1] != 12 &&
								mapGridPlayer[tempShipX + 1][tempShipY - 1] != 12 &&
								mapGridPlayer[tempShipX + 2][tempShipY - 1] != 12 &&
								mapGridPlayer[tempShipX + 3][tempShipY - 1] != 12 &&
								mapGridPlayer[tempShipX + 4][tempShipY - 1] != 12 &&
								mapGridPlayer[tempShipX + 5][tempShipY - 1] != 12 &&
								mapGridPlayer[tempShipX + 5][tempShipY] != 12)
							{
								mapGridPlayer[tempShipX][tempShipY] = 12;
								mapGridPlayer[tempShipX + 1][tempShipY] = 12;
								mapGridPlayer[tempShipX + 2][tempShipY] = 12;
								mapGridPlayer[tempShipX + 3][tempShipY] = 12;
								mapGridPlayer[tempShipX + 4][tempShipY] = 12;

								shipsCounter++;
							}
							else {
								tempShipX = 0;
								tempShipY = 0;
							}
						}

						system("cls");
					}
					else if (shipsPlaceAutomatic == false) {
						cout << "----Player--Map----\n";
						mapRender(mapGridPlayer);
						cout << "Enter position (X - Y)\n";
						cin >> tempShipX >> tempShipY;

						if (mapGridPlayer[tempShipX][tempShipY] != 12 &&
							mapGridPlayer[tempShipX - 1][tempShipY] != 12 &&
							mapGridPlayer[tempShipX + 1][tempShipY] != 12 &&
							mapGridPlayer[tempShipX - 1][tempShipY + 1] != 12 &&
							mapGridPlayer[tempShipX + 1][tempShipY + 1] != 12 &&
							mapGridPlayer[tempShipX][tempShipY + 1] != 12 &&
							mapGridPlayer[tempShipX - 1][tempShipY - 1] != 12 &&
							mapGridPlayer[tempShipX + 1][tempShipY - 1] != 12 &&
							mapGridPlayer[tempShipX][tempShipY - 1] != 12 &&
							mapGridPlayer[tempShipX][tempShipY] != 12 &&
							mapGridPlayer[tempShipX][tempShipY + 1] != 12 &&
							mapGridPlayer[tempShipX][tempShipY + 2] != 12 &&
							mapGridPlayer[tempShipX][tempShipY + 3] != 12 &&
							mapGridPlayer[tempShipX][tempShipY + 4] != 12 &&

							mapGridPlayer[tempShipX][tempShipY + 1] != 12 &&
							mapGridPlayer[tempShipX][tempShipY + 2] != 12 &&
							mapGridPlayer[tempShipX][tempShipY + 3] != 12 &&
							mapGridPlayer[tempShipX][tempShipY + 4] != 12 &&

							mapGridPlayer[tempShipX][tempShipY - 1] != 12 &&
							mapGridPlayer[tempShipX - 1][tempShipY] != 12 &&
							mapGridPlayer[tempShipX - 1][tempShipY - 1] != 12 &&
							mapGridPlayer[tempShipX + 1][tempShipY - 1] != 12 &&
							mapGridPlayer[tempShipX + 1][tempShipY + 1] != 12 &&
							mapGridPlayer[tempShipX + 1][tempShipY] != 12 &&
							mapGridPlayer[tempShipX - 1][tempShipY + 1] != 12 &&
							mapGridPlayer[tempShipX + 1][tempShipY + 2] != 12 &&
							mapGridPlayer[tempShipX + 1][tempShipY + 3] != 12 &&
							mapGridPlayer[tempShipX + 1][tempShipY + 4] != 12 &&
							mapGridPlayer[tempShipX + 1][tempShipY + 5] != 12 &&
							mapGridPlayer[tempShipX - 1][tempShipY + 2] != 12 &&
							mapGridPlayer[tempShipX - 1][tempShipY + 3] != 12 &&
							mapGridPlayer[tempShipX - 1][tempShipY + 4] != 12 &&
							mapGridPlayer[tempShipX - 1][tempShipY + 5] != 12 &&
							mapGridPlayer[tempShipX][tempShipY + 5] != 12 &&

							mapGridPlayer[tempShipX][tempShipY + 1] == 00 &&
							mapGridPlayer[tempShipX][tempShipY + 2] == 00 &&
							mapGridPlayer[tempShipX][tempShipY + 3] == 00 &&
							mapGridPlayer[tempShipX][tempShipY + 4] == 00)
						{
							mapGridPlayer[tempShipX][tempShipY] = 12;
							mapGridPlayer[tempShipX][tempShipY + 1] = 12;
							mapGridPlayer[tempShipX][tempShipY + 2] = 12;
							mapGridPlayer[tempShipX][tempShipY + 3] = 12;
							mapGridPlayer[tempShipX][tempShipY + 4] = 12;

							shipsCounter++;
						}
						else {
							tempShipX = 0;
							tempShipY = 0;
						}
						system("cls");
					}
				}

				shipsCounter = 0;

				while (shipsCounter != 3) {
					tempShipX = rand() % 9 + 1;
					tempShipY = rand() % 9 + 1;

					tempRotation = rand() % 2 + 1;

					if (tempRotation == 1) {
						if (mapGridComputerHide[tempShipX][tempShipY] != 12 &&
							mapGridComputerHide[tempShipX - 1][tempShipY] != 12 &&
							mapGridComputerHide[tempShipX + 1][tempShipY] != 12 &&
							mapGridComputerHide[tempShipX - 1][tempShipY + 1] != 12 &&
							mapGridComputerHide[tempShipX + 1][tempShipY + 1] != 12 &&
							mapGridComputerHide[tempShipX][tempShipY + 1] != 12 &&
							mapGridComputerHide[tempShipX - 1][tempShipY - 1] != 12 &&
							mapGridComputerHide[tempShipX + 1][tempShipY - 1] != 12 &&
							mapGridComputerHide[tempShipX][tempShipY - 1] != 12 &&
							mapGridComputerHide[tempShipX][tempShipY] != 12 &&
							mapGridComputerHide[tempShipX][tempShipY + 1] != 12 &&
							mapGridComputerHide[tempShipX][tempShipY + 2] != 12 &&
							mapGridComputerHide[tempShipX][tempShipY + 3] != 12 &&
							mapGridComputerHide[tempShipX][tempShipY + 4] != 12 &&

							mapGridComputerHide[tempShipX][tempShipY + 1] != 12 &&
							mapGridComputerHide[tempShipX][tempShipY + 2] != 12 &&
							mapGridComputerHide[tempShipX][tempShipY + 3] != 12 &&
							mapGridComputerHide[tempShipX][tempShipY + 4] != 12 &&
							mapGridComputerHide[tempShipX][tempShipY + 5] != 12 &&

							mapGridComputerHide[tempShipX][tempShipY - 1] != 12 &&
							mapGridComputerHide[tempShipX - 1][tempShipY] != 12 &&
							mapGridComputerHide[tempShipX - 1][tempShipY - 1] != 12 &&
							mapGridComputerHide[tempShipX + 1][tempShipY - 1] != 12 &&
							mapGridComputerHide[tempShipX + 1][tempShipY + 1] != 12 &&
							mapGridComputerHide[tempShipX + 1][tempShipY] != 12 &&
							mapGridComputerHide[tempShipX - 1][tempShipY + 1] != 12 &&
							mapGridComputerHide[tempShipX + 1][tempShipY + 2] != 12 &&
							mapGridComputerHide[tempShipX + 1][tempShipY + 3] != 12 &&
							mapGridComputerHide[tempShipX + 1][tempShipY + 4] != 12 &&
							mapGridComputerHide[tempShipX + 1][tempShipY + 5] != 12 &&
							mapGridComputerHide[tempShipX - 1][tempShipY + 2] != 12 &&
							mapGridComputerHide[tempShipX - 1][tempShipY + 3] != 12 &&
							mapGridComputerHide[tempShipX - 1][tempShipY + 4] != 12 &&
							mapGridComputerHide[tempShipX - 1][tempShipY + 5] != 12 &&
							mapGridComputerHide[tempShipX][tempShipY + 5] != 12 &&

							mapGridComputerHide[tempShipX][tempShipY + 1] == 00 &&
							mapGridComputerHide[tempShipX][tempShipY + 2] == 00 &&
							mapGridComputerHide[tempShipX][tempShipY + 3] == 00 &&
							mapGridComputerHide[tempShipX][tempShipY + 4] == 00 &&
							mapGridComputerHide[tempShipX][tempShipY + 5] == 00)
						{
							mapGridComputerHide[tempShipX][tempShipY] = 12;
							mapGridComputerHide[tempShipX][tempShipY + 1] = 12;
							mapGridComputerHide[tempShipX][tempShipY + 2] = 12;
							mapGridComputerHide[tempShipX][tempShipY + 3] = 12;
							mapGridComputerHide[tempShipX][tempShipY + 4] = 12;

							shipsCounter++;
						}
						else {
							tempShipX = 0;
							tempShipY = 0;
						}
					}

					if (tempRotation == 2) {
						if (mapGridComputerHide[tempShipX][tempShipY] != 12 &&
							mapGridComputerHide[tempShipX][tempShipY] != 12 &&
							mapGridComputerHide[tempShipX + 1][tempShipY] != 12 &&
							mapGridComputerHide[tempShipX + 2][tempShipY] != 12 &&
							mapGridComputerHide[tempShipX + 3][tempShipY] != 12 &&
							mapGridComputerHide[tempShipX + 4][tempShipY] != 12 &&

							mapGridComputerHide[tempShipX][tempShipY + 1] != 12 &&
							mapGridComputerHide[tempShipX - 1][tempShipY + 1] != 12 &&
							mapGridComputerHide[tempShipX][tempShipY - 1] != 12 &&
							mapGridComputerHide[tempShipX - 1][tempShipY - 1] != 12 &&
							mapGridComputerHide[tempShipX - 1][tempShipY] != 12 &&

							mapGridComputerHide[tempShipX][tempShipY] == 00 &&
							mapGridComputerHide[tempShipX + 1][tempShipY] == 0 &&
							mapGridComputerHide[tempShipX + 2][tempShipY] == 0 &&
							mapGridComputerHide[tempShipX + 3][tempShipY] == 0 &&
							mapGridComputerHide[tempShipX + 4][tempShipY] == 0 &&

							mapGridComputerHide[tempShipX + 1][tempShipY + 1] != 12 &&
							mapGridComputerHide[tempShipX + 2][tempShipY + 1] != 12 &&
							mapGridComputerHide[tempShipX + 3][tempShipY + 1] != 12 &&
							mapGridComputerHide[tempShipX + 4][tempShipY + 1] != 12 &&
							mapGridComputerHide[tempShipX + 5][tempShipY + 1] != 12 &&
							mapGridComputerHide[tempShipX + 1][tempShipY - 1] != 12 &&
							mapGridComputerHide[tempShipX + 2][tempShipY - 1] != 12 &&
							mapGridComputerHide[tempShipX + 3][tempShipY - 1] != 12 &&
							mapGridComputerHide[tempShipX + 4][tempShipY - 1] != 12 &&
							mapGridComputerHide[tempShipX + 5][tempShipY - 1] != 12 &&
							mapGridComputerHide[tempShipX + 5][tempShipY] != 12)
						{
							mapGridComputerHide[tempShipX][tempShipY] = 12;
							mapGridComputerHide[tempShipX + 1][tempShipY] = 12;
							mapGridComputerHide[tempShipX + 2][tempShipY] = 12;
							mapGridComputerHide[tempShipX + 3][tempShipY] = 12;
							mapGridComputerHide[tempShipX + 4][tempShipY] = 12;

							shipsCounter++;
						}
						else {
							tempShipX = 0;
							tempShipY = 0;
						}
					}

					system("cls");
				}

				endGameWinPlayer = 0;
				endGameWinComputer = 0;

				while (true)
				{
					if (endGameWinComputer == 1) {
						cout << "Player Won!";
						Sleep(1000);
						break;
					}
					else if (endGameWinPlayer == 1) {
						cout << "Computer Won!";
						Sleep(1000);
						break;
					}

					// Игра
					continueStepPlayer = 0;

					while (true)
					{
						cout << "---Computer--Map---\n";
						// Игрок вывод поля игрока
						mapRender(mapGridComputer);

						//cout << "\n----Debug---Map----\n";
						//// Игрок вывод поля игрока скрытое
						//mapRender(mapGridComputerHide);

						cout << endl;

						cout << "\n----Player--Map----\n";
						mapRender(mapGridPlayer);

						if (continueStepPlayer == 1) {
							break;
						}
						else {
							cout << endl << " Player, Enter position >> ";
							cin >> tempShipX >> tempShipY;

							if (tempShipX == 0 || tempShipY == 0 || tempShipX > 9 || tempShipY > 9) {
								continueStepPlayer = 0;
								//cout << "range";
								//Sleep(100);
							}
							else if (mapGridComputerHide[tempShipX][tempShipY] == 11) {
								continueStepPlayer = 0;
								//cout << "sdecb uze udarili";
								//Sleep(100);
							}
							else if (mapGridComputerHide[tempShipX][tempShipY] == 12) {
								mapGridComputerHide[tempShipX][tempShipY] = 13;
								mapGridComputer[tempShipX][tempShipY] = 13;
								continueStepPlayer = 0;
								//cout << "popal";
								//Sleep(100);
							}
							else if (mapGridComputerHide[tempShipX][tempShipY] == 13) {
								continueStepPlayer = 0;
								//cout << "uze popal po korablu boat";
								//Sleep(100);
							}
							else if (mapGridComputerHide[tempShipX][tempShipY] == 0) {
								mapGridComputerHide[tempShipX][tempShipY] = 11;
								mapGridComputer[tempShipX][tempShipY] = 11;
								continueStepPlayer = 1;
								//cout << "normal +1";
								//Sleep(100);
							}
						}
						system("cls");
					}

					continueStepComputer = 0;

					while (true)
					{
						if (continueStepComputer == 1) {
							break;
						}
						else {
							tempShipX = rand() % 9 + 1;
							tempShipY = rand() % 9 + 1;

							if (tempShipX == 0 || tempShipY == 0 || tempShipX > 9 || tempShipY > 9) {
								continueStepComputer = 0;
								//cout << "range";
								//Sleep(100);
							}
							else if (mapGridPlayer[tempShipX][tempShipY] == 11) {
								continueStepComputer = 0;
								//cout << "sdecb uze udarili";
								//Sleep(100);
							}
							else if (mapGridPlayer[tempShipX][tempShipY] == 12) {
								mapGridPlayer[tempShipX][tempShipY] = 13;
								continueStepPlayer = 0;
								//cout << "popal";
								//Sleep(100);
							}
							else if (mapGridPlayer[tempShipX][tempShipY] == 13) {
								continueStepComputer = 0;
								//cout << "uze popal po korablu boat";
								//Sleep(100);
							}
							else if (mapGridPlayer[tempShipX][tempShipY] == 0) {
								mapGridPlayer[tempShipX][tempShipY] = 11;
								continueStepComputer = 1;
								//cout << "normal";
								//Sleep(100);
							}
						}
					}

					shipsLostPlayer = 0;
					shipsLostComputer = 0;

					tempCounter1 = 0;
					tempCounter2 = 0;

					system("cls");
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 10; j++) {
							if (mapGridComputerHide[i][j] == 13) {
								tempCounter1 += 1;
							}
							if (mapGridPlayer[i][j] == 13) {
								tempCounter2 += 1;
							}

							if (tempCounter2 == 15) {
								endGameWinPlayer = 1;
							}
							if (tempCounter1 == 15) {
								endGameWinComputer = 1;
							}

							if (mapGridComputerHide[i][j] == 12) {
								shipsLostComputer += 1;
							}
							if (mapGridPlayer[i][j] == 12) {
								shipsLostPlayer += 1;
							}
						}
					}
				}
			}
		}
		else if (what == '2') {
			system("cls");

			cout << "Rules.\n1*1 > There are 2 fields, your field and the computer field. it has 8 ships of size 1 x 1. The goal of the game is to guess where the computer's ships are and hit them.\n1*5 > There are 2 fields, your field and the computer field. it has 3 ships of size 1 x 5. The goal of the game is to guess where the computer's ships are and hit them. Good luck!";
			cout << "\n1. Back\nSelect >> ";
			cin >> what;
		}
		else if (what == '3') {
			system("cls");

			cout << "Coded by Solin4035\nhttps://github.com/SolinCode";
			cout << "\n1. Back\nSelect >> ";
			cin >> what;
		}
		else if (what == '4') {
			cout << "\nBye!";
			Sleep(500);
			break;
		}
	}
}

void mapRender(int mapGrid[mapSize][mapSize]) {
	for (int i = 0; i < mapSize; i++) {
		for (int j = 0; j < mapSize; j++) {
			if (mapGrid[i][j] == 0) {
				cout << "-";
			}
			else if (mapGrid[i][j] == 10) {
				cout << "0";
			}
			else if (mapGrid[i][j] == 11) {
				cout << "X";
			}
			else if (mapGrid[i][j] == 12) {
				cout << "@";
			}
			else if (mapGrid[i][j] == 13) {
				cout << "%";
			}
			else {
				cout << mapGrid[i][j];
			}
			cout << " ";
		}
		cout << endl;
	}
}


// 0  = поле
// 10 = 0 (нулевая точка на поле)
// 11 = x (удар)
// 12 = @ (корабль)
// 13 = % (подбитый корабль)