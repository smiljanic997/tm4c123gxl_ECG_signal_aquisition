import serial
import time
import csv
import matplotlib
matplotlib.use("tkAgg")
import matplotlib.pyplot as plt
import numpy as np

PORT = '/dev/ttyACM0'
BAUD = 115200
print('Opening serial port', PORT)
ser = serial.Serial(port = PORT, baudrate = BAUD)


ser.flushInput()
plot_window = 50
y_var = np.array(np.zeros([plot_window]))

plt.ion()
fig, ax = plt.subplots()
line, = ax.plot(y_var)
ax.axes.get_xaxis().set_visible(False) 

while True:
    try:
        ser_bytes = ser.readline()
        try:
            value = float(ser_bytes[0 : len(ser_bytes) - 2].decode("utf-8"))
            value = value * 5.0 / 4095.0
            print(value)
        except:
            continue
        y_var = np.append(y_var, value)
        y_var = y_var[1 : plot_window + 1]
        line.set_ydata(y_var)
        ax.relim()
        ax.autoscale_view()
        fig.canvas.draw()
        fig.canvas.flush_events()
    except:
        print('Plotting stopped.')
        break
