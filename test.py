from distutils.cmd import Command
from msilib.schema import Error, Icon
import re
from sys import flags
import tkinter as tk
from tkinter import messagebox
import tkinter.ttk as ttk
from turtle import color, width


    

window = tk.Tk()
window.geometry("200x150")
window.resizable(False, False)
window.title("testGame")
current_var = 0




def click():
    current_var.set(current_var.get()+float(ent.get()))
    progressbar.update()
    if(current_var.get() >= 100.0):
        messagebox.showinfo("성공","물을 다 채웠당")
        messagebox.IGNORE(quit())
        
        
def click1():
    current_var.set(0)
    progressbar.update() 
    messagebox.showinfo("성공","물을 다 비웠다")

def click2():
    current_var.set(0)
    progressbar.update() 
    mB = messagebox.askquestion("도망가게?", "진짜 갈꺼야?")       
    if(mB == 'yes'):
        tk.messagebox.showinfo('물이나 넣어','그래')
        quit() 
    else:
        tk.messagebox.showinfo('그래','그래')


         

current_var = tk.DoubleVar()
progressbar = ttk.Progressbar(window, length=150, variable=current_var, maximum=100)
progressbar.pack()

ent = ttk.Entry(window, width=20)
ent.pack()

btn = ttk.Button(window, width=20, text="물 넣기",command=click)
btn.pack()

btn1 = ttk.Button(window, width=20, text="물 버리기",command=click1)
btn1.pack()

btn2 = ttk.Button(window, width=20, text="도망치기",command=click2)
btn2.pack()


window.mainloop()



