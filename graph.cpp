#include <iostream>
#include <vector>

class Graph 
{
 public:
    int numVertices; // یک متغیر عددی است که تعداد رئوس گراف را نشان میدهد
    std::vector<std::vector<int>> adjacencyList; // یک بردار از بردار های داخلی است که لیست مجاورت برای یک راس را نگه میدارد

    // سازنده
    Graph(int vertices) 
    {
        numVertices = vertices;
        adjacencyList.resize(numVertices);  //فضای لازم برای لیست مجاورت را تخصیص میدهد
    }

    // اضافه کردن یال بین دو راس
    void addEdge(int src, int dest)  // این دو پارامتر بصورت دوطرفه اضافه میشود
    {
        // اضافه کردن یال بین دو راس
        adjacencyList[src].push_back(dest);
        adjacencyList[dest].push_back(src);
    }
};