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

using namespace std;

//void simpleSortTotal(Airport* s[], int c);
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d);

class Airport
{
public:
    char code[5];
    double longitude;
    double latitude;
};

struct Node
{
    Airport data;
    Node* next;

    Node(const Airport& a) : data(a), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

void add(Airport& port) {
     Node* newNode = new Node(port);
      if (head == nullptr)
      {
        newNode->next = head; 
        head = newNode;
      }
      else
      {
        Node* last = head; 

        while (last->next != nullptr) {
          last = last->next;
        }
        last->next = newNode;
      }
}


void toString() {
     Node* temp = head;
      int index = 0;
      while (temp) {
           cout << temp->data.code << " long: " << temp->data.longitude
                     << " lat: " << temp->data.latitude << endl;
           temp = temp->next;
           index++;
        }
     }

void insert(int position, const Airport& port) {
     Node* newNode = new Node(port);
        // at beginning
        if (position == 0 || head == nullptr) {
            newNode->next = head;
            head = newNode;
            return;
        }
     
      Node* temp = head;
      int index = 0;

      // inserts before position
      while (temp->next != nullptr && index < position - 1) {
          temp = temp->next;
          index++;
      }

      newNode->next = temp->next;
      temp->next = newNode;
     }
bool equals(LinkedList right) {
     int index = 0;
      Node* temp = head;
      Node* tempRight = right.head;
      while (temp->next != nullptr && tempRight->next != nullptr) {
        //cout << temp->data.longitude;
        //cout << tempRight->data.longitude;
        if (temp->data.longitude != tempRight->data.longitude)
          return false;
        temp = temp->next;
        //get tempRight next value
        index++;
      }
      return true;
    }
Airport get(int index) {
     int position = 0;
      Node* temp = head;
      while (temp->next != nullptr && position < index) {
          temp = temp->next;
          position++;
      }
      return temp->data;
    }
void swap(int index1, int index2) {
if (index1 > index2)
        { //making index 1 the smaller value
          int tempint = index2;
          index2=index1;
          index1=tempint;
        }
      int position = 0;
      Node* prev1 = head; //node before temp
      while (prev1->next != nullptr && position < index1-1) {
          prev1 = prev1->next;
          position++;
      }
      Node *temp = prev1->next;
      Node *next1 = temp->next;

      position =0 ;
      Node* prev2 = head; //node before temp
      while (prev2->next != nullptr && position < index2-1) {
          prev2 = prev2->next;
          position++;
      }
      Node* temp2 = prev2->next;
      Node* next2 = temp2->next;

      if (next2 != nullptr)
      {

        //Node* swapperTemp = temp;
        Node* swapperNext = next1;

        prev1->next = temp2;
        temp2->next = next1;

        prev2->next = temp;
        temp->next = next2;
      }
      else
      {
        //Node* swapperTemp = temp;

        prev1->next = temp2;
        temp2->next = next1;

        prev2->next = temp;
        temp->next = nullptr;

      }
    }
    int size(){
      int count = 0;
        Node* prev = head;
      while (prev->next != nullptr) {
                prev = prev->next;
                count++;
            }
        return count;
      }


////////////////////////////
};







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
        while (infile.good()) //edited
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
        /*
         for (int c=0; c < airportCount; c++)
            if (!(c % 1000))
            {
                cout << myList.get(c).code << " long: " << myList.get(c).longitude << " lat: " << myList.get(c).latitude <<  endl;
                cout << myList.get(c+1).code << " long: " << myList.get(c+1).longitude << " lat: " << myList.get(c+1).latitude <<  endl;
                cout <<"Distance between " << myList.get(c).code << " and " << myList.get(c+1).code << " is "
                  << distanceEarth( myList.get(c).longitude, myList.get(c).latitude , myList.get(c+1).longitude, myList.get(c+1).latitude) << endl;
            }
            */
    Airport b;
    b.latitude = 1;
    b.longitude = 2;
    //cout << "My list \n";
    ///myList.toString();
    //myList.insert(4,b);
    //cout << "\n Inserted, My list \n";
    //myList.toString();
    //cout << myList.get(2).code << " " << myList.get(2).longitude<< " " << myList.get(2).latitude;
    //cout << c;
    //myList.swap(3,5);
    //cout << "\nMy list \n";
    //myList.subList(2,3).toString();


    //airports within 100 miles
    double ausLat = 30.1944;
    double ausLong = 97.6700;
    double satLat = 29.5336;
    double satLong = 98.4697;
    double grkLat = 31.0672;
    double grkLong = 97.8289;

    cout << distanceEarth(grkLat, grkLong, ausLat, ausLong);

    LinkedList list2;

    for (int i=0; i<myList.size(); i++)
    {
        double lat1 = myList.get(i).latitude;
        //cout << lat1 << "\n";
        double long1 = myList.get(i).longitude;
        //cout << long1 << "\n";
        double dist = distanceEarth(ausLat, ausLong, lat1, long1);
        if ( dist <= 100.0)
        {
            //list2.add(&myList.get(i));
            cout <<(myList.get(i).code);
        }
    }

    //farthest 
    for (int i=0; i<myList.size(); i++)
    {
        double lat1 = myList.get(i).latitude;
        //cout << lat1 << "\n";
        double long1 = myList.get(i).longitude;
        //cout << long1 << "\n";
        double dist = distanceEarth(ausLat, ausLong, lat1, long1);
        if ( dist <= 100.0)
        {
            //list2.add(&myList.get(i));
            cout <<(myList.get(i).code);
        }
    }

    
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

