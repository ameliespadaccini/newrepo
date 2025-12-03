//
//  main.cpp
//  LLTemplate
//
//  Created by James Shockey on 12/6/16.
//  Copyright © 2016 James Shockey. All rights reserved.
//


/*
 *
 *	Linked List lab.
 *	- Build a library for singly linked list.
 *	- Replace the airport array in main with a Linked List.
 *  - sort the array. 
 *	
 */

#include <iostream>
#include <fstream>
#include <cmath> 
#include "slist.h"

using namespace std;

void simpleSortTotal(Airport* s[], int c);
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d);

int main()
{
    ifstream infile;
    int i=0;
    char cNum[10] ;
    LinkedList myList; /////
    int   airportCount;
    Airport* a[13500];
    
    infile.open ("C:\\Users\\S10047370\\Work\\lasalle-lasa-air-logistics-ameliespadaccini-master\\USAirportCodes.csv", ifstream::in);
    if (infile.is_open())
    {
        int   c=0;
        while (infile.good() && c<8) //edited
        { 
            
            Airport a;
            infile.getline(a.code, 256, ',');
            infile.getline(cNum, 256, ',');
            a.longitude = atof(cNum);
            infile.getline(cNum, 256, '\n');
            a.latitude = atof(cNum);

            myList.add(a);
            if (!(c % 1000))
                //cout << airportArr[c]->code << " long: " << airportArr[c]->longitude << " lat: " << airportArr[c]->latitude <<  endl;

            /*
            if (!(c % 1000))
            {
                cout << airportArr[c]->code << " long: " << airportArr[c]->longitude << " lat: " << airportArr[c]->latitude <<  endl;
                cout << airportArr[c+1]->code << endl; //" long: " << airportArr[c+1]->longitude << " lat: " << airportArr[c+1]->latitude <<  endl;                               
            }
            */

            
            i++ ;
            c++;
        }
        airportCount = c-1;
        infile.close();
        
         for (int c=0; c < airportCount; c++)
            if (!(c % 1000))
            {
                cout << myList.get(c).code << " long: " << myList.get(c).longitude << " lat: " << myList.get(c).latitude <<  endl;
                cout << myList.get(c+1).code << " long: " << myList.get(c+1).longitude << " lat: " << myList.get(c+1).latitude <<  endl;
                cout <<"Distance between " << myList.get(c).code << " and " << myList.get(c+1).code << " is "
                  << distanceEarth( myList.get(c).longitude, myList.get(c).latitude , myList.get(c+1).longitude, myList.get(c+1).latitude) << endl;
            }
    Airport b;
    b.latitude = 1;
    b.longitude = 2;
    cout << "My list \n";
    myList.toString();
    //myList.insert(4,b);
    //cout << "\n Inserted, My list \n";
    //myList.toString();
    //cout << myList.get(2).code << " " << myList.get(2).longitude<< " " << myList.get(2).latitude;
    //cout << c;
    //myList.swap(3,5);
    cout << "\nMy list \n";
    //myList.subList(2,3).toString();
  }
  else
  {
      cout << "Error opening file";
  }
    
}



#define pi 3.14159265358979323846
#define earthRadiusKm 6371.0

// This function converts decimal degrees to radians
double deg2rad(double deg) {
  return (deg * pi / 180);
}

//  This function converts radians to decimal degrees
double rad2deg(double rad) {
  return (rad * 180 / pi);
}


/**
 * Returns the distance between two points on the Earth.
 * Direct translation from http://en.wikipedia.org/wiki/Haversine_formula
 * @param lat1d Latitude of the first point in degrees
 * @param lon1d Longitude of the first point in degrees
 * @param lat2d Latitude of the second point in degrees
 * @param lon2d Longitude of the second point in degrees
 * @return The distance between the two points in kilometers
 */
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d) {
  double lat1r, lon1r, lat2r, lon2r, u, v;
  lat1r = deg2rad(lat1d);
  lon1r = deg2rad(lon1d);
  lat2r = deg2rad(lat2d);
  lon2r = deg2rad(lon2d);
  u = sin((lat2r - lat1r)/2);
  v = sin((lon2r - lon1r)/2);
  return 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}


/*
	Provide sort routine on linked list
*/
/*
void simpleSortTotal()
{

}
*/
