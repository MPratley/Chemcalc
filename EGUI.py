from PyQt5 import QtCore, QtGui, uic
class chem(QtGui.QWidget)
    ...
    #somewhere in constructor:
    uic.loadUi('chem.ui', self)
