/*
Auteur : BELLO Noah
Date : 02/02/2023
Nom du fichier : Source.cpp
*/


//Directive
#include "Header.h"

//Déclaration de Fonction 
#pragma region Fonctions_Programme

void Calcul_Minute_En_Une_Annee(void) {
	cout << "\nVous avez " << 60 * 24 * 365 << " minute/annee" << endl;
}

int Calcul(void) {
	return 365 * 60 * 24;
}

void Table_Multiplication_Version_1(void) {
	int nombre;
	cout << "\nSaisir un nombre pour avoir sa table de multiplication : ";
	cin >> nombre;
	cout << "\nTable de Multiplication " << nombre << " avec une boucle for " << endl;
	for (int i = 1; i < 11; i++) {
		cout << nombre << " x " << i << " = " << nombre * i << endl;
	}
}

void Table_Multiplication_Version_2(void) {
	int j = 1, nombre;
	cout << "\nSaisir un nombre pour avoir sa table de multiplication : ";
	cin >> nombre;
	cout << "\nTable de Multiplication " << nombre << " avec une boucle while " << endl;
	while (j < 11) {
		cout << nombre << " x " << j << " = " << nombre * j << endl;
		j++;
	}
}

void Triangle(void) {
	for (int i = 0; i < 9; i++) {
		for (int j = 1; j <= i; j++) {
			cout << "*";
		}
		cout << endl;
	}

	cout << "----------" << endl;

	string etoile = "*";
	for (int i = 0; i < 9; i++) {
		cout << etoile << endl;
		etoile += "*";
	}
}

void Creation_Tableau_Pair(int tab[], int n) {
	for (int i = 0; i < n + 20; i++) {
		if (i % 2 == 0) {
			tab[i / 2] = i;
		}
	}

	/*
	//Ou
	for(int i=0; i<n+20; i+=2){
		tab[i] = i ;
	}
	*/
}

void Afficher_Tableau(int tab[], int n) {
	cout << "| ";
	for (int i = 0; i < n; i++) {
		cout << tab[i] << " | ";
	}
	cout << endl;
}

void Menu(void) {
	cout << "Voici le menu des programmes faits le 02/02/2023 : " << endl <<
		"0 : Hello World\n1 : Affichage de variable et variables\n2 : Entree et sortie\n3 : Appel de fonction\n4 : Fonction et boucle" << endl <<
		"5 : Boucle imbrique\n6 : Tableaux\n7 : Projet avec Yoven" << endl;
}
#pragma endregion

#pragma region Projet_avec_Yoven

void Affichage_Regle(void) {
	system("cls");
	cout << "\t*********************************************************" << endl;
	cout << "\t*\t\t\tRegle du Jeu\t\t\t*" << endl;
	cout << "\t* \t1 - Trouver le nombre que le programme cache \t*" << endl;
	cout << "\t* \t2 - Choisissez votre difficulte \t\t*" << endl;
	cout << "\t* \t!!! Entrez seulement des nombre !!! \t\t*" << endl;
	cout << "\t* !!! Respecter le temps impartie par votre mode de \t*" << endl << "\t* \t\t\tdifficulte !!! \t\t\t*" << endl;
	cout << "\t*********************************************************" << endl;
}

void Affichage_Jeu_Commence(void) {
	system("cls");
	cout << "\t*********************************************************" << endl;
	cout << "\t*\t\tLe Jeu va commmencer\t\t\t*" << endl;
	cout << "\t*********************************************************" << endl;
}

void Menu1(void) {

	int choix_entre_regle_et_jeu; int jeu_commence(0);
	while (true) {
		cout << "Pour connaitre les regles, tapez \033[1;34m1\033[0m; pour commencer le jeu, tapez \033[1;34m2\033[0m : ";
		cin >> choix_entre_regle_et_jeu;
		if (cin.fail()) {
			cout << "Vous n'avez pas saisie un nombre entier, reessayer" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else {
			if (choix_entre_regle_et_jeu < 1 || choix_entre_regle_et_jeu > 2) cout << "Vous avez saisie un nombre qui n'est pas compris entre 1 et 2 : " << choix_entre_regle_et_jeu << ", reessayer" << endl;
			else {

				switch (choix_entre_regle_et_jeu)
				{
				case 1:
					Affichage_Regle();
					break;
				default:
					Affichage_Jeu_Commence();
					jeu_commence = 1;
					break;
				}
				if (jeu_commence == 1) break;
				else continue;
			}
		}
	}
}

void Menu_Difficulte(void) {
	cout << endl << "\t*************************************************" << endl;
	cout << "\t*\t\tChoix de la Difficulte\t\t*" << endl;
	cout << "\t* \t\t     \033[1;32m1 : Facile\033[0m  \t\t*" << endl;
	cout << "\t* \t\t     \033[1;34m2 : Moyen\033[0m  \t\t*" << endl;
	cout << "\t* \t\t     \033[1;31m3 : Dur\033[0m \t\t\t*" << endl;
	cout << "\t* \t\t     \033[1;35m4 : Personaliser  !\033[0m \t*" << endl;
	cout << "\t*************************************************" << endl;
}

int Choix_Difficulte(void) {
	int difficulte;
	while (true) {
		Menu_Difficulte();
		cout << "Entrer la difficultee : ";
		cin >> difficulte;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			system("cls");
		}
		else {
			if (difficulte < 1 || difficulte > 4) system("cls");
			else break;
		}
	}
	return difficulte;
}

void Recupere_Difficulte(int difficulte, int* nombre_essai, int* temps) {
	switch (difficulte) {
	case 1:
		*temps = 60;
		*nombre_essai = 15;
		break;
	case 2:
		*temps = 40;
		*nombre_essai = 10;
		break;

	case 3:
		*temps = 20;
		*nombre_essai = 5;
		break;
	default:
		int temps_user(0);
		int nbr_user(0);

		cout << "Saisiez le temps en seconde:\t";
		cin >> temps_user;

		cout << "Saisiez le nombre d'essaie :\t";
		cin >> nbr_user;

		*temps = temps_user;
		*nombre_essai = nbr_user;
		break;
	}
}

void Affiche_Victoire(void) {
	cout << "\t*****************************************" << endl;
	cout << "\t*\t\033[1;32mBravo, vous avez trouvez !\033[0m\t*" << endl;
	cout << "\t*****************************************" << endl;
}

int Indication(int nombre_secret, int nombre_utilisateur, int* nombre_essaie) {
	int arret(0);
	if (nombre_secret < nombre_utilisateur) {
		cout << "\033[1;31mC'est moins !\033[0m" << endl;
		--* nombre_essaie;
	}
	else if (nombre_secret > nombre_utilisateur) {
		cout << "\033[1;31mC'est plus !\033[0m" << endl;
		--* nombre_essaie;
	}
	else {
		system("cls");
		Affiche_Victoire();
		arret = 1;
	}
	return arret;
}

char Verification_Recommencer_Ou_Pas(void) {
	char recommencer;
	while (true) {
		cout << "Si vous voulez recommencer, taper \033[1;34mY\033[0m sinon \033[1;34mN\033[0m : ";
		cin >> recommencer;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			system("cls");
		}
		else {
			if (recommencer != 'Y' && recommencer != 'N') system("cls");
			else break;
		}
	}
	return recommencer;
}

void Au_Revoir(void) {
	cout << "\t*************************" << endl;
	cout << "\t*\t\033[1;34mAu Revoir !\033[0m\t*" << endl;
	cout << "\t*************************" << endl;
}

void Perdu(int nombre_essai, int temps) {
	if (nombre_essai <= 0) {
		system("cls");
		cout << "\033[1;31mTu n'as plus d'essaie !\tTu a perdu !\033[0m\n";
	}
	else if (temps <= 0) {
		system("cls");
		cout << "\033[1;31mTu n'as plus de temps !\tTu a perdu !\033[0m\n";
	}
}

#pragma endregion

#pragma region Programme_Cours

void Programme_0(void) {
	//PartieTest
	cout << "Hello World!" << endl;
}

void Programme_1(void) {
	//Partie 1 : Affichage de variable et variables
	int test = 10;
	float test2 = 5.5;
	bool test3 = true;
	char test4[100] = "Bonjour";//Pour avoir une chaîne de caractère: version 2
	string test5 = "Hello"; //Pour avoir une chaîne de caractère: version 1
	if (test3) cout << "Voici la valeur de test = " << test << "\nVoici la valeur de test2 = " << test2 << "\nVoici la valeur de test3 = Vrai\nVoici la valeur de test4 = " << test4 << "\nVoici la valeur de test5 = " << test5 << endl;
	else cout << "Voici la valeur de test = " << test << "\nVoici la valeur de test2 = " << test2 << "\nVoici la valeur de test3 = Faux\nVoici la valeur de test4 = " << test4 << "\nVoici la valeur de test5 = " << test5 << endl;
}

void Programme_2(void) {
	//Partie 2 : Entree et sortie
	string Prenom;
	cout << "Bonjour\nComment tu t'appelles ?" << endl; //Le cout permet d'afficher
	cin >> Prenom; //Le cin permet de saisir des données
	cout << "Votre prenom est : " << Prenom << endl;
}

void Programme_3(void) {
	//Partie 3 : Appel de fonction
	Calcul_Minute_En_Une_Annee();
	cout << "Vous avez " << Calcul() << " minute/annee" << endl;
}

void Programme_4(void) {
	//Partie 4 : Fonction et boucle
	Table_Multiplication_Version_1();
	Table_Multiplication_Version_2();
	int nombre;
	cout << "Saisir un nombre pour avoir sa table de multiplication sinon 0 pour afficher tout :\t";
	cin >> nombre;
	if (nombre != 0) {
		cout << "\nTable de Multiplication " << nombre << endl;
		for (int i = 1; i < 11; i++) {
			cout << nombre << " x " << i << " = " << nombre * i << endl;
		}
	}

	else {
		cout << "\nTable De Multiplication" << endl;
		for (int i = 1; i < 11; i++) {
			cout << "\nTable de Multiplication " << i << endl;
			for (int j = 1; j < 11; j++) cout << i << " x " << j << " = " << i * j << endl;
		}
	}
}

void Programme_5(void) {
	//Partie 5 : Boucle imbrique
	Triangle();
}

void Programme_6(void) {
	//Partie 6 : Tableaux
	int Tab[N];
	Creation_Tableau_Pair(Tab, N);
	Afficher_Tableau(Tab, N);
}

void Programme_7(void) {
	srand(time(0));
	int Nombre_Secret = rand() % 100 + 1;

	int Nombre_Utilisateur(0), Nombre_Essaie(0), Time(0), Time2(0), Difficulte(0), Test_Arret(0);
	char Recommencer = 'Y';

	while (Recommencer == 'Y') {
		system("cls");

		Menu1();
		Difficulte = Choix_Difficulte();
		Recupere_Difficulte(Difficulte, &Nombre_Essaie, &Time);

		system("cls");

		auto start = high_resolution_clock::now();
		do {
			auto elapsed = high_resolution_clock::now() - start;
			auto elapsedSeconds = duration_cast<chrono::seconds>(elapsed).count();
			Time2 = Time - elapsedSeconds;
			cout << "\033[1;31mTemps restant : " << Time2 << " secondes\033[0m\r";
			cout.flush();
			this_thread::sleep_for(seconds(1));

			if (Time2 <= 0) break;
			else {
				cout << endl << "\033[1;34mVous avez \033[0m" << Nombre_Essaie << "\033[1;34m essai\033[0m";
				cout << endl << "Entrer un nombre : ";
				cin >> Nombre_Utilisateur;
				if (cin.fail()) {
					system("cls");
					cout << "Vous n'avez pas saisie un nombre entier, reessayer" << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				else {
					Test_Arret = Indication(Nombre_Secret, Nombre_Utilisateur, &Nombre_Essaie);
				}

				if (Test_Arret == 1) break;
				else continue;
			}
		} while (Nombre_Essaie != 0 && Time2 > 0);

		Perdu(Nombre_Essaie, Time2);

		Recommencer = Verification_Recommencer_Ou_Pas();
		if (Recommencer == 'Y') continue;
		else {
			system("cls");
			Au_Revoir();
			break;
		}
	}
}

int Choix(void) {
	int c;
	while (true) {
		Menu();
		cout << "Vous pouvez choisir un programme : ";
		cin >> c;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			system("cls");
		}
		else {
			if (c < 0 || c > 7) system("cls");
			else break;
		}
	}
	return c;
}

#pragma endregion

void Programme_Debut_Cours(void) {
	int choix; string recom = "Y";

	while (recom == "Y") {
		choix = Choix();

		switch (choix) {
		case 0:
			Programme_0();
			break;
		case 1:
			Programme_1();
			break;
		case 2:
			Programme_2();
			break;
		case 3:
			Programme_3();
			break;
		case 4:
			Programme_4();
			break;
		case 5:
			Programme_5();
			break;
		case 6:
			Programme_6();
			break;
		default:
			Programme_7();
			break;
		}

		while (true) {
			cout << "Si vous voulez recommencer, taper \033[1;34mY\033[0m sinon \033[1;34mN\033[0m : ";
			cin >> recom;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				system("cls");
			}
			else {
				if (recom != "Y" && recom != "N") system("cls");
				else break;
			}
		}

		if (recom == "Y") {
			system("cls");
			continue;
		}
		else {
			system("cls");
			break;
		}
	}
}