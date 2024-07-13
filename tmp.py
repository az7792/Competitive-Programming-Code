import pyautogui
import time
from pynput import keyboard
from pynput.mouse import Button, Controller
import threading

# 确保安装 pywin32
try:
    import win32gui
    import win32con
except ImportError as e:
    print("Error importing win32gui or win32con. Make sure you have installed pywin32 correctly.")
    raise e

mouse = Controller()
ok = False

def bring_to_foreground():
    # 使用 pywin32 将目标窗口置于前台
    hwnd = win32gui.FindWindow(None, "ZenlessZoneZero")  # 替换为实际窗口名称
    if hwnd:
        win32gui.ShowWindow(hwnd, win32con.SW_RESTORE)
        win32gui.SetForegroundWindow(hwnd)
        time.sleep(2)  # 等待窗口置于前台

def on_press(key):
    global ok
    try:
        print(f'Key {key} pressed')
        if key == keyboard.Key.up:
            ok = not ok  # 切换状态
            if ok:
                threading.Thread(target=mouse_clicker).start()
    except AttributeError:
        print(f'Special key {key} pressed')

def on_release(key):
    print(f'Key {key} released')
    if key == keyboard.Key.esc:
        return False

def mouse_clicker():
    global ok
    bring_to_foreground()  # 确保目标应用程序在前台
    ct = 0
    while ok:
        mouse.position = (958, 775)
        mouse.click(Button.left, 1)  # 左键点击一次
        time.sleep(1)
        mouse.position = (816, 650)
        mouse.click(Button.left, 1)  # 左键点击一次
        time.sleep(7)
        ct += 1
        print(ct)

# 开始监听
with keyboard.Listener(on_press=on_press, on_release=on_release) as listener:
    listener.join()
