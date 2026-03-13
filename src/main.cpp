#include <iostream>
using namespace std;

void afficherBornes(const float puiss[], const float dist[], int taille);
int indiceBorneLaPlusProche(const float dist[], int taille);
float calculerTempsRecharge(float capacite, float puissance);
void modifierBorne(float dist[], int taille);

int main() {
    const int taille = 5;
    float puiss[taille] = {50, 100, 22, 150, 75};
    float dist[taille] = {12, 5, 20, 8, 15};

    int choix;

    do
    {
        cout << "1 Afficher toutes les bornes" << "!\n";
        cout << "2 Afficher la borne la plus proche" <<"!\n";
        cout << "3 Estimer un temps de recharge" <<"\n";
        cout << "4 Modifier une borne" <<"!\n";
        cout << "5 Quitter" <<"!\n";

        cin >> choix;

        if(choix == 1)
        {
            afficherBornes(puiss, dist, taille);
        }

        if(choix == 2)
        {
            int indice;
            indice = indiceBorneLaPlusProche(dist, taille);
            cout << indice <<"!\n";
        }

        if(choix == 3)
        {
            int indice;
            float capacite;
            float temps;

            cin >> indice;
            cin >> capacite;

            temps = calculerTempsRecharge(capacite, puiss[indice-1]);

            cout << temps <<"!\n";
        }

        if(choix == 4)
        {
            modifierBorne(dist, taille);
        }

    } while(choix != 5);

    return 0;
}

void afficherBornes(const float puiss[], const float dist[], int taille)
{
    for(int i = 0; i < taille; i++)
        cout << "Borne " << i + 1 << " : " << puiss[i] << " kW, " << dist[i] << " km!\n";
}

int indiceBorneLaPlusProche(const float dist[], int taille)
{
    int indice = 0;

    for(int i = 1; i < taille; i++)
        if(dist[i] < dist[indice])
            indice = i;

    return indice + 1;
}

float calculerTempsRecharge(float capacite, float puissance)
{
    float t;
    t = capacite / puissance;
    return t;
}

void modifierBorne(float dist[], int taille)
{
    int choix;
    int indiceBorne;
    float nouvelleDist;

    cout << "Voulez-vous modifier la distance d'une borne ? (0/1) : ";
    cin >> choix;

    if(choix == 1)
    {
        cout << "Numero de la borne : ";
        cin >> indiceBorne;

        cout << "Nouvelle distance : ";
        cin >> nouvelleDist;

        if(indiceBorne >= 1 && indiceBorne <= taille)
            dist[indiceBorne - 1] = nouvelleDist;
    }
}