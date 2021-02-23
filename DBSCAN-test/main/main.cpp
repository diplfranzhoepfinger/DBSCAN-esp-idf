#include <stdio.h>
#include <iostream>
#include "dbscan.h"

using std::cout;
using std::endl;

#define MINIMUM_POINTS 4     // minimum number of cluster
#define EPSILON (0.75)  // distance for clustering

void readBenchmarkData(vector<Point>& points)
{



    Point p;

    p.x = 5.1;    p.clusterID = UNCLASSIFIED;    points.push_back(p);
    p.x = 5.2;    p.clusterID = UNCLASSIFIED;    points.push_back(p);
    p.x = 4.8;    p.clusterID = UNCLASSIFIED;    points.push_back(p);
    p.x = 4.9;    p.clusterID = UNCLASSIFIED;    points.push_back(p);



    p.x = 3.1;    p.clusterID = UNCLASSIFIED;    points.push_back(p);
    p.x = 3.2;    p.clusterID = UNCLASSIFIED;    points.push_back(p);
    p.x = 2.8;    p.clusterID = UNCLASSIFIED;    points.push_back(p);
    p.x = 2.9;    p.clusterID = UNCLASSIFIED;    points.push_back(p);

}

void printResults(vector<Point>& points)
{
    printf("Number of points: %u\n"
        " x   cluster_id\n"
        "-----------------------------\n"
        , points.size());
    for ( const Point  &element : points )
    {
          printf("%5.2lf : %d\n",
        		  element.x,
				  element.clusterID);

    }
}

/* Inside .cpp file, app_main function must be declared with C linkage */
extern "C" void app_main(void)
{
    cout << "app_main starting" << endl;
    vector<Point> points;

    // read point data
    readBenchmarkData(points);

    // constructor
    DBSCAN ds(MINIMUM_POINTS, EPSILON, points);

    // main loop
    ds.run();

    vector<vector<Point>> vvp = ds.getClusters();




    // result of DBSCAN algorithm
    printResults(ds.m_points);



    cout << "app_main done" << endl;
}
