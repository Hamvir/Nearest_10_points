# NEAREST_10_POINTS

## Problem Statement

We have a large set of datas given or randomly generated(each data point consisting of 100 dimensions) and we are asked a query consisting of a point of 100 dimension and we need to give its nearest 10 points present in the data set.

## Solution - "Optimised Brute force way"

### Values:

Time in milliseconds required for each query - around 850 to 1020 milliseconds(range generally varies between this).

Data points randomly generated - 10^6 (1 million).

Language used : c++

Compiler used : gcc

### Pseudo-code:

#### Part 1 : Data points generation 

Here 1 million data points are randomly generated less than 100.

#### Part 2 : Taking user input

Here user is asked following inputs:
1) Number of queries.
2) Whether query points will be manually entered by user or generated randomly.

Then query point is stored in an array and following search operation is done for each Query.

#### Part 3 : Finding nearest 10 points

Using euclidean distance nearest 10 neighbours are found. The distances are calculated and stored in an array of size 10 in an sorted fashion, when a new distance is calculated and if its size is less than the highest element of array then its iteratiely sorted into array (simmilar to insertion sort). We also have another array that notes the indexes of the nearest elements. Some other optimisations are also used in the code.

While calculating the euclidean distance the sum is checked and once the sum becomes greater than the largest element of the array storing the distance(of 10 nearest neighbour) it breaks away of the loop calculating the distance as its not required anymore.

We have used chrono library to determine the time taken for this part only(part 3).

#### Part 4 : Output 

The data points along with the time taken are printed out.


### Improvements:

Currently trying K-D trees if it can reduce the time taken more.

The problem statement mentioned 10 million data sets but this code is for 1 million data sets. It gives less than 1 sec for 1 million data points but for 10 million data points its exceeding the limit.

## How to use
>Download the cpp file.

>Compile it using gcc

>run the exe file created.

>Just follow the instructions prompted in command window during running and you are good to go

