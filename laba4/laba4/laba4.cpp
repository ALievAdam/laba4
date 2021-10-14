#include <iostream>
#include<conio.h>

using namespace std;

int n;
int tarif[2][1000];
int dist[2][1000];
int arr[2][1000];

int vvod_dist(int dist[2][1000], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Расстояние для сотрудника " << i + 1 << ":" << endl;
        cin >> dist[2][i];  
        dist[1][i] = i + 1;
    }
    return 0;
}

int sort_dist(int dist[2][1000], int n)
{
    for (int j = 0; j < n - 1; j++) {
        for (int i = 0; i < n - 1; i++) {
            if (dist[2][i] >= dist[2][i + 1])
            {
                swap(dist[2][i], dist[2][i + 1]);
                swap(dist[1][i], dist[1][i + 1]);
            }
        }
    }
    return 0;
}

int vvod_tarif(int tarif[2][1000], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Тариф в " << i + 1 << " такси:" << endl;
        cin >> tarif[2][i];
        tarif[1][i] = i + 1;
    }
    return 0;
}

int sort_tarif(int tarif[2][1000], int n)
{
    for (int j = 0; j < n - 1; j++) {
        for (int i = 0; i < n - 1; i++) {
            if (tarif[2][i] <= tarif[2][i + 1])
            {
                swap(tarif[2][i], tarif[2][i + 1]);
                swap(tarif[1][i], tarif[1][i + 1]);
            }
        }
    }
    return 0;
}

int print(int tarif[2][1000], int dist[2][1000], int arr[2][1000], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[2][i] = tarif[1][i];
        arr[1][i] = dist[1][i];
    }

    for (int j = 0; j < n - 1; j++)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[1][i] > arr[1][i + 1])
            {
                swap(arr[1][i], arr[1][i + 1]);
                swap(arr[2][i], arr[2][i + 1]);
            }
        }
    }

    cout << "Сотрудники должны сесть в такси под номерами:  ";
    for (int i = 0; i < n; i++)
        cout << arr[2][i] << " ";
    return 0;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    cout << "Введите количество сотрудников:" << endl;
    cin >> n;
    vvod_dist(dist, n);
    sort_dist(dist, n);
    vvod_tarif(tarif, n);
    sort_tarif(tarif, n);
    print(tarif, dist, arr, n);
    _getch();
    return 0;
}
