#include <SimpleAmqpClient/SimpleAmqpClient.h>
#include <string>

using namespace std;

#define QUIT "quit"
#define QUEUE_NAME "lanQueue"
#define QUEUE_KEY "exampleQueueKey"
#define EXCHANGE_NAME "exampleExchangeName"

int main()  {

  // Perform setup
  AmqpClient::Channel::ptr_t channel = AmqpClient::Channel::Create();

  channel->DeclareQueue(QUEUE_NAME);
  channel->BindQueue(QUEUE_NAME, EXCHANGE_NAME, QUEUE_KEY);  // This needs to be changed

  AmqpClient::BasicMessage::ptr_t message;

  do {
    cout << "What message would you like to send to your friend?\n";
    cin >> message;



  } while (message.compare(QUIT));

  return 0;
}
