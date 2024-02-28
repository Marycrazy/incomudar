#py -m pip install pyautogui instalaçao de bibliotecas
import pyautogui as pt
import time
from tqdm import tqdm

limit = input("Enter limit:")
message = input("Enter message:")
i = 0
print("delay for 5 seconds")
for _ in tqdm(range(5)):
    time.sleep(1)
    
while i < int(limit):
    pt.typewrite(message)
    # the message is written where -
    # the cursor belongs      
    #time.sleep(1)#para meter um tempo entre as mensagens 
    pt.press("enter")
    i+=1
    print(i)
