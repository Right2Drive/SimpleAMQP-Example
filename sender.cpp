#include <SimpleAmqpClient/SimpleAmqpClient.h>
#include <string>

using namespace std;

#define QUIT "quit"

int main()  {

  string message;

  do {
    cout << "What message would you like to send to your friend?\n";
    cin >> message;

  } while (message.compare(QUIT));

  return 0;
}
