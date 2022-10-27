#include <iostream>
#include <list>
#include <queue>
using namespace std;

template<class I>
void container_print(const I& start, const I& end){
    for (I it = start; it != end; ++it)
        cout << *it << " ";
    cout << endl;
}

int main() {
	list<string>List{ "Volodymyr", "Olexiy", "Nikita", "Maksym", "Andriy", "Kristian" };
    cout << "before sorting ->\n";
    container_print(List.begin(), List.end());
	List.sort();
    cout << "\nafter sorting ->\n";
    container_print(List.begin(), List.end());
    queue<string, list<string>> Queue(List);
    int crystals = 5;
    system("pause");
    while (!Queue.empty() && crystals > 0) {
        system("cls");
        unsigned int give_n;
        cout << "crystals: " << crystals << "\ninput number of crystals for " << Queue.front() << "-> ";
        cin >> give_n;
        while (give_n > crystals) {
            system("cls");
            cout << "error! invalid number of crystals.\n";
            cout << "crystals: " << crystals << "\ninput number of crystals for " << Queue.front() << "-> ";
            cin >> give_n;
        }
        crystals -= give_n;
        Queue.pop();
    }
    system("cls");
    cout << "crystals: " << crystals;
    cout << (crystals == 0 ? "\nno crystals more!" : "\nthe end of the list!");
}