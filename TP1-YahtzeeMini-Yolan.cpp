#include <iostream>
#include <ctime>
#include <string>
#include "yahtzee_function.h"

using namespace std;

int main() {
	srand(time(nullptr));

	int yahtzeeDes[3][5], pointage[9], choixDe, choixPointage;
	bool arrayCheck[5];
	initializeResult(pointage);

	for (int i = 0; i < 6; i++) {

		resetArrayDice(yahtzeeDes);
		resetArrayCheck(arrayCheck);

		for (int j = 0; j < 3; j++) {
			LaunchDice(j, yahtzeeDes, arrayCheck);
			printArray(yahtzeeDes);

			while (true) {
				cout << "Entrez un numero entre 1 et 6 pour v\x82rouiller/d\x82verouiller un dé, 0 pour lancer les d\x82s ou continuer : ";

				while (!(cin >> choixDe)) {
					cout << "ERREUR, Veuillez entrer un chiffre";
					cin.clear();
					cin.ignore(256, '\n');
				}

				while (choixDe < 0 || choixDe > 6) {
					cout << "ERREUR, veuillez entrer un chiffre entre 0 et 6 :";
					cin >> choixDe;
					cout << endl;
				}
				if (choixDe == 0) { break; }
				LockUnlock(arrayCheck, choixDe);
			}
		}
		cout << "Quel num\x82ro voulez-vous pointer ? ";
		while (!(cin >> choixPointage)) {
			cout << "ERREUR, Veuillez entrer un chiffre";
			cin.clear();
			cin.ignore(256, '\n');
		}
		bool setPointage = calcPoint(yahtzeeDes, pointage, choixPointage);
		printPointage(pointage);
	}

	cout << "---------------" << endl << "Pointage final : " << pointage[8] << endl << "---------------" << endl;

	return 0;
}

