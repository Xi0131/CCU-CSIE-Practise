import os
import time
import discord
from dotenv import load_dotenv

BOT_SEND_CHENNEL_ID=os.getenv('BOT_SEND_CHENNEL_ID')
DISCORD_BOT_APIKEY=os.getenv('DISCORD_BOT_APIKEY')

print(time.ctime(time.time()))   # Tue Oct 19 07:59:19 2021
time.sleep(2)                    # 暫停兩秒
print(time.ctime(time.time()))   # Tue Oct 19 07:59:21 2021
