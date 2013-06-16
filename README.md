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
+ Used partial sort rather than a full sort, since we don't care about the ordering of anything outside of the K closest points.

Two further optimizations to implement:
+ Nth element would be an even better choice than partial sort if K is large, since we don't really care about the ordering of the K closest points either.
+ It might be useful to weight the K nearest neighbours according to their distance.
