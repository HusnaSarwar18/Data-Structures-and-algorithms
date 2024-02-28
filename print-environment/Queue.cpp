#include <iostream>
#include "Queue.cpp"
#include <time.h>
using namespace std;

void PrintEnvironment(int **arr, int width, int height)
{

    for (int i = 0; i < height; i++)

    {

        for (int j = 0; j < width; j++)

        {

            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
int

main()
{

    int height = 0, width = 0, percentage = 0, X, Y;

    cout << "BCSF21m018_Husna Sarwar" << endl;

    cout << "\n<---Welcome to the WaveFront Pather--->" << endl;

    cout << "\nPlease tell me about the grid you want to generate. " << endl;

    cout << "Enter the width/number of columns (at least 10): ";

    cin >> width;

    while (width < 0 || width > 10)

    {

        cout << "\nInvalid width.Enter again: ";

        cin >> width;
    }

    cout << "Enter the height/number of rows (at least 10): ";

    cin >> height;

    while (height < 0 || height > 10)

    {

        cout << "\nInvalid height. Enter again: ";

        cin >> height;
    }

    int **arr;

    arr = new int *[height];

    for (int i = 0; i < height; i++)

    {

        arr[i] = new int[width];
    }
    for (int i = 0; i < height; i++)

    {

        for (int j = 0; j < width; j++)

        {

            arr[i][j] = 0;
        }
    }
    cout << "\nEnter the percent of impassible terrain (0 - 100): ";

    cin >> percentage;

    while (percentage < 0 || percentage > 100)

    {

        cout << "\nInvalid percentage. Enter again: ";

        cin >> percentage;
    }

    // calculating total number of elements in 2D array
    int total = width * height;

    int impassibleTerrain = (total * percentage) / 100;

    while (impassibleTerrain > 35)

    {

        int choice;

        cout <<

            "\nWarning!!! it might make poor results.Do you want to continue?(1/0): ";

        cin >> choice;

        while (choice < 0 || choice > 1)

        {

            cout << "Invalid choice. Enter 1 for 'yes' and 0 for 'No' only";

            cin >> choice;
        }

        if (choice == 0)

        {

            cout << "\nEnter the percent of impassible terrain (0 - 100): ";

            cin >> percentage;

            impassibleTerrain = (total * percentage) / 100;
        }
    }

    // cells to mark as Impassibale terrain
    srand(time(0));

    for (int i = 0; i < impassibleTerrain; i++)

    {

        int impassibleRows = rand() % height;

        int impassibleCol = rand() % width;

        if (arr[impassibleRows][impassibleCol] != -1)

        {

            arr[impassibleRows][impassibleCol] = -1;
        }
    }

    PrintEnvironment(arr, width, height);

    cout << "\nPlease enter the Goal Position X: ";

    cin >> X;

    while (X < 0 || X >= height)

    {

        cout << "Sorry, that position is out of bounds." << endl;

        cin >> X;
    }

    cout << "\nPlease enter the Goal Position Y: ";

    cin >> Y;

    while (Y < 0 || Y > width)

    {

        cout << "Sorry, that position is out of bounds." << endl;

        cin >> Y;
    }

    if (arr[X][Y] == -1)

    {

        cout << "\nSorry, that position is inside an obstacle.";

        cout << "\nPlease enter the Goal Position X: ";

        cin >> X;

        while (X < 0 || X >= height)

        {

            cout << "\nInvalid X position. Enter again: ";

            cin >> X;
        }

        cout << "\nPlease enter the Goal Position Y: ";

        cin >> Y;

        while (Y < 0 || Y > width)

        {

            cout << "\nInvalid Y position. Enter again: ";

            cin >> Y;
        }
    }

    arr[X][Y] = 1;

    PrintEnvironment(arr, width, height);

    Queue q;

    Data d;

    Data temp;

    d.x = X;

    d.y = Y;

    q.enqueue(d);

    for (int i = 0; !q.isEmpty(); i++)

    {

        d = q.dequeue();

        int center = arr[d.x][d.y];

        if (d.x - 1 >= 0 && d.y - 1 >= 0 && arr[d.x - 1][d.y - 1] == 0)

        {

            arr[d.x - 1][d.y - 1] = center + 1;

            temp.x = d.x - 1;

            temp.y = d.y - 1;

            q.enqueue(temp);
        }

        if (d.x - 1 >= 0 && arr[d.x - 1][d.y] == 0)

        {

            arr[d.x - 1][d.y] = center + 1;

            temp.x = d.x - 1;

            temp.y = d.y;

            q.enqueue(temp);
        }

        if (d.x - 1 >= 0 && d.y + 1 < width && arr[d.x - 1][d.y + 1] == 0)

        {

            arr[d.x - 1][d.y + 1] = center + 1;

            temp.x = d.x - 1;

            temp.y = d.y + 1;

            q.enqueue(temp);
        }

        if (d.y + 1 < width && arr[d.x][d.y + 1] == 0)

        {

            arr[d.x][d.y + 1] = center + 1;

            temp.x = d.x;

            temp.y = d.y + 1;

            q.enqueue(temp);
        }

        if (d.x + 1 < height && d.y + 1 < width && arr[d.x + 1][d.y + 1] == 0)

        {

            arr[d.x + 1][d.y + 1] = center + 1;

            temp.x = d.x + 1;

            temp.y = d.y + 1;

            q.enqueue(temp);
        }

        if (d.x + 1 < height && arr[d.x + 1][d.y] == 0)

        {

            arr[d.x + 1][d.y] = center + 1;

            temp.x = d.x + 1;

            temp.y = d.y;

            q.enqueue(temp);
        }

        if (d.x + 1 < height && d.y - 1 >= 0 && arr[d.x + 1][d.y - 1] == 0)

        {

            arr[d.x + 1][d.y - 1] = center + 1;

            temp.x = d.x + 1;

            temp.y = d.y - 1;

            q.enqueue(temp);
        }

        if (d.y - 1 >= 0 && arr[d.x][d.y - 1] == 0)

        {

            arr[d.x][d.y - 1] = center + 1;

            temp.x = d.x;

            temp.y = d.y - 1;

            q.enqueue(temp);
        }
    }

    cout << "\n<----------------Area Fill----------------------->" << endl;

    PrintEnvironment(arr, width, height);

    cout << "\n<----------------Path Find----------------------->" << endl;
    cout << "\narr[" << temp.x << "][" << temp.y << "] = " << arr[temp.x][temp.y] << endl;
    for (int i = 0; i < height * width; i++)
    {
        if (temp.x - 1 >= 0 && temp.y - 1 >= 0 && arr[temp.x - 1][temp.y - 1] != -1 && arr[temp.x - 1][temp.y - 1] < arr[temp.x][temp.y])
        {
            arr[temp.x - 1][temp.y - 1] = 0;
            temp.x = temp.x - 1;
            temp.y = temp.y - 1;
        }
        else if (temp.x - 1 >= 0 && arr[temp.x - 1][temp.y] != -1 && arr[temp.x - 1][temp.y] < arr[temp.x][temp.y])
        {
            arr[temp.x - 1][temp.y] = 0;
            temp.x = temp.x - 1;
        }
        else if (temp.x - 1 >= 0 && temp.y + 1 < width && arr[temp.x - 1][temp.y + 1] != -1 && arr[temp.x - 1][temp.y + 1] < arr[temp.x][temp.y])
        {
            arr[temp.x - 1][temp.y + 1] = 0;
            temp.x = temp.x - 1;
            temp.y = temp.y + 1;
        }
        else if (temp.y + 1 < width && arr[temp.x][temp.y + 1] != -1 && arr[temp.x][temp.y + 1] < arr[temp.x][temp.y])
        {
            arr[temp.x][temp.y + 1] = 0;
            temp.y = temp.y + 1;
        }
        else if (temp.x + 1 < height && temp.y + 1 < width && arr[temp.x + 1][temp.y + 1] != -1 && arr[temp.x + 1][temp.y + 1] < arr[temp.x][temp.y])
        {
            arr[temp.x + 1][temp.y + 1] = 0;
            temp.x = temp.x + 1;
            temp.y = temp.y + 1;
        }
        else if (temp.x + 1 < height && arr[temp.x + 1][temp.y] != -1 && arr[temp.x + 1][temp.y] < arr[temp.x][temp.y])
        {
            arr[temp.x + 1][temp.y] = 0;
            temp.x = temp.x + 1;
        }
        else if (temp.x + 1 < height && temp.y - 1 >= 0 && arr[temp.x + 1][temp.y - 1] != -1 && arr[temp.x + 1][temp.y - 1] < arr[temp.x][temp.y])
        {
            arr[temp.x + 1][temp.y - 1] = 0;
            temp.x = temp.x + 1;
            temp.y = temp.y - 1;
        }
        else if (temp.y - 1 >= 0 && arr[temp.x][temp.y - 1] != -1 && arr[temp.x][temp.y - 1] < arr[temp.x][temp.y])
        {
            arr[temp.x][temp.y - 1] = 0;
            temp.y = temp.y - 1;
        }
    }

    PrintEnvironment(arr, width, height);
}