#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

int isFileRead;
int adjacencyMatrix[26][26];
int isExists[26];
int dist[26];
int parentArr[26];

/* Min Heap */

struct Node
{
    int city;
    int distance;
};

struct MinHeap
{
    Node* internalArray;
    int capacity;
    int currentSize;
};

void initializeMinHeap(MinHeap* minHeap, int capacity)
{
    minHeap->internalArray = new Node[capacity];
    minHeap->capacity = capacity;
    minHeap->currentSize = 0;
}

void swapMinHeapNodes(Node &x, Node &y)
{
    Node temp = x;
    x = y;
    y = temp;
}

int parentOfHeapNode(int i)
{
    return (i - 1) / 2;
}

int leftChildOfHeapNode(int i)
{
    return (2 * i + 1);
}

int rightChildOfHeapNode(int i)
{
    return (2 * i + 2);
}

Node getMinElementFromMinHeap(MinHeap* minHeap)
{
    return minHeap->internalArray[0];
}

void insertElementToMinHeap(MinHeap* minHeap, Node element)
{
    if (minHeap->currentSize < minHeap->capacity)
    {
        minHeap->currentSize++;
        int i = minHeap->currentSize - 1;

        minHeap->internalArray[i] = element;

        while (i != 0 &&
               minHeap->internalArray[parentOfHeapNode(i)].distance >
               minHeap->internalArray[i].distance)
        {
            swapMinHeapNodes(
                minHeap->internalArray[i],
                minHeap->internalArray[parentOfHeapNode(i)]
            );

            i = parentOfHeapNode(i);
        }
    }
}

void heapify(MinHeap* minHeap, int i)
{
    int l = leftChildOfHeapNode(i);
    int r = rightChildOfHeapNode(i);

    int smallest = i;

    if (l < minHeap->currentSize &&
        minHeap->internalArray[l].distance <
        minHeap->internalArray[smallest].distance)
    {
        smallest = l;
    }

    if (r < minHeap->currentSize &&
        minHeap->internalArray[r].distance <
        minHeap->internalArray[smallest].distance)
    {
        smallest = r;
    }

    if (smallest != i)
    {
        swapMinHeapNodes(
            minHeap->internalArray[i],
            minHeap->internalArray[smallest]
        );

        heapify(minHeap, smallest);
    }
}

void extractMinElementFromMinHeap(MinHeap* minHeap)
{
    if (minHeap->currentSize > 0)
    {
        if (minHeap->currentSize == 1)
        {
            minHeap->currentSize--;
            return;
        }

        minHeap->internalArray[0] =
            minHeap->internalArray[minHeap->currentSize - 1];

        minHeap->currentSize--;

        heapify(minHeap, 0);
    }
}

/* Min Heap */

void readInputFile()
{
    int i, j;

    for (i = 0; i < 26; i++)
    {
        isExists[i] = 0;
    }

    for (i = 0; i < 26; i++)
    {
        for (j = 0; j < 26; j++)
        {
            adjacencyMatrix[i][j] = -1;
        }
    }

    string fileName;

    cout << "Enter the file name: ";
    cin >> fileName;

    char first, second, tmp;
    int firstIndex, secondIndex, intensity;

    ifstream inputFile(fileName);

    while (inputFile >> first >> tmp >> second >> tmp >> intensity)
    {
        firstIndex = first - 'A';
        secondIndex = second - 'A';

        isExists[firstIndex] = 1;
        isExists[secondIndex] = 1;

        adjacencyMatrix[firstIndex][secondIndex] = intensity;
        adjacencyMatrix[secondIndex][firstIndex] = intensity;
    }

    inputFile.close();

    isFileRead = 1;

    cout << fileName << " successfully read!" << endl;
}

void showAdjacencyMatrix()
{
    int i, j;

    if (isFileRead == 0)
    {
        cout << "First read an input file!" << endl;
        return;
    }

    cout << "Adjacency Matrix:\n\n\t";

    for (i = 0; i < 26; i++)
    {
        if (isExists[i])
        {
            cout << "   " << char(i + 'A') << "\t";
        }
    }

    cout << endl;

    for (i = 0; i < 26; i++)
    {
        if (isExists[i])
        {
            cout << char(i + 'A') << "\t";

            for (j = 0; j < 26; j++)
            {
                if (isExists[j])
                {
                    if (adjacencyMatrix[i][j] == -1)
                    {
                        cout << "   -\t";
                    }
                    else
                    {
                        cout << adjacencyMatrix[i][j] << "\t";
                    }
                }
            }

            cout << endl;
        }
    }
}

int showMenuAndGetChoice()
{
    int choice;
    int okay = 0;

    while (okay == 0)
    {
        cout << "\n\nMenu\n";
        cout << "--------------------------------------\n";
        cout << "1 - Read File\n";
        cout << "2 - Show Adjacency Matrix\n";
        cout << "3 - Find Shortest Path\n";
        cout << "4 - Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 4)
        {
            okay = 1;
        }
        else
        {
            cout << "\nWrong choice! Please enter again.";
        }
    }

    cout << endl;

    return choice;
}

void printPath(int j)
{
    if (parentArr[j] != -1)
    {
        printPath(parentArr[j]);

        cout << "-> " << char('A' + j) << " ";
    }
}

void shortestPath()
{
    int i;

    if (isFileRead == 0)
    {
        cout << "First read an input file!" << endl;
        return;
    }

    char sourceChar, destinationChar;

    cout << "Enter the source vertex: ";
    cin >> sourceChar;

    cout << "Enter the destination vertex: ";
    cin >> destinationChar;

    int source = sourceChar - 'A';
    int destination = destinationChar - 'A';

    MinHeap* myHeap = new MinHeap;

    initializeMinHeap(myHeap, 26);

    for (i = 0; i < 26; i++)
    {
        dist[i] = INT_MAX;
    }

    parentArr[source] = -1;

    dist[source] = 0;

    Node sourceNode;

    sourceNode.city = source;
    sourceNode.distance = 0;

    insertElementToMinHeap(myHeap, sourceNode);

    while (myHeap->currentSize > 0)
    {
        int currCity = getMinElementFromMinHeap(myHeap).city;

        extractMinElementFromMinHeap(myHeap);

        for (i = 0; i < 26; i++)
        {
            if (i != currCity &&
                adjacencyMatrix[currCity][i] != -1)
            {
                int weight = adjacencyMatrix[currCity][i];

                if (dist[i] > dist[currCity] + weight)
                {
                    dist[i] = dist[currCity] + weight;

                    parentArr[i] = currCity;

                    Node newNode;

                    newNode.city = i;
                    newNode.distance = dist[i];

                    insertElementToMinHeap(myHeap, newNode);
                }
            }
        }
    }

    if (dist[destination] == INT_MAX)
    {
        cout << "\nThere is no path from "
             << sourceChar << " to "
             << destinationChar << endl;
    }
    else
    {
        cout << "\nThe shortest path from "
             << sourceChar << " to "
             << destinationChar << ": ";

        cout << sourceChar << " ";

        printPath(destination);

        cout << "\nThe length of this path: "
             << dist[destination] << endl;
    }

    delete[] myHeap->internalArray;
    delete myHeap;
}

int main()
{
    isFileRead = 0;

    int userExited = 0;

    while (userExited == 0)
    {
        int choice = showMenuAndGetChoice();

        if (choice == 1)
        {
            readInputFile();
        }
        else if (choice == 2)
        {
            showAdjacencyMatrix();
        }
        else if (choice == 3)
        {
            shortestPath();
        }
        else if (choice == 4)
        {
            userExited = 1;

            cout << "Good bye!" << endl;
        }
    }

    return 0;
}
