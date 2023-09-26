/*
Auteur : BELLO Noah
Date : 03/02/2023
Nom du fichier : Source.cpp
*/

//Directive
#include "Header.h"

#pragma region Déclaration_Fonctions_Utiles

void Menu(void) {
	cout << "Voici le menu des programmes faits le 03/02/2023 : " << endl <<
		"1 : Decouverte des struct\n2 : Decouverte des class\n3 : Classe Triangle avec ce qu'on a fait hier\n4 : Classe Guerrier qui herite de la classe"
		<< " Perso avec une force en plus et il peut taper\n5 : Classe Magicien qui herite de la classe Perso avec du mana en plus et il peut montre sa magie"
		<< "\n6 : Classe Epeiste qui herite de la classe Guerrier avec la longueur de l'epee en plus et il montre son epee et donne un coup d'estoc\n7 : Combat" <<
		"\n8 : Projet avec Yoven, Lorenzo et Florian" << endl;
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
			if (c < 1 || c > 8) system("cls");
			else break;
		}
	}
	return c;
}

void Accueil(void) {
	/*************************************************************
	*	Le nom de la fonction est Accueil, elle permet d'afficher un accueil.
	*	Elle ne reçoit aucune valeur et ne renvoie pas de valeurs.
	*	Instructions utilisées : 5 cout et 5 endl
	**************************************************************/

	cout << "\t" << "\033[0;33m" << "******************************************" << "\033[0m" << endl;
	cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t\t\t\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
	cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t" << "\033[1;36m" << "Bienvenue a la Bibliotheque" << "\033[0m" << "\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
	cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t\t\t\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
	cout << "\t" << "\033[0;33m" << "******************************************" << "\033[0m" << endl;
}

string Verification_Recommencer_Ou_Pas(void) {
	/*************************************************************
	*	Le nom de la fonction est Verification_Recommencer_Ou_Pas, elle permet à l'utilisateur de saisir si il veut recommencer ou pas
	*		si la valeur n'est cohérente pas, on redemandera la saisie jusqu'à avoir une valeur cohérente.
	*	Elle ne reçoit aucune valeur et renvoie une valeur de type string.
	*	Instructions utilisées : 1 cout, 1 cin, 1 endl, 1 while, 2 if, 2 else, 1 return, 1 system, 1 clear, 1 fail, 1 ignore
	*	Fonction utilisées : Menu
	**************************************************************/

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
	/*************************************************************
	*	Le nom de la fonction est Menu, elle permet d'afficher un menu de choses possibles par le programme.
	*	Elle ne reçoit aucune valeur et ne renvoie pas de valeurs.
	*	Instructions utilisées : 9 cout et 10 endl
	**************************************************************/

	cout << endl << "\t" << "\033[0;33m" << "**********************************************************" << "\033[0m" << endl;
	cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t\t\t\t\t\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
	cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t\t" << "\033[1;36m" << "Choix de la Difficulte" << "\033[0m" << "\t\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
	cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t" << "\033[1;32m" << "1 : Ajouter un livre a la bibliotheque" << "\033[0m" << "\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
	cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t" << "\033[1;34m" << "2 : Retirer un livre a la bibliotheque" << "\033[0m" << "\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
	cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t" << "\033[1;31m" << "3 : Emprunter ou Rendre un livre" << "\033[0m" << "\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
	cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t" << "\033[1;35m" << "4 : Afficher la bibliotheque" << "\033[0m" << "\t\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
	cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t\t\t\t\t\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
	cout << "\t" << "\033[0;33m" << "**********************************************************" << "\033[0m" << endl;
}

int Choix_Fonction(void) {
	/*************************************************************
	*	Le nom de la fonction est Choix_Fonction, elle permet à l'utilisateur de saisir un choix dans le menu puis la retourne
	*		sauf si je n'ai pas compris dans le menu, alors on redemande la saisie jusqu'à avoir une valeur cohérente.
	*	Elle ne reçoit aucune valeur et renvoie une valeur de type int.
	*	Instructions utilisées : 1 cout, 1 cin, 1 endl, 1 while, 2 if, 2 else, 1 return, 1 system, 1 clear, 1 fail, 1 ignore
	*	Fonction utilisées : Menu
	**************************************************************/
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
			if (choix < 1 || choix > 4) system("cls");
			else break;
		}
	}
	return choix;
}

void Au_Revoir(void) {
	/*************************************************************
	*	Le nom de la fonction est Au_Revoir, elle permet d'afficher un au revoir quand l'utilisateur veut arrêter le programme.
	*	Elle ne reçoit aucune valeur et ne renvoie pas de valeurs.
	*	Instructions utilisées : 3 cout et 3 endl
	**************************************************************/

	cout << "\t" << "\033[0;33m" << "*************************" << "\033[0m" << endl;
	cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t" << "\033[1;36m" << "Au Revoir " << "\033[0m" << "\t" << "\033[0;33m" << "*" << "\033[0m" << endl;
	cout << "\t" << "\033[0;33m" << "*************************" << "\033[0m" << endl;
}

#pragma endregion

#pragma region Déclaration_Fonction_Programme_Cours

void Programme_1(void) {
	//Exo1 : Décou"\033[1;32m"e des struct
	system("cls");
	Cercle Petit_Cercle(4, 6, 3);

	Petit_Cercle.afficher();
}

void Programme_2(void) {
	//Exo 2 : Décou"\033[1;32m"e des class
	system("cls");
	int age_perso, taille_perso;
	string prenom_perso;
	while (true) {
		cout << "Entrer votre age : ";
		cin >> age_perso;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			system("cls");
		}
		else {
			break;
		}
	}

	while (true) {
		cout << "Entrer votre taille : ";
		cin >> taille_perso;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			system("cls");
		}
		else {
			break;
		}
	}

	cout << "Entrer votre prenom : ";
	cin >> prenom_perso;

	Perso personnage(age_perso, taille_perso, prenom_perso);
	personnage.Presentation();

	personnage.Prend_Degat(rand() % 50 + 1);
}

void Programme_3(void) {
	//Exo 3 : Classe Triangle avec ce qu'on a fait hier
	system("cls");
	Triangle triangle(9);
	triangle.afficher();
}

void Programme_4(void) {
	//Exo 4 : Classe Guerrier qui hérite de la classe Perso avec une force en plus et il peut taper
	system("cls");
	int age_guerrier, taille_guerrier, force_guerrier;
	string prenom_guerrier;
	while (true) {
		cout << "Entrer votre age : ";
		cin >> age_guerrier;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			system("cls");
		}
		else {
			break;
		}
	}

	while (true) {
		cout << "Entrer votre taille : ";
		cin >> taille_guerrier;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			system("cls");
		}
		else {
			break;
		}
	}

	while (true) {
		cout << "Quel est votre force : ";
		cin >> force_guerrier;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			system("cls");
		}
		else {
			break;
		}
	}

	cout << "Entrer votre prenom : ";
	cin >> prenom_guerrier;

	Guerrier guerrier(age_guerrier, taille_guerrier, force_guerrier, prenom_guerrier);
	guerrier.Presentation();
	guerrier.Taper();
}

void Programme_5(void) {
	//Exo 5 : Classe Magicien qui hérite de la classe Perso avec du mana en plus et il peut montre sa magie
	system("cls");
	int age_magicien, taille_magicien, mana_magicien;
	string prenom_magicien;
	while (true) {
		cout << "Entrer votre age : ";
		cin >> age_magicien;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			system("cls");
		}
		else {
			break;
		}
	}

	while (true) {
		cout << "Entrer votre taille : ";
		cin >> taille_magicien;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			system("cls");
		}
		else {
			break;
		}
	}

	while (true) {
		cout << "Quel est votre mana : ";
		cin >> mana_magicien;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			system("cls");
		}
		else {
			break;
		}
	}

	cout << "Entrer votre prenom : ";
	cin >> prenom_magicien;

	Magicien magicien(age_magicien, taille_magicien, mana_magicien, prenom_magicien);
	magicien.Presentation();
	magicien.Sort();
}

void Programme_6(void) {
	//Exo 6 : Classe Epeiste qui hérite de la classe Guerrier avec du mana en plus et il peut montre sa magie
	system("cls");
	int age_epeiste, taille_epeiste, force_epeiste, longueur;
	string prenom_epeiste;
	while (true) {
		cout << "Entrer votre age : ";
		cin >> age_epeiste;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			system("cls");
		}
		else {
			break;
		}
	}

	while (true) {
		cout << "Entrer votre taille : ";
		cin >> taille_epeiste;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			system("cls");
		}
		else {
			break;
		}
	}

	while (true) {
		cout << "Quel est votre force : ";
		cin >> force_epeiste;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			system("cls");
		}
		else {
			break;
		}
	}

	while (true) {
		cout << "Quel est la longueur de votre epee : ";
		cin >> longueur;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			system("cls");
		}
		else {
			break;
		}
	}

	cout << "Entrer votre prenom : ";
	cin >> prenom_epeiste;

	Epeiste epeiste(age_epeiste, taille_epeiste, force_epeiste, longueur, prenom_epeiste);
	epeiste.Presentation();
	epeiste.Longueur();
	epeiste.Coup_Estoque();
}

void Programme_7(void) {
	//Exo 7 : Combat
	system("cls");
	Magicien magicien(50, 150, 20, "Magicien");
	Epeiste epeiste(50, 150, 10, 20, "Epeiste");
	epeiste.Presentation();
	magicien.Presentation();

	cout << endl;

	epeiste.Coup_Estoque2(&magicien);
	magicien.Sort2(&epeiste);
	cout << endl;
}

void Programme_8(void) {
	//Projet avec Yoven, Lorenzo et Florian
	int Choix_Pour_Les_Fonction;
	string Recommencer = "Y";
	Bibliotheque Bibliotheque_Livre(0);

	while (Recommencer == "Y") {
		system("cls");

		Accueil();
		Choix_Pour_Les_Fonction = Choix_Fonction();

		Bibliotheque_Livre.Utilisation_Fonction_Selon_Choix(Choix_Pour_Les_Fonction);

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
		case 7:
			Programme_7();
			break;

		default:
			Programme_8();
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

		if (recom == "Y") { system("cls"); continue; }
		else { system("cls"); break; }
	}
}