# K Nearest Neighbour (Machine Learning Algorithm) in C++11

Just a bit of fun copying the activities [here](http://spin.atomicobject.com/2013/05/06/k-nearest-neighbor-racket/).

K Nearest Neighbour (KNN) is a pretty simple classification algorithm:

* Take your unclassified data point and a (relatively) large classified data set
* For each point in data set, calculate Euclidean distance to unclassified data point
* Sort by minimum distance
* Predict that unclassified data point has the modal class of the K closest points

This should be a pretty good exercise of the STL algorithms.

### Post completion update:
This was straightforward, lots of use of the algorithm standard library. The problem is really well suited to a functional approach.

I added two optimization to the above:
+ Skipped the square root in calculating the Euclidean distance - no effect on the sorting, but saves N square root calculations.
+ Used nth element rather than a full sort, since we don't care about the ordering beyond whether or not the point is among the K closest.

Potential future optimizations:
+ It might be useful to weight the K nearest neighbours according to their distance - if there is a tight cluster of type A right on top of the unclassified element, but the K closest contains lots of type B, this would help the correct classification as A.
