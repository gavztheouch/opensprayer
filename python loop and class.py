import time
from fastai.vision import *
from PIL import Image, ImageChops
import serial


doc = Image.open('learn/test/doc.jpg')

#creates a new empty image, RGB mode, and size 400 by 400.
new_im = Image.new('RGB', (2048,1536))
doc_array = []
Arduino_Serial = serial.Serial('/dev/cu.wchusbserial1420', 9600)  # Create Serial port object called arduinoSerialData

for e in range(0,1536,256):
    for x in range(0,2048,256):


        square = doc.crop((x,e,x+256,e+256))
        #Image._show(square)
        #c = x/256
        #d = y/256
        #c = int(c)
        #d = int(d)
        #print(c)
        square.save("learn/tested/blue.jpg")
        learn = load_learner('learn', test=ImageItemList.from_folder('learn/tested'))
        preds, y = learn.get_preds(ds_type=DatasetType.Test)
        out = np.argmax(preds)
        print(out)
        if out == tensor(0):
            print("Dock")
            square = ImageChops.invert(square)
            new_im.paste(square, (x, e))
            doc_array.append(1)
        else:
            print("Not Dock")
            new_im.paste(square, (x, e))
            doc_array.append(0)
        square.close()

new_im.save("learn/output.jpg")
doc_array.append(7)
for x in range(len(doc_array)):
    print (doc_array[x])

mystring = ''.join(str(e) for e in doc_array)   # joins array into string (could add 7 to end here?)

Arduino_Serial.write(mystring.encode())  # send 1 to arduino
