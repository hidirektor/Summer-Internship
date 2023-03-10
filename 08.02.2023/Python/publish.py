import random
import time

from paho.mqtt import client as mqtt_client


broker = 'broker.emqx.io'
port = 1883
topic = "python/mqtt"
# generate client ID with pub prefix randomly
client_id = f'python-mqtt-{random.randint(0, 1000)}'
username = 'emqx'
password = 'public'

def connect_mqtt():
    def on_connect(client, userdata, flags, rc):
        if rc == 0:
            print("MQTT Bağlantısı tamamdır!")
        else:
            print("Bağlantı hatası, hata kodu %d\n", rc)

    client = mqtt_client.Client(client_id)
    client.username_pw_set(username, password)
    client.on_connect = on_connect
    client.connect(broker, port)
    return client


def publish(client):
    msg = ""
    while msg != "cikis":
        time.sleep(1)
        print("Lütfen gönderilecek mesajı girin: ")
        msg = input("Mesajınız: ")
        result = client.publish(topic, msg)
        # result: [0, 1]
        status = result[0]
        if status == 0:
            print(f"`{msg}` Mesaj `{topic}` kanalı üstünden gönderildi")
        else:
            print(f"Mesaj {topic} kanalındaki hatadan dolayı gönderilemedi")


def run():
    client = connect_mqtt()
    client.loop_start()
    publish(client)


if __name__ == '__main__':
    run()