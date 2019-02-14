import time
from fastai.vision import *
from PIL import Image, ImageChops


doc = Image.open('learn/test/doc.jpg')

#creates a new empty image, RGB mode, and size 400 by 400.
new_im = Image.new('RGB', (2048,1536))

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
        else:
            print("Not Dock")
            new_im.paste(square, (x, e))
        square.close()

new_im.save("learn/output.jpg")
      
