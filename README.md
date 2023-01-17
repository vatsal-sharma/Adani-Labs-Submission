# Adani-Labs-Submission

The time complexity of the create2DRandomList() function is O(mn), where m is the number of rows and n is the number of columns in the 2D list.

The space complexity of the create2DRandomList() function is also O(mn) because it creates a 2D array with dimensions mn using dynamic memory allocation.
The size of the memory allocated is proportional to mn, so the space complexity is O(mn)

The time complexity of the sort2DListByColumn() function is O(mlog(m)) where m is the number of rows in the 2D list.
This is because the function first creates a vector of pairs containing the values in the given column and their corresponding row indices.

The space complexity of the sort2DListByColumn() function is O(m) where m is the number of rows in the 2D list.
Because it creates a new 2D array of the same size as the input array
