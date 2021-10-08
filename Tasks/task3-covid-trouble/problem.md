Dhananjay lives in a colony having N houses and some roads that connects houses to each other. It is also known that in total there are N-1 roads and it is also possible to reach from any house to any other house uniquely by using some roads. The number of covid cases are rapidly increasing in the colony.  For each house there can be two possibilities ,  either it can have a covid positive patient or not. The house that have a covid positive patient is assigned a value 1 otherwise assigned the value 0. So to overcome the situation colony member have decided to shift all the covid patients ( that is the person living in house that is assigned value 1) to some other house, so that they all get proper treatment at one place and other people of the colony can also be saved. They wanted to do this task as soon as possible. So they decided to choose such a house, such the sum of distances that each covid positive patient travels to reach to that house from their respective houses is as small as possible. Dhananjay being a responsible citizen and a programmer decided to code a program that would return required house.

All the houses are numbered from 1 to N. ( 1<=n<=10^5)
The information of N-1 roads are given in format (a, b), that is there is a road between house a and house b.
Detail of whether i_th house have covid positive patient or not is given for each i from 1 to N.
Dhananjay’s code is given in “solution.cpp” in Task-2 folder. But the code is too slow. And takes a lot time to run. But the covid situation is becoming worse with each second passed. So can you help to optimize Dhananjay code, so that it can run in approx. O(n) time complexity. If multiple houses are possible for answer, output the house number having least index.

Sample Case :
INPUT :

5

1 2      

1 3      

3 4      

3 5      

1 0 1 0 1

OUTPUT :

3

If all the covid patient are shifted to house number 3, the sum of distances that all  patients travels is 2, it is smallest possible sum of distance possible among all cases.
