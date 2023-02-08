package me.t3sl4.mqtt;

import org.eclipse.paho.client.mqttv3.MqttClient;
import org.eclipse.paho.client.mqttv3.MqttConnectOptions;
import org.eclipse.paho.client.mqttv3.MqttException;
import org.eclipse.paho.client.mqttv3.MqttMessage;
import org.eclipse.paho.client.mqttv3.persist.MemoryPersistence;

import java.util.Scanner;

public class Publish {

    public static void main(String[] args) {

        String broker = "tcp://broker.emqx.io:1883";
        String topic = "mqtt/test";
        String username = "emqx";
        String password = "public";
        String clientid = "publish_client";
        String content = "ilk değer";
        Scanner tempSc = new Scanner(System.in);
        int qos = 0;

        while(content != "cikisyap") {
            try {
                MqttClient client = new MqttClient(broker, clientid, new MemoryPersistence());
                MqttConnectOptions options = new MqttConnectOptions();
                options.setUserName(username);
                options.setPassword(password.toCharArray());
                options.setConnectionTimeout(60);
                options.setKeepAliveInterval(60);
                client.connect(options);
                System.out.println("Lütfen ağa göndermek istediğiniz mesajı girin: ");
                content = tempSc.nextLine();

                MqttMessage message = new MqttMessage(content.getBytes());
                message.setQos(qos);

                client.publish(topic, message);
                System.out.println("-------------------");
                System.out.println("Mesaj Ağa Gönderildi !");
                System.out.println("Dizin: " + topic);
                System.out.println("Gönderilen Mesaj: " + content);
                System.out.println("-------------------");

                client.disconnect();

                client.close();
            } catch (MqttException e) {
                throw new RuntimeException(e);
            }
        }
    }
}