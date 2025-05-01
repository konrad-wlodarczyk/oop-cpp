#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

void print(const vector<float>& vector)
{
    cout << "\nVector: [";
    
    for(auto& item : vector)
    {
        cout << " " << item;
    }
    
    cout << "]";
}

vector<float> sum(const vector<float>& vector1, const vector<float>& vector2)
{
    int size = vector1.size();
    
    vector<float> result;
    
    for(int i = 0; i < size; i++)
    {
        result.push_back(vector1[i] + vector2[i]);
    }
    
    return result;
}

int main()
{
    //Creating the empty float vectors
    vector<float> vector1;
    vector<float> vector2;
    
    srand(time(NULL));
    //Filling the vectors with rand numbers
    float a = rand() % 20 + 1; //The random size of the first vectors
    
    //Filling the first vector with rand numbers
    for(int i = 0; i < a; i++)
    {

        vector1.push_back(rand() % 50 + 1);
        vector2.push_back(rand() % 50 + 1);
        
    }
    
    //Printing the both vectors
    print(vector1);
    print(vector2);
    
    //Summing the two vectors
    vector<float> result = sum(vector1, vector2);
    
    //Printing the sum of vectors
    cout << "\nThe sum of the vectors: [";
    
    int size = result.size();
    
    for(int i = 0; i < size; i++)
    {
        cout << result[i] << " ";
    }
    
    cout << "]";
    
    return 0;
}