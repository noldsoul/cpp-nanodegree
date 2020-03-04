#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    string a("1,2,3,");
    istringstream my_stream(a);
    int n;
    char c;
    while (my_stream >> n >>c)
    {
        cout<<"Stream is successful: "<<n<<" "<<c<<endl;
    }
}