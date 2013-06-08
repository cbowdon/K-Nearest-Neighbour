# K Nearest Neighbour (Machine Learning Algorithm) in C++11

Just a bit of fun copying the activities [here](http://spin.atomicobject.com/2013/05/06/k-nearest-neighbor-racket/).

K Nearest Neighbour (KNN) is a pretty simple classification algorithm:

* Take your unclassified data point and a (relatively) large classified data set
* For each point in data set, calculate Euclidean distance to unclassified data point
* Sort by minimum distance
* Predict that unclassified data point has the modal class of the K closest points

This should be a pretty good exercise of the STL algorithms.
