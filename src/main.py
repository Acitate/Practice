import ctypes
from PySide2.QtWidgets import QApplication, QMainWindow, QFrame, QPushButton, QVBoxLayout, QWidget
import sys
from ui import Ui_MainWindow


lib = ctypes.CDLL('./libfuncs.so')


lib.add.argtypes = [ctypes.c_float, ctypes.c_float]
lib.add.restype = ctypes.c_float
lib.sub.argtypes = [ctypes.c_float, ctypes.c_float]
lib.sub.restype = ctypes.c_float
lib.mult.argtypes = [ctypes.c_float, ctypes.c_float]
lib.mult.restype = ctypes.c_float
lib.divide.argtypes = [ctypes.c_float, ctypes.c_float]
lib.divide.restype = ctypes.c_float


class MainApp(QMainWindow):
    def __init__(self):
        super(MainApp, self).__init__()
        self.ui = Ui_MainWindow()
        self.ui.setupUi((self))

        self.ui.doAdd.clicked.connect(self.doAdd)
        self.ui.doSub.clicked.connect(self.doSub)
        self.ui.doMul.clicked.connect(self.doMul)
        self.ui.doDiv.clicked.connect(self.doDiv)



    def doAdd(self):
        x = float(self.ui.x.text())
        y = float(self.ui.y.text())
        res = lib.add(x, y)
        self.ui.add_Res.setText(str(res))


    def doSub(self):
        x = float(self.ui.x_3.text())
        y = float(self.ui.y_3.text())
        res = lib.sub(x, y)
        self.ui.sub_Res.setText(str(res))


    def doMul(self):
        x = float(self.ui.x_6.text())
        y = float(self.ui.y_6.text())
        res = lib.mult(x, y)
        self.ui.mul_Res.setText(str(res))


    def doDiv(self):
        x = float(self.ui.x_8.text())
        y = float(self.ui.y_8.text())
        res = lib.divide(x, y)
        self.ui.div_Res.setText(str(res))


if __name__ == "__main__":
    app = QApplication(sys.argv)
    mainWindow = MainApp()
    mainWindow.show()
    sys.exit(app.exec_())
