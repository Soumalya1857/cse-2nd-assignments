#include <iostream>

using namespace std;

class time
{
        private:

                int hour;
                int minute;
                int sec;
                string type;

        public:

                void get_input(int x,int y,int z)
                {
                        hour = x;
                        minute = y;
                        sec = z;
                }
                void get_input(int x,int y,int z,string p)
                {
                        hour = x;
                        minute = y;
                        sec = z;
                        type = p;
                }


                void get_output()
                {
                        if(hour>12)
                        {
                                hour-=12;
                                cout << "time: " << hour <<" hour" << minute <<" minute"<< sec <<" second"
                                     <<" PM"<< "\n";
                        }
                        else cout << "time: " << hour <<" hour" << minute <<" minute"<< sec <<" second"
                                  <<" AM" << "\n";

                }

                void get_output(string )

};

int main()
{

    return 0;
}
