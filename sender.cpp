#include <SimpleAmqpClient/SimpleAmqpClient.h>
#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

#define QUIT "quit"
#define QUEUE_NAME "brad-queue"
#define ROUTING_KEY "exampleQueueKey"
#define EXCHANGE_NAME "amq.direct"

int main()  {

        // Perform setup
        AmqpClient::Channel::ptr_t channel = AmqpClient::Channel::Create("localhost");

        channel->DeclareQueue(QUEUE_NAME, false, false, false, false);
        channel->BindQueue(QUEUE_NAME, EXCHANGE_NAME, ROUTING_KEY); // This needs to be changed

        AmqpClient::BasicMessage::ptr_t message = AmqpClient::BasicMessage::Create();
        string msg_body;

        do {
                cout << "What message would you like to send to your friend?\n";
                cin >> msg_body;
                message->Body(msg_body);

                channel->BasicPublish(EXCHANGE_NAME, ROUTING_KEY, message);

        } while (msg_body.compare(QUIT));

        return 0;
}
