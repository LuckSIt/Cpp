#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <limits>

using namespace std;

int main() {
    map<string,int> store;
    map<string,int> cart;

    try {
        cout << "Enter number of products in the store: ";
        int n;
        if (!(cin >> n) || n < 0) throw invalid_argument("Invalid number of products");
        for (int i = 0; i < n; ++i) {
            string sku;
            int qty;
            cout << "SKU and quantity: ";
            if (!(cin >> sku >> qty) || qty < 0)
                throw invalid_argument("Invalid SKU or quantity");
            store[sku] = qty;
        }

        cout << "\nCommands:\n"
             << "  add <sku> <qty>    - add product to cart\n"
             << "  remove <sku> <qty> - remove product from cart\n"
             << "  show               - show cart contents\n"
             << "  exit               - quit program\n\n";

        string cmd;
        while (true) {
            cout << "> ";
            if (!(cin >> cmd)) break;

            if (cmd == "exit") break;
            else if (cmd == "show") {
                cout << "Cart:\n";
                for (auto &p : cart)
                    cout << "  " << p.first << " : " << p.second << "\n";
                continue;
            }

            string sku;
            int qty;
            if (!(cin >> sku >> qty)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cerr << "Error: expected SKU and quantity\n";
                continue;
            }

            try {
                if (store.find(sku) == store.end())
                    throw invalid_argument("SKU not found in store database");
                if (qty <= 0)
                    throw invalid_argument("Quantity must be positive");

                if (cmd == "add") {
                    int available = store[sku] - cart[sku];
                    if (qty > available)
                        throw runtime_error("Not enough product in stock");
                    cart[sku] += qty;
                    cout << "Added " << qty << " of " << sku << " to cart\n";
                }
                else if (cmd == "remove") {
                    if (cart[sku] < qty)
                        throw runtime_error("Not enough product in the cart to remove");
                    cart[sku] -= qty;
                    if (cart[sku] == 0) cart.erase(sku);
                    cout << "Removed " << qty << " of " << sku << " from cart\n";
                }
                else {
                    throw invalid_argument("Unknown command");
                }
            }
            catch (const invalid_argument &e) {
                cerr << "[Invalid input] " << e.what() << "\n";
            }
            catch (const runtime_error &e) {
                cerr << "[Error] " << e.what() << "\n";
            }
        }

        cout << "Program finished.\n";
    }
    catch (const exception &e) {
        cerr << "Critical error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
