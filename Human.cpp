#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <time.h>
using namespace std;
const int stdlength = 100;
const double walkspeed = 3;
const double jogspeed = 6;

struct pathNode
{
    double latetitude;
    double longtitude;
    double timetogo;
    double distancewalked;
};

class human
{
    public:
        void assignIdentity()
        {
            char firstName[stdlength];
            char secondName[stdlength];
            cout << "Set first and then second names." << endl;
            cin.clear();
            cin.sync();
            cin.getline(firstName,stdlength);
            cin.clear();
            cin.sync();
            cin.getline(secondName,stdlength);
            cin.clear();
            cin.sync();
            strcpy (m_firstName, firstName);
            strcpy (m_secondName, secondName);
        }
        void assignAge()
        {
            cout << "Set age." << endl;
            cin >> m_age;
        }
        void assignHeight()
        {
            cout << "Set height." << endl;
            cin >> m_height;
        }
        void setLocation()
        {
            cout << "Set location." << endl;
            cin >> m_location[0];
            cin >> m_location[1];
        }
        void walk()
        {
            srand( time(0) );
            double lon2 = rand() % 180;
            if(rand() % 2 == 1)
            {
                lon2 = -lon2;
            }
            double lat2 = rand() % 90;
            if(rand() % 2 == 1)
            {
                lat2 = -lat2;
            }
            double result = 111.2 * sqrt( (m_location[0] - lon2)*(m_location[0] - lon2) + (m_location[1] - lat2)*cos(M_PI*m_location[0]/180)*(m_location[1] - lat2)*cos(M_PI*m_location[0]/180));
            path.push_back(pathNode());
            path.at(path.size()-1).timetogo = result / walkspeed;
            path.at(path.size()-1).distancewalked = result;
            path.at(path.size()-1).longtitude = m_location[0];
            path.at(path.size()-1).latetitude = m_location[1];
            m_location[0] = lon2;
            m_location[1] = lat2;
        }
        void jog()
        {
            srand( time(0) );
            double lon2 = rand() % 180;
            if(rand() % 2 == 1)
            {
                lon2 = -lon2;
            }
            double lat2 = rand() % 90;
            if(rand() % 2 == 1)
            {
                lat2 = -lat2;
            }
            double result = 111.2 * sqrt( (m_location[0] - lon2)*(m_location[0] - lon2) + (m_location[1] - lat2)*cos(M_PI*m_location[0]/180)*(m_location[1] - lat2)*cos(M_PI*m_location[0]/180));
            path.push_back(pathNode());
            path.at(path.size()-1).timetogo = result / jogspeed;
            path.at(path.size()-1).distancewalked = result;
            path.at(path.size()-1).longtitude = m_location[0];
            path.at(path.size()-1).latetitude = m_location[1];
            m_location[0] = lon2;
            m_location[1] = lat2;
        }
        void showAll()
        {
            cout << "Personality - " << m_firstName << " " << m_secondName << endl;
            cout << "Statistics: " << endl;
            cout << "Age - " << m_age << endl;
            cout << "Height - " << m_height << endl;
            cout << "Location: " << "Longitude - " << m_location[0] << ";" << "Latitude - " << m_location[1] << endl;
        }
        void getPath()
        {
            for(int i = 1; i <=path.size();i++)
            {
                cout << "Step - " << i << endl;
                cout << "Latitude - " << path.at(i-1).latetitude << endl;
                cout << "Longitude - " << path.at(i-1).longtitude << endl;
                cout << "Time(hours) - " << path.at(i-1).timetogo << endl;
                cout << "Kilometers walked - " << path.at(i-1).distancewalked << endl;
            }
        }
    private:
        char m_firstName[stdlength];
        char m_secondName[stdlength];
        int m_age;
        int m_height;
        int m_location[2];
        vector <pathNode> path;
};

int main(int argc, char* argv[])
{
    clock_t begin = clock();
    int numOfHumans;
    int command = 0;
    int loc = 0;
    vector <human> pityHumans;
    cout << "Set number of humans." << endl;
    cin >> numOfHumans;
    pityHumans.resize(numOfHumans);
    cout << "Command roster:" << endl;
    cout << "1-finish" << endl;
    cout << "2-edit human info" << endl;
    cout << "3-walk somewhere" << endl;
    cout << "4-jog somewhere" << endl;
    cout << "5-show everything about human" << endl;
    cout << "6-show his path" << endl;
    while(command != 1)
    {
        cout << "Input command and number of human - 1." << endl;
        cin >> command;
        switch(command)
        {
        case 1:
            {
                break;
            }
        case 2:
            {
                cin >> loc;
                pityHumans.at(loc).assignIdentity();
                pityHumans.at(loc).assignAge();
                pityHumans.at(loc).assignHeight();
                pityHumans.at(loc).setLocation();
                break;
            }
        case 3:
            {
                cin >> loc;
                pityHumans.at(loc).walk();
                break;
            }
        case 4:
            {
                cin >> loc;
                pityHumans.at(loc).jog();
                break;
            }
        case 5:
            {
                cin >> loc;
                pityHumans.at(loc).showAll();
                break;
            }
        case 6:
            {
                cin >> loc;
                pityHumans.at(loc).getPath();
                break;
            }
        }
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin);
    cout << "Execution: " << time_spent << "milsec" << endl;
    return 0;
}
