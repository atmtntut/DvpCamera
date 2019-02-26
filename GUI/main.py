import sys
from PyQt5.QtWidgets import QApplication, QWidget, QLabel
from ctypes import *
import time

class Demo(QWidget):
    libcam = None
    def __init__(self):
        super().__init__()
        self.initUI()

    def initUI(self):
        label = QLabel('test', self)

        self.resize(250, 150)
        self.move(300, 300)
        self.setWindowTitle('Simple')
        self.show()

        self.libcam = cdll.LoadLibrary('dvpcam.dll')
        self.libcam.initCam(c_void_p(label.winId().__init__()))



if __name__ == '__main__':
    app = QApplication(sys.argv)

    d = Demo()

    time.sleep(1)
    strs = d.libcam.getImage()
    print(dir(strs))
    print(strs.imag)

    sys.exit(app.exec_())

