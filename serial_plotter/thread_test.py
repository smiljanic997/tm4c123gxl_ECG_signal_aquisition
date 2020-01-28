import threading
import serial
from datetime import datetime
import csv
import numpy as np
import matplotlib
import matplotlib.pyplot as plt
import matplotlib.animation as animation
matplotlib.use("tkAgg")
import pandas as pd
import time
import os


c = threading.Condition()
figure_closed = False
plot_window = 50
arr = np.array(np.zeros([plot_window]))

def log_to_csv(file_name):
    global c
    global plot_window
    ser = serial.Serial(port = '/dev/ttyACM0', baudrate = 115200)
    ser.flushInput()
    global arr
    while True:
        global figure_closed
        if figure_closed == True:
            break
        try:
            received = ser.readline()
            decoded = float(received[0 : len(received) - 2].decode('utf-8'))
            c.acquire()
            arr = np.append(arr, decoded)
            arr = arr[1 : plot_window + 1]
            c.release()
            with open(file_name, 'a') as f:
                writer = csv.writer(f, delimiter = ',')
                writer.writerow([decoded])
                # print(decoded)
        except ValueError as ex:
           continue
        # TODO
        except KeyboardInterrupt:
            print('Plotting finished.')
            break


def animate(i):
    global arr
    # data = np.loadtxt(open(file_name, 'r'), delimiter = ',')
    x = np.linspace(0, plot_window)
    line.set_data(x, arr)
    return line,

def init_drawing():
    line.set_data([], [])
    return line,

def create_csv():
    if not os.path.exists('ecg_csv'):
        os.makedirs('ecg_csv')
    now = datetime.now()
    now_formatted = now.strftime('ECG_%d_%m_%Y %H:%M:%S.csv')
    return 'ecg_csv/' + now_formatted

def handle_close(evt):
    global figure_closed
    figure_closed = True
    print('Plotting finished.')


# set up the figure
fig = plt.figure()
fig.canvas.mpl_connect('close_event', handle_close)
ax = plt.axes(xlim = (0, plot_window), ylim = (0, 6))
line, = ax.plot([], [], lw = 2)

file_name = create_csv()
logging_thread = threading.Thread(target = log_to_csv, args = (file_name,))
logging_thread.start()
ani = animation.FuncAnimation(fig, animate, init_func = init_drawing, frames = None, interval = 0.01, blit = True)
plt.show()
logging_thread.join()
print('main')
