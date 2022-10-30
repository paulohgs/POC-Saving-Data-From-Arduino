import serial.tools.list_ports
import serial

def port():
    ports = serial.tools.list_ports.comports()
    return ports[2]

if __name__ == "__main__":
    arduino_port = "/dev/cu.usbmodem1301"
    baud = 9600
    fileName = "analog-data.csv"
    samples = 5
    ser = serial.Serial(arduino_port, baud)
    print_labels = True
    print("Connected to Arduino Port: ", arduino_port)
    file = open(fileName, "a")
    print("Created file")

    line = 0
    while line <= samples:
        if print_labels:
            if line == 0:
                print("Printing Column Headers")
            else:
                print("Line " + str(line) + ": writing...")
        getData = ser.readline().decode('utf-8')
        decodedData = getData
        data = decodedData[0:][:-2]
        print(data)

        file = open(fileName, "a")
        file.write(data + "\n")

        line += 1

    print("Data collection complete.")
    

