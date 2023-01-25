#ROS API Skeleton Code:
import rospy

def talker():
    pb = rospy.Publisher('chatter', String, queue_size=10)
    rospy.init_node('talker', anonymous=True)
    rate = rospy.Rate(10)
    while not rospy.is_shutdown():
        hello_str = "[Onder Grup] Saat: %s" % rospy.get_time()
        rospy.loginfo(hello_str)
        pub.publish(hello_str)
        rate.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass

#ROS IoT Skeleton Code
import rospy
from std_msgs.msg import Float32

temperature = 0

def temp_callback(data):
    global temperature
    temperature = data.data

rospy.init_node('home_automation')
rospy.Subscriber('temperature_sensor', Float32, temp_callback)
heating_pub = rospy.Publisher('heating_system', Float32, queue_size=10)

desired_temp = 22

while not rospy.is_shutdown():
    if temperature < desired_temp:
        heating_pub.publish(1)
    else:
        heating_pub.publish(0)
rospy.sleep(1)

#MQTT communication Protocol
import paho.mqtt.client as mqtt

def on_connect(client, userdata, flags, rc):
    print("Connected with result code "+str(rc))
    client.subscribe("onderGrup/communication")

def on_message(client, userdata, msg):
    print(msg.topic+" "+str(msg.payload))

client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message

client.connect("your_mqtt_server", 1883, 60)
client.loop_start()

client.publish("onderGrup/communication", "[OnderGrup] Communication Protocols send test code !")

#DDS Communication Protocol
import OpenDDS.DCPS.transport as transport
from OpenDDS.DCPS.DataWriter import DataWriter
from OpenDDS.DCPS.TypeSupport import TypeSupport

ts = TypeSupport()
ts.register_type(MyMessageType)

dw = DataWriter()
dw.create_datawriter(ts, "MyTopic")

msg = MyMessageType()
msg.data = "[OnderGrup] Communication Protocols send test code !"
dw.write(msg)

#OPC UA Communication Protocol
from opcua import Client

client = Client("opc.tcp://your_opcua_server:4840")
client.connect()

root = client.get_root_node()

var_node = root.get_child(["0:Objects", "2:MyDevice", "2:MyVariable"])

var_node.set_value("[OnderGrup] Communication Protocols send test code !")

client.disconnect()

#Z-Wave Communication Protocol
from pyzwave.pyzwave import ZWave

zwave = ZWave("COM3")

zwave.send_broadcast("[OnderGrup] Communication Protocols send test code !")

zwave.close()

#ZigBee Communication Protocol
from xbee import ZigBee
import serial

ser = serial.Serial('COM3', 9600)

xbee = ZigBee(ser)

xbee.send("tx", dest_addr_long = "XXXXXXXXXXXXXXXX", data = "[OnderGrup] Communication Protocols send test code !")

ser.close()

#Bluetooth Communication Protocol
import pygatt

adapter = pygatt.GATTToolBackend()
adapter.start()
device = adapter.connect("XX:XX:XX:XX:XX:XX")

device.char_write("XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX", "[OnderGrup] Communication Protocols send test code !")

adapter.stop()

#6LoWPAN Communication Protocol
import py6lowpan

lowpan = py6lowpan.SixLowpan()

lowpan.send("[OnderGrup] Communication Protocols send test code !")

lowpan.close()

#Wi-Fi Communication Protocol
import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

s.connect(("your_wifi_server", 80))

message = "[OnderGrup] Communication Protocols send test code !"
s.send(message.encode())

s.close()

#SigFox Communication Protocol
import PySigfox

sigfox = PySigfox.Sigfox()

sigfox.send("[OnderGrup] Communication Protocols send test code !")

sigfox.close()