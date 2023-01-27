//Wi-Fi Protocol
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main()
{
    int sock;
    struct sockaddr_in server;
    char message[100] = "[OnderGrup] Communication protocools send test code !";

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket");
    }
    puts("Socket created");

    server.sin_addr.s_addr = inet_addr("IP_ADDRESS");
    server.sin_family = AF_INET;
    server.sin_port = htons( PORT );

    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0) {
        perror("connect failed. Error");
        return 1;
    }

    puts("Connected\n");

    if( send(sock , message , strlen(message) , 0) < 0) {
        puts("Send failed");
        return 1;
    }
    puts("Data Send\n");

    return 0;
}

//DDS Protocol
#include "ndds/ndds_c.h"
#include "example_main.h"

#include "example.h"

int publisher_main(int domainId, int sample_count) {
    /* Create a DomainParticipant */
    DDS_DomainParticipant *participant = DDS_DomainParticipantFactory_create_participant(
            DDS_TheParticipantFactory, domainId, &DDS_PARTICIPANT_QOS_DEFAULT,
            NULL /* listener */, DDS_STATUS_MASK_NONE);
    if (participant == NULL) {
        printf("create_participant error\n");
        publisher_shutdown(participant);
        return -1;
    }

    /* Create a Topic */
    DDS_Topic *topic = DDS_DomainParticipant_create_topic(
            participant, "Example Topic", example_msgTypeSupport_get_type_name(),
            &DDS_TOPIC_QOS_DEFAULT, NULL /* listener */, DDS_STATUS_MASK_NONE);
    if (topic == NULL) {
        printf("create_topic error\n");
        publisher_shutdown(participant);
        return -1;
    }

    /* Create a DataWriter */
    DDS_DataWriter *writer = DDS_Publisher_create_datawriter(
            DDS_DomainParticipant_create_publisher(participant, &DDS_PUBLISHER_QOS_DEFAULT, NULL /* listener */, DDS_STATUS_MASK_NONE),
            topic, &DDS_DATAWRITER_QOS_DEFAULT, NULL /* listener */, DDS_STATUS_MASK_NONE);
    if (writer == NULL) {
        printf("create_datawriter error\n");
        publisher_shutdown(participant);
        return -1;
    }

    /* Create a message */
    example_msg *message = example_msgTypeSupport_create_data_ex(DDS_BOOLEAN_TRUE);
    if (message == NULL) {
        printf("example_msgTypeSupport_create_data error\n");
        publisher_shutdown(participant);
        return -1;
    }

    /* Set the message text */
    message->text = DDS_String_dup("[OnderGrup] Communication protocools send test code !");

    /* Send the message */
    DDS_ReturnCode_t retcode = example_msgDataWriter_write(writer, message, &DDS_HANDLE_
