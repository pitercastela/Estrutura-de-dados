#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int M, N, fez_gol, bom_jogador = 0;
    vector<int> jogadores;

    cin >> M >> N;

    for (int i = 0; i < N; i++)
    {
        jogadores.push_back(0);
    }

    for (int i = 0 ; i < M; i++)
    {
        for (int j = 0 ; j < N; j++)
        {
            cin >> fez_gol;
            if (fez_gol != 0)
            {
                jogadores[j] = jogadores[j] + 1;

            }
        }

    }
    for(int i : jogadores){
        if (i == M){
            bom_jogador++;
        }
    }

    cout << bom_jogador << endl;

}