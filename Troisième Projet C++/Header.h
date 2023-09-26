/*
Auteur : BELLO Noah
Date : 06/02/2023
Nom du fichier : Header.h
*/

#pragma region Directives
#include <iostream>
#include <vector>
#include <string>
#include <random>

using namespace std;
#pragma endregion

#pragma region Classes

class Produit {
public:
	Produit(float prix, float  promotion, float couts, int quantite, string date, string nom_produit, string code_barre, string date_expiration)
	{
		Prix = prix;
		Promotion = promotion;
		Couts = couts;
		Quantite = quantite;
		Date = date;
		Nom_Produit = nom_produit;
		Code_Barre = code_barre;
		Date_Expiration = date_expiration;
	}

	~Produit(void) {}

	string Acces_Nom(void) {
		return Nom_Produit;
	}

	string Acces_Code_Barre(void) {
		return Code_Barre;
	}

	int Acces_Quantite(void) {
		return Quantite;
	}

	float Acces_Prix(void) {
		return Prix;
	}


	void Affichage_Produit(void) {
		cout << "\033[1;34m" << "Nom du produit : " << "\033[0m" << Nom_Produit << endl << "\033[1;34m" << "Lieu de vente : " << "\033[0m" << endl
			<< "\033[1;34m" << "Code barre : " << "\033[0m" << Code_Barre << endl << "\033[1;34m" << "Prix : " << "\033[0m" << Prix << endl
			<< "\033[1;34m" << "Date : " << "\033[0m" << Date << endl << "\033[1;34m" << "Quantite : " << "\033[0m" << Quantite << endl << "\033[1;34m" << "Promotion : "
			<< "\033[0m" << Promotion << endl << "\033[1;34m" << "Couts : " << "\033[0m" << Couts << endl;
	}

protected:
	float Prix, Promotion, Couts;
	int Quantite;
	string Date, Nom_Produit, Code_Barre, Date_Expiration;
};

class Stockage {
public:

	Stockage(int initialisation_constructeur) {
		Initialisation_Constructeur = initialisation_constructeur;
	}

	~Stockage(void) {
		cout << endl << "\033[1;31m" << "Destruction de la variable de classe Stockage" << "\033[0m" << endl;
	}

	void Verification(float* prix, float* promotion, float* couts, int* quantite, string* date, string* nom_produit, string* code_barre, string* date_expiration) {

		while (true) {
			cout << endl << "Nom du produit : ";
			cin >> *nom_produit;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				system("cls");
			}
			else break;
		}

		while (true) {
			cout << endl << "Code barre : ";
			cin >> *code_barre;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				system("cls");
			}
			else break;
		}

		while (true) {
			cout << endl << "Prix : ";
			cin >> *prix;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				system("cls");
			}
			else break;
		}

		while (true) {
			cout << endl << "Date : ";
			cin >> *date;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				system("cls");
			}
			else break;
		}

		while (true) {
			cout << endl << "Quantite : ";
			cin >> *quantite;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				system("cls");
			}
			else break;
		}

		while (true) {
			cout << endl << "Promotion : ";
			cin >> *promotion;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				system("cls");
			}
			else break;
		}

		while (true) {
			cout << endl << "Couts : ";
			cin >> *couts;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				system("cls");
			}
			else break;
		}
	}

	void Menu_Recherche(void) {
		cout << endl;
		cout << "\t" << "\033[0;33m" << "**************************************************" << "\033[0m" << endl;
		cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t\t\t\t\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
		cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t\t" << "\033[1;36m" << "Methode de recherche" << "\033[0m" << "\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
		cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t\t   " << "\033[1;32m" << "1: Par Nom de Produit" << "\033[0m" << "\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
		cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t\t   " << "\033[1;31m" << "2: Par Code Barre" << "\033[0m" << "\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
		cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t\t   " << "\033[1;34m" << "3: Une recherche groupee" << "\033[0m" << "\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
		cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t\t\t\t\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
		cout << "\t" << "\033[0;33m" << "**************************************************" << "\033[0m" << endl;
	}

	void Recherche_Par_Nom(int* id) {
		string nom;
		cout << endl << "\033[1;32m" << "Vous avez choisi la recherche par nom" << "\033[0m" << endl;
		cout << "Saisissez le nom recherche : ";
		cin >> nom;
		for (int i = 0; i < Stockage_Produit.size(); i++) {
			if (Stockage_Produit[i].Acces_Nom() == nom) {
				*id = i;
			}
		}
	}

	void Recherche_Par_Code_Barre(int* id) {
		cout << endl << "\033[1;32m" << "Vous avez choisi la recherche par code barre" << "\033[0m" << endl;
		string code_barre;
		cout << "Saisissez le code barre recherche : ";
		cin >> code_barre;
		for (int i = 0; i < Stockage_Produit.size(); i++) {
			if (Stockage_Produit[i].Acces_Code_Barre() == code_barre) {
				*id = i;
			}
		}
	}

	void Recherche_Groupe(int* id) {
		cout << endl << "\033[1;32m" << "Vous avez choisi la recherche groupee" << "\033[0m" << endl;
		string nom, code_barre;
		cout << "Saisissez le titre recherche : ";
		cin >> nom;

		cout << "Saisissez le titre recherche : ";
		cin >> code_barre;

		for (int i = 0; i < Stockage_Produit.size(); i++) {
			if (Stockage_Produit[i].Acces_Nom() == nom || Stockage_Produit[i].Acces_Code_Barre() == code_barre) {
				*id = i;
			}
		}

	}

	void Recherche_Stockage(int* id) {
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
				if (choix < 1 || choix > 3) system("cls");
				else break;
			}
		}

		switch (choix)
		{
		case 1:
			Recherche_Par_Nom(id);
			break;
		case 2:
			Recherche_Par_Code_Barre(id);
			break;
		default:
			Recherche_Groupe(id);
			break;
		}
	}

	void Menu_Affichage(void) {
		cout << endl;
		cout << "\t" << "\033[0;33m" << "******************************************" << "\033[0m" << endl;
		cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t\t\t\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
		cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t" << "\033[1;36m" << "Methode d'affichage" << "\033[0m" << "\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
		cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t   " << "\033[1;32m" << "1: Complete" << "\033[0m" << "\t\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
		cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t   " << "\033[1;31m" << "2: Par Section" << "\033[0m" << "\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
		cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t   " << "\033[1;34m" << "3: D'un produit precis" << "\033[0m" << "\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
		cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t   " << "\033[1;35m" << "4: Dans les pertes" << "\033[0m" << "\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
		cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t\t\t\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
		cout << "\t" << "\033[0;33m" << "******************************************" << "\033[0m" << endl;
	}

	void Affichage_Complete(void) {
		system("cls");
		cout << endl << "\033[1;32m" << "Vous avez choisi l'affichage complete" << "\033[0m" << endl << endl;
		for (int i = 0; i < Stockage_Produit.size(); i++) { Stockage_Produit[i].Affichage_Produit(); cout << endl; }

	}

	void Affichage_Section(void) {
		system("cls");
		cout << endl << "\033[1;32m" << "Vous avez choisi l'affichage par section" << "\033[0m" << endl;
		int commencement, fin;
		while (true) {
			cout << endl << "Ou voulez-vous commencez ?: ";
			cin >> commencement;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				system("cls");
			}
			else {
				if (commencement > Stockage_Produit.size() || commencement < 0) system("cls");
				else break;
			}
		}

		while (true) {
			system("cls");
			cout << endl << "Ou voulez-vous  finir ?: ";
			cin >> fin;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				system("cls");
			}
			else {
				if (fin > Stockage_Produit.size() || fin < commencement) system("cls");
				else break;
			}
		}

		cout << endl;
		for (int i = commencement; i < fin; i++) { Stockage_Produit[i].Affichage_Produit(); cout << endl; }
	}

	void Affichage_D_Un_Produit(void) {
		system("cls");
		cout << endl << "\033[1;32m" << "Vous avez choisi l'affichage d'un Produit precis" << "\033[0m" << endl;
		int index;
		while (true) {
			cout << endl << "Ou se trouve le Produit que vous voulez voir ?: ";
			cin >> index;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				system("cls");
			}
			else {
				if (index > Stockage_Produit.size() || index < 0) system("cls");
				else break;
			}
		}

		cout << endl;
		Stockage_Produit[index].Affichage_Produit();
		cout << endl;
	}

	void Affichage_Dans_Les_Pertes(void) {
		system("cls");
		cout << endl << "\033[1;32m" << "Vous avez choisi l'affichage les Produit dans les pertes" << "\033[0m" << endl;
		for (int i = 0; i < Perte_Produit.size(); i++) { Perte_Produit[i].Affichage_Produit(); cout << endl; }
	}

	void Menu_Ajout(void) {
		cout << endl;
		cout << "\t" << "\033[0;33m" << "**************************************************" << "\033[0m" << endl;
		cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t\t\t\t\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
		cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t\t" << "\033[1;36m" << "Methode d'ajout" << "\033[0m" << "\t\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
		cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t   " << "\033[1;32m" << "1: Avant le premier produit" << "\033[0m" << "\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
		cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t   " << "\033[1;34m" << "2: Apres le dernier produit" << "\033[0m" << "\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
		cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t   " << "\033[1;35m" << "3: Random" << "\033[0m" << "\t\t\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
		cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t\t\t\t\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
		cout << "\t" << "\033[0;33m" << "**************************************************" << "\033[0m" << endl;
	}

	void Avant_Premier(void) {
		system("cls");
		int index = -1;
		string add;

		while (true) {
			cout << "Si vous voulez ajouter un Produit au debut de la stockage, taper " << "\033[1;34m" << "Y" << "\033[0m" << " sinon " << "\033[1;34m" << "N " << "\033[0m" << ": ";
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
						cout << "\033[1;31m" << "Avant d'ajouter un Produit dans le stockage, faites une recherche pour voir si il y est deja ou pas" << "\033[0m" << endl;

						Recherche_Stockage(&index);

						if (index == -1) {
							cout << endl << "\033[1;32m" << "Vous allez rajouter un Produit au debut du stockage" << "\033[0m" << endl;
							float prix, promotion, couts;
							int quantite;
							string date, nom_produit, code_barre, date_expiration;
							Verification(&prix, &promotion, &couts, &quantite, &date, &nom_produit, &code_barre, &date_expiration);

							Produit produit(prix, promotion, couts, quantite, date, nom_produit, code_barre, date_expiration);

							Stockage_Produit.insert(Stockage_Produit.begin(), produit);
						}

						else cout << endl << "\033[1;31m" << "Ce Produit est deja dans le stockage" << "\033[0m" << endl << endl;

						break;
					}
					else break;
			}
		}
	}

	void Apres_Dernier(void) {
		system("cls");

		int index = -1;
		string add;

		while (true) {
			cout << "Si vous voulez ajouter un produit a la fin du stockage, tapez " << "\033[1;34m" << "Y" << "\033[0m" << " sinon " << "\033[1;34m" << "N " << "\033[0m" << ": ";
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
						cout << "\033[1;31m" << "Avant d'ajouter un Produit dans le stockage, faites une recherche pour voir si il y est deja ou pas" << "\033[0m" << endl;

						Recherche_Stockage(&index);

						if (index == -1) {
							cout << endl << "\033[1;32m" << "Vous allez rajouter un produit a la fin du stockage" << "\033[0m" << endl;
							float prix, promotion, couts;
							int quantite;
							string date, nom_produit, code_barre, date_expiration;
							Verification(&prix, &promotion, &couts, &quantite, &date, &nom_produit, &code_barre, &date_expiration);

							Produit produit(prix, promotion, couts, quantite, date, nom_produit, code_barre, date_expiration);

							Stockage_Produit.push_back(produit);
						}

						else cout << endl << "\033[1;31m" << "Ce Produit est deja dans le stockage" << "\033[0m" << endl << endl;

						break;
					}
					else break;
			}
		}
	}

	void Random(void) {
		int nombre_pour_mettre_dans_le_stockage;
		while (true) {
			cout << endl << "Combien vous voulez ajouter ?: ";
			cin >> nombre_pour_mettre_dans_le_stockage;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				system("cls");
			}
			else break;
		}

		for (int i = 0; i < nombre_pour_mettre_dans_le_stockage; i++) {
			float prix = (rand() % 1000 + 100) / (float)1, promotion = (rand() % 1000 + 100) / (float)1, couts = (rand() % 1000 + 100) / (float)1;
			Produit produit(prix, promotion, couts, rand() % 1000 + 100, to_string(rand() % 30 + 1) + " / " +
				to_string(rand() % 11 + 1) + " / " + to_string(2023), "Nom_Produit_" + to_string(i + 1),
				to_string(rand() % 9 + 1) + "-" + to_string(rand() % 1000 + 1) + "-" + to_string(rand() % 1000 + 1) + "-" + to_string(rand() % 9 + 1),
				to_string(rand() % 30 + 1) + " / " +
				to_string(rand() % 11 + 1) + " / " + to_string(2023));
			Stockage_Produit.push_back(produit);
		}
	}

	void Menu_Supprimer(void) {
		cout << endl;
		cout << "\t" << "\033[0;33m" << "**************************************************" << "\033[0m" << endl;
		cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t\t\t\t\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
		cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t     " << "\033[1;36m" << "Methode de suppression" << "\033[0m" << "\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
		cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t\t " << "\033[1;32m" << "1: Tout le stockage" << "\033[0m" << "\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
		cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t\t " << "\033[1;34m" << "2: Un element" << "\033[0m" << "\t\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
		cout << "\t" << "\033[0;33m" << "*" << "\033[0m" << "\t\t\t\t\t\t " << "\033[0;33m" << "*" << "\033[0m" << endl;
		cout << "\t" << "\033[0;33m" << "**************************************************" << "\033[0m" << endl;
	}

	void Tout(void) {
		system("cls");
		string supp;
		while (true) {
			cout << "Si vous voulez supprimer tout les Produits de le stockage, taper " << "\033[1;34m" << "Y" << "\033[0m" << " sinon " << "\033[1;34m" << "N " << "\033[0m" << ": ";
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
						Stockage_Produit.clear();
						cout << "\033[1;32m" << "Vous avez supprime tout les Produits du stockage" << "\033[0m" << endl;
						break;
					}
					else break;
			}
		}
	}

	void Un_Element(void) {
		system("cls");
		int index = -1;
		string supp;

		cout << "\033[1;31m" << "Avant de supprimer un produit dans le stockage dites nous quel produit vous interesse en faisant une recherche" << "\033[0m" << endl;

		Recherche_Stockage(&index);

		if (index != -1) {
			while (true) {
				cout << "Si vous voulez supprimer un Produit du stockage, taper " << "\033[1;34m" << "Y" << "\033[0m" << " sinon " << "\033[1;34m" << "N " << "\033[0m" << ": ";
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
							cout << "\033[1;32m" << "Vous avez supprime un Produit" << "\033[0m" << endl << endl;
							Stockage_Produit.erase(Stockage_Produit.begin() + index);
							break;
						}
						else break;
				}
			}
		}
		else cout << endl << "\033[1;31m" << "Vous ne pouvez pas supprimer ce Produit car il n'existe pas" << "\033[0m" << endl << endl;
	}

	void Affichage_Stockage(void) {
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
			Affichage_Section();
			break;
		case 3:
			Affichage_D_Un_Produit();
			break;
		default:
			Affichage_Dans_Les_Pertes();
			break;
		}
	}

	void Ajout_Stockage(void) {
		system("cls");
		int choix;

		cout << endl << "\033[1;31m" << "Vous allez rajouter un nouveau Produit dans la stockage" << "\033[0m" << endl;
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
			Random();
			break;
		}
	}

	void Supprimer_Stockage(void) {
		system("cls");
		int choix;

		cout << endl << "\033[1;31m" << "Vous allez supprimer un ou plusieurs produit(s) de la stockage" << "\033[0m" << endl;

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
				if (choix < 1 || choix > 2) system("cls");
				else break;
			}
		}

		switch (choix)
		{
		case 1:
			Tout();
			break;
		default:
			Un_Element();
			break;
		}
	}

	void Retourner_Un_Produit_Le_Stockage(void) {
		system("cls");
		string choix;

		cout << "\033[1;31m" << "Avant de retourner un Produit dite nous quel Produit vous interesse en fassant une recherche" << "\033[0m" << endl;

		while (true) {
			system("cls");
			cout << endl << "Vous etes venu pour retourner un produit (pour envoyer dans le stockage, tapez " << "\033[1;34m" << "S" << "\033[0m"
				<< "; pour envoyer dans les pertes, tapez " << "\033[1;34m" << "P " << "\033[0m" << "): ";
			cin >> choix;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				system("cls");
			}
			else {
				if (choix != "S" && choix != "P") system("cls");
				else break;
			}
		}

		if (choix == "S") {
			cout << endl << "\033[1;32m" << "Vous allez retourner un produit dans le stockage" << "\033[0m" << endl;
			float prix, promotion, couts;
			int quantite;
			string date, nom_produit, code_barre, date_expiration;
			Verification(&prix, &promotion, &couts, &quantite, &date, &nom_produit, &code_barre, &date_expiration);

			Produit produit(prix, promotion, couts, quantite, date, nom_produit, code_barre, date_expiration);

			Stockage_Produit.push_back(produit);
		}

		else {
			cout << endl << "\033[1;32m" << "Vous allez retourner un produit dans les pertes" << "\033[0m" << endl;
			float prix, promotion, couts;
			int quantite;
			string date, nom_produit, code_barre, date_expiration;
			Verification(&prix, &promotion, &couts, &quantite, &date, &nom_produit, &code_barre, &date_expiration);

			Produit produit(prix, promotion, couts, quantite, date, nom_produit, code_barre, date_expiration);

			Perte_Produit.push_back(produit);
		}
	}

	void Calcul_Chiffre_Affaire(void) {
		float ca_total(0);
		for (int i = 0; i < Stockage_Produit.size(); i++) {
			ca_total += Stockage_Produit[i].Acces_Quantite() * Stockage_Produit[i].Acces_Prix();
		}
		cout << "Le chiffre d'affaire des produits est " << ca_total << endl;
	}


	void Utilisation_Fonction_Selon_Choix(int ch) {
		switch (ch)
		{
		case 1:
			Ajout_Stockage();
			break;
		case 2:
			Supprimer_Stockage();
			break;
		case 3:
			Retourner_Un_Produit_Le_Stockage();
			break;
		case 4:
			Affichage_Stockage();
			break;
		default:
			Calcul_Chiffre_Affaire();
			break;
		}
	}

protected:
	vector<Produit> Stockage_Produit;
	vector<Produit> Perte_Produit;
	int Initialisation_Constructeur;
};

#pragma endregion

#pragma region Prototypes

void Programme_Debut_Cours(void);

#pragma endregion
