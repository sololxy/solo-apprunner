#!/bin/env python
# --*-- encoding:utf-8 --*--

from PyQt5.QtCore import *

#print dir()
# 打开文件
xmlFile =  QFile("./App.config")
xmlFile.open(QIODevice.ReadOnly|QIODevice.Text)

# 关联到xmlreader
xmlReader = QXmlStreamReader(xmlFile)

while not xmlReader.atEnd():

    #print xmlReader.attributes().values()

    xmlReader.readNext()

    if xmlReader.hasError():
        print "error:",xmlReader.errorString()

    if xmlReader.isStartDocument():
        print "isStartDocument:",xmlReader.lineNumber(), xmlReader.name()
        continue

    elif xmlReader.isStartElement():
        name = xmlReader.name()

        if name == 'ProgramGroup':
            while not xmlReader.atEnd():
                xmlReader.readNext()
                print "ProgramGroup:",xmlReader.lineNumber(), xmlReader.name()
