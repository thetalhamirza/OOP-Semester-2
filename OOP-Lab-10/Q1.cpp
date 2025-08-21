#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

string encrypt(string text) {
    vector<int> asciis;
    for (char c : text) {
        asciis.push_back(int(c));
    }
    string cipher = "";
    for (int i=0; i < asciis.size(); i++) {
        asciis[i] += i + 1;
        cipher = cipher + char(asciis[i]);
    }
    return cipher;
}

string decrypt(string text) {
    vector<int> asciis;
    for (char c : text) {
        asciis.push_back(int(c));
    }
    string decipher = "";
    for (int i=0; i < asciis.size(); i++) {
        asciis[i] -= i + 1;
        decipher = decipher + char(asciis[i]);
    }
    return decipher;
}

void store(string cipher) {
    string fname = "pwd.txt";
    ofstream out(fname);
    if (out.is_open()) {
        out << cipher << endl;
    }   else {cerr << "File can't be opened." << endl;}
}

string read() {
    string fname = "pwd.txt";
    ifstream inA(fname);
    string line;
    if (inA.is_open()) {
        getline(inA, line);
        // inA >> line;
    }
    inA.close();
    return line;
}


int main() {
    string in;
    cout << "Enter String = ";

    // cin >> in;
    getline(cin, in);

    store(encrypt(in));

    // cout << encrypt(in) << endl;
    // cout << decrypt(in) << endl;
    
    cout << decrypt(read()) << endl;
}