import serial
import time
import pyautogui
import os
import platform

sis_op = platform.system() # windows or linux I'll use the program with both

if sis_op == 'Linux':
    ArduinoSerial = serial.Serial('/dev/ttyACM0',9600)
    time.sleep(2)

else:
    # buscar quin port es
    pass

while 1:
    inp = str(ArduinoSerial.readline())
    print(inp)
    
    # mode 0
    if '10' in inp: #if is the button 1 and mode 0
        pyautogui.typewrite("just cheking", interval=0.30)
        pyautogui.typewrite(['enter'], 0.2)

    elif '20' in inp: 
        pyautogui.hotkey('ctrl', 'z')

    #mode 1
    elif '11' in inp:
    	pyautogui.hotkey('ctrl', 'c')

    elif '21' in inp: 
        pyautogui.hotkey("ctrl", 'v')

    # mode 2
    elif '12' in inp:
    	pyautogui.click('file.txt')

    elif '22' in inp:
        pyautogui.alert("this is an alert")

    # mode 3
    elif '13' in inp:
    	pyautogui.typewrite('heyyy')
    	pyautogui.typewrite(['enter'], 0.2)
    elif '23' in inp:
        pyautogui.typewrite("anything")
        pyautogui.typewrite(['enter'], 0.2)


    inp = ""
