import serial
import time 

ser = serial.Serial('/dev/cu.usbmodem312201', 115200, timeout=1)
time.sleep(2) # wait for arduino to reset

def send_spikes(spike_pattern):
    
    ser.write(spike_pattern.encode())

binary_array = []

with open('spike_output.txt', 'r') as file:
    for line in file:
        # strip to remove new line characters \n
        # replace to remove commas
        binary_string = line.strip().replace(',','')
        binary_array.append(binary_string)

for step in binary_array:
    send_spikes(step)
    time.sleep(0.025)
