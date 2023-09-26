/*
Auteur : BELLO Noah
Date : 06/02/2023
Nom du fichier : Source.cpp
*/

//Directive
#include "Header.h"

#pragma region Déclaration_Fonctions_Utiles

void Menu(void) {
	cout << "Voici le menu des programmes faits le 06/02/2023 : " << endl <<
		"\n1 : Fonction qui permet de parler d'un pointeur\n2 : Decouverte des pointeurs\n3 : Fonction qui utilise les pointeurs pour retourner 2 valeurs"
		<< endl << "4 : Projet avec Florian, Lorenzo, Lucas" << endl;
}

int Choix(void) {
	int c;
	while (true) {
		Menu();
		cout << endl << "Vous pouvez choisir un programme : ";
		cin >> c;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			system("cls");
		}
		else {
			if (c < 1 || c > 4) system("cls");
			else break;
		}
	}
	return c;
}

int Retour_Minute(int seconde) {
	return seconde / 60;
}

int Retour_Minute_Et_Seconde(int* seconde) {
	int sec = *seconde;
	*seconde %= 60;
	return  sec / 60;
}

#pragma endregion

#pragma region Déclaration_Fonctions_Utiles_Pour_Projet

void Accueil(void) {
	cout << "\t" << "\033[0;33m" << "**************************************************" << "\033[0m" << endl;
	cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t\t\t\t\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
	cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t" << "\033[1;36m" << "Bienvenue Dans L'Espace de Stockage" << "\033[0m" << "\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
	cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t\t\t\t\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
	cout << "\t" << "\033[0;33m" << "**************************************************" << "\033[0m" << endl;
}

string Verification_Recommencer_Ou_Pas(void) {
	string recommencer;
	while (true) {
		cout << "Si vous voulez recommencer, taper " << "\033[1;34m" << "Y" << "\033[0m" << " sinon " << "\033[1;34m" << "N " << "\033[0m" << ": ";
		cin >> recommencer;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			system("cls");
		}
		else {
			if (recommencer != "Y" && recommencer != "N") system("cls");
			else break;
		}
	}
	return recommencer;
}

void Menu2(void) {
	cout << endl << "\t" << "\033[0;33m" << "**********************************************************" << "\033[0m" << endl;
	cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t\t\t\t\t\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
	cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t\t" << "\033[1;36m" << "Choix des Possibilites dans le Stockage" << "\033[0m" << "\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
	cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t" << "\033[1;32m" << "1 : Ajouter un produit dans le stockage" << "\033[0m" << "\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
	cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t" << "\033[1;34m" << "2 : Supprimer un produit  dans le stockage" << "\033[0m" << "\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
	cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t" << "\033[1;31m" << "3 : Retourner un produit" << "\033[0m" << "\t\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
	cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t" << "\033[1;35m" << "4 : Afficher le stockage" << "\033[0m" << "\t\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
	cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t" << "\033[1;32m" << "5 : Calculer le chiffre d'affaires des produits" << "\033[0m" << "\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
	cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t\t\t\t\t\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
	cout << "\t" << "\033[0;33m" << "**********************************************************" << "\033[0m" << endl;
}

int Choix_Fonction(void) {
	int choix;
	while (true) {
		Menu2();
		cout << endl << "Entrer votre choix : ";
		cin >> choix;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			system("cls");
		}
		else {
			if (choix < 1 || choix > 5) system("cls");
			else break;
		}
	}
	return choix;
}

void Au_Revoir(void) {
	cout << "\t" << "\033[0;33m" << "*************************" << "\033[0m" << endl;
	cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t" << "\033[1;36m" << "Au Revoir " << "\033[0m" << "\t" << "\033[0;33m" << "*" << "\033[0m" << endl;
	cout << "\t" << "\033[0;33m" << "*************************" << "\033[0m" << endl;
}

#pragma endregion

#pragma region Déclaration_Fonction_Programme_Cours

void Programme_1(void) {
	//Exo1 : Pour parler sur les pointeurs
	system("cls");
	int seconde;
	cout << endl << "Veuillez saisir le nombre de seconde : ";
	cin >> seconde;
	cout << endl << seconde << " secondes = " << Retour_Minute(seconde) << "minutes." << endl;
}

void Programme_2(void) {
	//Exo2 :Utilisation de pointeurs
	system("cls");
	int nombre = 0;
	int* pointeur = &nombre;
	cout << endl << "Valeur nombre = " << nombre << endl << "Adresse nombre : " << &nombre << endl << "Valeur pointeur : " << *pointeur << endl
		<< "Adresse pointeur : " << pointeur << endl;
}

void Programme_3(void) {
	//Exo3 :Utilisation de pointeurs pour créer une fonction qui renvoie des minutes et des secondes
	system("cls");
	int seconde;
	cout << endl << "Veuillez saisir le nombre de seconde : ";
	cin >> seconde;
	cout << endl << Retour_Minute_Et_Seconde(&seconde) << " minutes et " << seconde << " secondes." << endl;
}

void Programme_4(void) {
	//Exo4 : Projet avec Lucas, Florian et Lorenzo
	int Choix_Pour_Les_Fonction;
	string Recommencer = "Y";
	Stockage Stockage_De_Produit(0);

	while (Recommencer == "Y") {
		system("cls");

		Accueil();
		Choix_Pour_Les_Fonction = Choix_Fonction();

		Stockage_De_Produit.Utilisation_Fonction_Selon_Choix(Choix_Pour_Les_Fonction);

		Recommencer = Verification_Recommencer_Ou_Pas();

		if (Recommencer == "Y") continue;
		else {
			system("cls");
			Au_Revoir();
			break;
		}
	}
}

#pragma endregion

void Programme_Debut_Cours(void) {
	int choix; string recom = "Y";

	while (recom == "Y") {
		choix = Choix();

		switch (choix) {
		case 1:
			Programme_1();
			break;
		case 2:
			Programme_2();
		case 3:
			Programme_3();
		default:
			Programme_4();
			break;
		}

		while (true) {
			cout << endl << "Si vous voulez recommencer, taper \033[1;34mY\033[0m sinon \033[1;34mN\033[0m : ";
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

		if (recom == "Y") { system("cls"); continue; }
		else { system("cls"); break; }
	}
}