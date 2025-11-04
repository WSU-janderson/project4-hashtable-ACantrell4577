[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/7RAFczHS)
# Project 4 - HashTable

Project description can be found [in the repo](Project4_HashTable.pdf)

Place your complexity analysis below.

---

`insert` : O(n)
Insert has a linear time complexity as it has only 1 for loop that wont itterate more than the number of values in the hash table thus the worse case scenario is O(n)

`remove` : O(n)
Remove is also linear for the same reasons I do not have nested loops and it will only itterate the number of times equal to the number of buckets

`contains` : O(n)
Contains only itterates through the hash table once and only for the number of elements that can be contained inside the hash table thus the worst case is n

`get` : O(n)
Get much like the other funtions in this list itterate throught the hash table the exact same way and thus it only itterates through the hash table a maximum of n times

`operator` : O(n)
Works similar to the other functions where it only itterates through the table a maximum of n times thus the time complexity is O(n)
