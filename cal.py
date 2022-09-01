from distutils.cmd import Command
from msilib.schema import Error, Icon
import re
from sys import flags
import tkinter as tk
from tkinter import messagebox
import tkinter.ttk as ttk
from turtle import color, width
from zlib import MAX_WBITS


    

window = tk.Tk()
window.geometry("200x150")
window.resizable(False, False)
window.title("testGame")

def click():
    sum = (float(ent.get()) / 100) * (float(ent.get()) / 100)
    bum = float(ent1.get()) / sum
    ste = 'n'
    if(bum<10.0):
        ste = '멸치'
    elif(bum < 18.0):
        ste = '저체중'
    elif(bum < 22.0):
        ste = '정상체중'
    elif(bum < 24.0):
        ste = '과체중'
    elif(bum < 28.0):
        ste = '비만'
    elif(bum > 28.0):
        ste = '돼지새끼'
    tk.messagebox.showinfo('BMI지수는?',(ste, str(int(bum))))

tx = tk.Label(window, text= '신장', width=20,fg='blue')
tx.pack()

ent = ttk.Entry(window, width=20)
ent.pack()

tx = tk.Label(window, text= '몸무게', width=20,fg='blue')
tx.pack()

ent1 = ttk.Entry(window, width=20)
ent1.pack()

btn = ttk.Button(window, width=20, text="계산",command=click)
btn.pack()

window.mainloop()