#include <iostream>
#include <vector>
#include <map>


using namespace std;

int main() {
    bool cambio;
    int number;
    string encoded, notEncoded;
    vector<char> vec, vec1;
    map <char, int> deco, deco2;
    char pivote;
    map <char, char> key;

    cin >> number;
    getline(cin, notEncoded);
    for(int i =0; i < number + 1; i++){
        getline(cin, notEncoded);
        getline(cin, notEncoded);
        getline(cin, encoded);

        for (char k : notEncoded) {deco2[k] += 1 ;}

        for (char k : encoded) {deco[k] += 1 ;}

        for (auto const& pair: deco2) {vec.push_back(pair.first);}
        for (auto const& pair: deco) {vec1.push_back(pair.first);}

        for (int l = 0; l < vec.size() ; ++l) {
            cambio = false;
            for (int j = 0; j < vec.size()-l-1 ; ++j) {
                if(deco2[vec[j]] < deco2[vec[j+1]] )
                {
                    pivote = vec[j];
                    vec[j] = vec[j+1];
                    vec[j+1] = pivote;
                    cambio = true;
                }
            }
            if(!cambio){break;}
        }
        for (int l = 0; l < vec1.size() ; ++l) {
            cambio = false;
            for (int j = 0; j < vec1.size()-l-1 ; ++j) {
                if(deco[vec1[j]] < deco[vec1[j+1]] )
                {
                    pivote = vec1[j];
                    vec1[j] = vec1[j+1];
                    vec1[j+1] = pivote;
                    cambio = true;
                }
            }
            if(!cambio){break;}
        }

        for (int m = 0; m < vec.size(); ++m) {key[vec1[m]] = vec[m];}

        if(i != 0){cout << endl << endl;}
        for (char k : encoded) {cout << key[k];}


        vec.clear();
        vec1.clear();
        deco.clear();
        deco2.clear();
    }
    return 0;
}
