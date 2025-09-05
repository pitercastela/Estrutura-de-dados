// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int l, r, m;
int vetor[15] = {0,0,1,1,1,3,5,9,15,25,26,27,50,51,52};
int lista[8] = {-1,2,9,25,35,50,60,26};


int busca_binaria(int vetortemp[], int x, int n){
    l = 0;
    r = n - 1;
    
    while (true){
        cout << "l = " << l << endl;
        cout << "r = " << r << endl;
        m = (r + l)/2;
            if(x < vetortemp[m]){
            r = m - 1;
            } else if(x > vetortemp[m]){
                l = m + 1;
            } else if(x == vetortemp[m]){
                return m;
            } if (l >= r + 1 ){
                return -1;
            }
        
    }
    
}

int main() {
    for (int i = 0 ; i < sizeof(lista)/4; i++ ){
        cout << busca_binaria(vetor, lista[i], sizeof(vetor)/4) << endl;
    }

    return 0;
}

//recursivo

// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int l, r, m, n;
int vetor[15] = {0,0,1,1,1,3,5,9,15,25,26,27,50,51,52};
int lista[8] = {-1,2,9,25,35,50,60,26};


int busca_binaria(int vetortemp[], int x, int r, int l){
    
        cout << "l = " << l << endl;
        cout << "r = " << r << endl;
        m = (r + l)/2;
            if(x < vetortemp[m]){
            r = m - 1;
            } else if(x > vetortemp[m]){
                l = m + 1;
            } else if(x == vetortemp[m]){
                return m;
            } if (l >= r + 1 ){
                return -1;
            }else {
                return busca_binaria(vetortemp,x, r, l);
            }
            
        
    
    
}

int main() {
    n = sizeof(vetor)/4;
    l = 0;
    r = n - 1;
    
    for (int i = 0 ; i < sizeof(lista)/4; i++ ){
        cout << busca_binaria(vetor, lista[i], r, l) << endl;
    }
    

    return 0;
}