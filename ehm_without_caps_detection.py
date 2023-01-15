# Importing Libraries
import serial
import time
import wmi

arduino = serial.Serial(port='COM7', baudrate=115200, timeout=.1) #change the com-port to the port your mircocontroller is connected to
w = wmi.WMI(namespace="root\OpenHardwareMonitor")

def write_read(x):
    arduino.write(bytes(x, 'utf-8'))
    time.sleep(0.05)
    data = arduino.readline()
    return data
while True:
    temperature_infos = w.Sensor()
    for sensor in temperature_infos:
        if sensor.SensorType == u'Temperature':
            if sensor.Name == 'CPU Package':
                cputemp = str(round(sensor.Value, 1))
        if sensor.SensorType == u'Load':
            if sensor.Name == 'CPU Total':
                cpuload = str(round(sensor.Value, 1))
        if sensor.SensorType == u'Load':
            if sensor.Name == 'Memory':
                ramload = str(round(sensor.Value, 1))
        if sensor.SensorType == u'Data':
            if sensor.Name == 'Used Memory':
                ramgb = str(round(sensor.Value, 1))
        if sensor.SensorType == u'Temperature':
            if sensor.Name == 'GPU Core':
                gputemp = str(round(sensor.Value, 1))
        if sensor.SensorType == u'Load':
            if sensor.Name == 'GPU Core':
                gpuload = str(round(sensor.Value, 1))

    num = 'cputemp:' + cputemp + ':cpuload:' + cpuload + ':ramload:' + ramload + ':ramgb:' + ramgb + ':gputemp:' + gputemp + ':gpuload:' + gpuload + ':'
    value = write_read(num)
    time.sleep(1)
