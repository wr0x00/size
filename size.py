
from ctypes import *
if __name__ == "__main__":
    c_=cdll.LoadLibrary("./forc.dll")
    files=input("输入字典名称：")
    string=input("输入包括的字符：")
    lens=input("输入生成字典位数：")
    c_.dic(files,string,lens)
