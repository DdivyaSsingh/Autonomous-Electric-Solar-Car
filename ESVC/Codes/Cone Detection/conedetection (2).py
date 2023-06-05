import cv2 as cv
import numpy as np
global x
global y
cap = cv.VideoCapture("D:\conedetection\video.mp4")
whT = 320
confThreshold =0.01
nmsThreshold= 0.2
#### LOAD MODEL
## Coco Names
#classesFile = "C://Users//ASUS//Projects//models//coco.names"
classNames = ["cone"]
#with open(classesFile, 'rt') as f:
 #   classNames = f.read().rstrip('\n').split('\n')
#print(classNames)
## Model Files
modelConfiguration = "D:\conedetection\yolov3_testing.cfg"
modelWeights = "D:\conedetection\yolov3_training_1000.weights"
net = cv.dnn.readNetFromDarknet(modelConfiguration, modelWeights)
net.setPreferableBackend(cv.dnn.DNN_BACKEND_OPENCV)
net.setPreferableTarget(cv.dnn.DNN_TARGET_OPENCL)

def left():
    #10deg sterring with 20km/hr speed
    print("left")
def right():
    #10 deg sterring with 20km/hr
    print("right")

def decider(x,y):
    if 200<y<300 and x<100 :
        left()

    if  200<y<300 and 100<x<250 :
        right()


def findObjects(outputs,img):
    hT, wT, cT = img.shape
    bbox = []
    classIds = []
    confs = []
    for output in outputs:
        for det in output:
            scores = det[5:]
            classId = np.argmax(scores)
            confidence = scores[classId]
            if confidence > confThreshold:
                w,h = int(det[2]*wT) , int(det[3]*hT)
                x,y = int((det[0]*wT)-w/2) , int((det[1]*hT)-h/2)
                bbox.append([x,y,w,h])
                classIds.append(classId)
                confs.append(float(confidence))
                decider(x,y)
    indices = cv.dnn.NMSBoxes(bbox, confs, confThreshold, nmsThreshold)
    for i in indices:
        i = i[0]
        box = bbox[i]
        x, y, w, h = box[0], box[1], box[2], box[3]
        decider(x,y)
        print(x,y)
        cv.rectangle(img, (x, y), (x+w,y+h), (255, 0 , 255), 2)
        cv.putText(img,f'{classNames[classIds[i]].upper()} {int(confs[i]*100)}%',
                  (x, y-10), cv.FONT_HERSHEY_SIMPLEX, 0.6, (255, 0, 255), 2)
while True:
    success, img = cap.read()
    #resized = cv.resize(img, (224, 224))
    #blob = cv.dnn.blobFromImage(resized, 1, (224, 224), (104, 117, 123))
    blob = cv.dnn.blobFromImage(img, 1 / 255, (whT, whT), [0, 0, 0])
    net.setInput(blob)
    layersNames = net.getLayerNames()
    outputNames = [(layersNames[i[0] - 1]) for i in net.getUnconnectedOutLayers()]
    outputs = net.forward(outputNames)
    findObjects(outputs,img)
    cv.imshow('Image', img)
    cv.waitKey(1)
