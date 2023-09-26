/*
Auteur : BELLO Noah
Date : 03/02/2023
Nom du fichier : Header.h
*/

#pragma region Directives
#include <iostream>
#include <vector>
#include <string>
#include <random>

using namespace std;
#pragma endregion

#pragma region Classes_Du_Cours
struct Cercle {

public:
	//Constructeur
	Cercle(int px, int py, int diam) {
		posX = px;
		posY = py;
		diametre = diam;
	}

	//Fonction destructeur (qui détruit une variable de la structure)
	~Cercle() {
		cout << "Destructeur" << endl;
	}

	//Fonction propre à la structure
	void afficher() {
		//Code pour afficher le Cercle 
		cout << "Affichage du cercle de diametre " << diametre << endl;
	}

private:
	//Variable qui est caractéristique à la structure
	int posX, posY, diametre;
};

class Perso {
public: //Les membres public de la class
	Perso(int a, int t, string p) {
		age = a;
		taille = t;
		prenom = p;
	}

	~Perso() {
		cout << "Destruction de la variable de classe Perso" << endl;
	}

	void Presentation(void) { //Méthode pour se présenter
		cout << "Je m'appelle " << prenom << ", j'ai " << age << " ans et je mesure " << taille << " cm." << endl;
		cout << "De plus je possede " << pv << " point de vie " << endl;
	}

	void Prend_Degat(int degat) {
		pv -= degat;
		if (pv < degat || pv <= 0) cout << prenom << " est mort" << endl;
		else cout << prenom << ", il vous reste " << pv << " de point de vie." << endl;
	}

protected://Donnée protégée avec accès
	int age, taille, pv = 50;
	string prenom;
};

class Triangle {
public:
	Triangle(int h) {
		hauteur = h;
	}

	~Triangle() {
		cout << "Destruction de la variable de classe Triangle" << endl;
	}

	void triangle_iso() {
		cout << "Selectionnez la hauteur de votre sapin :\t";
		cin >> hauteur;
		for (int i = 1; i <= hauteur; i++) {
			for (int repet = hauteur - i; repet > 0; repet--) {
				cout << " ";
			}
			for (int etoile = 1; etoile <= (i - 1); etoile++) {
				cout << " *";
			}
			cout << endl;
		}
	}

	void afficher() {
		while (true)
		{
			string retry("");
			cout << "Voulez vous faire un sapin ? (Y ou N) ?\t";
			cin >> retry;
			if (retry == "Y" || retry == "N" || retry == "y" || retry == "n") {
				if (retry == "Y" || retry == "y") {
					system("cls");
					triangle_iso();
				}
				else {
					cout << "Ciao fdp!" << endl;
					break;
				}
			}
			else {
				system("cls");
				cout << "Entrez sois Y sois N !" << endl;
			}
		}
	}

private:
	int hauteur;
};

class Guerrier : public Perso { //La classe Guerrier hérite de la classe Perso
public: // Les membres public de la class
	Guerrier(int a, int t, int f, string p) : Perso(a, t, p) {
		force = f;
	}

	~Guerrier() {
		cout << "Destruction de la variable de classe Guerrier" << endl;
	}

	void Taper(void) { // Méthode pour se battre
		cout << "Vous tapez avec une force de " << force << endl;
	}
	void Taper2(Perso* cible) { // Méthode pour se battre
		cout << "Vous tapez avec une force de " << force << endl;
		cible->Prend_Degat(force);
	}


protected:
	int force;
};

class Magicien : public Perso {
public: // Les membres public de la class
	Magicien(int a, int t, int m, string p) : Perso(a, t, p) {
		mana = m;
	}

	~Magicien() {
		cout << "Destruction de la variable de classe Magicien" << endl;
	}

	void Sort(void) { // Méthode pour se battre
		cout << "Vous avez " << mana << " de mana." << endl;
	}

	void Sort2(Perso* cible) { // Méthode pour se battre
		cout << prenom << " utilise " << mana << " de mana " << endl;
		cible->Prend_Degat(mana);
	}

private: // Les membres prive de la class
	int mana;
};

class Epeiste : public Guerrier {
public:
	Epeiste(int a, int t, int f, int e, string p) : Guerrier(a, t, f, p) {
		epee = e;
	}

	~Epeiste() {
		cout << "Destruction de la variable de classe Epeiste" << endl;
	}

	void Longueur(void) {
		cout << "Votre epee est de longueur " << epee << endl;
	}

	void Coup_Estoque(void) {
		cout << "Vous donnez un coup d'estoque avec votre epee avec une force de " << force << endl;
	}

	void Coup_Estoque2(Perso* cible) { // Méthode pour se battre
		cout << prenom << " utilise " << force << " de force" << endl;
		cible->Prend_Degat(force);
	}

private:
	int epee;
};
#pragma endregion

#pragma region Classes_Du_Projet_Avec_Yoven_Lorenzo_Florian
class Livre {
public:
	// DÉCLARATIONS DE MÉTHODES //

	//Méthode Constructeur de Livre et Destructeur de Livre
	Livre(string titre, string auteur, string isbn, int disponibilite, int nombre_pages)
	{
		/*************************************************************
		*	Le nom de la méthode est Livre, elle permet construire une classe Livre.
		*	Elle reçoit 5 paramètres : 3 de type string et 2 de type int.
		**************************************************************/

		Titre = titre;
		Auteur = auteur;
		ISBN = isbn;
		Disponibilite = disponibilite;
		Nombre_Pages = nombre_pages;
	}

	~Livre(void) {
		/*************************************************************
		*	Le nom de la méthode est ~Livre, elle permet détruire une variable de classe Livre.
		*	Elle ne reçoit pas de valeurs.
		**************************************************************/
	}

	//Méthode pour avoir accès au attibut
	string Acces_Titre(void) {
		/*************************************************************
		*	Le nom de la méthode est Acces_Titre, elle permet l'accès à la variable Titre.
		*	Elle ne reçoit aucune valeur et renvoie une valeur de type string.
		*	Instructions utilisées : 1 return
		**************************************************************/

		return Titre;
	}

	string Acces_Auteur(void) {
		/*************************************************************
		*	Le nom de la méthode est Acces_Auteur, elle permet l'accès à la variable Auteur.
		*	Elle ne reçoit aucune valeur et renvoie une valeur de type string.
		*	Instructions utilisées : 1 return
		**************************************************************/

		return Auteur;
	}

	string Acces_ISBN(void) {
		/*************************************************************
		*	Le nom de la méthode est Acces_ISBN, elle permet l'accès à la variable ISBN.
		*	Elle ne reçoit aucune valeur et renvoie une valeur de type string.
		*	Instructions utilisées : 1 return
		**************************************************************/

		return ISBN;
	}

	int Acces_Disponibilite(void) {
		/*************************************************************
		*	Le nom de la méthode est Acces_Disponibilite, elle permet l'accès à la variable Disponibilite.
		*	Elle ne reçoit aucune valeur et renvoie une valeur de type int.
		*	Instructions utilisées : 1 return
		**************************************************************/

		return Disponibilite;
	}

	//Méthode qui permet de modifier un attribut et d'afficher un livre
	void Modification_Disponibilite(void) {
		/*************************************************************
		*	Le nom de la méthode est Modification_Disponibilite, elle permet de modifier la variable Disponibilite.
		*	Elle ne reçoit aucune valeur et ne renvoie pas de valeurs.
		*	Instructions utilisées : 1 if
		**************************************************************/

		if (Disponibilite == 1) Disponibilite = 0;
	}

	void Disponibilite_Modifier(void) {
		/*************************************************************
		*	Le nom de la méthode est Disponibilite_Modifier, elle permet de modifier la variable Disponibilite.
		*	Elle ne reçoit aucune valeur et ne renvoie pas de valeurs.
		*	Instructions utilisées : 1 if
		**************************************************************/

		if (Disponibilite == 0) Disponibilite = 1;
	}

	void Affichage_Livre(void) {
		/*************************************************************
		*	Le nom de la méthode est Affichage_Livre, elle permet d'afficher un livre.
		*	Elle ne reçoit aucune valeur et ne renvoie pas de valeurs.
		*	Instructions utilisées : 1 if, 1 else, 2 cout, 10 endl
		**************************************************************/

		if (Disponibilite == 1)
			cout << "\033[1;34m" << "Titre : " << "\033[0m" << Titre << endl << "\033[1;34m" << "Auteur : " << "\033[0m" << Auteur << endl << "\033[1;34m" << "ISBN : " << "\033[0m" << ISBN << endl << "\033[1;32m"
			<< "OUI" << "\033[0m" << endl << "\033[1;34m" << "Nombre de pages : " << "\033[0m" << Nombre_Pages << endl;
		else
			cout << "\033[1;34m" << "Titre : " << "\033[0m" << Titre << endl << "\033[1;34m" << "Auteur : " << "\033[0m" << Auteur << endl << "\033[1;34m" << "ISBN : " << "\033[0m" << ISBN << endl << "\033[1;31m"
			<< "NON" << "\033[0m" << endl << "\033[1;34m" << "Nombre de pages : " << "\033[0m" << Nombre_Pages << endl;
	}

protected:
	// DÉCLARATIONS DES MEMBRES OU VARIABLES MEMBRES //
	string Titre, Auteur, ISBN;
	int Disponibilite;
	int Nombre_Pages;
};

class Bibliotheque {
public:
	// DÉCLARATIONS DE MÉTHODES //

	//Méthode Constructeur de Bibliotheque et Destructeur de Bibliotheque
	Bibliotheque(int initialisation_constructeur) {
		/*************************************************************
		*	Le nom de la méthode est Bibliotheque, elle permet construire une classe Bibliotheque et d'initialiser le vecteur Bibliotheque_De_Livre.
		*	Elle reçoit un paramètre : 1 de type int.
		*	Instructions utilisées : 1 for et 1 push_back
		**************************************************************/

		for (int i = 0; i < 100; i++) {
			Livre livre("Titre_" + to_string(i + 1), "Auteur_" + to_string(i + 1),
				to_string(rand() % 9 + 1) + "-" + to_string(rand() % 1000 + 1) + "-" + to_string(rand() % 1000 + 1) + "-" + to_string(rand() % 9 + 1), 1, rand() % 1000 + 100);

			Bibliotheque_De_Livre.push_back(livre);
		}
		Initialisation_Constructeur = initialisation_constructeur;
	}

	~Bibliotheque(void) {
		/*************************************************************
		*	Le nom de la méthode est ~Bibliotheque, elle permet détruire une variable de classe Bibliotheque et affiche si ça a fonctionné.
		*	Elle ne reçoit pas de valeurs.
		*	Instructions utilisées : 1 cout et 2 endl
		**************************************************************/

		cout << endl << "\033[1;31m" << "Destruction de la variable de classe Bibliotheque" << "\033[0m" << endl;
	}

	//Méthode pour éviter de répéter du code
	void Verification(string* titr, string* aut, string* isbn, int* disp, int* nb_pg) {

		/*************************************************************
		*	Le nom de la méthode est Verification, elle permet de vérifier la saisie des l'élément.
		*	Elle reçoit 5 paramètres tous en pointeur : 3 de type string et 2 de type int. Elle ne renvoie pas de valeurs
		*	Instructions utilisées : 5 while, 5 cout, 5 cin, 5 endl, 5 fail, 5 clear, 5 ignore, 7 system, 7 if, 7 else, 5 break
		**************************************************************/

		while (true) {
			cout << endl << "Titre du livre : ";
			cin >> *titr;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				system("cls");
			}
			else break;
		}

		while (true) {
			cout << endl << "Auteur du livre : ";
			cin >> *aut;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				system("cls");
			}
			else break;
		}

		while (true) {
			cout << endl << "ISBN du livre : ";
			cin >> *isbn;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				system("cls");
			}
			else break;
		}

		while (true) {
			cout << endl << "Disponibilite du livre : ";
			cin >> *disp;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				system("cls");
			}
			else {
				if (*disp < 0 || *disp > 1) system("cls");
				else break;
			}
		}

		while (true) {
			cout << endl << "Nombre de page : ";
			cin >> *nb_pg;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				system("cls");
			}
			else {
				if (*nb_pg < 0 || *nb_pg > 1000) system("cls");
				else break;
			}
		}
	}

	//Méthode de recherche
	void Menu_Recherche(void) {
		/*************************************************************
		*	Le nom de la méthode est Menu_Recherche, elle permet d'afficher un menu pour les recherches.
		*	Elle ne reçoit pas de valeurs et ne renvoie pas de valeurs
		*	Instructions utilisées : 10 cout, 10 endl
		**************************************************************/

		cout << endl;
		cout << "\t" << "\033[0;33m" << "**************************************************" << "\033[0m" << endl;
		cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t\t\t\t\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
		cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t\t" << "\033[1;36m" << "Methode de recherche" << "\033[0m" << "\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
		cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t\t   " << "\033[1;32m" << "1: Par Titre" << "\033[0m" << "\t\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
		cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t\t   " << "\033[1;34m" << "2: Par Auteur" << "\033[0m" << "\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
		cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t\t   " << "\033[1;31m" << "3: Par ISBN" << "\033[0m" << "\t\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
		cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t     " << "\033[1;35m" << "4: Une recherche groupee" << "\033[0m" << "\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
		cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t\t\t\t\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
		cout << "\t" << "\033[0;33m" << "**************************************************" << "\033[0m" << endl;
	}

	void Recherche_Par_Titre(int* id) {
		/*************************************************************
		*	Le nom de la méthode est Recherche_Par_Titre, elle permet de rechercher un livre grâce à son titre.
		*	Elle reçoit 1 paramètre en pointeur de type int. Elle ne renvoie pas de valeurs
		*	Instructions utilisées : 1 if, 2 cout, 1 cin, 2 endl, 1 for, 1 size
		*	Fonctions utilisées : Acces_Titre
		**************************************************************/

		string titre;
		cout << endl << "\033[1;32m" << "Vous avez choisi la recherche par titre" << "\033[0m" << endl;
		cout << "Saisissez le titre recherche : ";
		cin >> titre;
		for (int i = 0; i < Bibliotheque_De_Livre.size(); i++) {
			if (Bibliotheque_De_Livre[i].Acces_Titre() == titre) {
				*id = i;
			}
		}
	}

	void Recherche_Par_Auteur(int* id) {
		/*************************************************************
		*	Le nom de la méthode est Recherche_Par_Auteur, elle permet de rechercher un livre grâce à son auteur.
		*	Elle reçoit 1 paramètre en pointeur de type int. Elle ne renvoie pas de valeurs
		*	Instructions utilisées : 1 if, 2 cout, 1 cin, 2 endl, 1 for, 1 size
		*	Fonctions utilisées : Acces_Auteur
		**************************************************************/

		cout << endl << "\033[1;32m" << "Vous avez choisi la recherche par auteur" << "\033[0m" << endl;
		string auteur;
		cout << "Saisissez le auteur recherche : ";
		cin >> auteur;
		for (int i = 0; i < Bibliotheque_De_Livre.size(); i++) {
			if (Bibliotheque_De_Livre[i].Acces_Auteur() == auteur) {
				*id = i;
			}
		}
	}

	void Recherche_Par_ISBN(int* id) {
		/*************************************************************
		*	Le nom de la méthode est Recherche_Par_ISBN, elle permet de rechercher un livre grâce à son ISBN.
		*	Elle reçoit 1 paramètre en pointeur de type int. Elle ne renvoie pas de valeurs
		*	Instructions utilisées : 1 if, 2 cout, 1 cin, 2 endl, 1 for, 1 size
		*	Fonctions utilisées : Acces_ISBN
		**************************************************************/

		cout << endl << "\033[1;32m" << "Vous avez choisi la recherche par ISBN" << "\033[0m" << endl;
		string isbn;
		cout << "Saisissez le ISBN recherche : ";
		cin >> isbn;
		for (int i = 0; i < Bibliotheque_De_Livre.size(); i++) {
			if (Bibliotheque_De_Livre[i].Acces_ISBN() == isbn) {
				*id = i;
			}
		}
	}

	void Recherche_Groupe(int* id) {
		/*************************************************************
		*	Le nom de la méthode est Recherche_Groupe, elle permet de rechercher un livre grâce soit avec son titre, soit avec son auteur,
		*		soit avec son ISBN soit avec tout en même temps.
		*	Elle reçoit 1 paramètre en pointeur de type int. Elle ne renvoie pas de valeurs
		*	Instructions utilisées : 1 if, 4 cout, 3 cin, 2 endl, 1 for, 1 size
		*	Fonctions utilisées : Acces_Titre, Acces_Auteur, Acces_ISBN
		**************************************************************/

		cout << endl << "\033[1;32m" << "Vous avez choisi la recherche groupee" << "\033[0m" << endl;
		string titre, auteur, isbn;
		cout << "Saisissez le titre recherche : ";
		cin >> titre;

		cout << "Saisissez le titre recherche : ";
		cin >> auteur;

		cout << "Saisissez le titre recherche : ";
		cin >> isbn;

		for (int i = 0; i < Bibliotheque_De_Livre.size(); i++) {
			if (Bibliotheque_De_Livre[i].Acces_Titre() == titre || Bibliotheque_De_Livre[i].Acces_Auteur() == auteur || Bibliotheque_De_Livre[i].Acces_ISBN() == isbn) {
				*id = i;
			}
		}

	}

	void Recherche_Livre(int* id) {
		/*************************************************************
		*	Le nom de la méthode est Recherche_Livre, elle permet de choisir une méthode de recherche avec une vérification de saisie.
		*	Elle reçoit 1 paramètre en pointeur de type int. Elle ne renvoie pas de valeurs
		*	Instructions utilisées : 1 switch, 3 case, 1 default, 5 break, 1 while, 2 if, 2 else, 2 system, 1 cout, 1 cin, 1 endl, 1 fail, 1 clear, 1 ignore
		*	Fonctions utilisées : Menu_Recherche, Recherche_Par_Titre, Recherche_Par_Auteur, Recherche_Par_ISBN, Recherche_Groupe
		**************************************************************/

		int choix;

		while (true) {
			Menu_Recherche();
			cout << endl << "Methode : ";
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

		switch (choix)
		{
		case 1:
			Recherche_Par_Titre(id);
			break;
		case 2:
			Recherche_Par_Auteur(id);
			break;
		case 3:
			Recherche_Par_ISBN(id);
			break;
		default:
			Recherche_Groupe(id);
			break;
		}
	}

	//Méthode d'affichage
	void Menu_Affichage(void) {
		/*************************************************************
		*	Le nom de la méthode est Menu_Affichage, elle permet d'afficher un menu pour l'affichage.
		*	Elle ne reçoit pas de valeurs et ne renvoie pas de valeurs
		*	Instructions utilisées : 10 cout, 10 endl
		**************************************************************/

		cout << endl;
		cout << "\t" << "\033[0;33m" << "******************************************" << "\033[0m" << endl;
		cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t\t\t\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
		cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t" << "\033[1;36m" << "Methode d'affichage" << "\033[0m" << "\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
		cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t   " << "\033[1;32m" << "1: Complete" << "\033[0m" << "\t\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
		cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t   " << "\033[1;34m" << "2: Semi-complete" << "\033[0m" << "\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
		cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t   " << "\033[1;31m" << "3: Par Section" << "\033[0m" << "\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
		cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t   " << "\033[1;35m" << "4: D'un livre precis" << "\033[0m" << "\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
		cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t\t\t\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
		cout << "\t" << "\033[0;33m" << "******************************************" << "\033[0m" << endl;
	}

	void Affichage_Complete(void) {
		/*************************************************************
		*	Le nom de la méthode est Affichage_Complete, elle permet d'afficher toute la bibliotheque.
		*	Elle ne reçoit pas de valeurs et ne renvoie pas de valeurs
		*	Instructions utilisées : 1 for, 2 cout, 4 endl, 1 system, 1 size
		*	Fonctions utilisées : Affichage_Livre
		**************************************************************/

		system("cls");
		cout << endl << "\033[1;32m" << "Vous avez choisi l'affichage complete" << "\033[0m" << endl << endl;
		for (int i = 0; i < Bibliotheque_De_Livre.size(); i++) { Bibliotheque_De_Livre[i].Affichage_Livre(); cout << endl; }

	}

	void Affichage_Semi_Complete(void) {
		/*************************************************************
		*	Le nom de la méthode est Affichage_Semi_Complete, elle permet d'afficher une partie de la bibliotheque selon la position demander.
		*	Elle ne reçoit pas de valeurs et ne renvoie pas de valeurs
		*	Instructions utilisées : 1 while, 1 for, 4 cout, 1 cin, 5 endl, 3 system, 1 size, 1 fail, 1 clear, 1 ignore, 2 if, 2 else, 1 break
		*	Fonctions utilisées : Affichage_Livre
		**************************************************************/

		system("cls");
		int commencement;
		cout << endl << "\033[1;32m" << "Vous avez choisi l'affichage semi-complete" << "\033[0m" << endl;
		while (true) {
			cout << endl << "Ou voulez-vous commencez : ";
			cin >> commencement;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				system("cls");
			}
			else {
				if (commencement > Bibliotheque_De_Livre.size() || commencement < 0) system("cls");
				else break;
			}
		}

		cout << endl;
		for (int i = commencement; i < Bibliotheque_De_Livre.size(); i++) { Bibliotheque_De_Livre[i].Affichage_Livre(); cout << endl; }
	}

	void Affichage_Section(void) {
		/*************************************************************
		*	Le nom de la méthode est Affichage_Section, elle permet d'afficher une partie de la bibliotheque selon la position de départ et de "\033[0m" demander.
		*	Elle ne reçoit pas de valeurs et ne renvoie pas de valeurs
		*	Instructions utilisées : 2 while, 1 for, 5 cout, 2 cin, 6 endl, 6 system, 2 size, 2 fail, 2 clear, 2 ignore, 4 if, 4 else, 2 break
		*	Fonctions utilisées : Affichage_Livre
		**************************************************************/

		system("cls");
		cout << endl << "\033[1;32m" << "Vous avez choisi l'affichage par section" << "\033[0m" << endl;
		int commencement, fin;
		while (true) {
			cout << endl << "Ou voulez-vous commencez : ";
			cin >> commencement;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				system("cls");
			}
			else {
				if (commencement > Bibliotheque_De_Livre.size() || commencement < 0) system("cls");
				else break;
			}
		}

		while (true) {
			system("cls");
			cout << endl << "Ou voulez-vous finir : ";
			cin >> fin;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				system("cls");
			}
			else {
				if (fin > Bibliotheque_De_Livre.size() || fin < commencement) system("cls");
				else break;
			}
		}

		cout << endl;
		for (int i = commencement; i < fin; i++) { Bibliotheque_De_Livre[i].Affichage_Livre(); cout << endl; }
	}

	void Affichage_D_Un_Livre(void) {
		/*************************************************************
		*	Le nom de la méthode est Affichage_D_Un_Livre, elle permet d'afficher un livre de la bibliotheque.
		*	Elle ne reçoit pas de valeurs et ne renvoie pas de valeurs
		*	Instructions utilisées : 1 while, 4 cout, 1 cin, 5 endl, 2 system, 1 size, 1 fail, 1 clear, 1 ignore, 2 if, 2 else, 1 break
		*	Fonctions utilisées : Affichage_Livre
		**************************************************************/

		system("cls");
		cout << endl << "\033[1;32m" << "Vous avez choisi l'affichage d'un livre precis" << "\033[0m" << endl;
		int index;
		while (true) {
			cout << endl << "Ou se trouve le livre que vous voulez voir : ";
			cin >> index;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				system("cls");
			}
			else {
				if (index > Bibliotheque_De_Livre.size() || index < 0) system("cls");
				else break;
			}
		}

		cout << endl;
		Bibliotheque_De_Livre[index].Affichage_Livre();
		cout << endl;
	}

	//Méthode d'ajout
	void Menu_Ajout(void) {
		/*************************************************************
		*	Le nom de la méthode est Menu_Affichage, elle permet d'afficher un menu pour l'ajout.
		*	Elle ne reçoit pas de valeurs et ne renvoie pas de valeurs
		*	Instructions utilisées : 9 cout, 10 endl
		**************************************************************/

		cout << endl;
		cout << "\t" << "\033[0;33m" << "**************************************************" << "\033[0m" << endl;
		cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t\t\t\t\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
		cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t\t" << "\033[1;36m" << "Methode d'ajout" << "\033[0m" << "\t\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
		cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t   " << "\033[1;32m" << "1: Avant le premier livre" << "\033[0m" << "\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
		cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t   " << "\033[1;34m" << "2: Apres le dernier livre" << "\033[0m" << "\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
		cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t" << "\033[1;31m" << "3: Une section de livre dans la " << "\033[0m" << "\t " << "\033[0;33m" << "*" << "\033[0m" << endl
			<< "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t\t" << "\033[1;31m" << "bibliotheque" << "\033[0m" << "\t\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
		cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t\t\t\t\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
		cout << "\t" << "\033[0;33m" << "**************************************************" << "\033[0m" << endl;
	}

	void Avant_Premier(void) {
		/*************************************************************
		*	Le nom de la méthode est Avant_Premier, elle permet d'ajouter un livre au début de la bibliotheque avec vérification de saisie.
		*	Elle ne reçoit pas de valeurs et ne renvoie pas de valeurs
		*	Instructions utilisées : 1 while, 3 if, 3 else, 4 cout, 1 cin, 6 endl, 1 insert, 1 begin, 3 system, 1 fail, 1 clear, 1 ignore, 2 break
		*	Fonctions utilisées : Recherche_Livre, Verification
		**************************************************************/

		system("cls");
		int index = -1;
		string add;

		while (true) {
			cout << "Si vous voulez ajouter un livre au debut de la bibliotheque, taper " << "\033[1;34m" << "Y" << "\033[0m" << " sinon " << "\033[1;34m" << "N " << "\033[0m" << ": ";
			cin >> add;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				system("cls");
			}
			else {
				if (add != "Y" && add != "N") system("cls");
				else
					if (add == "Y") {
						cout << "\033[1;31m" << "Avant d'ajouter un livre dans la bibliotheque, fesait une recherche pour voir si il y est deja ou pas" << "\033[0m" << endl;

						Recherche_Livre(&index);

						if (index == -1) {
							cout << endl << "\033[1;32m" << "Vous allez rajouter un livre au debut de la bibliotheque" << "\033[0m" << endl;
							string titre, auteur, ISBN;
							int disponible, nombrePages;
							Verification(&titre, &auteur, &ISBN, &disponible, &nombrePages);

							Livre livre(titre, auteur, ISBN, disponible, nombrePages);

							Bibliotheque_De_Livre.insert(Bibliotheque_De_Livre.begin(), livre);
						}

						else cout << endl << "\033[1;31m" << "Ce livre est deja dans la bibliotheque" << "\033[0m" << endl << endl;

						break;
					}
					else break;
			}
		}
	}

	void Apres_Dernier(void) {
		/*************************************************************
		*	Le nom de la méthode est Apres_Dernier, elle permet d'ajouter un livre à la "\033[0m" de la bibliotheque avec vérification de saisie.
		*	Elle ne reçoit pas de valeurs et ne renvoie pas de valeurs
		*	Instructions utilisées : 1 while, 4 if, 4 else, 4 cout, 1 cin, 6 endl, 1 push_back, 3 system, 1 fail, 1 clear, 1 ignore, 2 break
		*	Fonctions utilisées : Recherche_Livre, Verification
		**************************************************************/

		system("cls");

		int index = -1;
		string add;

		while (true) {
			cout << "Si vous voulez ajouter un livre a la fin de la bibliotheque, taper " << "\033[1;34m" << "Y" << "\033[0m" << " sinon " << "\033[1;34m" << "N " << "\033[0m" << ": ";
			cin >> add;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				system("cls");
			}
			else {
				if (add != "Y" && add != "N") system("cls");
				else
					if (add == "Y") {
						cout << "\033[1;31m" << "Avant d'ajouter un livre dans la bibliotheque, fesait une recherche pour voir si il y est deja ou pas" << "\033[0m" << endl;

						Recherche_Livre(&index);

						if (index == -1) {
							cout << endl << "\033[1;32m" << "Vous allez rajouter un livre a la fin de la bibliotheque" << "\033[0m" << endl;
							string titre, auteur, ISBN;
							int disponible, nombrePages;
							Verification(&titre, &auteur, &ISBN, &disponible, &nombrePages);

							Livre livre(titre, auteur, ISBN, disponible, nombrePages);

							Bibliotheque_De_Livre.push_back(livre);
						}

						else cout << endl << "\033[1;31m" << "Ce livre est deja dans la bibliotheque" << "\033[0m" << endl << endl;

						break;
					}
					else break;
			}
		}
	}

	void Section(void) {
		/*************************************************************
		*	Le nom de la méthode est Section, elle permet d'ajouter plusieurs livres dans la bibliotheque avec vérification de saisie.
		*	Elle ne reçoit pas de valeurs et ne renvoie pas de valeurs
		*	Instructions utilisées : 3 while, 1 for, 6 if, 6 else, 4 cout, 3 cin, 4 endl, 1 push_back, 1 insert, 2 begin, 1 end, 6 system, 3 fail, 3 clear, 3 ignore, 4 break
		*	Fonctions utilisées : Verification
		**************************************************************/

		string add;

		while (true) {
			cout << "Si vous voulez ajouter une section de livre dans la bibliotheque, taper " << "\033[1;34m" << "Y" << "\033[0m" << " sinon " << "\033[1;34m" << "N " << "\033[0m" << ": ";
			cin >> add;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				system("cls");
			}
			else {
				if (add != "Y" && add != "N") system("cls");
				else
					if (add == "Y") {
						system("cls");
						cout << endl << "\033[1;32m" << "Vous allez rajouter une section de livre dans la bibliotheque" << "\033[0m" << endl;
						string titre, auteur, ISBN;
						int disponible, nombrePages, commencement, nombre_livre;
						vector<Livre> livres;

						while (true) {
							cout << endl << "Ou voulez-vous placer les livres dans la bibliotheque : ";
							cin >> commencement;
							if (cin.fail()) {
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								system("cls");
							}
							else {
								if (commencement > Bibliotheque_De_Livre.size() || commencement < 0) system("cls");
								else break;
							}
						}

						while (true) {
							cout << endl << "Combien de livres voulez-vous mettre : ";
							cin >> nombre_livre;
							if (cin.fail()) {
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								system("cls");
							}
							else {
								break;
							}
						}

						for (int i = 0; i < nombre_livre; i++) {
							Verification(&titre, &auteur, &ISBN, &disponible, &nombrePages);

							Livre livre(titre, auteur, ISBN, disponible, nombrePages);

							livres.push_back(livre);
						}

						Bibliotheque_De_Livre.insert(Bibliotheque_De_Livre.begin() + commencement, livres.begin(), livres.end());

						break;
					}
					else break;
			}
		}
	}

	//Méthode de suppression
	void Menu_Supprimer(void) {
		/*************************************************************
		*	Le nom de la méthode est Menu_Supprimer, elle permet d'afficher un menu pour la suppresion.
		*	Elle ne reçoit pas de valeurs et ne renvoie pas de valeurs
		*	Instructions utilisées : 9 cout, 9 endl
		**************************************************************/

		cout << endl;
		cout << "\t" << "\033[0;33m" << "**************************************************" << "\033[0m" << endl;
		cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t\t\t\t\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
		cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t     " << "\033[1;36m" << "Methode de suppression" << "\033[0m" << "\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
		cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t   " << "\033[1;32m" << "1: Toute la bibliotheque" << "\033[0m" << "\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
		cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t\t " << "\033[1;34m" << "2: Un element" << "\033[0m" << "\t\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
		cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t\t " << "\033[1;31m" << "3: Une section" << "\033[0m" << "\t\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
		cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t\t\t\t\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
		cout << "\t" << "\033[0;33m" << "**************************************************" << "\033[0m" << endl;
	}

	void Tout(void) {
		/*************************************************************
		*	Le nom de la méthode est Tout, elle permet de supprimer toute la bibliotheque avec vérification de saisie.
		*	Elle ne reçoit pas de valeurs et ne renvoie pas de valeurs
		*	Instructions utilisées : 3 system, 1 while, 2 cout, 1 cin, 1 endl, 1 fail, 1 clear, 1 ignore, 3 if, 3 else, 2 break
		**************************************************************/

		system("cls");
		string supp;
		while (true) {
			cout << "Si vous voulez supprimer tout les livres de la bibliotheque, taper " << "\033[1;34m" << "Y" << "\033[0m" << " sinon " << "\033[1;34m" << "N " << "\033[0m" << ": ";
			cin >> supp;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				system("cls");
			}
			else {
				if (supp != "Y" && supp != "N") system("cls");
				else
					if (supp == "Y") {
						Bibliotheque_De_Livre.clear();
						cout << "\033[1;32m" << "Vous avez supprimer tout les livres de la bibliotheque" << "\033[0m" << endl;
						break;
					}
					else break;
			}
		}
	}

	void Un_Element(void) {
		/*************************************************************
		*	Le nom de la méthode est Un_Element, elle permet de supprimer un livre de la bibliotheque avec vérification de saisie.
		*	Elle ne reçoit pas de valeurs et ne renvoie pas de valeurs
		*	Instructions utilisées : 3 system, 1 while, 4 cout, 1 cin, 6 endl, 1 fail, 1 clear, 1 ignore, 4 if, 4 else, 2 break, 1 erase, 1 begin
		*	Fonction utilisée : Recherche_Livre
		**************************************************************/

		system("cls");
		int index = -1;
		string supp;

		cout << "\033[1;31m" << "Avant de supprimer un livre dans la bibliotheque dite nous quel livre vous interesse en fassant une recherche" << "\033[0m" << endl;

		Recherche_Livre(&index);

		if (index != -1) {
			while (true) {
				cout << "Si vous voulez supprimer un livre de la bibliotheque, taper " << "\033[1;34m" << "Y" << "\033[0m" << " sinon " << "\033[1;34m" << "N " << "\033[0m" << ": ";
				cin >> supp;
				if (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					system("cls");
				}
				else {
					if (supp != "Y" && supp != "N") system("cls");
					else
						if (supp == "Y") {
							cout << "\033[1;32m" << "Vous avez supprimer un livre" << "\033[0m" << endl << endl;
							Bibliotheque_De_Livre.erase(Bibliotheque_De_Livre.begin() + index);
							break;
						}
						else break;
				}
			}
		}
		else cout << endl << "\033[1;31m" << "Vous ne pouvez pas supprimer ce livre car il n'existe pas" << "\033[0m" << endl << endl;
	}

	void Une_Section(void) {
		/*************************************************************
		*	Le nom de la méthode est Une_Section, elle permet de supprimer une section de la bibliotheque avec vérification de saisie.
		*	Elle ne reçoit pas de valeurs et ne renvoie pas de valeurs
		*	Instructions utilisées : 7 system, 3 while, 5 cout, 3 cin, 6 endl, 3 fail, 3 clear, 3 ignore, 7 if, 7 else, 4 break, 1 erase, 2 begin
		**************************************************************/

		cout << "\033[1;31m" << "Avant de supprimer une portion de la bibliotheque dite nous quel livre vous interesse en fassant une recherche" << "\033[0m" << endl;

		system("cls");
		string supp;
		int commencement, fini;

		while (true) {
			cout << "Si vous voulez supprimer une section de la bibliotheque, taper " << "\033[1;34m" << "Y" << "\033[0m" << " sinon " << "\033[1;34m" << "N " << "\033[0m" << ": ";
			cin >> supp;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				system("cls");
			}
			else {
				if (supp != "Y" && supp != "N") system("cls");
				else
					if (supp == "Y") {
						while (true) {
							cout << endl << "Ou voulez-vous commencez : ";
							cin >> commencement;
							if (cin.fail()) {
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								system("cls");
							}
							else {
								if (commencement > Bibliotheque_De_Livre.size() || commencement < 0) system("cls");
								else break;
							}
						}

						while (true) {
							cout << endl << "Ou voulez-vous finir : ";
							cin >> fini;
							if (cin.fail()) {
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								system("cls");
							}
							else {
								if (fini > Bibliotheque_De_Livre.size() || fini < commencement) system("cls");
								else break;
							}
						}

						cout << endl << "\033[1;32m" << "Vous avez supprimer une portion de la bibliotheque" << "\033[0m" << endl << endl;
						Bibliotheque_De_Livre.erase(Bibliotheque_De_Livre.begin() + commencement, Bibliotheque_De_Livre.begin() + fini);
						break;
					}
					else break;
			}
		}
	}

	//Méthode Principal
	void Affichage_Bibliotheque(void) {
		/*************************************************************
		*	Le nom de la méthode est Affichage_Bibliotheque, elle permet de choisir une méthode de d'affichage avec une vérification de saisie.
		*	Elle ne reçoit pas de valeurs et ne renvoie pas de valeurs
		*	Instructions utilisées : 1 switch, 3 case, 1 default, 5 break, 1 while, 2 if, 2 else, 3 system, 1 cout, 1 cin, 1 endl, 1 fail, 1 clear, 1 ignore
		*	Fonctions utilisées : Menu_Affichage, Affichage_Complete, Affichage_Semi_Complete, Affichage_Section, Affichage_D_Un_Livre
		**************************************************************/

		int choix;
		while (true) {
			system("cls");
			Menu_Affichage();
			cout << endl << "Methode : ";
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

		switch (choix)
		{
		case 1:
			Affichage_Complete();
			break;
		case 2:
			Affichage_Semi_Complete();
			break;
		case 3:
			Affichage_Section();
			break;
		default:
			Affichage_D_Un_Livre();
			break;
		}
	}

	void Ajout_Dans_Bibliotheque(void) {
		/*************************************************************
		*	Le nom de la méthode est Ajout_Dans_Bibliotheque, elle permet de choisir une méthode de d'ajout avec une vérification de saisie.
		*	Elle ne reçoit pas de valeurs et ne renvoie pas de valeurs
		*	Instructions utilisées : 1 switch, 2 case, 1 default, 4 break, 1 while, 2 if, 2 else, 4 system, 2 cout, 1 cin, 3 endl, 1 fail, 1 clear, 1 ignore
		*	Fonctions utilisées : Menu_Ajout, Avant_Premier, Apres_Dernier, Section
		**************************************************************/

		system("cls");
		int choix;

		cout << endl << "\033[1;31m" << "Vous allez rajouter un nouveau livre dans la bibliotheque" << "\033[0m" << endl;
		while (true) {
			system("cls");
			Menu_Ajout();
			cout << endl << "Methode : ";
			cin >> choix;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				system("cls");
			}
			else {
				if (choix < 1 || choix > 3) system("cls");
				else break;
			}
		}

		switch (choix)
		{
		case 1:
			Avant_Premier();
			break;
		case 2:
			Apres_Dernier();
			break;
		default:
			Section();
			break;
		}
	}

	void Supprimer_Dans_La_Bibliotheque(void) {
		/*************************************************************
		*	Le nom de la méthode est Supprimer_Dans_La_Bibliotheque, elle permet de choisir une méthode de de suppression avec une vérification de saisie.
		*	Elle ne reçoit pas de valeurs et ne renvoie pas de valeurs
		*	Instructions utilisées : 1 switch, 2 case, 1 default, 4 break, 1 while, 2 if, 2 else, 4 system, 2 cout, 1 cin, 3 endl, 1 fail, 1 clear, 1 ignore
		*	Fonctions utilisées : Menu_Supprimer, Tout, Un_Element, Une_Section
		**************************************************************/

		system("cls");
		int choix;

		cout << endl << "\033[1;31m" << "Vous allez supprimer un ou plusieurs livre(s) de la bibliotheque" << "\033[0m" << endl;

		while (true) {
			system("cls");
			Menu_Supprimer();
			cout << endl << "Methode : ";
			cin >> choix;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				system("cls");
			}
			else {
				if (choix < 1 || choix > 3) system("cls");
				else break;
			}
		}

		switch (choix)
		{
		case 1:
			Tout();
			break;
		case 2:
			Un_Element();
			break;
		default:
			Une_Section();
			break;
		}
	}

	void Emprunter_Retourner_Un_Livre_A_La_Bibliotheque(void) {
		/*************************************************************
		*	Le nom de la méthode est Emprunter_Retourner_Un_Livre_A_La_Bibliotheque, elle permet de choisir si on veut emprunter ou rendre avec une vérification de saisie.
		*	Elle ne reçoit pas de valeurs et ne renvoie pas de valeurs
		*	Instructions utilisées : 4 break, 1 while, 6 if, 6 else, 4 system, 7 cout, 1 cin, 17 endl, 1 fail, 1 clear, 1 ignore
		*	Fonctions utilisées : Recherche_Livre, Modification_Disponibilite, Acces_Titre, Disponibilite_Modifier, Acces_Disponibilite
		**************************************************************/

		system("cls");
		string choix;
		int index = -1;

		cout << "\033[1;31m" << "Avant d'emprunter ou de rendre un livre dite nous quel livre vous interesse en fassant une recherche" << "\033[0m" << endl;

		Recherche_Livre(&index);

		if (index != -1) {
			while (true) {
				system("cls");
				cout << endl << "Vous etes venu pour emprunte un livre ou pour rendre un livre (pour emprunter, tapez " << "\033[1;34m" << "E" << "\033[0m" << "; pour rendre, tapez "
					<< "\033[1;34m" << "R " << "\033[0m" << "): ";
				cin >> choix;
				if (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					system("cls");
				}
				else {
					if (choix != "E" && choix != "R") system("cls");
					else break;
				}
			}

			if (choix == "E") {
				if (Bibliotheque_De_Livre[index].Acces_Disponibilite() != 0) {
					Bibliotheque_De_Livre[index].Modification_Disponibilite();
					cout << endl << "\033[1;32m" << "Vous avez emprunte le livre qui a pour titre : " << Bibliotheque_De_Livre[index].Acces_Titre() << "\033[0m" << endl << endl;
				}
				else cout << endl << "\033[1;31m" << "Impossible d'emprunte car il n'est pas dans la bibliotheque" << "\033[0m" << endl << endl;
			}

			else {
				if (Bibliotheque_De_Livre[index].Acces_Disponibilite() != 1) {
					Bibliotheque_De_Livre[index].Disponibilite_Modifier();
					cout << endl << "\033[1;32m" << "Vous avez rendu le livre qui a pour titre : " << Bibliotheque_De_Livre[index].Acces_Titre() << "\033[0m" << endl << endl;
				}
				else cout << endl << "\033[1;31m" << "Impossible de rendre car il est deja dans la bibliotheque" << "\033[0m" << endl << endl;
			}
		}
		else cout << endl << "\033[1;31m" << "Vous ne pouvez pas emprunter ou rendre ce livre car il n'est pas disponible" << "\033[0m" << endl << endl;
	}

	void Utilisation_Fonction_Selon_Choix(int ch) {
		/*************************************************************
		*	Le nom de la méthode est Utilisation_Fonction_Selon_Choix, elle permet d'utiliser une fonction selon le choix de l'utilisateur.
		*	Elle reçoit 1 paramètre en pointeur de type int. Elle ne renvoie pas de valeurs
		*	Instructions utilisées : 1 switch, 3 case, 1 default, 4 break, 3 if, 3 else, 3 cout, 6 endl
		*	Fonctions utilisées : Ajout_Dans_Bibliotheque, Supprimer_Dans_La_Bibliotheque, Emprunter_Retourner_Un_Livre_A_La_Bibliotheque, Affichage_Bibliotheque
		**************************************************************/

		switch (ch)
		{
		case 1:
			Ajout_Dans_Bibliotheque();
			break;
		case 2:
			if (Bibliotheque_De_Livre.size() != 0) Supprimer_Dans_La_Bibliotheque();
			else cout << endl << "\033[1;31m" << "Vous ne pouvez pas supprimer car la bibliotheque est vide" << "\033[0m" << endl;
			break;
		case 3:
			if (Bibliotheque_De_Livre.size() != 0) Emprunter_Retourner_Un_Livre_A_La_Bibliotheque();
			else cout << endl << "\033[1;31m" << "Vous ne pouvez pas emprunter ou rendre car la bibliotheque est vide" << "\033[0m" << endl;
			break;
		default:
			if (Bibliotheque_De_Livre.size() != 0) Affichage_Bibliotheque();
			else cout << endl << "\033[1;31m" << "Vous ne pouvez pas afficher car la bibliotheque est vide" << "\033[0m" << endl;
			break;
		}
	}

private:
	// DÉCLARATIONS DES MEMBRES OU VARIABLES MEMBRES //
	vector<Livre> Bibliotheque_De_Livre;
	int Initialisation_Constructeur;
};
#pragma endregion

#pragma region Prototypes
void Accueil(void);
void Au_Revoir(void);
int Choix_Fonction(void);
string Verification_Recommencer_Ou_Pas(void);
void Programme_Debut_Cours(void);
#pragma endregion
