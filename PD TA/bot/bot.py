import os
import sys
import time
import discord
import requests
from discord.ext import commands
from discord.ext import tasks
from dotenv import load_dotenv

import discord.ext

intents = discord.Intents.default() #intents 是要求的權限
intents.message_content = True
bot = commands.Bot(command_prefix='!', intents=intents)
load_dotenv()

BOT_SEND_CHENNEL_ID=os.getenv('BOT_SEND_CHENNEL_ID')
DISCORD_BOT_APIKEY=os.getenv('DISCORD_BOT_APIKEY')

# print(time.ctime(time.time()))   # Tue Oct 19 07:59:19 2021
# time.sleep(2)                    # 暫停兩秒
# print(time.ctime(time.time()))   # Tue Oct 19 07:59:21 2021

@tasks.loop(seconds=1.0) #每180秒執行一次
async def checkTimeAndUpload():
    try:
        print('hi')
    except:
        print(sys.exc_info()[0])
        
############ bot commands ############
        
@bot.slash_command(name="ping", description="測試指令")
async def ping(ctx):
    embed=discord.Embed(title="Pong!", description="目前機器人延遲為 " + str(round(bot.latency*1000)) + "ms", color=0x00ff00)
    await ctx.respond(embed=embed)

@bot.slash_command(name="help", description="列出所有指令")
async def help(ctx):
    # using Embed
    embed=discord.Embed(title="指令列表", description="以下是所有指令的列表", color=0x00ff00)
    embed.add_field(name="add [userID]", value="新增一位CSES使用者", inline=False)
    embed.add_field(name="addcf [userName]", value="新增一位Codeforces使用者", inline=False)
    embed.add_field(name="list", value="列出所有CSES使用者", inline=False)
    embed.add_field(name="listcf", value="列出所有Codeforces使用者", inline=False)
    embed.add_field(name="delete [userID]", value="刪除一位CSES使用者", inline=False)
    embed.add_field(name="deletecf [userName]", value="刪除一位Codeforces使用者", inline=False)
    embed.add_field(name="help", value="列出所有指令", inline=False)
    embed.add_field(name="ping", value="測試指令", inline=False)
    await ctx.respond(embed=embed)
    
@bot.slash_command(name="addProbToContest", description="測試指令")
async def addProbToContest(ctx, prob_id):
    

############ bot commands ############
        
@bot.event
async def on_ready(): #啟動成功時會呼叫
    try:
        channel = discord.utils.get(bot.get_all_channels(), id=int(BOT_SEND_CHENNEL_ID)) # 用頻道ID定位想要發送訊息的那個頻道
        await channel.send('**[System]** bot成功啟動!')
    except Exception as e:
        # 印出錯誤原因
        channel = discord.utils.get(bot.get_all_channels(), id=int(BOT_SEND_CHENNEL_ID))
        await channel.send(str(e))

    checkTimeAndUpload()

@bot.event
async def on_message(message): #有新的訊息便會呼叫
    try:
        if message.author == bot.user: #若新訊息是bot本身則忽略
            return
        elif message.content[:12]=='System call ':
            commend=message.content[12:]

            sendMessage=System_Commend(message,commend)
            print(sendMessage)
            bot._connection._messages.clear()
            await message.channel.send(sendMessage)
    except Exception as e:
        # 印出錯誤原因
        channel = discord.utils.get(bot.get_all_channels(), id=int(BOT_SEND_CHENNEL_ID))
        await channel.send(str(e))

bot.run(DISCORD_BOT_APIKEY)