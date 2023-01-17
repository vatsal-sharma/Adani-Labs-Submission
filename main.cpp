#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()
#include <algorithm> // for sort()

//The time complexity of the create2DRandomList() function is O(mn), where m is the number of rows and n is the number of columns in the 2D list.
int** create2DRandomList(int rows, int cols) {
    // Seed the random number generator
    srand(time(0));
    // The space complexity of the create2DRandomList() function is also O(mn) because it creates a 2D array with dimensions mn using dynamic memory allocation.
    //The size of the memory allocated is proportional to mn, so the space complexity is O(mn)
    
    // Allocate memory for the 2D list
    int** list = new int*[rows];
    for (int i = 0; i < rows; i++) {
        list[i] = new int[cols];
    }

    // Fill the list with random integers between 0 and 100
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            list[i][j] = rand() % 101;
        }
    }

    return list;
}

//The time complexity of the sort2DListByColumn() function is O(mlog(m)) where m is the number of rows in the 2D list.
//This is because the function first creates a vector of pairs containing the values in the given column and their corresponding row indices

int** sort2DListByColumn(int** list, int rows, int cols, int columnIndex) {
    // Create a vector of pairs to store the values in the column and their corresponding row indices
    std::vector<std::pair<int, int>> columnValues;
    for (int i = 0; i < rows; i++) {
        columnValues.push_back(std::make_pair(list[i][columnIndex], i));
    }

    // Sort the vector of pairs based on the column values
    std::sort(columnValues.begin(), columnValues.end());
    
    //The space complexity of the sort2DListByColumn() function is O(m) where m is the number of rows in the 2D list. 
    //Because it creates a new 2D array of the same size as the input array

    // Create a new 2D list to store the sorted values
    int** sortedList = new int*[rows];
    for (int i = 0; i < rows; i++) {
        sortedList[i] = new int[cols];
    }

    // Fill the sorted list with the values from the original list, in the order determined by the sorted vector of pairs
    for (int i = 0; i < rows; i++) {
        int originalRow = columnValues[i].second;
        for (int j = 0; j < cols; j++) {
            sortedList[i][j] = list[originalRow][j];
        }
    }

    return sortedList;
}

int main() {
    // Create a 2D list with 4 rows and 5 columns
    int rows = 4, cols = 5;
    int** myList = create2DRandomList(rows, cols);

    // Print the 2D list before sorting
    std::cout << "Original list:" << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << myList[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Sort the 2D list by the values in column 3
    int** sortedList = sort2DListByColumn(myList, rows, cols, 3);

    // Print the sorted 2D list
    std::cout << "Sorted list:" << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << myList[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Deallocate the memory for the 2D list
    for (int i = 0; i < rows; i++) {
        delete[] myList[i];
    }
    delete[] myList;

    return 0;
}
