#include <iostream>
using namespace std;

void afficherBornes(const float puiss[], const float dist[], int taille);
int indiceBorneLaPlusProche(const float dist[], int taille);
float calculerTempsRecharge(float capacite, float puissance);

int main() {

    float capacite;
    int indice;

    float puissance[5] = {50.0, 22.0, 11.0, 150.0, 7.4}; // en kW
    float distances[5] = {12.5, 35.0, 8.0, 60.0, 2.3};   // en km

    afficherBornes(puissance, distances, 5);

    int plusProche = indiceBorneLaPlusProche(distances, 5);
    cout << "La borne la plus proche est la borne : " << plusProche << "!\n";
    cout << "Veuillez indiquer l'indice de la station que vous souhaitez utiliser : ";
    cin >> indice;
    cout << "Veuillez indiquer la capacité que vous souhaitez recharger (en kWh) : ";
    cin >> capacite;
    float temps = calculerTempsRecharge(capacite, puissance[indice-1]);
    cout << "Temps de recharge estime : " << temps << " heures" << "\n";

    return 0;
}

void afficherBornes(const float puiss[], const float dist[], int taille)
{
    for(int i = 0; i < taille; i++)
        cout << "Borne " << i + 1 << " : " << puiss[i] << " kW, " << dist[i] << " km" <<"!\n";
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