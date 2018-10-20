from PIL import Image
doc = Image.open('Doc1.jpg')


for y in range(0,1536,256):
    for x in range(0,2048,256):
        print (y,x,y+256,x+256)

        square = doc.crop((x,y,x+256,y+256))
       # Image._show(square)
        c = x/256
        d = y/256
        c = int(c)
        d = int(d)
        print(c)
        square.save("red" + str(c) +str(d) + ".png")
