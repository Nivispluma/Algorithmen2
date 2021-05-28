// Algorithmen2.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//


#include "Header.h"

const int a = 50000;
long zahlenArray[a];

//------------------------------
//------------------------------
//------------------------------
//------------------------------

//Das ist eher fürs management
void quickSort()
{
    int arrayKopie[a];

    for (int i = 0; i < a; i++)
    {
        arrayKopie[i] = zahlenArray[i];
    }

    clock_t start = clock(); // Timer start

    quickSortRekursiv(arrayKopie,0,a-1);

    clock_t end = clock(); // timer ende

    double Zeit = double(end - start) / CLOCKS_PER_SEC; //umrechnen in sekunden

    for (int i = 0; i < a; i++)// Ausgabe
    {
        std::cout << "Index " << i << ": " << arrayKopie[i] << std::endl;
    }

    std::cout << "Sekunden: " << Zeit << std::endl;

    return;
}

//Die eigentliche Implementierung von Quick Sort
void quickSortRekursiv(int Feld[], int links, int rechts)
{
    int temp;
    int i = links;
    int j = rechts;
    int mitte = (links + rechts) / 2;
    int x = Feld[mitte];

    do
    {
        while (Feld[i] < x)
        {
            i++;
        }

        while (Feld[j] > x)
        {
            j++;
        }

        if(i <= j)
        {
            temp = Feld[i];
            Feld[i] = Feld[j];
            Feld[j] = temp;
            i++;
            j--;
        }
    } while (i <= j);

    if(links < j)
    {
        quickSortRekursiv(Feld, links, j);
    }
    if (i < rechts)
    {
        quickSortRekursiv(Feld, i, rechts);
    }
    return;
}

//------------------------------
//------------------------------
//------------------------------
//------------------------------

void BubbleSort()
{
    int index, temp,laenge;
    bool swapped;
    long arrayKopie[a];

    for(int i = 0; i < a; i ++)
    {
        arrayKopie[i] = zahlenArray[i];
    }

    clock_t start = clock(); // Timer start

    do
    {
        swapped = false;
        for (int i = 0; i < a - 1; i++)
        {
            if(arrayKopie[i] > arrayKopie[i+1]) // tauschen, wenn der vordere Wert größer ist als der hintere
            {
                temp = arrayKopie[i];
                arrayKopie[i] = arrayKopie[i + 1];
                arrayKopie[i + 1] = temp;
                swapped = true;
            }
        }
    } while (swapped);

    clock_t end = clock(); // timer ende

    double Zeit = double(end - start) / CLOCKS_PER_SEC; //umrechnen in sekunden

    for(int i = 0; i < a; i++)// Ausgabe
    {
        std::cout << "Index " << i << ": " << arrayKopie[i] << std::endl;
    }

    std::cout << "Sekunden: " << Zeit <<std::endl;

    return;
}

//------------------------------
//------------------------------
//------------------------------
//------------------------------
//------------------------------

void heapSort()
{
    int links, rechts, n, temp;
    int arrayKopie[a];

    for (int i = 0; i < a; i++)
    {
        arrayKopie[i] = zahlenArray[i];
    }

    clock_t start = clock(); // Timer start

    n = a;

    for (links = (n-2)/2;links >= 0; links--)
    {
        sift(arrayKopie, links, n - 1);
    }

    for (rechts = n-1; rechts > 0; rechts --)
    {
        temp = arrayKopie[0];
        arrayKopie[0] = arrayKopie[rechts];
        arrayKopie[rechts] = temp;
        sift(arrayKopie, 0, rechts - 1);
    }

    clock_t end = clock(); // timer ende

    double Zeit = double(end - start) / CLOCKS_PER_SEC; //umrechnen in sekunden

    for (int i = 0; i < a; i++)// Ausgabe
    {
        std::cout << "Index " << i << ": " << arrayKopie[i] << std::endl;
    }

    std::cout << "Sekunden: " << Zeit << std::endl;

    return;
}

void sift(int Feld[],int links, int rechts)
{
    int i, j;
    int Wurzel;

    i = links;
    Wurzel = Feld[i];
    j = 2 * i + 1;
    if ((j < rechts) && (Feld[j + 1] < Feld[j]))
    {
        j++;
    }
    while((j <= rechts)&&(Feld[j]<Wurzel))
    {
        Feld[i] = Feld[j];
        i = j;
        j = 2 * j + 1;
        if((j < rechts)&&(Feld[j+1] < Feld[j]))
        {
            j++;
        }
        Feld[i] = Wurzel;
    }
    return;
}

//------------------------------
//------------------------------
//------------------------------
//------------------------------

int main()
{
    srand(time(NULL));
    for (int i = 0; i < a; i++)
    {
        zahlenArray[i] = rand() % 1000001;
    }
    /*
    for(int i = 0; i < a; i++)
    {
        std::cout << "Zahl " << i + 1 << ": " << zahlenArray[i] << std::endl;
    }
    */
    //BubbleSort();
    //heapSort();
    quickSort();
}
