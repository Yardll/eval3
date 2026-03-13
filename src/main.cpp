#include <iostream>
using namespace std;

void afficherBornes(const float puiss[], const float dist[], int taille);
int indiceBorneLaPlusProche(const float dist[], int taille);


int main() {
    float puissance[5] = {50.0, 22.0, 11.0, 150.0, 7.4}; //en kW
    float distances[5] = {12.5, 35.0, 8.0, 60.0, 2.3}; //en Km

    for(int i = 0; i < 5; i++) {
        cout << "Borne " << i+1 << " : " << puissance[i] << "Kw, à " << distances[i] << " km \n";
    }

    return 0;
    
}
void afficherBornes(const float puiss[], const float dist[], int taille)
{
    for(int i = 0; i < taille; i++)
        cout << "Borne " << i + 1 << " : " << puiss[i] << " kW " << dist[i] << " km" << endl;
}
int indiceBorneLaPlusProche(const float dist[], int taille)
{
    int indice = 0;
    for(int i = 1; i < taille; i++)
        if(dist[i] < dist[indice])
            indice = i;
    return indice;
}
    
