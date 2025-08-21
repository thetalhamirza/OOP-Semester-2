#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

// split CSV line
vector<string> split(const string &line, char delimiter = ',') {
    vector<string> tokens;
    string token;
    istringstream stream(line);
    while (getline(stream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

// Step 1: Write dummy data into files
void writeDummyData() {
    ofstream users("users.csv"), products("products.csv"), orders("orders.csv");

    // user_id,first_name,last_name,address,email
    users << "u1,Linus,Sebastian,Ohio,linus@lttstore.com\n";
    users << "u2,Alex,Alex,Ohio,alex@lttstore.com\n";

    // product_id,product_name,description,price
    products << "p1,Linux T-Shirt,Black tee with Linux logo,25\n";
    products << "p2,Kernel Handbook,Guide to Linux Kernel,40\n";

    // order_id,user,product_ordered,total_paid
    orders << "o1,u1,p1,25\n";
    orders << "o2,u1,p2,40\n";

    users.close();
    products.close();
    orders.close();
}

// Step 2: Query products ordered by user with first_name "Linus"
void queryProductsByUser(const string& first_name) {
    ifstream users("users.csv"), orders("orders.csv"), products("products.csv");

    string line, linus_id;
    // Find user_id for Linus
    while (getline(users, line)) {
        vector<string> row = split(line);
        if (row[1] == first_name) {
            linus_id = row[0];
            break;
        }
    }

    if (linus_id.empty()) {
        cout << "User " << first_name << " not found.\n";
        return;
    }

    // Get product IDs from orders
    vector<string> product_ids;
    while (getline(orders, line)) {
        vector<string> row = split(line);
        if (row[1] == linus_id) {
            product_ids.push_back(row[2]);
        }
    }

    // Get product names from products
    cout << "Products ordered by " << first_name << ":\n";
    while (getline(products, line)) {
        vector<string> row = split(line);
        for (const string& pid : product_ids) {
            if (row[0] == pid) {
                cout << "- " << row[1] << endl;
            }
        }
    }

    users.close();
    orders.close();
    products.close();
}

int main() {
    writeDummyData();
    queryProductsByUser("Linus");
    return 0;
}
