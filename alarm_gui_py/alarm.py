#!/usr/bin/python3

import time
import tkinter
from tkinter import *

while True:
    time.sleep(30*60)

    # 进入消息循环
    top = tkinter.Tk()
    top.wm_attributes('-topmost',1) # 置顶
    textlist  = Listbox(top)

    text = ['have a rest']
    for it in text:
        textlist.insert(-1,it)
    textlist.pack()

    top.mainloop()