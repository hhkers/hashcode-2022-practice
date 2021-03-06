# Google HashCode 2022 Practice Round: One Pizza
My solution for Google HashCode 2022 Practice Round

## Problem
You can find the problem statements [here](https://codingcompetitions.withgoogle.com/hashcode/round/00000000008f5ca9/00000000008f6f33).

## Solution

The codes for the solution are in [Solve.ipynb](notebook/Solve.ipynb) and [src.cpp](src.cpp).

The solution follows these steps:

1. Processing ([Solve.ipynb](notebook/Solve.ipynb))

   1. Count ```likes```, ```dislikes``` and calculate ```like - dislike``` for each ingredient.
   
   2. Include the ingredients greater than ```0``` in 1.
   
2. Optimisation ([src.cpp](src.cpp))

   1. Swap a random ingredient from "on the pizza" to "not on the pizza" and vice versa.

   2. Pick a random client that is currently not satisfied and swap ingredients to satisfy.


## Results
| File  | Score |
| ------------- | ------------- |
| A - An example | 2 |
| B - Basic  | 5 |
| C - Coarse  | 5 |
| D - Difficult | 1,805 |
| E - Elaborate | 2,065 |
| **Total** | **3,882** |

With more optimisation, D and E might be improved. 
