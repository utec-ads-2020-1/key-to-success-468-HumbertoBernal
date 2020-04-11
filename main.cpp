#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stdio.h>
#include <string.h>

using namespace std;



struct comp
{
    template<typename T>
    bool operator()(const T& l, const T& r) const
    {
        if (l.second != r.second)
            return l.second > r.second;

        return l.first > r.first;
    }
};

int main() {


    bool cambio;
    int number, n;
    string encoded, notEncoded;
    vector<char> encod;
    map <char, int> deco, deco2;
    char pivote;
    map <char, char> key;

    cin >> number;
    getline(cin, notEncoded);
    for(int i =0; i < number + 1; i++){
        getline(cin, notEncoded);
        getline(cin, notEncoded);
        getline(cin, encoded);

        char notEncodedBuff[notEncoded.length()];
        strcpy(notEncodedBuff,notEncoded.c_str());
        char encodedBuff[encoded.length()];
        strcpy(encodedBuff, encoded.c_str());

        for (int j = 0; j < notEncoded.length(); ++j) {
            deco[notEncodedBuff[j]] += 1;
        }
        for (int k = 0; k < encoded.length(); ++k) {
            deco2[encodedBuff[k]] += 1;
        }

        for (auto& x: deco2) {
            encod.push_back(x.first);
        }

        for (int m = 0; m < encod.size(); ++m) {

            cout << encod[m] << " " << deco2[encoded[m]]  << endl;

        }

        for (int l = 0; l < encod.size() ; ++l) {
            cambio = false;
            for (int j = 0; j < encod.size() ; ++j) {
                if(deco2[encod[l]] < deco2[encod[l+1]] )
                {
                    pivote = encod[l];
                    encod[l] = encod[l+1];
                    encod[l+1] = pivote;
                    cambio = true;
                }
            }
            if(!cambio){break;}
        }

        // create an empty vector of pairs
        set<pair<char,int>, comp> set(deco.begin(), deco.end());

        // print the vector
        n = 0;
        for (auto const &pair: set) {
            key[encod[n]] = pair.first;
            cout << pair.first << " " <<  deco[pair.first] << endl;
            n += 1;
        }
        cout << endl ;
        for (int m = 0; m < encod.size(); ++m) {

            cout << encod[m] << " " << deco2[encoded[m]]  << endl;

        }

        for (int m = 0; m < encoded.length(); ++m) {

            cout << key[encodedBuff[m]] ;

        }
        cout << endl;

        encod.clear();
        deco.clear();
        deco2.clear();
    }
    return 0;
}
