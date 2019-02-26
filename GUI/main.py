import sys
from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.QtCore import QTimer
from ctypes import *
import time

class Demo(QWidget):
    libcam = None
    lb = None
    def __init__(self):
        super().__init__()
        self.timer = QTimer(self)
        self.timer.timeout.connect(self.operate)
        self.timer.start(200)
        self.initUI()

    def initUI(self):
        width = 1024
        height = 768
        self.lb = QLabel(self)
        self.lb.setGeometry(0,0,width, height)
        self.lb.setStyleSheet("border: 2px solid red")
        #lb.setPixmap(pix)

        self.resize(width, height)
        self.move(300, 300)
        self.setWindowTitle('Simple')
        self.show()

        self.libcam = cdll.LoadLibrary('dvpcam.dll')
        self.libcam.initCam(c_void_p(self.lb.winId().__init__()))

    def operate(self):
        self.libcam.getImage.restype = POINTER(c_char_p)
        imgAddr = self.libcam.getImage()

        bitmap = c_char*1024*768*3;
        arr = bitmap()
        memmove(arr, imgAddr, 1024*768*3)

        img = QImage(arr, 1024, 768, QImage.Format_RGB888)
        pix = QPixmap.fromImage(img)
        self.lb.setPixmap(pix)

if __name__ == '__main__':
    app = QApplication(sys.argv)

    d = Demo()
    #time.sleep(1)
    #d.refresh()

    sys.exit(app.exec_())

