import cv2 as cv
import numpy as np
import imutils
from imutils.video import VideoStream
import argparse
import time
# here we can give a video locations as a string of the path

prevCircle = None
def dist(x1, y1, x2, y2):
    return pow((x1-x2), 2)+pow((y1-y2), 2)

#this is all the video capturing part
ap = argparse.ArgumentParser()

ap.add_argument("-b", "--buffer", type=int, default=64,
                help="max buffer size")
args = vars(ap.parse_args())
time.sleep(2.0)
# if a video path was not supplied, grab the reference
# to the webcam
if not args.get("video", False):
    vs = VideoStream(src=0).start()
# out = cv2.VideoWriter('opt')

#distance measurement part starts from here 



while True:
    frame = vs.read()
    frame = frame[1] if args.get("video", False) else frame
    # cap.get(cv2.cap)  using the prop id

    gray = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)
    blurFrame = cv.GaussianBlur(gray, (17, 17), 0)
    # cv.imshow('frame', gray)

    #100 is the minimum distance between the centers of 2 circles for qualifying as
    # two different circles
    #param1 - sensitivity of circle detection
    #param2 - no of edgespoints for detection of a circle
    circles = cv.HoughCircles(blurFrame, cv.HOUGH_GRADIENT, 1.2, 100,
                              param1=100, param2=30, minRadius=75, maxRadius=400)

    if circles is not None:
        circles = np.int32(np.around(circles))
        chosen = None
        for i in circles[0, :]:
            if chosen is None:
                chosen = i
            if prevCircle is not None:
                if dist(chosen[0], chosen[1], prevCircle[0], prevCircle[1]) <= dist(i[0], i[1], prevCircle[0], prevCircle[1]):
                    chosen = i
        #drawing the circumfrence of the ball and the center point
        cv.circle(frame, (chosen[0], chosen[1]), 1, (0, 100, 100), 3)
        cv.circle(frame, (chosen[0], chosen[1]), chosen[2], (0, 0, 255), 3)
        prevCircle = chosen
    cv.imshow("circles", frame)

    if cv.waitKey(1) & 0xFF == ord('q'):
        break

if not args.get("video", False):
    vs.stop()
# otherwise, release the camera
else:
    vs.release()
cv.destroyAllWindows()
