  #include <SimpleAmqpClient/SimpleAmqpClient.h>
  #include <string>

  using namespace std;

  #define QUEUE_NAME "brad-queue"
  #define ROUTING_KEY "exampleQueueKey"
  #define EXCHANGE_NAME "amq.direct"
  #define CONSUMER_TAG "brad-consumer"

  int main()  {

    cout << "Receiving messages now\n";

    // Perform setup
    //
    // Create the channel
    AmqpClient::Channel::ptr_t channel = AmqpClient::Channel::Create("localhost");

    // Declare the queue, ensure not exclusive and no autodelete
    channel->DeclareQueue(QUEUE_NAME, false, false, false, false);

    // Bind the queue to an exchange
    channel->BindQueue(QUEUE_NAME, EXCHANGE_NAME, ROUTING_KEY);  // This needs to be changed

    // TODO update the description for what this does
    channel->BasicConsume(QUEUE_NAME, CONSUMER_TAG);

    // Create the message that will be received
    AmqpClient::BasicMessage::ptr_t message;

    while (1) {
      cout << endl << "message: " << channel->BasicConsumeMessage(CONSUMER_TAG)->Message()->Body() << endl;
    }

    return 0;
  }
