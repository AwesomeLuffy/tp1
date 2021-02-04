using namespace std;

void printPointage(int tab[9]) {//Affichage du tableau de résultats
	string nameToPrint[9] = { "As", "Deux", "Trois", "Quatre",
							  "Cinq", "Six", "Sous-Total", "Bonus", "Total" };
	cout << "[POINTAGE]" << endl;
	for (int i = 0; i < 9; i++) {
		cout << nameToPrint[i] << " : " << tab[i] << endl;
	}
	cout << endl;
}

void updateTotal(int tabpointage[9], int total) {//Mise à jour SousTotal/Bonus/Total
	tabpointage[6] = total;
	if (tabpointage[6] >= 63 && tabpointage[7] == 0) {
		tabpointage[7] = 35;
	}
	tabpointage[8] += total + tabpointage[7];
}

void initializeResult(int tab[9]) {//Initialization du tableau de pointage
	for (int i = 0; i < 9; i++) {
		(i <= 5) ? tab[i] = -1 : tab[i] = 0;
	}
}

void resetArrayDice(int tab[3][5]) {//Mise à 0 du tableau de lancé de dés
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			tab[i][j] = 0;
		}
	}
}

void printArray(int tab[3][5]) {//Affichage du tableau de lancé de dès
	string six;
	for (int i = 0; i < 3; i++) {
		cout << "Lancer #" << i + 1 << " : ";
		for (int j = 0; j < 5; j++) {
			(j == 4) ? six = "" : six = " --- ";
			cout << tab[i][j] << six;
		}
		cout << endl;
	}
	cout << endl;
}

void resetArrayCheck(bool tab[5]) {//Mise à 0 du tableau de vérification de vérouillage/dévérouillage
	for (int i = 0; i < 5; i++) {
		tab[i] = false;
	}
}

void LockUnlock(bool arrayCheck[5], int choixDe) {//Veoruillage Deverouillage
	string state;
	(arrayCheck[choixDe - 1]) ? arrayCheck[choixDe - 1] = false : arrayCheck[choixDe - 1] = true;
	(arrayCheck[choixDe - 1]) ? state = " d\x82verouill\x82" : state = " v\x82rrouille\x82";
	cout << "De num\x82ro " << choixDe << state << endl;
}

int getDice() { return rand() % 6 + 1; }//Lancement d'un dè

void LaunchDice(int state, int tab[3][5], bool arrayCheck[5]) {//Lancement des dès
	for (int i = 0; i < 5; i++) {
		(!(arrayCheck[i])) ? tab[state][i] = getDice() : tab[state][i] = tab[state - 1][i];
	}
}

bool calcPoint(int tab[3][5], int tabpointage[9], int choixAPointer) {//Calcul des points
	while (choixAPointer < 1 || choixAPointer > 6) {
		cout << "Veuillez entrer un chiffre compris entre 1 et 6 uniquement" << endl;
		cin >> choixAPointer;
	}
	while (tabpointage[choixAPointer - 1] != -1) {
		cout << "ERREUR, veuillez s\x82lectionner un pointage qui n'est pas encore fait." << endl;
		cin >> choixAPointer;
	}
	int total = 0;
	for (int i = 0; i < 5; i++) {
		if (tab[2][i] == choixAPointer) {
			total += tab[2][i];
		}
	}
	tabpointage[choixAPointer - 1] = total;
	updateTotal(tabpointage, total);
	return true;
}