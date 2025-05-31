#include <iostream>
#include <ctime>
using namespace std;
int main() {
    cout << "Starting timer..." << std::endl;

    time_t start_time = time(NULL);


    cout << "Waiting for 5 seconds..." << std::endl;

   
    while (time(NULL) - start_time < 5) {
       
    }

    
    time_t end_time = time(NULL);

  
    int elapsed = (int)(end_time - start_time);

    cout << "Elapsed time: " << elapsed << " seconds" << std::endl;

    return 0;
}
