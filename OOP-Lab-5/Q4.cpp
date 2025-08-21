#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

class Mixer {
public:
    void MixJuice(string fruit) {
        cout << "\nMixing " << fruit << " juice..." << endl;
        for (int i = 0; i < 3; i++) {
            cout << "Processing..." << endl;
            sleep(1);
        }
        cout << "\nMixing complete!" << endl;
    }
};

class Crusher {
public:
    void CrushJuice(string fruit) {
        cout << "\nCrushing " << fruit << " juice..." << endl;
        sleep(4);
        cout << "\nCrushing complete!" << endl;
    }
};

class JuiceProcessor {
private:
    Mixer mix;
    Crusher crush;

public:
    void PrepareJuice(string fruit) {
        mix.MixJuice(fruit);
        crush.CrushJuice(fruit);
        cout << fruit << " juice is ready to serve \n" << endl;
    }
};

int main() {
    string fruitType;
    cout << "\nEnter a fruit: ";
    cin >> fruitType;
    JuiceProcessor machine;
    machine.PrepareJuice(fruitType);
    return 0;
}
