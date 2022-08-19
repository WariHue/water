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
current_var = 0

sum = 0
mc = 'void'


def click():
    global mc
    global sum
    
    tx['text'] = '임금 : ' + str(sum) + 'G'
    current_var.set(current_var.get()+float(ent.get()))
    progressbar.update()
    if(current_var.get() >= 100.0):
        messagebox.showinfo("성공","물을 다 채웠당")
        mc = messagebox.askquestion("성공", "더 일할래?")     
    if(mc == 'yes'):   
        sum = sum + 1
        tx['text'] = '임금 : ' + str(sum) + 'G'
        current_var.set(0)
    elif(mc == 'no'):
        print(mc)
        tk.messagebox.showinfo('임금지급','잘 가')
        sum = sum  + 1
        tx['text'] = '임금 : ' + str(sum) + 'G'
        current_var.set(0)
        quit()
    else:
        return
        
def click1():
    if(current_var.get()-float(ent.get()) <= 0):
        current_var.set(0)
    else:
        current_var.set(current_var.get()-float(ent.get()))
    progressbar.update() 
    messagebox.showinfo("성공","물을 버렸다")

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

tx = tk.Label(window, text= '임금 : 0G', width=20,height=3,fg='blue')
tx.pack()


window.mainloop()


