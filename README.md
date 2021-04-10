# Doc
- https://fr.wikipedia.org/wiki/Analyse_de_la_complexit%C3%A9_des_algorithmes
- https://en.wikipedia.org/wiki/Best,\_worst_and_average_case
- https://en.wikipedia.org/wiki/Sorting_algorithm#Comparison_of_algorithms
- https://en.wikipedia.org/wiki/Search_data_structure#Asymptotic_amortized_worst-case_analysis
- https://en.wikipedia.org/wiki/Data_structure
- https://en.wikipedia.org/wiki/Random_access
- https://en.wikipedia.org/wiki/Stack_(abstract_data_type)
- https://en.wikipedia.org/wiki/Computational_complexity_theory
- https://www.geeksforgeeks.org/stack-data-structure-introduction-program/
- https://www.geeksforgeeks.org/implement-two-stacks-in-an-array/
# Algo Push_swap
## Concept ⚙️
After many tests and reasearchs it appeared that the best solution to have best results was to put all the numbers in stack B in the good descending order.
So the scale to search the good value in **A** to put in **B** is the whole **A stack**.
But as we don't want to run the half of the stack to put the right **A** value to the top of **B**, we prefer to see on each **A value** the perfect spot in **B** and how many moves it takes to drop it off.

We finally choose the combination of **A value/B spot** which takes the less moves to be achieved.
### A to B
While A is not empty, we look for the best move (shortest) to be achieved.
We execute this move then search for the next best move. And so on.
### B to A
B stack is sorted in a descending way but it doesn't necessarily starts from the highest or smallest value.
As we need to have the highest value at the bottom of A and the smallest at the top to get the ascending order we want, we just need to move the highest value of B to its top then push them all.
End of game.
