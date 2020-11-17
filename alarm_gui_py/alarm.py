#!/usr/bin/python3

import time
import tkinter
from tkinter import *

while True:
    time.sleep(30*60)

    # 进入消息循环
    top = tkinter.Tk()
    textlist  = Listbox(top)

    text = ['have a rest']
    for it in text:
        textlist.insert(-1,it)
    textlist.pack()

    top.mainloop()