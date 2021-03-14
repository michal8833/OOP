#include <iostream>
#include "Warehouse.h"

using namespace std;

int main()
{
    Warehouse warehouse;

    warehouse.addLiquidContainer(22, 3);
    warehouse.addLiquidContainer(25.3);
    warehouse.addLiquidContainer(24, 2);
    cout<<"Magazyn \"warehouse\" po dodaniu kontenerow o objetosciach: 22(dodany trzy razy), 25.3 i 24(dodany dwa razy) :"<<endl;
    cout << warehouse << endl;
    cout << "Sumaryczna objetosc magazynu: " << warehouse.getTotalVolume() << endl;
    cout << "Liczba kontenerow: " << warehouse.getNumberOfLiquidContainers() << endl << endl;

    warehouse.deleteLiquidContainer(2);
    cout<<"Magazyn \"warehouse\" po usunieciu dwoch ostatnich kontenerow:"<<endl;
    cout << warehouse << endl;
    cout << "Liczba kontenerow: " << warehouse.getNumberOfLiquidContainers() << endl << endl;


    try {
        warehouse.pourIn(24.8);
        cout<<"Magazyn \"warehouse\" po dolaniu 24.8:"<<endl;
        cout << warehouse << endl;
        cout << "Sumaryczna zajeta objetosc magazynu: " << warehouse.getTotalOccupiedVolume() << endl << endl;
        warehouse.pourIn(92.1);
    }
    catch(Overflow& o) {
        printf("Ilosc plynu, ktora sie nie zmiescila: %lf\n", o.getOverflow());
        cout<<"Magazyn \"warehouse\" po dolaniu ilosci plynu, ktora spowodowala wygenerowanie wyjatku:"<<endl;
        cout << warehouse << endl;
    }

    cout << "Pobrano " << warehouse.pourOut(30.1) << " plynu." << endl;
    cout<<"Magazyn \"warehouse\" po probie pobrania 30.1 plynu:"<<endl;
    cout << warehouse << endl;
    cout << "Pobrano " << warehouse.pourOut(70) << " plynu." << endl;
    cout<<"Magazyn \"warehouse\" po probie pobrania 70 plynu:"<<endl;
    cout << warehouse << endl;

    try {
        warehouse.setLiquidName("woda");
        cout << "Zmieniono nazwe plynu na \"" << warehouse.getLiquidName() << "\"." << endl;
        warehouse.pourIn(15);
        cout<<"Dolano 15 i podjeto probe zmiany nazwy plynu."<<endl;
        warehouse.setLiquidName("azot");
    }
    catch(const char* s) {
        cout<<s<<endl;
        cout << "Nazwa plynu po nieudanej probie zmiany: " << warehouse.getLiquidName() << endl << endl;
    }

    cout << "Sumaryczna zajeta objetosc magazynu: " << warehouse.getTotalOccupiedVolume() << endl;
    cout << "Sumaryczna objetosc magazynu: " << warehouse.getTotalVolume() << endl;

    cout<<"Czy magazyn zawiera przynajmniej 10.2 plynu? ";
    if(warehouse.occupiedAtLeast(10.2))
        cout<<"Tak."<<endl;
    else
        cout<<"Nie."<<endl;
    cout<<"Czy magazyn zawiera przynajmniej 15.3 plynu? ";
    if(warehouse.occupiedAtLeast(15.3))
        cout<<"Tak."<<endl;
    else
        cout<<"Nie."<<endl;
    cout<<"Czy magazyn moze jeszcze przyjac 54 plynu? ";
    if(warehouse.occupiedAtMost(54))
        cout<<"Tak."<<endl;
    else
        cout<<"Nie."<<endl;
    cout<<"Czy magazyn moze jeszcze przyjac 100.8 plynu? ";
    if(warehouse.occupiedAtMost(100.8))
        cout<<"Tak."<<endl;
    else
        cout<<"Nie."<<endl;

    return 0;
}
