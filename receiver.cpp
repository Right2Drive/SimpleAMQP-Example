#include <SimpleAmqpClient/SimpleAmqpClient.h>
#include <string>

using namespace std;

#define QUEUE_NAME "brad-queue"
#define ROUTING_KEY "exampleQueueKey"
#define EXCHANGE_NAME "brad-exchange"
#define CONSUMER_TAG "brad-consumer"

int main()  {

  cout << "Receiving messages now\n";

   // Perform setup
  AmqpClient::Channel::ptr_t channel = AmqpClient::Channel::Create("localhost");

  channel->DeclareQueue(QUEUE_NAME);
  channel->BindQueue(QUEUE_NAME, EXCHANGE_NAME, ROUTING_KEY);  // This needs to be changed

  channel->BasicConsume(QUEUE_NAME, CONSUMER_TAG);

  AmqpClient::BasicMessage::ptr_t message;

  while (1) {
    cout << endl << "message: " << channel->BasicConsumeMessage(CONSUMER_TAG)->Message()->Body() << endl;
  }

  return 0;
}
