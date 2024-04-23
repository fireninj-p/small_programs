#include <iostream>
#include <thread>
using namespace std;


void wait_() {
    while (true) {
        t.wait();
        t.expires_after(asio::chrono::seconds(10));
        cout << "\n10 seconds have passed!" << endl;
    }
   
}





//second thread
void logger() 
{
    string user_input;
    while (true) 
    {
        cout << "Enter anything here: ";
        cin >> user_input;
        cout << user_input;
    }
    
}



int main() {

    std::thread timerThread(wait_);
    std::thread loggerThread(logger);

    while (true) 
    {
        timerThread.join();
        loggerThread.join();
    
    }
    return 0;
}
