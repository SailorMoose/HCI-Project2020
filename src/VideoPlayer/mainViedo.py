# This Python file uses the following encoding: utf-8
#import sys

#from PyQt5.QtCore import QTimer
#from PyQt5.QtGui import QGuiApplication
#from PyQt5.QtQml import QQmlApplicationEngine
from PyQt5.QtWidgets import QApplication
from PyQt5.QtQuick import QQuickView
from PyQt5.QtCore import QUrl


if __name__ == "__main__":
    app = QApplication([])
    view = QQuickView()
    url = QUrl("VideoPlayer.qml")

    view.setSource(url)
    view.setTitle("Prototype")
    view.show()
    app.exec_()


#if __name__ == '__main__':

#    app = QGuiApplication(sys.argv)

#    engine = QQmlApplicationEngine()
#    engine.load('./VideoPlayer.qml')

#    timer = QTimer()
#    timer.timeout.connect(lambda: None)
#    timer.start(100)

#    sys.exit(app.exec_())
