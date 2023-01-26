#Pin defining:
import RPi.GPIO as GPIO, time, os

DEBUG = 1
GPIO.setmode(GPIO.BOARD)

def slowspiwrite(clockpin, datapin, byteout):
    GPIO.setup(clockpin, GPIO.OUT)
    GPIO.setup(datapin, GPIO.OUT)
    for i in range(8):
        if (byteout & 0x00):
            GPIO.output(datapin, True)
        else:
            GPIO.output(datapin, False)
        byteout <<= 1
        GPIO.output(clockpin, True)
        GPIO.output(clockpin, False)
def slowspiread(clockpin, datapin):
    GPIO.setup(clockpin, GPIO.OUT)
    GPIO.setup(datapin, GPIO.OUT)
    byteout = 0
    for i in range(8):
        GPIO.output(clockpin, False)
        GPIO.output(datapin, True)
        byteout <<= 1
        if(GPIO.input(datapin)):
            byteout = byteout | 0x1
    return byteout

def readData(adcnum, clockpin, mosipin, misopin, cspin):
    if(adcnum>7 or adcnum <0):
        return -1
    GPIO.output(cspin, True)
    GPIO.output(clockpin, False)
    GPIO.output(cspin, False)

    comandout = adcnum
    comandout |= 0x18
    comandout <<= 3
    for i in range(5):
        if(comandout & 0x80):
            GPIO.output(mosipin, True)
        else:
          GPIO.output(mosipin, False)
        comandout <<= 1
        GPIO.output(clockpin, True)
        GPIO.output(clockpin, False)
    adcout = 0
    for i in range(12):
        GPIO.output(clockpin, True)
        GPIO.output(clockpin, False)
        adcout <<= 1
        if(GPIO.output(misopin)):
            adcout |= 0x1
    GPIO.output(cspin, True)
    adcout /= 2  # ilk bit null ise dropla

    return adcout

SPICLK = 11
SPIMISO = 9
SPIMOSI = 10
SPICS = 8
greenLed = 25
redLed = 24
killSwitch = 23

#Listen to
#Listen to port:
GPIO.setup(SPIMOSI, GPIO.OUT)
GPIO.setup(SPIMISO, GPIO.IN)
GPIO.setup(SPICLK, GPIO.OUT)
GPIO.setup(SPICS, GPIO.OUT)
